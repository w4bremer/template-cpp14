//go:build mage

package main

import (
	"archive/tar"
	"compress/gzip"
	"context"
	"fmt"
	"github.com/google/go-github/v48/github"
	"github.com/magefile/mage/sh"
	"io"
	"log"
	"net/http"
	"os"
	"runtime"
	"strings"
)

const (
	goldenDir        = "goldenmaster"
	generatedTestDir = "test"
)

func must(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

func gitClone(url, dir string) {
	must(sh.RunV("git", "clone", "--depth=1", url, dir))
}

func runDiff(dir1, dir2 string) {
	must(sh.RunV("git", "--no-pager", "diff", "--no-index", dir1, dir2))
}

func goInstall(pkg string) {
	must(sh.RunV("go", "install", pkg))
}
func genSol(sol string) {
	must(sh.RunV("bin/apigear", "g", "sol", sol))
}

func rmDir(dir string) {
	must(sh.Rm(dir))
}

// Install installs the apigear cli and testbed-apis.
func Install(pf string, arch string) error {
	log.Printf("installing apigear cli")
	err := os.MkdirAll("tmp", 0755)
	if err != nil {
		return err
	}

	err = os.MkdirAll("bin", 0755)
	if err != nil {
		return err
	}

	gh := github.NewClient(nil)
	release, _, err := gh.Repositories.GetLatestRelease(context.Background(), "apigear-io", "cli-releases")
	if err != nil {
		return err
	}
	log.Printf("using latest release: %s", release.GetTagName())

	// patch version
	vers := strings.TrimLeft(release.GetTagName(), "v")
	// asset name we are looking for
	asset := fmt.Sprintf("apigear_%s_%s_%s.tar.gz", vers, pf, arch)
	log.Printf("looking for asset %s in release assets", asset)
	foundAsset := false
	for _, a := range release.Assets {
		if a.GetName() == asset {
			log.Printf("found asset %s", asset)
			foundAsset = true
			err = httpDownload(a.GetBrowserDownloadURL(), "tmp/apigear.tar.gz")
			if err != nil {
				return err
			}
			err = extractTarGz("tmp/apigear.tar.gz", "tmp")
			if err != nil {
				return err
			}
			break
		}
	}
	if !foundAsset {
		return fmt.Errorf("could not find matching asset %s in release assets", asset)
	}
	if runtime.GOOS == "windows" {
		os.Rename("tmp/apigear.exe", "bin/apigear.exe")
		// make it executable
		os.Chmod("bin/apigear.exe", 0755)
	} else {
		os.Rename("tmp/apigear", "bin/apigear")
		// make it executable
		os.Chmod("bin/apigear", 0755)
	}

	rmDir("tmp")
	return nil
}

// Diff runs the generator and compares the output with the golden master.
func Diff() {
	genSol("./apigear/goldenmaster.solution.yaml")
	runDiff(goldenDir, generatedTestDir)
}

// Clean removes all generated files.
func Clean() {
	rmDir(generatedTestDir)
}

// compares the goldenmaster files with the generated files
func DiffOnly() {
	runDiff(goldenDir, generatedTestDir)
}

// generate the goldenmaster files in the test directory
func GenTest() {
	rmDir(generatedTestDir)
	genSol("./apigear/goldenmaster.solution.yaml")
}

// automatically format all goldenmaster files according to the clang-format
func FormatStyle() {
	must(sh.RunV("bash", "-c", "find goldenmaster -type f -iname '*.h' -o -type f -iname '*.cpp' | xargs clang-format -i"))
}

// test whether the goldenmaster files are formatted according to the clang-format
func TestStyle() {
	must(sh.RunV("bash", "-c", "clang-format --version && find goldenmaster -type f -iname '*.h' -o -type f -iname '*.cpp' | xargs clang-format --dry-run --Werror"))
}

// extractTarGz extracts a tar.gz file to a destination directory.
func extractTarGz(src, dest string) error {
	log.Printf("extracting %s to %s", src, dest)
	r, err := os.Open(src)
	if err != nil {
		return fmt.Errorf("failed to open file: %v", err)
	}
	defer r.Close()
	gzipReader, err := gzip.NewReader(r)
	if err != nil {
		return fmt.Errorf("failed to create gzip reader: %v", err)
	}
	defer gzipReader.Close()
	tr := tar.NewReader(gzipReader)
	for {
		hdr, err := tr.Next()
		if err != nil {
			if err == io.EOF {
				break
			}
			return fmt.Errorf("error reading tar: %v", err)

		}
		if hdr.Typeflag == tar.TypeReg {
			tf, err := os.Create(fmt.Sprintf("%s/%s", dest, hdr.Name))
			defer tf.Close()
			if err != nil {
				return fmt.Errorf("failed to create file: %v", err)
			}
			_, err = io.Copy(tf, tr)
			if err != nil {
				return fmt.Errorf("failed to copy file: %v", err)
			}
		}
	}
	return nil
}

// httpDownload downloads a file from a url to a local file.
func httpDownload(url, dest string) error {
	log.Printf("downloading %s to %s", url, dest)
	resp, err := http.Get(url)
	if err != nil {
		return fmt.Errorf("failed to download file: %v", err)
	}
	defer resp.Body.Close()
	out, err := os.Create(dest)
	if err != nil {
		return fmt.Errorf("failed to create file: %v", err)
	}
	defer out.Close()
	_, err = io.Copy(out, resp.Body)
	if err != nil {
		return fmt.Errorf("failed to copy file: %v", err)
	}
	return nil
}

{{- $module_id := snake .Module.Name -}}
import os
from conan import ConanFile
from conan.tools.cmake import CMake, CMakeDeps, CMakeToolchain
# from conan.tools.build import cross_building
from conan.tools.build import can_run


class {{$module_id}}TestConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    requires = "{{$module_id}}/{{.Module.Version}}"

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()
        deps = CMakeDeps(self)
        deps.generate()

    def build(self):
        cmake = CMake(self)
        # Current dir is "test_package/build/<build_id>" and CMakeLists.txt is
        # in "test_package"
        cmake.configure()
        cmake.build()

    def imports(self):
        copy(self, "*", src="@bindirs", dst="bin")
        copy(self, "*", src="@libdirs", dst="lib")

    def test(self):
        if can_run(self):
            cmd = os.path.join(self.cpp.build.bindir, "test_{{$module_id}}")
            self.run(cmd, env="conanrun")
        # if not cross_building(self):
        #     # Visual Studio uses Release/Debug subfolders to generate binaries
        #     if self.settings.compiler == "msvc":
        #         build_type = self.settings.get_safe("build_type", default="Release")
        #         self.run(os.path.sep.join([".", build_type, "test_{{$module_id}}"]))
        #     else:
        #         self.run(os.path.sep.join([".", "test_{{$module_id}}"]))

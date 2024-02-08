import os

from conans import ConanFile, CMake, tools


class tb_same2TestConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake_find_package"
    requires = "tb_same2/1.0.0"

    def build(self):
        cmake = CMake(self)
        # Current dir is "test_package/build/<build_id>" and CMakeLists.txt is
        # in "test_package"
        cmake.configure()
        cmake.build()

    def imports(self):
        self.copy("*", src="@bindirs", dst="bin")
        self.copy("*", src="@libdirs", dst="lib")

    def test(self):
        if not tools.cross_building(self):
            # Visual Studio uses Release/Debug subfolders to generate binaries
            if self.settings.compiler == "Visual Studio":
                build_type = self.settings.get_safe("build_type", default="Release")
                self.run(os.path.sep.join([".", build_type, "test_tb_same2"]), run_environment=True)
            else:
                self.run(os.path.sep.join([".", "test_tb_same2"]), run_environment=True)

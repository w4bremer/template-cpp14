from conans import ConanFile, CMake, tools
from pathlib import os

class tb_enumConan(ConanFile):
    name = "tb_enum"
    version = "1.0"
    license = "GPL v3"
    author = "ApiGear UG"
    #url = "<Package recipe repository url here, for issues about the package>"
    settings = "os", "compiler", "build_type", "arch"
    requires = "catch2/2.13.7", "nlohmann_json/3.9.1", "apigear/0.1.0"
    generators = "cmake_find_package"
    exports_sources = "*"

    def build(self):
        cmake = CMake(self)
        cmake.configure(source_folder=".")
        cmake.build()

    def package(self):
        packages = ["api", "core", "monitor", "olink"]
        self.copy("**/*.h", dst="include/generated", src="generated")
        self.copy("*.h", dst="include", src="implementation")
        self.copy("*.lib", dst="lib", keep_path=False)
        self.copy("*.dll", dst="bin", keep_path=False)
        self.copy("*.dylib*", dst="lib", keep_path=False)
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
        self.env_info.path.append(os.path.join(self.package_folder, "bin"))
        self.cpp_info.components["tb_enum-api"].libs = ["tb_enum-api"]
        self.cpp_info.components["tb_enum-core"].libs = ["tb_enum-core"]
        self.cpp_info.components["tb_enum-core"].requires = ["tb_enum-api", "catch2::catch2", "nlohmann_json::nlohmann_json"]
        self.cpp_info.components["tb_enum-implementation"].libs = ["tb_enum-implementation"]
        self.cpp_info.components["tb_enum-implementation"].requires = ["tb_enum-core", "catch2::catch2", "nlohmann_json::nlohmann_json"]
        self.cpp_info.components["tb_enum-monitor"].libs = ["tb_enum-monitor"]
        self.cpp_info.components["tb_enum-monitor"].requires = ["tb_enum-core", "nlohmann_json::nlohmann_json", "apigear::poco-tracer"]
        self.cpp_info.components["tb_enum-olink"].libs = ["tb_enum-olink"]
        self.cpp_info.components["tb_enum-olink"].requires = ["tb_enum-core", "nlohmann_json::nlohmann_json", "apigear::poco-olink"]

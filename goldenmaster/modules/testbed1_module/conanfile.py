from conans import ConanFile, CMake, tools
from pathlib import os

class testbed1Conan(ConanFile):
    name = "testbed1"
    version = "1.0"
    license = "GPL v3"
    author = "ApiGear UG"
    #url = "<Package recipe repository url here, for issues about the package>"
    settings = "os", "compiler", "build_type", "arch"
    requires = "catch2/2.13.7", "nlohmann_json/3.9.1", "apigear/0.1.0"
    generators = "cmake_find_package"
    exports_sources = "*"
    options = {"build_testing": [True, False]}
    default_options = {"build_testing": True}

    def build(self):
        cmake = CMake(self)
        if not tools.cross_building(self):
            cmake.definitions['BUILD_TESTING'] = self.options.build_testing
        cmake.configure(source_folder="./testbed1")
        cmake.build()
        if not tools.cross_building(self):
            build_type = self.settings.get_safe("build_type", default="Release")
            # workaround - we need to add the api.dll and the core.dll to the windows PATH to be found for the test
            local_libs = { "PATH" : []}
            local_libs["PATH"].append(os.path.sep.join([self.build_folder, "generated", "api", build_type]))
            local_libs["PATH"].append(os.path.sep.join([self.build_folder, "generated", "core", build_type]))
            with tools.environment_append(local_libs):
                cmake.test()

    def package(self):
        packages = ["api", "core", "monitor", "olink"]
        self.copy("**/*.h", dst="include/testbed1/generated", src="testbed1/generated")
        self.copy("*.h", dst="include/testbed1/implementation", src="testbed1/implementation")
        self.copy("*.lib", dst="lib", keep_path=False)
        self.copy("*.dll", dst="bin", keep_path=False)
        self.copy("*.dylib*", dst="lib", keep_path=False)
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
        self.env_info.path.append(os.path.join(self.package_folder, "bin"))
        self.cpp_info.components["testbed1-api"].includedirs.append(os.path.join(self.package_folder, "include"))
        self.cpp_info.components["testbed1-api"].libs = ["testbed1-api"]
        self.cpp_info.components["testbed1-core"].includedirs.append(os.path.join(self.package_folder, "include"))
        self.cpp_info.components["testbed1-core"].libs = ["testbed1-core"]
        self.cpp_info.components["testbed1-core"].requires = ["testbed1-api", "catch2::catch2", "nlohmann_json::nlohmann_json"]
        self.cpp_info.components["testbed1-implementation"].includedirs.append(os.path.join(self.package_folder, "include"))
        self.cpp_info.components["testbed1-implementation"].libs = ["testbed1-implementation"]
        self.cpp_info.components["testbed1-implementation"].requires = ["testbed1-core", "catch2::catch2", "nlohmann_json::nlohmann_json"]
        self.cpp_info.components["testbed1-monitor"].includedirs.append(os.path.join(self.package_folder, "include"))
        self.cpp_info.components["testbed1-monitor"].libs = ["testbed1-monitor"]
        self.cpp_info.components["testbed1-monitor"].requires = ["testbed1-core", "nlohmann_json::nlohmann_json", "apigear::poco-tracer"]
        self.cpp_info.components["testbed1-olink"].includedirs.append(os.path.join(self.package_folder, "include"))
        self.cpp_info.components["testbed1-olink"].libs = ["testbed1-olink"]
        self.cpp_info.components["testbed1-olink"].requires = ["testbed1-core", "nlohmann_json::nlohmann_json", "apigear::poco-olink"]

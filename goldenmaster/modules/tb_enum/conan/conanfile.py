from conans import ConanFile, CMake, tools
from conan.tools.cmake import cmake_layout
from conan.tools.files import copy
from pathlib import os

class tb_enumConan(ConanFile):
    name = "tb_enum"
    version = "1.0.0"
    license = "GPL v3"
    author = "ApiGear UG"
    #url = "<Package recipe repository url here, for issues about the package>"
    settings = "os", "compiler", "build_type", "arch"
    requires = "catch2/2.13.7", "nlohmann_json/3.9.1", "apigear/3.5.2"
    generators = "cmake_find_package"
    options = {"build_testing": [True, False]}
    default_options = {
        "build_testing": True,
        "apigear:enable_monitor": True,
        "apigear:enable_olink": True,
        "apigear:enable_mqtt": True,
    }

    def layout(self):
        self.folders.root = ".."
        self.folders.source = "tb_enum"
        # cmake_layout(self)

    def export_sources(self):
        # move one level up from the recipe folder
        source_folder = os.path.join(self.recipe_folder, "..")
        # wrap sources into modules name
        dst_folder = os.path.join(self.export_sources_folder, "tb_enum")
        copy(self, "*", source_folder, dst_folder)

    def build(self):
        cmake = CMake(self)
        if not tools.cross_building(self):
            cmake.definitions['BUILD_TESTING'] = self.options.build_testing

        # workaround wrong layout setup if not using "conan create"
        if self.folders.source_folder != self.export_sources_folder:
            # we are building outside of the conan cache
            cmake.configure("..")
        else:
            cmake.configure()

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
        self.copy("**/*.h", dst="include/tb_enum/generated", src="tb_enum/generated")
        self.copy("*.h", dst="include/tb_enum/implementation", src="tb_enum/implementation")
        self.copy("*.lib", dst="lib", keep_path=False)
        self.copy("*.dll", dst="bin", keep_path=False)
        self.copy("*.dylib*", dst="lib", keep_path=False)
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
        self.env_info.path.append(os.path.join(self.package_folder, "bin"))
        self.cpp_info.components["tb_enum-api"].includedirs.append(os.path.join(self.package_folder, "include"))
        self.cpp_info.components["tb_enum-api"].libs = ["tb_enum-api"]
        self.cpp_info.components["tb_enum-core"].includedirs.append(os.path.join(self.package_folder, "include"))
        self.cpp_info.components["tb_enum-core"].libs = ["tb_enum-core"]
        self.cpp_info.components["tb_enum-core"].requires = ["tb_enum-api", "catch2::catch2", "nlohmann_json::nlohmann_json"]
        self.cpp_info.components["tb_enum-implementation"].includedirs.append(os.path.join(self.package_folder, "include"))
        self.cpp_info.components["tb_enum-implementation"].libs = ["tb_enum-implementation"]
        self.cpp_info.components["tb_enum-implementation"].requires = ["tb_enum-core", "catch2::catch2", "nlohmann_json::nlohmann_json"]
        self.cpp_info.components["tb_enum-monitor"].includedirs.append(os.path.join(self.package_folder, "include"))
        self.cpp_info.components["tb_enum-monitor"].libs = ["tb_enum-monitor"]
        self.cpp_info.components["tb_enum-monitor"].requires = ["tb_enum-core", "nlohmann_json::nlohmann_json", "apigear::poco-tracer"]
        self.cpp_info.components["tb_enum-olink"].includedirs.append(os.path.join(self.package_folder, "include"))
        self.cpp_info.components["tb_enum-olink"].libs = ["tb_enum-olink"]
        self.cpp_info.components["tb_enum-olink"].requires = ["tb_enum-core", "nlohmann_json::nlohmann_json", "apigear::poco-olink"]
        self.cpp_info.components["tb_enum-mqtt"].includedirs.append(os.path.join(self.package_folder, "include"))
        self.cpp_info.components["tb_enum-mqtt"].libs = ["tb_enum-mqtt"]
        self.cpp_info.components["tb_enum-mqtt"].requires = ["tb_enum-core", "nlohmann_json::nlohmann_json", "apigear::paho-mqtt"]

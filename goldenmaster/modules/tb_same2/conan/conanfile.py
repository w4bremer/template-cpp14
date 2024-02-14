from conan import ConanFile
from conan.tools.cmake import CMake, CMakeDeps, CMakeToolchain, cmake_layout
from conan.tools.build import check_max_cppstd, check_min_cppstd, cross_building
from conan.tools.files import load, copy
from pathlib import os

class tb_same2Conan(ConanFile):
    name = "tb_same2"
    version = "1.0.0"
    license = "GPL v3"
    author = "ApiGear UG"
    #url = "<Package recipe repository url here, for issues about the package>"
    settings = "os", "compiler", "build_type", "arch"
    requires = "catch2/2.13.7", "nlohmann_json/3.9.1", "apigear/3.5.2"
    options = {"build_testing": [True, False]}
    default_options = {
        "build_testing": True,
        "apigear/*:enable_monitor": True,
        "apigear/*:enable_olink": True,
        "apigear/*:enable_mqtt": True,
    }

    def validate(self):
        check_min_cppstd(self, "14")

    def layout(self):
        cmake_layout(self)
        self.folders.root = ".."
        self.folders.source = "tb_same2"

    def export_sources(self):
        # move one level up from the recipe folder
        source_folder = os.path.join(self.recipe_folder, "..")
        # wrap sources into modules name
        dst_folder = os.path.join(self.export_sources_folder, "tb_same2")
        copy(self, "*", source_folder, dst_folder)

    def source(self):
        cmake_file = load(self, "CMakeLists.txt")

    def generate(self):
        tc = CMakeToolchain(self)
        if not cross_building(self):
            tc.cache_variables['BUILD_TESTING'] = self.options.build_testing
        tc.generate()
        deps = CMakeDeps(self)
        deps.generate()

    def build(self):
        cmake = CMake(self)

        # workaround wrong layout setup if not using "conan create"
        if self.folders.base_source.endswith("tb_same2"):
            print("Building outside of the conan cache")
            # we are building outside of the conan cache
            cmake.configure(build_script_folder="..")
        else:
            cmake.configure()

        cmake.build()
        if not cross_building(self):
            cmake.test()
            # build_type = self.settings.get_safe("build_type", default="Release")
            # # workaround - we need to add the api.dll and the core.dll to the windows PATH to be found for the test
            # local_libs = { "PATH" : []}
            # local_libs["PATH"].append(os.path.sep.join([self.build_folder, "generated", "api", build_type]))
            # local_libs["PATH"].append(os.path.sep.join([self.build_folder, "generated", "core", build_type]))
            # with tools.environment_append(local_libs):
            #     cmake.test()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        # generates a Findtb_same2.cmake file in addition to the tb_same2-config.cmake
        self.cpp_info.set_property("cmake_find_mode", "both")
        self.env_info.path.append(os.path.join(self.package_folder, "bin"))
        self.cpp_info.components["tb_same2-api"].includedirs.append(os.path.join(self.package_folder, "include"))
        self.cpp_info.components["tb_same2-api"].libs = ["tb_same2-api"]
        self.cpp_info.components["tb_same2-core"].includedirs.append(os.path.join(self.package_folder, "include"))
        self.cpp_info.components["tb_same2-core"].libs = ["tb_same2-core"]
        self.cpp_info.components["tb_same2-core"].requires = ["tb_same2-api", "catch2::catch2", "nlohmann_json::nlohmann_json"]
        self.cpp_info.components["tb_same2-implementation"].includedirs.append(os.path.join(self.package_folder, "include"))
        self.cpp_info.components["tb_same2-implementation"].libs = ["tb_same2-implementation"]
        self.cpp_info.components["tb_same2-implementation"].requires = ["tb_same2-core", "catch2::catch2", "nlohmann_json::nlohmann_json"]
        self.cpp_info.components["tb_same2-monitor"].includedirs.append(os.path.join(self.package_folder, "include"))
        self.cpp_info.components["tb_same2-monitor"].libs = ["tb_same2-monitor"]
        self.cpp_info.components["tb_same2-monitor"].requires = ["tb_same2-core", "nlohmann_json::nlohmann_json", "apigear::poco-tracer"]
        self.cpp_info.components["tb_same2-olink"].includedirs.append(os.path.join(self.package_folder, "include"))
        self.cpp_info.components["tb_same2-olink"].libs = ["tb_same2-olink"]
        self.cpp_info.components["tb_same2-olink"].requires = ["tb_same2-core", "nlohmann_json::nlohmann_json", "apigear::poco-olink"]
        self.cpp_info.components["tb_same2-mqtt"].includedirs.append(os.path.join(self.package_folder, "include"))
        self.cpp_info.components["tb_same2-mqtt"].libs = ["tb_same2-mqtt"]
        self.cpp_info.components["tb_same2-mqtt"].requires = ["tb_same2-core", "nlohmann_json::nlohmann_json", "apigear::paho-mqtt"]
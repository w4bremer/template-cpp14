from conan import ConanFile
from conan.tools.cmake import CMake, CMakeDeps, CMakeToolchain, cmake_layout
from conan.tools.build import check_max_cppstd, check_min_cppstd, cross_building
from conan.tools.files import load, copy
from pathlib import os

class tb_enumConan(ConanFile):
    name = "tb_enum"
    version = "1.0.0"
    package_type = "library"
    license = "GPL v3"
    author = "ApiGear UG"
    #url = "<Package recipe repository url here, for issues about the package>"
    settings = "os", "compiler", "build_type", "arch"
    requires = "catch2/2.13.7", "nlohmann_json/3.9.1", "apigear/3.5.2"
    options = {
        "build_testing": [True, False],
        "shared": [True, False],
        "fPIC": [True, False], "enable_fetch_olinkcore": [True, False]
    }
    default_options = {
        "build_testing": True,
        "shared": True,
        "fPIC": False,
        "apigear/*:enable_monitor": True,
        "enable_fetch_olinkcore": True,
        "apigear/*:enable_olink": True,
        "apigear/*:enable_mqtt": True,
    }

    def config_options(self):
        if self.settings.os == "Windows":
            self.options.rm_safe("fPIC")

    def configure(self):
        if self.options.shared:
            self.options.rm_safe("fPIC")

    def validate(self):
        check_min_cppstd(self, "14")

    def layout(self):
        cmake_layout(self)
        self.folders.root = ".."
        self.folders.source = "tb_enum"

    def export_sources(self):
        # move one level up from the recipe folder
        source_folder = os.path.join(self.recipe_folder, "..")
        # wrap sources into modules name
        dst_folder = os.path.join(self.export_sources_folder, "tb_enum")
        copy(self, "*", source_folder, dst_folder)

    def source(self):
        cmake_file = load(self, "CMakeLists.txt")

    def generate(self):
        tc = CMakeToolchain(self)
        tc.cache_variables['TB_ENUM_FETCH_OLINKCORE'] = self.options.enable_fetch_olinkcore
        if not cross_building(self):
            tc.cache_variables['BUILD_TESTING'] = self.options.build_testing
        tc.generate()
        deps = CMakeDeps(self)
        deps.generate()

    def build(self):
        cmake = CMake(self)

        # workaround wrong layout setup if not using "conan create"
        if self.folders.base_source.endswith("tb_enum"):
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
        # generates a Findtb_enum.cmake file in addition to the tb_enum-config.cmake
        self.cpp_info.set_property("cmake_find_mode", "both")
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

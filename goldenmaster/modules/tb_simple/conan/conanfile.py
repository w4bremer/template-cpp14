from conan import ConanFile
from conan.tools.cmake import CMake, CMakeDeps, CMakeToolchain, cmake_layout
from conan.tools.build import check_max_cppstd, check_min_cppstd, cross_building
from conan.tools.files import load, copy
from conan.tools.build import can_run
from pathlib import os

class tb_simpleConan(ConanFile):
    name = "tb_simple"
    version = "1.0.0"
    package_type = "library"
    license = "GPL v3"
    author = "ApiGear UG"
    #url = "<Package recipe repository url here, for issues about the package>"
    settings = "os", "compiler", "build_type", "arch"
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

    def requirements(self):
        self.requires("nlohmann_json/3.9.1", transitive_headers=True)
        
        self.requires("apigear/3.5.2", transitive_headers=True)

    def build_requirements(self):
        self.test_requires("catch2/2.13.7")

    def validate(self):
        check_min_cppstd(self, "14")

    def layout(self):
        cmake_layout(self)
        self.folders.root = ".."
        self.folders.source = "tb_simple"

    def export_sources(self):
        # move one level up from the recipe folder
        source_folder = os.path.join(self.recipe_folder, "..")
        # wrap sources into modules name
        dst_folder = os.path.join(self.export_sources_folder, "tb_simple")
        copy(self, "*", source_folder, dst_folder)

    def source(self):
        cmake_file = load(self, "CMakeLists.txt")

    def generate(self):
        tc = CMakeToolchain(self)
        tc.cache_variables['TB_SIMPLE_FETCH_OLINKCORE'] = self.options.enable_fetch_olinkcore
        if not cross_building(self):
            tc.cache_variables['BUILD_TESTING'] = self.options.build_testing
        tc.generate()
        deps = CMakeDeps(self)
        deps.generate()

    def build(self):
        cmake = CMake(self)

        # workaround wrong layout setup if not using "conan create"
        if self.folders.base_source.endswith("tb_simple"):
            print("Building outside of the conan cache")
            # we are building outside of the conan cache
            cmake.configure(build_script_folder="..")
        else:
            cmake.configure()

        cmake.build()

        # we skip tests on windows since the conanrun env does not include locally built libraries
        if can_run(self) and self.settings.os != "Windows":
            cmake.test()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        # generates a Findtb_simple.cmake file in addition to the tb_simple-config.cmake
        self.cpp_info.set_property("cmake_find_mode", "both")
        self.cpp_info.components["tb_simple-api"].includedirs.append(os.path.join(self.package_folder, "include"))
        self.cpp_info.components["tb_simple-core"].includedirs.append(os.path.join(self.package_folder, "include"))
        self.cpp_info.components["tb_simple-core"].libs = ["tb_simple-core"]
        self.cpp_info.components["tb_simple-core"].requires = ["nlohmann_json::nlohmann_json"]
        self.cpp_info.components["tb_simple-implementation"].includedirs.append(os.path.join(self.package_folder, "include"))
        self.cpp_info.components["tb_simple-implementation"].libs = ["tb_simple-implementation"]
        self.cpp_info.components["tb_simple-implementation"].requires = ["tb_simple-core", "nlohmann_json::nlohmann_json"]
        self.cpp_info.components["tb_simple-monitor"].includedirs.append(os.path.join(self.package_folder, "include"))
        self.cpp_info.components["tb_simple-monitor"].libs = ["tb_simple-monitor"]
        self.cpp_info.components["tb_simple-monitor"].requires = ["tb_simple-core", "nlohmann_json::nlohmann_json", "apigear::poco-tracer"]
        self.cpp_info.components["tb_simple-olink"].includedirs.append(os.path.join(self.package_folder, "include"))
        self.cpp_info.components["tb_simple-olink"].libs = ["tb_simple-olink"]
        self.cpp_info.components["tb_simple-olink"].requires = ["tb_simple-core", "nlohmann_json::nlohmann_json", "apigear::poco-olink"]
        self.cpp_info.components["tb_simple-mqtt"].includedirs.append(os.path.join(self.package_folder, "include"))
        self.cpp_info.components["tb_simple-mqtt"].libs = ["tb_simple-mqtt"]
        self.cpp_info.components["tb_simple-mqtt"].requires = ["tb_simple-core", "nlohmann_json::nlohmann_json", "apigear::paho-mqtt"]

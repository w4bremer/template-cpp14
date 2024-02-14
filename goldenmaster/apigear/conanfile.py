from conan import ConanFile
from conan.tools.cmake import CMake, CMakeDeps, CMakeToolchain, cmake_layout
from conan.tools.build import check_max_cppstd, check_min_cppstd
from conan.tools.files import copy

from pathlib import os

class apigearConan(ConanFile):
    name = "apigear"
    version = "3.5.2"
    license = "Apache-2.0"
    author = "ApiGear UG"
    #url = "<Package recipe repository url here, for issues about the package>"
    settings = "os", "compiler", "build_type", "arch"
    options = {
        "enable_monitor": [True, False],
        "enable_olink": [True, False],
        "enable_mqtt": [True, False],
        "enable_fetch_olinkcore": [True, False],
    }
    default_options = {
                       "enable_monitor": False,
                       "enable_olink": False,
                       "enable_mqtt": False,
                       "enable_fetch_olinkcore": True,
                       "poco/*:shared": False,
                       "poco/*:enable_data_mysql": False,
                       "openssl/*:shared": False,
                       "poco/*:enable_activerecord": False,
                       "poco/*:enable_apacheconnector": False,
                       "poco/*:enable_cppparser": False,
                       "poco/*:enable_crypto": True,
                       "poco/*:enable_data": False,
                       "poco/*:enable_data_odbc": False,
                       "poco/*:enable_data_postgresql": False,
                       "poco/*:enable_data_sqlite": False,
                       "poco/*:enable_encodings": False,
                       "poco/*:enable_json": False,
                       "poco/*:enable_jwt": False,
                       "poco/*:enable_mongodb": False,
                       "poco/*:enable_net": True,
                       "poco/*:enable_netssl": True,
                       "poco/*:enable_pagecompiler": False,
                       "poco/*:enable_pagecompiler_file2page": False,
                       "poco/*:enable_pdf": False,
                       "poco/*:enable_pocodoc": False,
                       "poco/*:enable_redis": False,
                       "poco/*:enable_sevenzip": False,
                       "poco/*:enable_util": True,
                       "poco/*:enable_xml": False,
                       "poco/*:enable_zip": False,
                       "paho-mqtt-c/*:shared": False,
                       "paho-mqtt-c/*:asynchronous": True
                       }

    def export_sources(self):
        copy(self, "*", self.recipe_folder, self.export_sources_folder)

    def requirements(self):
        self.requires("catch2/2.13.7")
        if self.options.enable_monitor or self.options.enable_olink or self.options.enable_mqtt:
              self.requires("nlohmann_json/3.9.1")
        if self.options.enable_monitor or self.options.enable_olink:
              self.requires("poco/1.12.4")
        if self.options.enable_olink:
              self.test_requires("trompeloeil/46")
        if self.options.enable_mqtt:
              self.requires("paho-mqtt-c/1.3.12")

    def validate(self):
        check_min_cppstd(self, "14")

    def layout(self):
        cmake_layout(self)

    def generate(self):
        tc = CMakeToolchain(self)
        tc.cache_variables['APIGEAR_BUILD_WITH_MONITOR'] = self.options.enable_monitor
        tc.cache_variables['APIGEAR_BUILD_WITH_OLINK'] = self.options.enable_olink
        tc.cache_variables['APIGEAR_BUILD_WITH_MQTT'] = self.options.enable_mqtt
        tc.cache_variables['APIGEAR_FETCH_OLINKCORE'] = self.options.enable_olink and self.options.enable_fetch_olinkcore
        tc.generate()
        deps = CMakeDeps(self)
        deps.set_property("poco", "cmake_find_mode", "module", build_context=True)
        deps.generate()

    def configure(self):
        if self.settings.os == "Windows":
            self.options["openssl"].shared = True
            self.options["poco"].shared = False

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def configure(self):
        if self.settings.os == "Windows":
            self.options["openssl"].shared = True
            self.options["poco"].shared = False


    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        # generates a Findapigear.cmake file in addition to the apigear-config.cmake
        self.cpp_info.set_property("cmake_find_mode", "both")
        self.env_info.path.append(os.path.join(self.package_folder, "bin"))
        self.cpp_info.components["utilities"].libs = ["utilities"]
        self.cpp_info.components["utilities"].includedirs.append(os.path.join(self.package_folder, "include"))
        if self.options.enable_monitor:
            self.cpp_info.components["poco-tracer"].libs = ["poco-tracer"]
            self.cpp_info.components["poco-tracer"].includedirs.append(os.path.join(self.package_folder, "include"))
            self.cpp_info.components["poco-tracer"].requires = ["catch2::catch2", "poco::poco", "nlohmann_json::nlohmann_json", "utilities"]
        if self.options.enable_olink:
            self.cpp_info.components["poco-olink"].libs = ["poco-olink"]
            self.cpp_info.components["poco-olink"].includedirs.append(os.path.join(self.package_folder, "include"))
            self.cpp_info.components["poco-olink"].requires = ["poco::poco", "nlohmann_json::nlohmann_json", "utilities"]
        if self.options.enable_mqtt:
            self.cpp_info.components["paho-mqtt"].libs = ["paho-mqtt"]
            self.cpp_info.components["paho-mqtt"].requires = ["paho-mqtt-c::paho-mqtt-c", "nlohmann_json::nlohmann_json", "utilities"]

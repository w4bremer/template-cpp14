from conans import ConanFile, CMake, tools
from pathlib import os

class apigearConan(ConanFile):
    name = "apigear"
    version = "3.5.1"
    license = "Apache-2.0"
    author = "ApiGear UG"
    #url = "<Package recipe repository url here, for issues about the package>"
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake_find_package", "virtualenv"
    options = {
        "enable_monitor": [True, False],
        "enable_olink": [True, False],
        "enable_mqtt": [True, False],
    }
    default_options = {
                       "enable_monitor": False,
                       "enable_olink": False,
                       "enable_mqtt": False,
                       "poco:shared": False,
                       "poco:enable_data_mysql": False,
                       "openssl:shared": False,
                       "poco:enable_activerecord": False,
                       "poco:enable_apacheconnector": False,
                       "poco:enable_cppparser": False,
                       "poco:enable_crypto": True,
                       "poco:enable_data": False,
                       "poco:enable_data_odbc": False,
                       "poco:enable_data_postgresql": False,
                       "poco:enable_data_sqlite": False,
                       "poco:enable_encodings": False,
                       "poco:enable_json": False,
                       "poco:enable_jwt": False,
                       "poco:enable_mongodb": False,
                       "poco:enable_net": True,
                       "poco:enable_netssl": True,
                       "poco:enable_pagecompiler": False,
                       "poco:enable_pagecompiler_file2page": False,
                       "poco:enable_pdf": False,
                       "poco:enable_pocodoc": False,
                       "poco:enable_redis": False,
                       "poco:enable_sevenzip": False,
                       "poco:enable_util": True,
                       "poco:enable_xml": False,
                       "poco:enable_zip": False,
                       "paho-mqtt-c:shared": False,
                       "paho-mqtt-c:asynchronous": True
                       }
    exports_sources = "*"

    def requirements(self):
        self.requires("catch2/2.13.7")
        if self.options.enable_monitor or self.options.enable_olink or self.options.enable_mqtt:
              self.requires("nlohmann_json/3.9.1")
              self.requires("openssl/1.1.1s")
        if self.options.enable_monitor:
              self.requires("poco/1.11.3@#2f5e663a2d744e2d86962bfff2b2345e")
        if self.options.enable_olink:
              self.requires("poco/1.11.3@#2f5e663a2d744e2d86962bfff2b2345e")
        if self.options.enable_mqtt:
              self.requires("paho-mqtt-c/1.3.12")

    def configure(self):
        if self.settings.os == "Windows":
            self.options["openssl"].shared = True
            self.options["poco"].shared = False

    def build(self):
        cmake = CMake(self)
        cmake.definitions['APIGEAR_BUILD_WITH_MONITOR'] = self.options.enable_monitor
        cmake.definitions['APIGEAR_BUILD_WITH_OLINK'] = self.options.enable_olink
        cmake.definitions['APIGEAR_BUILD_WITH_MQTT'] = self.options.enable_mqtt
        cmake.configure(source_folder=".")
        cmake.build()

    def configure(self):
        if self.settings.os == "Windows":
            self.options["openssl"].shared = True
            self.options["poco"].shared = False

    def package(self):
        packages = ["utilities", "tracer", "olink", "mqtt"]
        self.copy("**/*.h", dst="include/apigear", src=".")
        self.copy("*.lib", dst="lib", src=".", keep_path=False)
        self.copy("*.dll", dst="bin", src=".", keep_path=False)
        self.copy("*.dylib*", dst="lib", src=".", keep_path=False)
        self.copy("*.so*", dst="lib", src=".", keep_path=False, symlinks=True)
        self.copy("*.a", dst="lib", src=".", keep_path=False)
        # manually copy objectlink-core-cpp include files, to have headers for module/generated/olink instead of linking whole library
        self.copy(pattern="*.h", dst="include/olink", src="_deps/olink-core-src/src/olink", keep_path=True)

    def package_info(self):
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
            self.cpp_info.components["paho-mqtt"].requires = ["nlohmann_json::nlohmann_json", "utilities"]

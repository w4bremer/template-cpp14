from conans import ConanFile, CMake, tools
from pathlib import os

class apigearConan(ConanFile):
    name = "apigear"
    version = "0.1.0"
    license = "Apache-2.0"
    author = "ApiGear UG"
    #url = "<Package recipe repository url here, for issues about the package>"
    settings = "os", "compiler", "build_type", "arch"
    requires = "catch2/2.13.7", "poco/1.11.1", "nlohmann_json/3.9.1"
    generators = "cmake_find_package", "virtualenv"
    default_options = {"poco:shared": False,
                       "poco:enable_data_mysql": False,
                       "openssl:shared": False,
                       "poco:enable_active_record": False,
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
                       "poco:enable_xml": True,
                       "poco:enable_zip": False
                       }
    exports_sources = "*"

    def configure(self):
        if self.settings.os == "Windows":
            self.options["openssl"].shared = True
            self.options["poco"].shared = False


    def build(self):
        cmake = CMake(self)
        cmake.configure(source_folder=".")
        cmake.build()

    def package(self):
        packages = ["tracer", "olink"]
        self.copy("**/*.h", dst="include/apigear", src=".")
        self.copy("*.lib", dst="lib", keep_path=False)
        self.copy("*.dll", dst="bin", keep_path=False)
        self.copy("*.dylib*", dst="lib", keep_path=False)
        self.copy("*.so*", dst="lib", keep_path=False, symlinks=True)
        self.copy("*.a", dst="lib", keep_path=False)
        # have to manually copy objectlink-core-cpp include files
        self.copy(pattern="*.h", dst="include", src="_deps/objectlink-core-cpp-src/src", keep_path=True)

    def package_info(self):
        self.env_info.path.append(os.path.join(self.package_folder, "bin"))
        self.cpp_info.components["poco-tracer"].libs = ["poco-tracer"]
        self.cpp_info.components["poco-tracer"].requires = ["catch2::catch2", "poco::poco", "nlohmann_json::nlohmann_json"]
        self.cpp_info.components["poco-olink"].libs = ["poco-olink"]
        self.cpp_info.components["poco-olink"].requires = ["poco::poco", "nlohmann_json::nlohmann_json"]

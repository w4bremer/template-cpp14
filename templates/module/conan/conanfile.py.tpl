{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{- $isApiHeaderOnly := and (eq (len .Module.Enums) 0) (eq (len .Module.Structs) 0) -}}
{{- $module_id := snake .Module.Name -}}
{{- $features := .Features -}}
from conan import ConanFile
from conan.tools.cmake import CMake, CMakeDeps, CMakeToolchain, cmake_layout
from conan.tools.build import check_max_cppstd, check_min_cppstd, cross_building
from conan.tools.files import load, copy
from pathlib import os

class {{$module_id}}Conan(ConanFile):
    name = "{{$module_id}}"
    version = "{{.Module.Version}}"
    license = "GPL v3"
    author = "ApiGear UG"
    #url = "<Package recipe repository url here, for issues about the package>"
    settings = "os", "compiler", "build_type", "arch"
    requires = {{ if or $features.stubs $features.core }}"catch2/2.13.7", {{ end }}"nlohmann_json/3.9.1"{{ if $features.apigear }}, "apigear/3.5.2"{{- end}}
    options = {"build_testing": [True, False]
        {{- if $features.olink }}, "enable_fetch_olinkcore": [True, False]{{ end }}}
    default_options = {
        "build_testing": True,
        {{- if $features.monitor }}
        "apigear/*:enable_monitor": True,
        {{- end}}
        {{- if $features.olink }}
        "enable_fetch_olinkcore": True,
        "apigear/*:enable_olink": True,
        {{- end}}
        {{- if $features.mqtt }}
        "apigear/*:enable_mqtt": True,
        {{- end}}
    }

    def validate(self):
        check_min_cppstd(self, "14")

    def layout(self):
        cmake_layout(self)
        self.folders.root = ".."
        self.folders.source = "{{$module_id}}"

    def export_sources(self):
        # move one level up from the recipe folder
        source_folder = os.path.join(self.recipe_folder, "..")
        # wrap sources into modules name
        dst_folder = os.path.join(self.export_sources_folder, "{{$module_id}}")
        copy(self, "*", source_folder, dst_folder)

    def source(self):
        cmake_file = load(self, "CMakeLists.txt")

    def generate(self):
        tc = CMakeToolchain(self)
        {{- if $features.olink }}
        tc.cache_variables['{{upper (snake .Module.Name)}}_FETCH_OLINKCORE'] = self.options.enable_fetch_olinkcore
        {{- end }}
        if not cross_building(self):
            tc.cache_variables['BUILD_TESTING'] = self.options.build_testing
        tc.generate()
        deps = CMakeDeps(self)
        deps.generate()

    def build(self):
        cmake = CMake(self)

        # workaround wrong layout setup if not using "conan create"
        if self.folders.base_source.endswith("{{$module_id}}"):
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
            # {{ if $features.core -}} local_libs["PATH"].append(os.path.sep.join([self.build_folder, "generated", "core", build_type])) {{- end}}
            # with tools.environment_append(local_libs):
            #     cmake.test()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        # generates a Find{{$module_id}}.cmake file in addition to the {{$module_id}}-config.cmake
        self.cpp_info.set_property("cmake_find_mode", "both")
        self.env_info.path.append(os.path.join(self.package_folder, "bin"))
        self.cpp_info.components["{{$module_id}}-api"].includedirs.append(os.path.join(self.package_folder, "include"))
        {{- if (eq $isApiHeaderOnly false) }}
        self.cpp_info.components["{{$module_id}}-api"].libs = ["{{$module_id}}-api"]
        {{- end}}
        {{- if $features.core }}
        self.cpp_info.components["{{$module_id}}-core"].includedirs.append(os.path.join(self.package_folder, "include"))
        self.cpp_info.components["{{$module_id}}-core"].libs = ["{{$module_id}}-core"]
        {{- if (eq $isApiHeaderOnly false) }}
        self.cpp_info.components["{{$module_id}}-core"].requires = ["{{$module_id}}-api", "catch2::catch2", "nlohmann_json::nlohmann_json"]
        {{- else }}
        self.cpp_info.components["{{$module_id}}-core"].requires = ["catch2::catch2", "nlohmann_json::nlohmann_json"]
        {{- end }}
        {{- end}}
        {{- if $features.stubs }}
        self.cpp_info.components["{{$module_id}}-implementation"].includedirs.append(os.path.join(self.package_folder, "include"))
        self.cpp_info.components["{{$module_id}}-implementation"].libs = ["{{$module_id}}-implementation"]
        self.cpp_info.components["{{$module_id}}-implementation"].requires = ["{{$module_id}}-core", "catch2::catch2", "nlohmann_json::nlohmann_json"]
        {{- end}}
        {{- if .Features.monitor }}
        self.cpp_info.components["{{$module_id}}-monitor"].includedirs.append(os.path.join(self.package_folder, "include"))
        self.cpp_info.components["{{$module_id}}-monitor"].libs = ["{{$module_id}}-monitor"]
        self.cpp_info.components["{{$module_id}}-monitor"].requires = ["{{$module_id}}-core", "nlohmann_json::nlohmann_json", "apigear::poco-tracer"]
        {{- end}}
        {{- if $features.olink }}
        self.cpp_info.components["{{$module_id}}-olink"].includedirs.append(os.path.join(self.package_folder, "include"))
        self.cpp_info.components["{{$module_id}}-olink"].libs = ["{{$module_id}}-olink"]
        self.cpp_info.components["{{$module_id}}-olink"].requires = ["{{$module_id}}-core", "nlohmann_json::nlohmann_json", "apigear::poco-olink"]
        {{- end}}
        {{- if $features.mqtt }}
        self.cpp_info.components["{{$module_id}}-mqtt"].includedirs.append(os.path.join(self.package_folder, "include"))
        self.cpp_info.components["{{$module_id}}-mqtt"].libs = ["{{$module_id}}-mqtt"]
        self.cpp_info.components["{{$module_id}}-mqtt"].requires = ["{{$module_id}}-core", "nlohmann_json::nlohmann_json", "apigear::paho-mqtt"]
        {{- end}}

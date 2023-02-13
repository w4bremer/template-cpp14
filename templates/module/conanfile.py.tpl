{{- /* Copyright (c) ApiGear UG 2020 */ -}}
{{- $isApiHeaderOnly := and (eq (len .Module.Enums) 0) (eq (len .Module.Structs) 0) -}}
{{- $module_id := snake .Module.Name -}}
{{- $features := .Features -}}
from conans import ConanFile, CMake, tools
from pathlib import os

class {{$module_id}}Conan(ConanFile):
    name = "{{$module_id}}"
    version = "{{.Module.Version}}"
    license = "GPL v3"
    author = "ApiGear UG"
    #url = "<Package recipe repository url here, for issues about the package>"
    settings = "os", "compiler", "build_type", "arch"
    requires = "catch2/2.13.7", "nlohmann_json/3.9.1"{{ if $features.apigear }}, "apigear/0.1.0"{{- end}}
    generators = "cmake_find_package"
    exports_sources = "*"
    options = {"build_testing": [True, False]}
    default_options = {"build_testing": True}

    def build(self):
        cmake = CMake(self)
        if not tools.cross_building(self):
            cmake.definitions['BUILD_TESTING'] = self.options.build_testing
        cmake.configure(source_folder="./{{$module_id}}")
        cmake.build()
        if not tools.cross_building(self):
            build_type = self.settings.get_safe("build_type", default="Release")
            # workaround - we need to add the api.dll and the core.dll to the windows PATH to be found for the test
            local_libs = { "PATH" : []}
            local_libs["PATH"].append(os.path.sep.join([self.build_folder, "generated", "api", build_type]))
            {{ if $features.core -}} local_libs["PATH"].append(os.path.sep.join([self.build_folder, "generated", "core", build_type])) {{- end}}
            with tools.environment_append(local_libs):
                cmake.test()

    def package(self):
        packages = ["api"
        {{- if $features.core }}, "core"{{ end -}}
        {{- if $features.monitor }}, "monitor"{{ end -}}
        {{- if $features.olink }}, "olink"{{ end -}}
        ]
        self.copy("**/*.h", dst="include/{{$module_id}}/generated", src="{{$module_id}}/generated")
        {{ if $features.stubs -}} self.copy("*.h", dst="include/{{$module_id}}/implementation", src="{{$module_id}}/implementation") {{- end}}
        self.copy("*.lib", dst="lib", keep_path=False)
        self.copy("*.dll", dst="bin", keep_path=False)
        self.copy("*.dylib*", dst="lib", keep_path=False)
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
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

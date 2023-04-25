[requires]
{{- range .System.Modules }}
{{- $module := . }}
{{snake $module.Name}}/{{$module.Version}}
{{- end }}

[generators]
cmake_find_package
CMakeToolchain
virtualenv
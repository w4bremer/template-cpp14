[requires]
apigear/0.1.0
{{- range .System.Modules }}
{{- $module := . }}
{{snake $module.Name}}/{{$module.Version}}
{{- end }}

[generators]
cmake_find_package
CMakeToolchain
virtualenv

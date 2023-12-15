[requires]
{{- range .System.Modules }}
{{- $module := . }}
{{snake $module.Name}}/{{$module.Version}}
{{- end }}
apigear/0.1.0

[generators]
cmake_find_package
CMakeToolchain
virtualenv

[requires]
{{- range .System.Modules }}
{{- $module := . }}
{{snake $module.Name}}/{{$module.Version}}
{{- end }}
apigear/3.5.1

[generators]
cmake_find_package
CMakeToolchain
virtualenv

[requires]
{{- range .System.Modules }}
{{- $module := . }}
{{snake $module.Name}}/{{$module.Version}}
{{- end }}
apigear/3.5.2

[generators]
CMakeDeps
CMakeToolchain
VirtualRunEnv

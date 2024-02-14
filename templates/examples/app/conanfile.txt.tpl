[requires]
{{- range .System.Modules }}
{{- $module := . }}
{{snake $module.Name}}/{{$module.Version}}
{{- end }}
{{- if .Features.monitor }}
apigear/3.5.2
{{- end }}

[generators]
CMakeDeps
CMakeToolchain
VirtualRunEnv

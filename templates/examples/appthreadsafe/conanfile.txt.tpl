[requires]
{{- range .System.Modules }}
{{- $module := . }}
{{snake $module.Name}}/{{$module.Version}}
{{- end }}

[generators]
CMakeDeps
CMakeToolchain
VirtualRunEnv

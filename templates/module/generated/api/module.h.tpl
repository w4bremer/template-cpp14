{{- /* Copyright (c) ApiGear UG 2020 */ -}}
#pragma once

#include "{{snake .Module.Name}}/generated/api/datastructs.api.h"
{{- $module_id := snake .Module.Name -}}
{{- range .Module.Interfaces }}
#include "{{$module_id}}/generated/api/{{lower (camel .Name)}}.api.h"
{{- end -}}
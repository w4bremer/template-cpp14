{{- /* Copyright (c) ApiGear UG 2020 */ -}}
#pragma once

#if defined _WIN32 || defined __CYGWIN__
#ifdef __GNUC__
  #define {{ SNAKE .System.Name }}_{{ SNAKE .Module.Name }}_EXPORT __attribute__ ((dllexport))
#else
  #define {{ SNAKE .System.Name }}_{{ SNAKE .Module.Name }}_EXPORT __declspec(dllexport)
#endif
#else
  #if __GNUC__ >= 4
    #define {{ SNAKE .System.Name }}_{{ SNAKE .Module.Name }}_EXPORT __attribute__ ((visibility ("default")))
  #else
    #define {{ SNAKE .System.Name }}_{{ SNAKE .Module.Name }}_EXPORT
  #endif
#endif

#pragma once

#if defined _WIN32 || defined __CYGWIN__
#ifdef __GNUC__
  #define TEST_TB_SAME1_EXPORT __attribute__ ((dllexport))
#else
  #define TEST_TB_SAME1_EXPORT __declspec(dllexport)
#endif
#else
  #if __GNUC__ >= 4
    #define TEST_TB_SAME1_EXPORT __attribute__ ((visibility ("default")))
  #else
    #define TEST_TB_SAME1_EXPORT
  #endif
#endif

cmake_minimum_required(VERSION 3.14)
project(apigear)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(apigear_COMPONENTS "")

add_subdirectory(tracer)
list(APPEND apigear_COMPONENTS "tracer")

add_subdirectory(olink)
list(APPEND apigear_COMPONENTS "olink")
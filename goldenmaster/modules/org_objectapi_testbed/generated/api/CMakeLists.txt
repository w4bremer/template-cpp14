set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set (SOURCES
    org_objectapi_testbed_datastructs.api.cpp
)
add_library(org_objectapi_testbed-api STATIC ${SOURCES})
add_library(org_objectapi_testbed::api ALIAS org_objectapi_testbed-api)
target_include_directories(org_objectapi_testbed-api PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(org_objectapi_testbed-api PUBLIC Threads::Threads)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(org_objectapi_testbed-api PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(org_objectapi_testbed-api PRIVATE /W4 /WX /wd4251)
endif()

# install binary files
install(TARGETS org_objectapi_testbed-api
        RUNTIME DESTINATION bin                 COMPONENT Runtime
        LIBRARY DESTINATION lib                 COMPONENT Runtime
        ARCHIVE DESTINATION lib/org_objectapi_testbed   COMPONENT Development)
# install includes
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION include FILES_MATCHING PATTERN "*.h")

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(nlohmann_json REQUIRED)

set (SOURCES_CORE_SUPPORT
    org_objectapi_testbed.json.adapter.cpp
    org_objectapi_testbed_interface1.decorator.cpp
    org_objectapi_testbed_interface1.publisher.cpp
    org_objectapi_testbed_interface2.decorator.cpp
    org_objectapi_testbed_interface2.publisher.cpp
)
add_library(org_objectapi_testbed-core STATIC ${SOURCES_CORE_SUPPORT})
add_library(org_objectapi_testbed::core ALIAS org_objectapi_testbed-core)
target_include_directories(org_objectapi_testbed-core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../ ${CMAKE_CURRENT_SOURCE_DIR}/)
target_link_libraries(org_objectapi_testbed-core PUBLIC org_objectapi_testbed::api nlohmann_json::nlohmann_json)
# ensure maximum compiler support
if(NOT MSVC)
  target_compile_options(org_objectapi_testbed-core PRIVATE -Wall -Wextra -Wpedantic -Werror -fvisibility=hidden)
else()
  target_compile_options(org_objectapi_testbed-core PRIVATE /W4 /WX /wd4251)
endif()

install(TARGETS org_objectapi_testbed-core
        RUNTIME DESTINATION bin                 COMPONENT Runtime
        LIBRARY DESTINATION lib                 COMPONENT Runtime
        ARCHIVE DESTINATION lib/org_objectapi_testbed   COMPONENT Development)
# install includes
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION include/org_objectapi_testbed/generated FILES_MATCHING PATTERN "*.h")

include(FetchContent)

FetchContent_Declare(objectlink-core-cpp
    GIT_REPOSITORY https://github.com/apigear-io/objectlink-core-cpp
    GIT_TAG v0.1.3
    GIT_SHALLOW TRUE
    EXCLUDE_FROM_ALL FALSE
)
FetchContent_GetProperties(objectlink-core-cpp)
if(NOT objectlink-core-cpp_POPULATED)
  FetchContent_Populate(objectlink-core-cpp)
  add_subdirectory(${objectlink-core-cpp_SOURCE_DIR} ${objectlink-core-cpp_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

find_package(Poco REQUIRED Foundation Net Util)
# workaround for broken poco conan package
# can hopefully be removed with later verions than 1.11.1
IF (TARGET PCRE::PCRE)
  add_library(Pcre::Pcre ALIAS PCRE::PCRE)
ENDIF()
find_package(nlohmann_json REQUIRED)

set (SOURCES
    olinkhost.cpp
    olinkclient.cpp
)
add_library(apigear-poco-olink SHARED ${SOURCES})
add_library(apigear::poco-olink ALIAS apigear-poco-olink)
target_include_directories(apigear-poco-olink PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${objectlink-core-cpp_SOURCE_DIR}/src)
target_link_libraries(apigear-poco-olink Poco::Net Poco::Util olink_core)

# install binary files
install(TARGETS apigear-poco-olink
        RUNTIME DESTINATION bin           COMPONENT Runtime
        LIBRARY DESTINATION lib           COMPONENT Runtime
        ARCHIVE DESTINATION lib/apigear   COMPONENT Development)
# install includes
FILE(GLOB APIGEAR_INCLUDES *.h)
install(FILES ${APIGEAR_INCLUDES} ${OLINK_INCLUDES}
        DESTINATION include/apigear)
# install olink depedency headers
install(DIRECTORY ${objectlink-core-cpp_SOURCE_DIR}/src/ DESTINATION include/apigear FILES_MATCHING PATTERN "*.h")

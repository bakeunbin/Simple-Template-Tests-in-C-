cmake_minimum_required (VERSION 3.29)
project (simple_template_experiements
	VERSION 1.0.0
	DESCRIPTION "I heard you like programming, so I did programming inside programming."
	HOMEPAGE_URL ""
	LANGUAGES CXX
)

add_executable (test
    src/main/test.cpp
)

set_target_properties (test PROPERTIES
	VERSION ${PROJECT_VERSION}
	CXX_STANDARD 23
	CXX_STANDARD_REQUIRED True
	PUBLIC_HEADER include/big_integer.h
	CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
	CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
	CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

target_include_directories (test PRIVATE include)

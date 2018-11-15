cmake_minimum_required(VERSION 3.0)

# Initial Setup ============================================

set(PROJECT_NAME skeleton_project)
project(${PROJECT_NAME})

set( CMAKE_BUILD_TYPE Debug)
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )

if( "${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    if ("${CMAKE_C_COMPILER_ID}" STREQUAL "Clang")
      # using clang
      set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Weverything")
    elseif ("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
      # using gcc
      set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wall -Wextra")
    elseif ("${CMAKE_C_COMPILER_ID}" STREQUAL "Intel")
      # using intel c compiler
    elseif ("${CMAKE_C_COMPILER_ID}" STREQUAL "MSVC")
      # using visual studio c compiler
    endif()
endif()

set(CMAKE_CXX_STANDARD 14)

# Building the executable ===================================

set(COMMON_INCLUDES include/)
include_directories(${COMMON_INCLUDES})

set(SOURCES 
    src/main.cpp
    src/math/vector.cpp
)

add_executable( ${PROJECT_NAME} ${SOURCES})

# Building the tests ========================================

add_subdirectory(external/googletest)
enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(MATH_TEST_SOURCES 
    src/math/vector.cpp
    test/math_tests/vector_test.cpp
)

add_executable(math_tests ${MATH_TEST_SOURCES})
target_link_libraries(math_tests gtest gtest_main)

add_test(MathTests ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/math_tests)

# Building docs =============================================

if (CMAKE_BUILD_TYPE MATCHES "^[Rr]elease")
	option(BUILD_DOC "Build documentation" ON)
	set(DOXYGEN_SKIP_DOT false)

	find_package(Doxygen)
	if (DOXYGEN_FOUND)

	    set(DOXYGEN_IN docs/Doxyfile.in)
	    set(DOXYGEN_OUT ${CMAKE_BINARY_DIR}/docs/Doxyfile)

	    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

	    add_custom_target( docs ALL
		COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
		WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
		VERBATIM )

	else (DOXYGEN_FOUND)
	  message("Doxygen not installed")
	endif (DOXYGEN_FOUND)
endif()

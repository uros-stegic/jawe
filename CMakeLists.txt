cmake_minimum_required (VERSION 2.8)

# Project bio
project (jawe)
set (jawe_VERSION_MAJOR 1)
set (jawe_VERSION_MINOR 0)
set (TARGET jawe)

# -std=c++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)

# Configuration file
configure_file (
	"${PROJECT_SOURCE_DIR}/config.h.in"
	"${PROJECT_BINARY_DIR}/config.h"
)


# Flex&Bison configuration
find_package (FLEX 2.5.35)
find_package (BISON 2.4.1)

BISON_TARGET(MyParser language/lang.ypp ${CMAKE_CURRENT_BINARY_DIR}/lang.syn.cpp VERBOSE)
FLEX_TARGET(MyScanner language/lang.l ${CMAKE_CURRENT_BINARY_DIR}/lang.lex.cpp)
ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)


# Boost
find_package(Boost COMPONENTS program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})


include_directories ("${CMAKE_CURRENT_SOURCE_DIR}")
include_directories ("${CMAKE_CURRENT_BINARY_DIR}")
include_directories ("${PROJECT_SOURCE_DIR}/include")
include_directories ("${PROJECT_SOURCE_DIR}/include/syntax")
include_directories ("${PROJECT_SOURCE_DIR}/include/syntax/abstract")

file(GLOB_RECURSE SOURCES
	${PROJECT_SOURCE_DIR}/src/*.cpp
)

add_executable(${TARGET}
	${FLEX_MyScanner_OUTPUTS}
	${BISON_MyParser_OUTPUTS}
	${SOURCES}
)

target_link_libraries(${TARGET} ${Boost_LIBRARIES})


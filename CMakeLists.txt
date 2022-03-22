cmake_minimum_required(VERSION 3.1)
project(seash)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -lreadline -lpthread ")

set(CMAKE_BUILD_TYPE Release)

set(SRC ${PROJECT_SOURCE_DIR}/src)

set(EXECUTABLE_OUTPUT_PATH bin)

# find files
file(GLOB_RECURSE source_files 
	${SRC}/*
)


# csh executable
add_executable(
  seash
  ${source_files}
)

install(TARGETS seash DESTINATION bin)

cmake_minimum_required(VERSION 3.19)
project(MyProject)

find_package(PythonInterp REQUIRED)
add_custom_command(
  OUTPUT index.h 
  COMMAND ${PYTHON_EXECUTABLE} ${MyProject_SOURCE_DIR}/A/preparing.py ${MyProject_SOURCE_DIR}
  DEPENDS A/preparing.py
  COMMENT "Generating file from json"
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${MyProject_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${MyProject_SOURCE_DIR}/lib)

add_custom_target(RunGenerator DEPENDS index.h COMMENT "Checking if re-generation is required")

add_executable(MyProject C/main.cpp)

add_dependencies(MyProject RunGenerator)

add_subdirectory(B)
target_link_libraries(MyProject lib)
target_include_directories(MyProject PRIVATE ${PROJECT_SOURCE_DIR} ${PROJECT_BINARY_DIR})

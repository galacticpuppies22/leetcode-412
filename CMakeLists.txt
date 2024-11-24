# cmake_minimum_required(VERSION 3.15...3.25)

# project(MyProject
#   VERSION
#     1.0
#   DESCRIPTION
#     "Very nice project"
#   LANGUAGES
#     C #CXX
# )

# # Specify the C standard 
# set(CMAKE_C_STANDARD 11) 
# set(CMAKE_C_STANDARD_REQUIRED True)

# # Specify the C++ standard 
# # set(CMAKE_CXX_STANDARD 11) 
# # set(CMAKE_CXX_STANDARD_REQUIRED True)

# if(CMAKE_BUILD_TYPE STREQUAL "Debug") 
#   add_definitions(-DDEBUG)
#   set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g")
# endif()

# include_directories(${CMAKE_SOURCE_DIR}/incl)

# add_executable(myexample src/main.c src/problem.c)




cmake_minimum_required(VERSION 3.15)

project(MyProject
  VERSION 1.0
  DESCRIPTION "Very nice project"
  LANGUAGES C
)

# Specify the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/incl)

# Add the executable target
add_executable(myexample src/main.c src/problem.c)

# Add the DEBUG definition and set the -g flag for Debug builds
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(myexample PRIVATE DEBUG)
    target_compile_options(myexample PRIVATE -g)
endif()

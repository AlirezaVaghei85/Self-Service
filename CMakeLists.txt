cmake_minimum_required(VERSION 4.1.0)

project(Hashing_Password)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories("include")

find_library(bcrypt_lib
NAMES bcrypt
PATHS "${CMAKE_SOURCE_DIR}"
NO_DEFAULT_PATH)

add_executable(${PROJECT_NAME} "Self-Service.cpp")

target_link_libraries(${PROJECT_NAME} PRIVATE ${bcrypt_lib})
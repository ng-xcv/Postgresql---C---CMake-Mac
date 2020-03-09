cmake_minimum_required(VERSION 3.15)
project(connect)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")


add_executable(connect main.cpp)

# Inclut le dossier contenant libpqxx
include_directories("/usr/local/Cellar/libpqxx/6.4.5_5/include/")

# Inclure la librairie
target_link_libraries(connect /usr/local/Cellar/libpqxx/6.4.5_5/lib/libpqxx-6.4.dylib)

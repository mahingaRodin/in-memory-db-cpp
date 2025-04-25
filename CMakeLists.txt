cmake_minimum_required(VERSION 3.31)
project(inmem_db)

set(CMAKE_CXX_STANDARD 20)

add_executable(inmem_db
        main.cpp
        Database.cpp
        Table.cpp
)

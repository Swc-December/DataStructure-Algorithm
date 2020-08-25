cmake_minimum_required(VERSION 3.17)

set(PROJECT_NAME DataStructure-Algorithm)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)

include_directories(
        DataStructure
        Algorithm/Fundament)

aux_source_directory(DataStructure DIR_DS)

aux_source_directory(Algorithm/Fundament DIR_AL_FUND)


add_executable(${PROJECT_NAME}
        ${DIR_DS}
        ${DIR_AL_FUND}
        main.cpp)
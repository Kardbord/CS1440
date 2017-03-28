cmake_minimum_required(VERSION 3.6)
project(GenericDictionary)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Dictionary.cpp Dictionary.h
        KeyValue.cpp KeyValue.h)
add_executable(GenericDictionary main.cpp ${SOURCE_FILES})

set(TEST_FILES
        )
add_executable(Test Testing/testMain.cpp ${TEST_FILES} ${SOURCE_FILES})
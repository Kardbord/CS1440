cmake_minimum_required(VERSION 3.6)
project(GenericDictionary)

set(CMAKE_CXX_STANDARD 11)

set(INPUT_FILES
        countrynames.txt)

set(SOURCE_FILES
        Dictionary.h
        KeyValue.h)
add_executable(GenericDictionary main.cpp ${INPUT_FILES} ${SOURCE_FILES})

set(TEST_FILES
        Testing/DictionaryTester.cpp Testing/DictionaryTester.h Testing/KeyValueTester.cpp Testing/KeyValueTester.h)
add_executable(Test Testing/testMain.cpp ${TEST_FILES} ${SOURCE_FILES})
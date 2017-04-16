cmake_minimum_required(VERSION 3.7)
project(SOLID_Principles)

set(CMAKE_CXX_STANDARD 11)

set(TEST_FILES
        Testing/ConfigurationTester.cpp Testing/ConfigurationTester.h
        Testing/DenialOfServiceAnalyzerTester.cpp Testing/DenialOfServiceAnalyzerTester.h
        Testing/PortScanAnalyserTester.cpp Testing/PortScanAnalyserTester.h
        Testing/ResultSetTester.cpp Testing/ResultSetTester.h)

set(SOURCE_FILES Analyzer.cpp Analyzer.h
        DenialOfServiceAnalyzer.cpp DenialOfServiceAnalyzer.h
        PortScanAnalyzer.cpp PortScanAnalyzer.h
        Configuration.cpp Configuration.h
        ResultSet.cpp ResultSet.h)

add_executable(Test Testing/testMain.cpp ${TEST_FILES} ${SOURCE_FILES})
add_executable(SOLID_Principles main.cpp ${SOURCE_FILES})
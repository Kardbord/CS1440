cmake_minimum_required(VERSION 3.6)
project(Bingo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
            UserInterface.cpp UserInterface.h
            Deck.cpp Deck.h
            MenuOption.cpp MenuOption.h
            Menu.cpp Menu.h)

add_executable(Bingo main.cpp ${SOURCE_FILES})

set(TEST_FILES
        Testing/MenuTester.cpp Testing/MenuTester.h
        Testing/MenuOptionTester.cpp Testing/MenuOptionTester.h)

add_executable(Test Testing/testMain.cpp ${SOURCE_FILES} ${TEST_FILES})


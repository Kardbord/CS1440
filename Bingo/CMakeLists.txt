cmake_minimum_required(VERSION 3.6)
project(Bingo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        UserInterface.cpp UserInterface.h
        Deck.cpp Deck.h
        MenuOption.cpp MenuOption.h
        Menu.cpp Menu.h
        Card.cpp Card.h
        CardCell.cpp CardCell.h)

add_executable(Bingo main.cpp ${SOURCE_FILES})

set(TEST_FILES
        Testing/MenuTester.cpp Testing/MenuTester.h
        Testing/MenuOptionTester.cpp Testing/MenuOptionTester.h
        Testing/DeckTester.cpp Testing/DeckTester.h
        Testing/CardTester.cpp Testing/CardTester.h
        Testing/CardCellTester.cpp Testing/CardCellTester.h)

add_executable(Test Testing/testMain.cpp ${SOURCE_FILES} ${TEST_FILES})


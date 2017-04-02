cmake_minimum_required(VERSION 3.6)
project(AnalystComparer)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Utils.cpp Utils.h PurchaseSaleRecord.cpp PurchaseSaleRecord.h Analyst.cpp Analyst.h
        History.cpp History.h Comparer.cpp Comparer.h FormattedTable/ColumnDefinition.cpp FormattedTable/ColumnDefinition.h
        FormattedTable/FormattedCell.cpp FormattedTable/FormattedCell.h FormattedTable/FormattedRow.cpp FormattedTable/FormattedRow.h
        FormattedTable/FormattedTable.cpp FormattedTable/FormattedTable.h)
add_executable(AnalystComparer ${SOURCE_FILES})
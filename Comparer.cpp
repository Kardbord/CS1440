//
// Base code created by Stephen Clyde on 1/16/17.
// Modified by Tanner Kvarfordt 1/28/17
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Comparer.h"
#include <algorithm>
#include "./FormattedTable/FormattedTable.h"

// Creates Analysts and their histories, etc. from the command line arguments
int Comparer::load(int argv, char *argc[]) {
    if (argv < 3) {
        std::cout << "Invalid parameters" << std::endl;
        std::cout << "usage: AnalystComparer <output file> <input file 1> <input file 2> ..." << std::endl;
        return -1;
    }

    _outputFilename = argc[1];
    _analystCount = argv - 2;

    int analystIndex = 0;
    for (int i = 0; i < _analystCount; i++) {
        std::ifstream inputStream(argc[2 + analystIndex]);
        if (!inputStream) std::cout << "Failed to load " << argc[analystIndex] << std::endl;
        else {
            _analysts.push_back(Analyst(inputStream));
            ++analystIndex;
        }
    }

    loadSymbols();

    int result = 0;
    if (analystIndex < _analystCount)
        result = -1;

    return result;
}

int Comparer::compare() const {
    if (_analystCount < 2) {
        std::cout << "Cannot do comparison with " << _analystCount << " analysts" << std::endl;
        return -1;
    }

    if (_outputFilename == "") {
        std::cout << "Cannot do comparison because no output file is specified" << std::endl;
        return -1;
    }

    std::ofstream outputStream(_outputFilename);
    outputStream << "Analyst Comparison\n"
                 << "==================\n\n";
    outputInvestorNames(outputStream);
    outputOverallPerformance(outputStream);
    outputStockPerformance(outputStream);

    return 0;
}

// Stores the stock symbol of every company that an Analyst invested in
void Comparer::loadSymbols() {
    _symbolCount = 0;
    for (auto &&a: _analysts) {
        History history = a.getHistory();
        const std::vector<PurchaseSaleRecord> records = history.getRecords();
        for (auto &&r : records) {
            std::string symbol = r.getCompany();
            if (std::find(std::begin(_symbols), std::end(_symbols), symbol) == std::end(_symbols)) {
                _symbols.push_back(symbol);
            }
        }

    }
}


void Comparer::outputInvestorNames(std::ofstream &outputStream) const {
    outputStream << "Investors:\n";
    for (auto &&a : _analysts) {
        outputStream << "     ";
        outputStream << a.getName() << std::endl;
    }
    outputStream << std::endl << std::endl;
}

void Comparer::outputOverallPerformance(std::ofstream &outputStream) const {
    FormattedTable table(_analystCount, 5);

    table.addColumn(new ColumnDefinition("Analyst", 9, ColumnDefinition::String, ColumnDefinition::Center));
    table.addColumn(new ColumnDefinition("Days", 8, ColumnDefinition::Integer, ColumnDefinition::Right));
    table.addColumn(new ColumnDefinition("Seed Amount ($)", 18, ColumnDefinition::Money, ColumnDefinition::Right, 2));
    table.addColumn(new ColumnDefinition("TPL ($)", 13, ColumnDefinition::Money, ColumnDefinition::Right, 2));
    table.addColumn(new ColumnDefinition("PLPD ($)", 13, ColumnDefinition::Money, ColumnDefinition::Right, 2));

    for (auto &&a : _analysts){
        FormattedRow *row = new FormattedRow(&table);
        row->addCell(new FormattedCell(a.getInitials()));
        row->addCell(new FormattedCell(a.getHistory().getSimDays()));
        row->addCell(new FormattedCell(a.getHistory().getSeedMoney()));
        row->addCell(new FormattedCell(a.getHistory().computeTotalProfitLoss()));
        row->addCell(new FormattedCell(a.getHistory().computeProfitLossPerDay()));
        table.addRow(row);
    }

    table.write(outputStream);
};

void Comparer::outputStockPerformance(std::ofstream &outputStream) const {
    // TODO: Write out Stock Performance table.  The classes from the FormattedTable example might be helpful.
}

#include "Table.hpp"
#include <iostream>
#include <fstream>

// Constructor
Table::Table(const std::string& tableName, const std::vector<std::string>& columnNames)
    : name(tableName), columns(columnNames), rows() {}

// Insert a row into the table
void Table::insertRow(const std::vector<std::string>& rowData) {
    if (rowData.size() != columns.size()) {
        std::cerr << "Row size mismatch!\n";
        return;
    }
    rows.push_back(rowData);
}

// Print the entire table
void Table::printTable() const {
    for (const auto& col : columns)
        std::cout << col << "\t";
    std::cout << "\n";

    for (const auto& row : rows) {
        for (const auto& value : row)
            std::cout << value << "\t";
        std::cout << "\n";
    }
}

const std::string& Table::getName() const {
    return name;
}

// Select and print rows that match a condition
void Table::selectWhere(int columnIndex, const std::string& op, const std::string& value) const {
    if (columnIndex < 0 || columnIndex >= static_cast<int>(columns.size())) {
        std::cerr << "Invalid column index\n";
        return;
    }

    std::cout << "Results:\n";
    for (const auto& col : columns)
        std::cout << col << "\t";
    std::cout << "\n";

    for (const auto& row : rows) {
        if (op == "==" && row[columnIndex] == value) {
            for (const auto& val : row)
                std::cout << val << "\t";
            std::cout << "\n";
        }
        // You can expand this with more operators (>, <, etc.) if needed.
    }
}


void Table::saveToFile(const std::string &fileName) const {
std::ofstream file(fileName);
    if (!file.is_open()) {
        std::cerr<<"Failed to open the file: "<<fileName<<"\n";
        return;
    }

    //write column headers
    for (size_t i = 0; i < columns.size(); ++i) {
        file<< columns[i] ;
        if (i<columns.size() - 1)file<<",";
    }
    file<<"\n";

    // Write each row
    for (const auto& row : rows) {
        for (size_t i = 0; i < row.size(); ++i) {
            file << row[i];
            if (i < row.size() - 1) file << ",";
        }
        file << "\n";
    }

    file.close();
    std::cout << "Table \"" << name << "\" saved to " << fileName << "\n";
}


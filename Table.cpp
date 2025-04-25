#include "Table.hpp"
#include <iostream>

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

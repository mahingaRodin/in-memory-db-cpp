#ifndef TABLE_HPP
#define TABLE_HPP

#include <string>
#include <vector>
#include <iostream>

class Table {
private:
    std::string name;
    std::vector<std::string> columns;
    std::vector<std::vector<std::string>> rows;

    public:
    Table(const std::string& tableName, const std::vector<std::string>& columnNames);

    void insertRow(const std::vector<std::string>& rowData);
    void printTable() const;
    void selectWhere(int columnIndex, const std::string& op, const std::string& value) const;
    const std::string& getName() const;
    void saveToFile(const std::string& fileName) const;
};
#endif
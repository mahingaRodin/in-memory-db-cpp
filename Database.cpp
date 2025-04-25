#include "Database.hpp"
#include <iostream>

Database::Database(const std::string &dbName) : name(dbName) {
}

void Database::createTable(const std::string &tableName, const std::vector<std::string> &columnNames) {
    if (tables.find(tableName) != tables.end()) {
        std::cerr << "Table \"" << tableName << "\" already exists. \n" << std::endl;
        return;
    }
    tables.emplace(tableName, Table(tableName, columnNames));
    std::cout<<"Table \""<<tableName<<"\" create successfully. \n";
}

std::shared_ptr<Table> Database::getTable(const std::string &tableName) {
    auto it = tables.find(tableName);
    if (it != tables.end()) {
        return std::shared_ptr<Table>(&it->second);
    } else {
        std::cerr << "Table \"" << tableName << "\" not found.\n";
        return nullptr;
    }
}

void Database::listTables() const {
    if (tables.empty()) {
        std::cout << "No tables in the database.\n";
        return;
    }

    std::cout << "Tables in database \"" << name << "\":\n";
    for (const auto& pair : tables) {
        std::cout << "- " << pair.first << "\n";
    }
}




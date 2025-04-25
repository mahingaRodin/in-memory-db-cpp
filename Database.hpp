#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <memory>
#include <string>
#include <unordered_map>
#include "Table.hpp"

class Database {
private:
    std::string name;
    std::unordered_map<std::string, Table> tables;

public:
    Database(const std::string& dbName);

    void createTable(const std::string& tableName, const std::vector<std::string>& columns);
    std::shared_ptr<Table> getTable(const std::string& tableName);
    void listTables() const;
    void saveAllTables() const;
};
#endif

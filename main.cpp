#include "Database.hpp"

int main() {
    Database db("MyInMemoryDB");

    db.createTable("students", {"id", "name", "age"});

    Table* studentsTable = db.getTable("students").get();
    if (studentsTable) {
        studentsTable->insertRow({"1", "Rodin", "16"});
        studentsTable->insertRow({"2", "Pazzo", "18"});
        studentsTable->insertRow({"3", "Calvin", "17"});

        std::cout << "\n--- Students Table ---\n";
        studentsTable->printTable();
    }

    db.listTables();

    return 0;
}

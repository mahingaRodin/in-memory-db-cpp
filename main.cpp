#include "Database.hpp"

int main() {
    Database db("MyInMemoryDB");

    db.createTable("students", {"id", "name", "age"});

    Table* students = db.getTable("students").get();
    if (students) {
        students->insertRow({"1", "Rodin", "18"});
        students->insertRow({"2", "Leandre", "19"});
        students->printTable();
        students->selectWhere(1, "==", "Leandre");
    }

    db.listTables();

    return 0;
}

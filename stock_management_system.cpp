#include <iostream>
#include <sqlite3.h>

struct InventoryItem {
    int id;
    std::string name;
    int quantity;
};

sqlite3* db;
const char* dbFile = "inventory.db";

int initializeDatabase() {
    return sqlite3_open(dbFile, &db);
}

int closeDatabase() {
    return sqlite3_close(db);
}

void displayInventory() {
}

int main() {
    int rc = initializeDatabase();
    if (rc) {
        std::cerr << "Unable to open the database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }

    bool exitProgram = false;
    while (!exitProgram) {
        std::cout << "Menu:\n"
                  << "1. Add item to inventory\n"
                  << "2. Remove item from inventory\n"
                  << "3. Modify item in inventory\n"
                  << "4. Display inventory\n"
                  << "5. Exit\n"
                  << "Enter your choice: ";

        int userChoice;
        std::cin >> userChoice;

        switch (userChoice) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                displayInventory();
                break;
            case 5:
                exitProgram = true;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    closeDatabase();
    return 0;
}

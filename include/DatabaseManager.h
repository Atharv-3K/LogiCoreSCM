#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <string>
#include <memory>
#include <pqxx/pqxx>
#include "Product.h" // This include is correct

class DatabaseManager {
private:
    std::unique_ptr<pqxx::connection> C;
    std::string connection_string;

public:
    DatabaseManager(const std::string& dbname, const std::string& user, const std::string& password, const std::string& host, const std::string& port);

    bool connect();
    bool isConnected();

    // ADD THIS LINE - This is the missing declaration
    bool saveProduct(const Product& product);
};

#endif //DATABASEMANAGER_H
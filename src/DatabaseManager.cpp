#include "DatabaseManager.h"
#include <iostream>
#include "ElectronicProduct.h" // We need this for dynamic_cast

// --- ORIGINAL FUNCTIONS ---

// Constructor initializes the connection string
DatabaseManager::DatabaseManager(const std::string& dbname, const std::string& user, const std::string& password, const std::string& host, const std::string& port) {
    connection_string = "dbname=" + dbname + " user=" + user + " password=" + password + " hostaddr=" + host + " port=" + port;
}

bool DatabaseManager::connect() {
    try {
        C = std::make_unique<pqxx::connection>(connection_string);
        if (C->is_open()) {
            std::cout << "Successfully connected to database: " << C->dbname() << std::endl;
            return true;
        } else {
            std::cerr << "Failed to open database." << std::endl;
            return false;
        }
    } catch (const std::exception &e) {
        std::cerr << "Connection failed: " << e.what() << std::endl;
        return false;
    }
}

bool DatabaseManager::isConnected() {
    return (C && C->is_open());
}

// --- NEW FUNCTION ---

bool DatabaseManager::saveProduct(const Product& product) {
    if (!isConnected()) {
        std::cerr << "Cannot save product, not connected to database." << std::endl;
        return false;
    }
    
    try {
        // A "work" is a transaction. It's the safe way to execute queries.
        pqxx::work W(*C);
        
        // Check if the product is an ElectronicProduct using dynamic_cast
        const ElectronicProduct* elecProduct = dynamic_cast<const ElectronicProduct*>(&product);
        
        std::string sql;
        if (elecProduct) {
            // It's an ElectronicProduct! Include the warranty.
            sql = "INSERT INTO Products (name, description, price, product_type, warranty_period_months) VALUES (" +
                  W.quote(elecProduct->getName()) + ", " +
                  W.quote(elecProduct->getDescription()) + ", " +
                  std::to_string(elecProduct->getPrice()) + ", " + // Use std::to_string for numeric types
                  "'Electronic', " +
                  std::to_string(elecProduct->getWarrantyPeriod()) + ");";
        } else {
            // It's just a generic Product. Insert NULL for the warranty.
            sql = "INSERT INTO Products (name, description, price, product_type, warranty_period_months) VALUES (" +
                  W.quote(product.getName()) + ", " +
                  W.quote(product.getDescription()) + ", " +
                  std::to_string(product.getPrice()) + ", " + // Use std::to_string for numeric types
                  "'Generic', " +
                  "NULL);";
        }
        
        W.exec(sql);
        W.commit(); // Commit the transaction
        
        std::cout << "Successfully saved product: " << product.getName() << std::endl;
        return true;
        
    } catch (const std::exception &e) {
        std::cerr << "Failed to save product. SQL Error: " << e.what() << std::endl;
        return false;
    }
}
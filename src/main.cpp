#include <iostream>
#include <vector>
#include <memory>
#include "DatabaseManager.h"
#include "Product.h"
#include "ElectronicProduct.h"

int main() {
    std::cout << "--- Project Veritas SCM Starting ---" << std::endl;

    // --- Database Connection ---
    DatabaseManager dbManager("aura_scm_db", "postgres", "@thk0312", "127.0.0.1", "5432");
    if (!dbManager.connect()) {
        std::cerr << "Fatal: Could not connect to the database." << std::endl;
        return 1;
    }

    // --- Create Product Objects ---
    Product keyboard(101, "Standard Keyboard", "A reliable wired keyboard.", 25.99);
    ElectronicProduct mouse(202, "Gaming Mouse", "A high-DPI wireless gaming mouse.", 75.50, 24);

    // --- Save Products to Database ---
    std::cout << "\n--- Saving products to database ---" << std::endl;
    dbManager.saveProduct(keyboard);
    dbManager.saveProduct(mouse);

    std::cout << "\n--- Program finished ---" << std::endl;
    return 0;
}
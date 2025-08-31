#include "ElectronicProduct.h"
#include <iostream>

// The constructor first calls the base class (Product) constructor to initialize the common members
ElectronicProduct::ElectronicProduct(int id, const std::string& name, const std::string& desc, double price, int warranty)
    : Product(id, name, desc, price), warrantyPeriod(warranty) {}

// We override the display function to add our new information
void ElectronicProduct::display() const {
    Product::display(); // Call the base class's display function first
    std::cout << "Warranty:     " << warrantyPeriod << " months" << std::endl;
}

int ElectronicProduct::getWarrantyPeriod() const {
    return warrantyPeriod;
}
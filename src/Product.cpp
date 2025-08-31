#include "Product.h"
#include <iostream>
#include <iomanip>

Product::Product(int id, const std::string& name, const std::string& desc, double price)
    : productID(id), name(name), description(desc), price(price) {}

void Product::display() const {
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Product ID:   " << productID << std::endl;
    std::cout << "Name:         " << name << std::endl;
    std::cout << "Description:  " << description << std::endl;
    std::cout << "Price:        $" << std::fixed << std::setprecision(2) << price << std::endl;
}

int Product::getID() const {
    return productID;
}

std::string Product::getName() const {
    return name;
}

// ADD THESE FUNCTIONS TO THE END OF THE FILE
std::string Product::getDescription() const {
    return description;
}

double Product::getPrice() const {
    return price;
}
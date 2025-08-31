#ifndef ELECTRONICPRODUCT_H
#define ELECTRONICPRODUCT_H

#include "Product.h" // Include the base class header

class ElectronicProduct : public Product { // The ':' signifies inheritance
private:
    int warrantyPeriod; // in months

public:
    // Constructor that also calls the base class constructor
    ElectronicProduct(int id, const std::string& name, const std::string& desc, double price, int warranty);

    // Override the base class's display function
    void display() const override;
    int getWarrantyPeriod() const;
};

#endif //ELECTRONICPRODUCT_H
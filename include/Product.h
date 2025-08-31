#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
protected: // 'protected' is like 'private', but allows child classes to access these members
    int productID;
    std::string name;
    std::string description;
    double price;

public:
    // Constructor
    Product(int id, const std::string& name, const std::string& desc, double price);

    // Virtual destructor: essential for base classes in a hierarchy
    virtual ~Product() = default;

    // A virtual function that child classes can override
    virtual void display() const;

    // Getter methods
    int getID() const;
    std::string getName() const;
    std::string getDescription() const;
    double getPrice() const;
};

#endif //PRODUCT_H
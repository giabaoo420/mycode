/*Write a simple C++ program to help manage an online shopping platform as below:
The application needs to allow managing each shop by name and list of current selling products.
For each product, its name and unit price must be recorded.
For each customer account, we need to record name and list of orders. The information of each
order must include order id (counting up from 1), list of bought products, and the total expense.
When buying products, customers with normal accounts don’t get any discount, however, gold
membership accounts will get a discount rate of 5% for all products.
Implement classes with suitable attributes and methods to satisfy the above requirements. Test them
in main() with appropriate output messages.
Note: Assume that each customer only purchases one unit of each product, and the shops always
have the products listed in their selling list to serve the orders.*/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Product {
    public:
    string name;
    double unitPrice;

    Product(string name, double unitPrice) {
        this->name = name;
        this->unitPrice = unitPrice;
    }
};

class Order {
    public:
    static int orderCount;
    int orderId;
    vector<Product> products;
    double totalExpense;

    Order() {
        orderId = ++orderCount;
        totalExpense = 0.0;
    }

    void addProduct(const Product& product) {
       products.push_back(product);
       totalExpense += product.unitPrice;
    }

    void printOrder() {
        cout << "Order Id: " << orderId << "\nProducts:\n";
        for (const auto& product : products) {
            cout << "- " << product.name << " ($" << product.unitPrice << ")\n";
        }
        cout << "total Expenese: &" << fixed << setprecision(2) << totalExpense << "\n";
    }
};

int Order::orderCount = 0;

class Customer {
    public:
    string name;
    vector<Order> orders;
    bool isGoldMember;

    Customer(string name, bool goldMember) {
        this->name = name;
        isGoldMember = goldMember;
    }

    void placeOrder (const vector<Product>& products) {
        Order newOrder;
        for (const auto& product : products) {
            newOrder.addProduct(product);
        }
        if (isGoldMember) {
            newOrder.totalExpense *= 0.95;
        }

        orders.push_back(newOrder);
        cout << name << " placed an order.\n";
        newOrder.printOrder();
    }

    void returnProduct(int orderId) {
        for (auto& order : orders) {
            if (order.orderId == orderId) {
                cout << "Returning order ID: " << orderId << "\n";
                order.totalExpense = 0;

                order.products.clear();
                cout << "Order returned successfully.\n";
                return;
            }
        }
        cout << "order ID not found.\n";
    }
};

class Shop {
    public:
    string name;
    vector<Product> products;

    Shop(string name) {
        this->name = name;
    }

    void addProduct (const Product& product) {
        products.push_back(product);
    }

    void printProducts() {
        cout << "Products available in " << name << ":\n";
        for (const auto& product : products) {
           std::cout << "- " << product.name << " ($" << product.unitPrice << ")\n";
        }
    }
};

int main() {
    Shop myShop("Best Shop");
    myShop.addProduct(Product("Apple", 1.00));
    myShop.addProduct(Product("Banana", 0.50));
    myShop.addProduct(Product("Orange", 0.75));

    myShop.printProducts();

    Customer normalCustomer("Alice", false);
    Customer goldCustomer("Bob", true);


    normalCustomer.placeOrder({myShop.products[0], myShop.products[1]});
    goldCustomer.placeOrder({myShop.products[1], myShop.products[2]});

    goldCustomer.returnProduct(1);
    
    return 0;

}
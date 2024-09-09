/* Write a C++ program to help manage a retail shop as below:
The shop has a name and a list of selling products. Each product is characterized by a name, a
price, and its stock quantity. The shop has a function to create value and print out the bill for each
customer with given list of bought products including their purchasing quantities (the bill when
printing out should include these information).
The shop manages each customer with a name, the last bill, and their earning points from a
loyalty program. The customers earn points based on their spending (gets 1 point per 1$
purchase), which can be redeemed in future purchases (redeems 10 points for $1). Customers
should have the option to return a product from the last purchase.
The shop can generate a sale report which prints out its total revenue, the best-selling product,
and revenue of each product.
Implement classes with suitable attributes and methods to satisfy the above requirement. Test
them in main() with appropriate output messages.*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <unordered_map>

using namespace std;

class Product {
public:
    string name;
    double price;
    int stock;

    Product(string name, double price, int stock) {
        this->name = name;
        this->price = price;
        this->stock = stock;
    }
};

class Customer {
public:
    string name;
    double lastBill;
    int loyaltyPoints;

    Customer(string name) {
        this->name = name;
        this->lastBill = 0;
        this->loyaltyPoints = 0;
    }

    void earnPoints(double amount) {
        loyaltyPoints += static_cast<int>(amount);
    }

    void redeemPoints(double& amount) {
        if (loyaltyPoints >= 10) {
            int pointsToRedeem = loyaltyPoints / 10;
            amount -= pointsToRedeem;
            loyaltyPoints -= pointsToRedeem * 10;
        }
    }
};

class Shop {
private:
    string name;
    vector<Product> products;
    unordered_map<string, double> productRevenue;
    double totalRevenue;

public:
    Shop(string name) {
        this->name = name;
        totalRevenue = 0;
    }

    void addProduct(const string& productName, double price, int stock) {
        products.emplace_back(productName, price, stock);
        productRevenue[productName] = 0;
    }

    void printBill(Customer& customer, const vector<pair<string, int>>& purchasedProducts) {
        double totalAmount = 0;
        cout << "\nBill for " << customer.name << ":\n";
        cout << fixed << setprecision(2);
        cout << "-----------------------------------\n";
        cout << "Product\t\tQuantity\tPrice\n";
        cout << "-----------------------------------\n";

        for (const auto& item : purchasedProducts) {
            const string& productName = item.first;
            int quantity = item.second;

            for (auto& product : products) {
                if (product.name == productName) {
                    if (product.stock >= quantity) {
                        double amount = product.price * quantity;
                        totalAmount += amount;
                        productRevenue[productName] += amount;

                        product.stock -= quantity;
                        cout << product.name << "\t\t" << quantity << "\t\t" << amount << "\n";
                    } else {
                        cout << "Not enough stock for " << product.name << ". Available: " << product.stock << "\n";
                    }
                    break;
                }
            }
        }

        customer.lastBill = totalAmount;
        customer.earnPoints(totalAmount);
        totalRevenue += totalAmount;

        cout << "-----------------------------------\n";
        cout << "Total Amount: $" << totalAmount << "\n";
        cout << "Loyalty Points Earned: " << static_cast<int>(totalAmount) << "\n";
        cout << "-----------------------------------\n";
    }

    void returnProduct(Customer& customer, const string& productName, int quantity) {
        for (auto& product : products) {
            if (product.name == productName) {
                double refundAmount = (product.price * quantity);
                product.stock += quantity;
                totalRevenue -= refundAmount;
                customer.lastBill -= refundAmount;
                customer.loyaltyPoints -= static_cast<int>(refundAmount);

                cout << "Returned " << quantity << " of " << productName << ". Refund Amount: $" << refundAmount << "\n";
                return;
            }
        }

        cout << "Product not found.\n";
    }

    void generateSalesReport() {
        cout << "\nSales Report:\n";
        cout << "Total Revenue: $" << totalRevenue << "\n";
        string bestSellingProduct;
        double maxRevenue = 0;

        for (const auto& pair : productRevenue) {
            cout << "Product: " << pair.first << ", Revenue: $" << pair.second << "\n";
            if (pair.second > maxRevenue) {
                maxRevenue = pair.second;
                bestSellingProduct = pair.first;
            }
        }

        cout << "Best Selling Product: " << bestSellingProduct << " with Revenue: $" << maxRevenue << "\n";
    }
};

int main() {
    Shop shop("My Retail Shop");

    // Adding products to the shop
    shop.addProduct("Apple", 0.50, 100);
    shop.addProduct("Banana", 0.30, 150);
    shop.addProduct("Orange", 0.80, 80);
    shop.addProduct("Milk", 1.20, 50);
    shop.addProduct("Bread", 1.00, 60);

    // Creating a customer
    Customer customer("John Doe");

    // Purchase products
    vector<pair<string, int>> purchasedProducts = {{"Apple", 5}, {"Banana", 10}, {"Milk", 2}};
    shop.printBill(customer, purchasedProducts);

    // Return a product
    shop.returnProduct(customer, "Banana", 5);

    // Generate sales report
    shop.generateSalesReport();

    return 0;
}
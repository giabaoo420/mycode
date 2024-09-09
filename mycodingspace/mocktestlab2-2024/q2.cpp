/*Question 2 (10 pts)
Use linked list concepts to record real estate transactions (selling and buying a house) as below.
• David: bought the house for $800
• David --> John : price = $1000
• John --> Peter : price = $1200
• Peter --> Luna : price = $1800
• Luna --> Sophia: price = $3500
Hint: Define a class, e.g. namely Broker, with attributes are name, buyPrice and nextBuyer.
a) Write a function to print out all transactions exactly as above.
b) Write a function to print out information of the broker with the lowest profit excluding the last
broker who has not sold the house (note: profit = sellPrice - buyPrice).*/

#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Broker {
   public:
   string name;
   double buyPrice;
   Broker* nextBuyer;

   Broker(string name, int buyPrice) {
       this->name = name;
       this->buyPrice = buyPrice;
       nextBuyer = nullptr;
   }

   void setNext(Broker* next) {
       nextBuyer = next;
   }
};

void printTransactions(Broker* startBroker) {
    cout << startBroker->name << "; initially bought the house for $" << startBroker->buyPrice << endl;
    Broker* current = startBroker;

    while (current->nextBuyer != nullptr) {
        Broker* nextBroker = current->nextBuyer;
        cout << current->name << " --> " << nextBroker->name << ": price = $" << nextBroker->buyPrice << endl;
        current = nextBroker;
    }
}

void findlowestProfitBroker(Broker* startBroker) {
    Broker* current = startBroker;
    double lowestProfit = numeric_limits<double>::max();
    Broker* lowestBroker = nullptr;

   while (current->nextBuyer != nullptr) {
       Broker* nextBroker = current->nextBuyer;
       double profit = nextBroker->buyPrice - current->buyPrice;

       if (profit <lowestProfit) {
        lowestProfit = profit;
        lowestBroker = current;
       }
       current = nextBroker;
   }

   if (lowestBroker) {
    cout << "the broker with the lowest profit (excluding the last broker) is " << lowestBroker->name << " with a profit of $" << lowestProfit << endl;
   }
}

int main() {
    Broker* david = new Broker("David", 800);
    Broker* john = new Broker("John", 1000);
    Broker* peter = new Broker("Peter", 1200);
    Broker* luna = new Broker("Luna", 1800);
    Broker* sophia = new Broker("Sophia", 3500);

    // Link the brokers to create the transaction chain
    david->setNext(john);
    john->setNext(peter);
    peter->setNext(luna);
    luna->setNext(sophia);

    // Print all transactions
    printTransactions(david);

    // Find and print the broker with the lowest profit
    findlowestProfitBroker(david);

    // Clean up memory
    delete david;
    delete john;
    delete peter;
    delete luna;
    delete sophia;

    return 0;

}


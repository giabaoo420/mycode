/*Question 2 (12 pts)
A traveller would like to plan for her trip with list of visiting cities in order as below
• Hue: 5 days
• Da Nang: 3 days
• Nha Trang: 4 days
• Da Lat: 2 days
• Can Tho: 3 day
a) Use linked list concepts to record that trip plan. Write a function to print out the trip plan
exactly as above. Hint: Define a class, e.g. namely City, with attributes are name,
stayingDays and *nextCity.
b) Write a function which allows the user to update the trip plan by inputting the City’s name
and the new staying days. If the city's staying days is set to 0, remove that city from the trip
plan. Print out how many days that the traveller will stay from that City to the end of the trip.
Example Run:
Enter the City’s name: Nha Trang
Update the number of staying days: 5
> Updated. There will be a total of 10 days staying in this and next
cities in the trip.
Enter the City’s name: Da Lat
Update the number of staying days: 0
> Removed from the trip plan. There will be a total of 3 days staying in
the next cities in the trip.
Test all the functions in main() with appropriate output messages. */

#include <iostream>
#include <string>

using namespace std;

// Define the City class
class City {
public:
    string name;
    int stayingDays;
    City* nextCity;

    City(string name, int stayingDays) {
        this->name = name;
        this->stayingDays = stayingDays;
        nextCity = nullptr;
    }
};

// Function to print the trip plan
void printTripPlan(City* start) {
    City* current = start;
    while (current != nullptr) {
        cout << current->name << ": " << current->stayingDays << " days" << endl;
        current = current->nextCity;
    }
}

// Function to calculate total remaining days in the trip
int calculateRemainingDays(City* start) {
    int remainingDays = 0;
    City* current = start;
    while (current != nullptr) {
        remainingDays += current->stayingDays;
        current = current->nextCity;
    }
    return remainingDays;
}

// Function to update the trip plan
void updateTripPlan(City** start) {
    string cityName;
    int newStayingDays;

    cout << "Enter the City's name: ";
    getline(cin, cityName);

    cout << "Update the number of staying days: ";
    cin >> newStayingDays;
    cin.ignore(); // Ignore the newline character after the integer input

    City* current = *start;
    City* prev = nullptr;

    while (current != nullptr) {
        if (current->name == cityName) {
            if (newStayingDays == 0) {
                // Remove the city from the trip plan
                if (prev == nullptr) {
                    *start = current->nextCity; // Update head if it's the first city
                } else {
                    prev->nextCity = current->nextCity; // Bypass the current city
                }
                delete current; // Free memory

                cout << "> Removed from the trip plan. ";
            } else {
                current->stayingDays = newStayingDays; // Update staying days
                cout << "> Updated. ";
            }

            // Calculate the remaining days
            int remainingDays = calculateRemainingDays(current);
            cout << "There will be a total of " << remainingDays << " days staying in this and next cities in the trip." << endl;
            return;
        }
        prev = current; // Move to the next city
        current = current->nextCity;
    }
    cout << "City not found in the trip plan." << endl;
}

int main() {
    // Create the trip plan
    City* start = new City("Hue", 5);
    start->nextCity = new City("Da Nang", 3);
    start->nextCity->nextCity = new City("Nha Trang", 4);
    start->nextCity->nextCity->nextCity = new City("Da Lat", 2);
    start->nextCity->nextCity->nextCity->nextCity = new City("Can Tho", 3);

    // Print the initial trip plan
    cout << "Initial Trip Plan:" << endl;
    printTripPlan(start);

    // Update the trip plan - example 1
    updateTripPlan(&start);

    // Print the updated trip plan
    cout << "\nUpdated Trip Plan:" << endl;
    printTripPlan(start);

    // Update the trip plan - example 2
    updateTripPlan(&start);

    // Print the updated trip plan
    cout << "\nUpdated Trip Plan:" << endl;
    printTripPlan(start);

    // Clean up memory
    City* current = start;
    while (current != nullptr) {
        City* temp = current;
        current = current->nextCity;
        delete temp;
    }

    return 0;
}
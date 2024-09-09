/*Write a program to model the Facebook social network, in which each Facebooker is managed
by his/her name, and connections with their friends. Each Facebooker can have up to 5000
friends.
The program should provide following functionalities:
• View (print out to screen) all friends’ names of a given Facebooker.
• View all friends’ names of friends of a given Facebooker.
• View all mutual friends of two given Facebookers*/

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Facebooker {
private:
    string name;
    unordered_set<Facebooker*> friends;

public:
    // Constructor
    Facebooker(const string& name) : name(name) {}

    // Add a friend
    void addFriend(Facebooker* friendFacebooker) {
        if (friends.size() < 5000) {
            friends.insert(friendFacebooker);
            friendFacebooker->friends.insert(this);
        } else {
            cout << "Friend limit reached for " << name << endl;
        }
    }

    // Print all friends
    void printFriends() const {
        cout << name << "'s friends: ";
        for (const auto& friendFacebooker : friends) {
            cout << friendFacebooker->name << " ";
        }
        cout << endl;
    }

    // Print all friends of friends
    void printFriendsOfFriends() const {
        unordered_set<Facebooker*> friendsOfFriends;
        for (const auto& friendFacebooker : friends) {
            for (const auto& fof : friendFacebooker->friends) {
                if (fof != this && friends.find(fof) == friends.end()) {
                    friendsOfFriends.insert(fof);
                }
            }
        }
        cout << name << "'s friends of friends: ";
        for (const auto& fof : friendsOfFriends) {
            cout << fof->name << " ";
        }
        cout << endl;
    }

    // Print mutual friends with another Facebooker
    void printMutualFriends(const Facebooker& other) const {
        unordered_set<Facebooker*> mutualFriends;
        for (const auto& friendFacebooker : friends) {
            if (other.friends.find(friendFacebooker) != other.friends.end()) {
                mutualFriends.insert(friendFacebooker);
            }
        }
        cout << "Mutual friends of " << name << " and " << other.name << ": ";
        for (const auto& mutualFriend : mutualFriends) {
            cout << mutualFriend->name << " ";
        }
        cout << endl;
    }

    // Get the name of the Facebooker
    string getName() const {
        return name;
    }
};

int main() {
    // Create Facebookers
    Facebooker alice("Alice");
    Facebooker bob("Bob");
    Facebooker charlie("Charlie");
    Facebooker dave("Dave");
    Facebooker eve("Eve");

    // Set up friendships
    alice.addFriend(&bob);
    alice.addFriend(&charlie);
    bob.addFriend(&charlie);
    bob.addFriend(&dave);
    charlie.addFriend(&dave);
    charlie.addFriend(&eve);
    dave.addFriend(&eve);

    // Print Alice's friends
    alice.printFriends();

    // Print friends of Alice's friends
    alice.printFriendsOfFriends();

    // Print mutual friends between Alice and Bob
    alice.printMutualFriends(bob);

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

int f = -1, r = -1, n = 5;

class Pizza {
public:
    string name, add;
    int q;  // Quantity of pizza order
};

class PizzaQueue {
public:
    Pizza queue[100];  // Array to store pizza orders
    void acceptOrder();
    void serveOrder();
    void displayOrder();
};

void PizzaQueue::acceptOrder() {
    // Check if queue is full
    if ((r + 1) % n == f) {
        cout << "Orders are full. Please wait for a while." << endl;
    } else if (f == -1 && r == -1) {
        // First order case
        f = r = 0;
        cout << "Enter your name: ";
        cin >> queue[r].name;
        cout << "Enter your address: ";
        cin >> queue[r].add;
        cout << "Enter your quantity of order: ";
        cin >> queue[r].q;
    } else {
        // General case for adding order
        r = (r + 1) % n;
        cout << "Enter your name: ";
        cin >> queue[r].name;
        cout << "Enter your address: ";
        cin >> queue[r].add;
        cout << "Enter your quantity of order: ";
        cin >> queue[r].q;
    }
}

void PizzaQueue::serveOrder() {
    if (f == -1 && r == -1) {
        cout << "No orders to serve." << endl;
    } else if (f == r) {
        // Only one order to serve
        cout << "Serving order from: " << queue[f].name << endl;
        f = r = -1;  // Reset the queue after last order is served
    } else {
        // Serving order and updating front
        cout << "Serving order from: " << queue[f].name << endl;
        f = (f + 1) % n;
    }
}

void PizzaQueue::displayOrder() {
    if (f == -1) {
        cout << "No orders to display." << endl;
        return;
    }
    cout << "Current Orders:" << endl;
    int i = f;
    while (i != r) {
        cout << "Name: " << queue[i].name << ", Address: " << queue[i].add << ", Quantity: " << queue[i].q << endl;
        i = (i + 1) % n;
    }
    cout << "Name: " << queue[r].name << ", Address: " << queue[r].add << ", Quantity: " << queue[r].q << endl;
}

int main() {
    PizzaQueue pq;
    int choice;

    do {
        cout << "\n1. Accept Order\n2. Serve Order\n3. Display Orders\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                pq.acceptOrder();
                break;
            case 2:
                pq.serveOrder();
                break;
            case 3:
                pq.displayOrder();
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

#include <iostream>
#include <cstring>

using namespace std;

// Structure to hold customer information
struct Customer {
    char name[50];
    char phoneNumber[15];
    float usage;
    float totalBill;
};

Customer customers[100]; // Array to store customer data
int customerCount = 0; // Variable to keep track of the number of customers

// Function to clear the input buffer
void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Function to add a new customer record
void addRecord() {
    if (customerCount < 100) {
        cout << "\nEnter name: ";
        clearInputBuffer(); // Clear the input buffer before reading a new line
        cin.getline(customers[customerCount].name, sizeof(customers[customerCount].name));

        cout << "Enter phone number: ";
        cin >> customers[customerCount].phoneNumber;

        cout << "Enter usage (in minutes): ";
        cin >> customers[customerCount].usage;

        customers[customerCount].totalBill = customers[customerCount].usage * 0.1;
        customerCount++;
        cout << "\nRecord added successfully!\n";
    } else {
        cout << "\nMaximum number of records reached!\n";
    }
}

// Function to view the list of customer records
void viewRecords() {
    cout << "\nName\tPhone Number\tUsage(min)\tTotal Bill($)\n";
    for (int i = 0; i < customerCount; i++) {
        cout << customers[i].name << "\t" 
             << customers[i].phoneNumber << "\t" 
             << customers[i].usage << "\t\t" 
             << customers[i].totalBill << "\n";
    }
}

// Function to modify a customer record
void modifyRecord(const char phoneNumber[]) {
    for (int i = 0; i < customerCount; i++) {
        if (strcmp(customers[i].phoneNumber, phoneNumber) == 0) {
            cout << "\nEnter new usage (in minutes) for " << customers[i].name << ": ";
            cin >> customers[i].usage;
            customers[i].totalBill = customers[i].usage * 0.1;
            cout << "\nRecord modified successfully!\n";
            return;
        }
    }
    cout << "\nRecord not found!\n";
}

// Function to view payment for a customer
void viewPayment(const char phoneNumber[]) {
    for (int i = 0; i < customerCount; i++) {
        if (strcmp(customers[i].phoneNumber, phoneNumber) == 0) {
            cout << "\nTotal Bill for " << customers[i].name << ": $" << customers[i].totalBill << "\n";
            return;
        }
    }
    cout << "\nRecord not found!\n";
}

// Function to search for a customer record
void searchRecord(const char phoneNumber[]) {
    cout << "\nName\tPhone Number\tUsage(min)\tTotal Bill($)\n";
    for (int i = 0; i < customerCount; i++) {
        if (strcmp(customers[i].phoneNumber, phoneNumber) == 0) {
            cout << customers[i].name << "\t" 
                 << customers[i].phoneNumber << "\t" 
                 << customers[i].usage << "\t\t" 
                 << customers[i].totalBill << "\n";
            return;
        }
    }
    cout << "\nRecord not found!\n";
}

// Function to delete a customer record
void deleteRecord(const char phoneNumber[]) {
    for (int i = 0; i < customerCount; i++) {
        if (strcmp(customers[i].phoneNumber, phoneNumber) == 0) {
            for (int j = i; j < customerCount - 1; j++) {
                customers[j] = customers[j + 1];
            }
            customerCount--;
            cout << "\nRecord deleted successfully!\n";
            return;
        }
    }
    cout << "\nRecord not found!\n";
}

// Function to display menu options
void displayMenu() {
    cout << "\n1. Add New Record\n";
    cout << "2. View List of Records\n";
    cout << "3. Modify Record\n";
    cout << "4. View Payment\n";
    cout << "5. Search Record\n";
    cout << "6. Delete Record\n";
    cout << "7. Exit\n";
}

int main() {
    int choice;
    char phoneNumber[15];

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addRecord();
            break;
        case 2:
            viewRecords();
            break;
        case 3:
            cout << "\nEnter phone number to modify record: ";
            cin >> phoneNumber;
            modifyRecord(phoneNumber);
            break;
        case 4:
            cout << "\nEnter phone number to view payment: ";
            cin >> phoneNumber;
            viewPayment(phoneNumber);
            break;
        case 5:
            cout << "\nEnter phone number to search record: ";
            cin >> phoneNumber;
            searchRecord(phoneNumber);
            break;
        case 6:
            cout << "\nEnter phone number to delete record: ";
            cin >> phoneNumber;
            deleteRecord(phoneNumber);
            break;
        case 7:
            return 0;
        default:
            cout << "\nInvalid choice! Please try again.\n";
        }
    }

    return 0;
}

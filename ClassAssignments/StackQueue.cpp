#include <iostream>
#include <cstring>
using namespace std;

const int MAX_CONTACTS = 100;

// Contact structure definition
struct Contact {
    char FirstName[50];
    char LastName[50];
    char PhoneNumber[15];
    char EmailAddress[100];
};

// Array-based stack to store contacts
Contact contactStack[MAX_CONTACTS];
int top = -1;

// Function to push (add) a new contact to the stack
void pushContact(Contact newContact) {
    if (top < MAX_CONTACTS - 1) {
        top++;
        contactStack[top] = newContact;
        cout << "Contact Added" << endl;
    }else{
        cout << "Max Contacts reached" << endl;
    }
}

// Function to pop (remove) the most recently added contact from the stack
void popContact() {
    if (top >= 0) {
        cout << contactStack[top].FirstName << " " << contactStack[top].LastName << " Removed." << endl;
        top--;
    }else{
        cout << "No Contact to Remove" << endl;
    }
}

// Function to display all contacts in the stack
void displayContacts() {
    if(top >= 0){
        for (int i = top; i >= top; i--) {
            cout << "Contact " << i << ": " << endl;
            cout << "First Name: " << contactStack[i].FirstName << endl;
            cout << "Last Name: " << contactStack[i].LastName << endl;
            cout << "Phone Number: " << contactStack[i].PhoneNumber << endl;
            cout << "Email Address: " << contactStack[i].EmailAddress << endl;
        }
    }else{
        cout << "No Contacts to Print" << endl;
    }
        
    }
// Function to search for a contact by name (First Name or Last Name)
void searchContactByName(const char* name) {
    bool found = false;
    cout << "Search Results:" << endl;
    for (int i = top; i >= 0; i--) {
        if (strcmp(contactStack[i].FirstName, name) == 0 ||
        strcmp(contactStack[i].LastName, name) == 0) {
            cout << "-----------------------------" << endl;
            cout << "First Name: " << contactStack[i].FirstName << endl;
            cout << "Last Name: " << contactStack[i].LastName << endl;
            cout << "Phone Number: " << contactStack[i].PhoneNumber << endl;
            cout << "Email Address: " << contactStack[i].EmailAddress << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No matching contacts found." << endl;
    }
}

int main() {
    int choice;
    do {
    cout << "\nContact Management System Menu" << endl;
    cout << "1. Add Contact" << endl;
    cout << "2. Display Contacts" << endl;
    cout << "3. Search Contact by Name" << endl;
    cout << "4. Delete Contact" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            Contact newContact;
            cin.ignore();
            cout << "Enter First Name: ";
            cin.getline(newContact.FirstName, 50);
            cout << "Enter Last Name: ";
            cin.getline(newContact.LastName, 50);
            cout << "Enter Phone Number: ";
            cin.getline(newContact.PhoneNumber, 15);
            cout << "Enter Email Address: ";
            cin.getline(newContact.EmailAddress, 100);
            pushContact(newContact);
            break;
        }
        case 2:
            displayContacts();
            break;
        case 3: {
            cin.ignore();
            cout << "Enter Name to Search: ";
            char searchName[50];
            cin.getline(searchName, 50);
            searchContactByName(searchName);
            break;
        }
        case 4:
            popContact();
            break;
        case 5:
            cout << "Exiting the program." << endl;
            break;
            default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

struct Contact {
    string name;
    string phone;
    string note;
};

void addContact(Contact contacts[], int* count) {
    if (*count >= 100) {
        cout << "Error: Phonebook is full!" << endl;
        return;
    }

    cout << "--- Add Contact ---" << endl;

    cout << "Enter name: ";
    getline(cin, contacts[*count].name);

    cout << "Enter phone: ";
    getline(cin, contacts[*count].phone);

    cout << "Enter note (e.g., Work/Home): ";
    getline(cin, contacts[*count].note);

    (*count)++;
    cout << "Contact added successfully!" << endl;
}

void showContacts(Contact contacts[], int count) {
    if (count == 0) {
        cout << "Phonebook is empty." << endl;
        return;
    }

    cout << "--- Contact List (" << count << ") ---" << endl;
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << contacts[i].name
            << " | Phone: " << contacts[i].phone
            << " | " << contacts[i].note << endl;
    }
}

Contact* findContactByName(Contact contacts[], int count, string searchName) {
    for (int i = 0; i < count; i++) {
        if (contacts[i].name == searchName) {
            return &contacts[i];
        }
    }
    return nullptr;
}

int main() {
    Contact phonebook[100];
    int currentCount = 0;
    int choice;

    while (true) {
        cout << "=== PHONEBOOK MENU ===" << endl;
        cout << "1. Show all contacts" << endl;
        cout << "2. Add contact" << endl;
        cout << "3. Find and edit contact" << endl;
        cout << "0. Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;
        cin.ignore();
        if (choice == 0) {
            cout << "Exiting..." << endl;
            break;
        }
        else if (choice == 1) {
            showContacts(phonebook, currentCount);
        }
        else if (choice == 2) {
            addContact(phonebook, &currentCount);
        }
        else if (choice == 3) {
            cout << "Enter name to search: ";
            string name;
            getline(cin, name);
            Contact* foundContact = findContactByName(phonebook, currentCount, name);
            if (foundContact != nullptr) {
                cout << "Contact found!" << endl;
                cout << "Name: " << foundContact->name << endl;
                cout << "Phone: " << foundContact->phone << endl;
                cout << "Do you want to edit the number? (1 - Yes, 0 - No): ";
                int editChoice;
                cin >> editChoice;
                cin.ignore();
                if (editChoice == 1) {
                    cout << "Enter new number: ";
                    getline(cin, foundContact->phone);
                    cout << "Number updated." << endl;
                }
            }
            else {
                cout << "Contact with name '" << name << "' not found." << endl;
            }
        }
        else {
            cout << "Invalid input." << endl;
        }
    }

    return 0;
}
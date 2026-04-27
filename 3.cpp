#include <iostream>
#include <fstream>
using namespace std;

class WorkshopRegistration {
private:
    ofstream file;

public:
    void openFile() {
        file.open("signup.txt", ios::app); // append mode
        if (!file) {
            cout << "Error opening file.\n";
        }
    }

    void registerUsers() {
        string name, email, choice;

        do {
            cout << "Enter name: ";
            getline(cin, name);

            cout << "Enter email: ";
            getline(cin, email);

            file << "Name: " << name << ", Email: " << email << endl;

            cout << "Add another user? (yes/no): ";
            getline(cin, choice);

        } while (choice == "yes" || choice == "YES");

    }

    void closeFile() {
        file.close();
        cout << "Registrations saved successfully.\n";
    }
};

int main() {
    WorkshopRegistration wr;
    wr.openFile();
    wr.registerUsers();
    wr.closeFile();
    return 0;
}

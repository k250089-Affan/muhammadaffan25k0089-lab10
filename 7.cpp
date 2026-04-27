#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    char name[50];
    int id;
    float gpa;
};

class StudentRecord {
private:
    Student s;

public:
    void writeToFile() {
        ofstream file("students.dat", ios::binary | ios::app);

        if (!file) {
            cout << "Error opening file for writing!" << endl;
            return;
        }

        cout << "Enter Student Name: ";
        cin.ignore();
        cin.getline(s.name, 50);

        cout << "Enter Student ID: ";
        cin >> s.id;

        cout << "Enter Student GPA: ";
        cin >> s.gpa;

        file.write((char*)&s, sizeof(s));
        file.close();

        cout << "Record saved successfully.\n";
    }

    void readFromFile() {
        ifstream file("students.dat", ios::binary);

        if (!file) {
            cout << "Error opening file for reading!" << endl;
            return;
        }

        cout << "\nStored Student Records:\n";
        cout << "------------------------\n";

        while (file.read((char*)&s, sizeof(s))) {
            cout << "Name: " << s.name << endl;
            cout << "ID: " << s.id << endl;
            cout << "GPA: " << s.gpa << endl;
           }

        file.close();
    }
};

int main() {
    StudentRecord obj;
    int n;

    cout << "How many students do you want to enter? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for student " << i + 1 << ":\n";
        obj.writeToFile();
    }

    obj.readFromFile();

    return 0;
}

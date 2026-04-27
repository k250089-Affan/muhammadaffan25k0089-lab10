#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BackupLogger {
private:
    string filename;

public:
    BackupLogger(string fname) {
        filename = fname;
    }

    void addLog() {
        ofstream file(filename, ios::app);
        if (!file) {
            cout << "Error opening file!" << endl;
            return;
        }

        string message;
        char choice;

        do {
            cout << "Enter log message: ";
            cin.ignore();
            getline(cin, message);

            file << message << endl;

            cout << "Current file size: " << file.tellp() << " bytes" << endl;

            cout << "Add another log? (y/n): ";
            cin >> choice;

        } while (choice == 'y' || choice == 'Y');

        file.close();
    }
};

int main() {
    BackupLogger logger("backup_log.txt");
    logger.addLog();
    return 0;
}

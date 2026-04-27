#include <iostream>
#include <fstream>
using namespace std;

class Diary {
private:
    ofstream file;

public:
    void openFile() {
        file.open("diary.txt", ios::app); // append mode
        if (!file) {
            cout << "Error opening file.\n";
        }
    }

    void writeEntry() {
        string line;
        cout << "Start writing your diary (type 'exit' to finish):\n";

        while (true) {
            getline(cin, line);
            if (line == "exit")
                break;

            file << line << endl;
        }
    }

    void closeFile() {
        file.close();
        cout << "Diary saved successfully.\n";
    }
};

int main() {
    Diary d;
    d.openFile();
    d.writeEntry();
    d.closeFile();
    return 0;
}

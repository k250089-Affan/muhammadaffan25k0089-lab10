#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class SpellChecker {
private:
    fstream file;
    string word;

public:
    void openFile() {
        file.open("draft.txt", ios::in | ios::out);

        if (!file) {
            cout << "Error: Could not open draft.txt" << endl;
            return;
        }
    }

    void correctTypo() {
        char ch;
        string buffer = "";
        streampos pos;

        while (file.get(ch)) {
            buffer += ch;

            if (buffer.length() > 3)
                buffer.erase(0, 1);

            if (buffer == "teh") {

                pos = file.tellg();
                file.seekp(pos - 3);

                file.write("the", 3);

                cout << "First typo corrected successfully.\n";
                return;
            }
        }

        cout << "No typo found.\n";
    }

    void closeFile() {
        file.close();
    }
};

int main() {
    SpellChecker checker;

    checker.openFile();
    checker.correctTypo();
    checker.closeFile();

    return 0;
}

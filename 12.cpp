#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileDebugger {
private:
    string filename;

public:
    FileDebugger(string fname) {
        filename = fname;
    }

    void inspect() {
        ifstream file(filename);

        if (!file) {
            cout << "Error opening file!" << endl;
            return;
        }

        int offset;
        cout << "Enter byte offset: ";
        cin >> offset;

        cout << "Pointer before seek: " << file.tellg() << endl;

        file.seekg(offset, ios::beg);

        cout << "Pointer after seek: " << file.tellg() << endl;

        char buffer[101];
        file.read(buffer, 100);
        buffer[file.gcount()] = '\0';

        cout << "\nNext 100 characters:\n";
        cout << buffer << endl;

        file.close();
    }
};

int main() {
    FileDebugger debugger("article.txt");
    debugger.inspect();
    return 0;
}

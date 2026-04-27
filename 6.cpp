#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

class SignalScanner {
public:
    void countUppercase() {
        ifstream file("secret.txt");

        if (!file) {
            cout << "Error opening file.\n";
            return;
        }

        char ch;
        int count = 0;

        while (file.get(ch)) {
            if (isupper(ch)) {
                count++;
            }
        }

        file.close();

        cout << "Number of uppercase signals: " << count << endl;
    }
};

int main() {
    SignalScanner scanner;
    scanner.countUppercase();
    return 0;
}

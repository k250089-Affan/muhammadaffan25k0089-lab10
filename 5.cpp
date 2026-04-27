#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class VocabularyApp {
public:
    void displayWords() {
        ifstream file("story.txt");

        if (!file) {
            cout << "Error opening file.\n";
            return;
        }

        string line;
        
        // Read file line by line
        while (getline(file, line)) {
            istringstream iss(line);
            string word;

            // Extract words one by one
            while (iss >> word) {
                cout << word << endl;
            }
        }

        file.close();
    }
};

int main() {
    VocabularyApp app;
    app.displayWords();
    return 0;
}

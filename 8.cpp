#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BlogReader {
private:
    ifstream file;
    string line;

public:
    void openFile() {
        file.open("article.txt", ios::in);

        if (!file) {
            cout << "Error: Could not open article.txt" << endl;
            return;
        }
    }

    void previewMiddle() {
        file.seekg(0, ios::end);
        streampos fileSize = file.tellg();

        streampos middle = fileSize / 2;

        file.seekg(middle, ios::beg);

        getline(file, line);

        cout << "Preview from middle of the article:\n";

        for (int i = 0; i < 10 && getline(file, line); i++) {
            cout << line << endl;
        }
    }

    void closeFile() {
        file.close();
    }
};

int main() {
    BlogReader reader;

    reader.openFile();
    reader.previewMiddle();
    reader.closeFile();

    return 0;
}

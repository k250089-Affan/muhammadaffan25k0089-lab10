#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

class FileAnalyzer {
private:
    string inputFile, outputFile;

public:
    FileAnalyzer(string in, string out) {
        inputFile = in;
        outputFile = out;
    }

    void analyze() {
        ifstream file(inputFile);
        ofstream report(outputFile);

        if (!file || !report) {
            cout << "Error opening files!" << endl;
            return;
        }

        int characters = 0, words = 0, lines = 0, punctuation = 0;
        string line;

        while (getline(file, line)) {
            lines++;
            characters += line.length();

            for (char ch : line) {
                if (ispunct(ch))
                    punctuation++;
            }

            bool inWord = false;
            for (char ch : line) {
                if (isspace(ch)) {
                    inWord = false;
                } else if (!inWord) {
                    words++;
                    inWord = true;
                }
            }
        }
      
        report << "Total Characters: " << characters << endl;
        report << "Total Words: " << words << endl;
        report << "Total Lines: " << lines << endl;
        report << "Punctuation Marks: " << punctuation << endl;

        file.close();
        report.close();

        cout << "Report saved to report.txt" << endl;
    }
};

int main() {
    FileAnalyzer analyzer("article.txt", "report.txt");
    analyzer.analyze();
    return 0;
}

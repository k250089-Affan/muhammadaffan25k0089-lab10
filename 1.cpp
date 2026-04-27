#include <iostream>
#include <fstream>
using namespace std;

class GreetingCard {
private:
    string name;
    string message;

public:
    void getInput() {
        cout << "Enter recipient's name: ";
        getline(cin, name);

        cout << "Enter your message: ";
        getline(cin, message);
    }

    void writeToFile() {
        ofstream file("greeting.txt"); // opens in write mode (default)

        if (file.is_open()) {
            file << "Dear " << name << ",\n";
            file << message << "\n";
            file << "Best Regards!";
            file.close();
            cout << "Greeting saved to greeting.txt successfully.\n";
        } else {
            cout << "Error opening file.\n";
        }
    }
};

int main() {
    GreetingCard card;
    card.getInput();
    card.writeToFile();
    return 0;
}

#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

class SystemLogger {
private:
    ofstream file;

public:
    void logStartup() {
        file.open("system_log.txt", ios::app);
        if (!file) {
            cout << "Error opening file.\n";
            return;
        }

        // Get current time
        time_t now = time(0);
        char* dt = ctime(&now);

        file << "System started at: " << dt;

        file.close();
        cout << "Startup logged successfully.\n";
    }
};

int main() {
    SystemLogger logger;
    logger.logStartup();
    return 0;
}

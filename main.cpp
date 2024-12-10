#include "InMemoryDB.h"
#include <iostream>
#include <string>
#include <optional>
#include <stdexcept>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;

int main() {
    InMemoryDB db;
    string help_message = "Please enter one of the following commands:\n"
                          "begin_transaction\n"
                          "put <key> <value>\n"
                          "get <key>\n"
                          "commit\n"
                          "rollback\n"
                          "quit\n";

    cout << "In-Memory Database Program\n";
    cout << help_message;

    string command;
    while (true) {
        cout << "> ";
        getline(cin, command);

        // Split command into parts
        istringstream iss(command);
        vector<string> tokens((istream_iterator<string>(iss)), istream_iterator<string>());

        if (tokens.empty()) {
            cout << "Empty command. Try again.\n";
            continue;
        }

        try {
            if (tokens[0] == "begin_transaction") {
                db.begin_transaction();
                cout << "Transaction started.\n";
            } else if (tokens[0] == "put") {
                if (tokens.size() < 3) {
                    cout << "Usage: put <key> <value>\n";
                    continue;
                }
                string key = tokens[1];
                int value = stoi(tokens[2]); // Convert value to integer
                db.put(key, value);
                cout << "Key \"" << key << "\" updated with value: " << value << ".\n";
            } else if (tokens[0] == "get") {
                if (tokens.size() < 2) {
                    cout << "Usage: get <key>\n";
                    continue;
                }
                string key = tokens[1];
                auto result = db.get(key);
                if (result.has_value()) {
                    cout << "Value for key \"" << key << "\": " << result.value() << "\n";
                } else {
                    cout << "Key \"" << key << "\" not found.\n";
                }
            } else if (tokens[0] == "commit") {
                db.commit();
                cout << "Transaction committed.\n";
            } else if (tokens[0] == "rollback") {
                db.rollback();
                cout << "Transaction rolled back.\n";
            } else if (tokens[0] == "quit") {
                cout << "Exiting program.\n";
                break;
            } else {
                cout << "Command not recognized.\n";
                cout << help_message;
            }
        } catch (const exception &e) {
            cout << "Error: " << e.what() << "\n";
        }
    }

    return 0;
}

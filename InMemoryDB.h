#include <iostream>
#include <unordered_map>
#include <optional>

using namespace std;

class InMemoryDB
{
    unordered_map<string, int> db;
    bool transactionIsOpen = false;
    unordered_map<string, int> dbCopy = db;
public:
    optional<int> get(string key);
    void put(string key, int val);
    void begin_transaction();
    void commit();
    void rollback();
};

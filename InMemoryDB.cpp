#include "InMemoryDB.h"
#include <optional>

using namespace std;

optional<int> InMemoryDB::get(string key)
{
    if (db.find(key) != db.end())
        return db[key];

    return nullopt;
}

void InMemoryDB::put(string key, int val)
{
    if (!transactionIsOpen)
        throw runtime_error("A transaction is not currently active.");

    dbCopy[key] = val;
}

void InMemoryDB::begin_transaction()
{
    if (transactionIsOpen)
        throw runtime_error("A transaction is already active.");

    transactionIsOpen = true;
    dbCopy = db;
}

void InMemoryDB::commit()
{
    if (!transactionIsOpen)
        throw runtime_error("A transaction is not currently active. No changes to commit.");
    db = dbCopy;
    dbCopy.clear();
    transactionIsOpen = false;
}

void InMemoryDB::rollback()
{
    if (!transactionIsOpen)
        throw runtime_error("A transaction is not currently active. No changes to rollback.");
    transactionIsOpen = false;
    dbCopy.clear();
}
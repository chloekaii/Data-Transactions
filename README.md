# Data-Transactions
Simulating transactions in relational databases.

## Setup
Compile the program using the provided makefile by running "make", then run ./main in your command line. Alternatively, if you want to manually compile the program, use these commands (make sure g++ is installed):

  `g++ -std=c++17 -Wall -Wextra -c main.cpp -o main.o`
  
  `g++ -std=c++17 -Wall -Wextra -c InMemoryDB.cpp -o InMemoryDB.o`
  
  `g++ -o main main.o InMemoryDB.o`
  
  `./main`

Once the program is running, you can run the following commands:

`begin_transaction`: Begins a new transaction.

`put <key> <value>`: Creates a new key with the provided value if a key doesn’t exist. Otherwise it will update the value of an existing key.

`get <get>`: Returns the value associated with the key or null if the key doesn’t exist.

`commit`: Commits changes made in the current transaction to the database.

`rollback`: Rolls back changese made in the current transaction.

`quit`: Exits program.
## Suggested Improvements to Grading:
Explicitly defining how the database should behave under edge cases, such as attempting invalid operations like rolling back a transaction with no changes, could make the expected behavior of the program more clear. Providing example scenarios for error handling and input validation can also help clarify expectations. Including a grading component for unit tests could help, and students could be required to write their own unit tests or pass a provided test suite.

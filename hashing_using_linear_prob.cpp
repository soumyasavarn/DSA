/*This is implementation of hash table which handles collision using linear probing*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int TABLE_SIZE = 5;
/*
Soumya Savarn
220150031
DSAI
*/
//Defining key-value pair
struct Entry {
    int key;
    int value;
};

Entry EmptyEntry = {-1, -1};

int Hash(int key) {
    return key % TABLE_SIZE;
}

//This uses Linear probing to handle collisions
void Insert(Entry* table, int key, int value) {
    int hashValue = Hash(key);
    int init = -1;
    int emptyIndex = -1;
    while (table[hashValue].key != -1 && table[hashValue].key != key) {
        if (init == -1)
            init = hashValue;
        if (table[hashValue].key == EmptyEntry.key)
            emptyIndex = hashValue;
        hashValue = (hashValue + 1) % TABLE_SIZE;
    }
    if (table[hashValue].key == -1 || hashValue == init) {
        if (emptyIndex != -1)
            table[emptyIndex] = {key, value};
        else
            table[hashValue] = {key, value};
    }
    if (init != hashValue) {
        if (table[hashValue].key != EmptyEntry.key) {
            if (table[hashValue].key == key)
                table[hashValue].value = value;
        }
        else
            table[hashValue] = {key, value};
    }
}

int Search(Entry* table, int key) {
    int hashValue = Hash(key);
    int init = -1;
    while (table[hashValue].key != -1 && table[hashValue].key != key) {
        if (init == -1)
            init = hashValue;
        hashValue = (hashValue + 1) % TABLE_SIZE;
    }
    if (table[hashValue].key == -1 || hashValue == init)
        return -1;
    else
        return table[hashValue].value;
}

void Remove(Entry* table, int key) {
    int hashValue = Hash(key);
    int init = -1;
    while (table[hashValue].key != -1 && table[hashValue].key != key) {
        if (init == -1)
            init = hashValue;
        hashValue = (hashValue + 1) % TABLE_SIZE;
    }
    if (hashValue != init && table[hashValue].key != -1) {
        table[hashValue] = EmptyEntry;
    }
}

int main() {
    Entry table[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = EmptyEntry;
    }

    int key, value;
    int choice;
    while (1) {
        cout << "----------------------" << endl;
        cout << "Please select from below" << endl;
        cout << "----------------------" << endl;
        cout << "1.Insert element into the table" << endl;
        cout << "2.Search element from the key" << endl;
        cout << "3.Delete element at a key" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter element to be inserted: ";
            cin >> value;
            cout << "Enter key at which element to be inserted: ";
            cin >> key;
            Insert(table, key, value);
        } else if (choice == 2) {
            cout << "Enter key of the element to be searched: ";
            cin >> key;
            int result = Search(table, key);
            if (result == -1) {
                cout << "No element found at key " << key << endl;
                continue;
            } else {
                cout << "Element at key " << key << " : " << result << endl;
            }
        } else if (choice == 3) {
            cout << "Enter key of the element to be deleted: ";
            cin >> key;
            Remove(table, key);
        } else if (choice == 4) {
            exit(1);
        } else {
            cout << "\nEnter correct option\n";
        }
        cout << endl;
    }
    return 0;
}
/*
Soumya Savarn
220150031
DSAI
*/

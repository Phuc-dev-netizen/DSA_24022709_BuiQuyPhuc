#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 10;

struct Entry {
    string key;
    int value;
    bool isEmpty;
    bool isDeleted;
};

struct HashTable {
    Entry table[TABLE_SIZE];

    void init() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i].isEmpty = true;
            table[i].isDeleted = false;
        }
    }

    int hash(string key) {
        int sum = 0;
        for (char c : key)
            sum += c;
        return sum % TABLE_SIZE;
    }

    void insert(string key, int value) {
        int index = hash(key);
        for (int i = 0; i < TABLE_SIZE; ++i) {
            int pos = (index + i) % TABLE_SIZE;
            if (table[pos].isEmpty || table[pos].isDeleted || table[pos].key == key) {
                table[pos].key = key;
                table[pos].value = value;
                table[pos].isEmpty = false;
                table[pos].isDeleted = false;
                return;
            }
        }
        cout << "Bảng đã đầy!" << endl;
    }

    void remove(string key) {
        int index = hash(key);
        for (int i = 0; i < TABLE_SIZE; ++i) {
            int pos = (index + i) % TABLE_SIZE;
            if (!table[pos].isEmpty && !table[pos].isDeleted && table[pos].key == key) {
                table[pos].isDeleted = true;
                return;
            }
            if (table[pos].isEmpty && !table[pos].isDeleted)
                return;
        }
    }

    void search(string key) {
        int index = hash(key);
        for (int i = 0; i < TABLE_SIZE; ++i) {
            int pos = (index + i) % TABLE_SIZE;
            if (!table[pos].isEmpty && !table[pos].isDeleted && table[pos].key == key) {
                cout << "Tìm thấy: " << key << " → " << table[pos].value << endl;
                return;
            }
            if (table[pos].isEmpty && !table[pos].isDeleted)
                break;
        }
        cout << "Không tìm thấy: " << key << endl;
    }
};

int main() {
    HashTable ht;

    ht.insert("apple", 10);
    ht.insert("banana", 20);
    ht.insert("orange", 30);

    ht.search("banana");
    ht.remove("banana");
    ht.search("banana");
}

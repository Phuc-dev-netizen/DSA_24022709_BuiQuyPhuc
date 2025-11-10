#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 10; // Kích thước bảng băm

// Node trong danh sách liên kết
struct Node {
    string key;
    int value;
    Node* next;
};

// Hash Table
struct HashTable {
    Node* table[TABLE_SIZE]; // Mảng các danh sách liên kết

    // Constructor
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i)
            table[i] = nullptr;
    }

    // Hàm băm đơn giản
    int hash(string key) {
        int sum = 0;
        for (char c : key)
            sum += c;
        return sum % TABLE_SIZE;
    }

    // Thêm phần tử
    void insert(string key, int value) {
        int index = hash(key);
        Node* newNode = new Node{key, value, nullptr};
        newNode->next = table[index];
        table[index] = newNode;
    }

    // Tìm kiếm
    Node* search(string key) {
        int index = hash(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key)
                return current;
            current = current->next;
        }
        return nullptr;
    }

    // Xóa phần tử (không dùng prev)
    void remove(string key) {
        int index = hash(key);
        Node* current = table[index];

        // Xóa các node đầu nếu trùng key
        while (current != nullptr && current->key == key) {
            Node* toDel = current;
            current = current->next;
            delete toDel;
            table[index] = current;
        }

        // Xóa các node sau
        while (current != nullptr && current->next != nullptr) {
            if (current->next->key == key) {
                Node* toDel = current->next;
                current->next = current->next->next;
                delete toDel;
            } else {
                current = current->next;
            }
        }
    }
    
    // Destructor
    ~HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* Release = current;
                current = current->next;
                delete Release;
            }
        }
    }
};

int main() {
    HashTable ht;

    ht.insert("apple", 10);
    ht.insert("banana", 20);
    ht.insert("orange", 30);
    ht.insert("banana", 25);

    Node* found = ht.search("banana");
    if (found)
        cout << "Found banana: " << found->value << endl;
    else
        cout << "Banana not found" << endl;

    ht.remove("banana");
}
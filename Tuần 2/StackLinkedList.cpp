#include <iostream>
using namespace std;

// Định nghĩa Node
struct Node {
    int data;
    Node* next;
};

// Cấu trúc LinkedList
struct LinkedList {
    Node* head;

    // Khởi tạo danh sách rỗng
    LinkedList() {
        head = NULL;
    }

    // Tạo node mới
    Node* createNode(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;
        return newNode;
    }

    // Chèn vào đầu
    void insertHead(int value) {
        Node* newNode = createNode(value);
        newNode->next = head;
        head = newNode;
    }

    // Xóa đầu
    void deleteHead() {
        if (head == NULL) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }
};

// Cấu trúc Stack (cài đặt bằng LinkedList)
struct Stack {
    LinkedList L;

    // Thêm phần tử vào đỉnh stack: O(1)
    void push(int x) {
        L.insertHead(x);
    }

    // Xóa và trả về phần tử ở đỉnh stack: O(1)
    int pop() {
        if (L.head == NULL) {
            cout << "Stack rong!" << endl;
            return -1;
        }
        int val = L.head->data;
        L.deleteHead();
        return val;
    }

    // Trả về phần tử ở đỉnh stack: O(1)
    int top() {
        if (L.head == NULL) {
            cout << "Stack rong!" << endl;
            return -1;
        }
        return L.head->data;
    }

    // Trả về số phần tử trong stack: O(n) vì phải duyệt danh sách
    int size() {
        int cnt = 0;
        Node* temp = L.head;
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    // Kiểm tra stack rỗng: O(1)
    bool isEmpty() {
        return L.head == NULL;
    }
};
#include <iostream>
using namespace std;

// Định nghĩa node 
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

    // Hàm tạo node mới
    Node* createNode(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;
        return newNode;
    }

    // Chèn vào cuối
    void insertTail(int value) {
        Node* newNode = createNode(value);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }

    // Xóa đầu
    void deleteHead() {
        if (head == NULL) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Duyệt xuôi
    void traverseForward() {
        for (Node* temp = head; temp != NULL; temp = temp->next) {
            cout << temp->data << " ";
        }
        cout << endl;
    }
};

// Cấu trúc Queue Queue (cài đặt bằng LinkedList)
struct Queue {
    LinkedList L;

    // Kiểm tra rỗng: O(1)
    bool isEmpty() {
        return L.head == NULL;
    }

    // Thêm vào cuối: O(n) vì phải duyệt từ head đến cuối để chèn
    void enqueue(int value) {
        L.insertTail(value);
    }

    // Xóa đầu: O(1)
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue rong!" << endl;
            return -1;
        }
        int value = L.head->data;
        L.deleteHead();
        return value;
    }

    // Lấy giá trị đầu: O(1)
    int front() {
        if (isEmpty()) {
            cout << "Queue rong!" << endl;
            return -1;
        }
        return L.head->data;
    }

    // Duyệt queue: O(n) vì phải đi qua toàn bộ các phần tử để in ra
    void traverse() {
        L.traverseForward();
    }
};

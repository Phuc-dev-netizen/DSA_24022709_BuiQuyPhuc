#include <iostream>
using namespace std;
//Định nghĩa node 
struct Node {
    int data;
    Node* next;
};

// Hàm tạo node mới
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Chèn vào đầu
void insertHead(Node*& head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

// Chèn vào cuối
void insertTail(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

// Chèn vào vị trí i (0-based)
void insertAt(Node*& head, int value, int pos) {
    if (pos == 0) {
        insertHead(head, value);
        return;
    }
    Node* temp = head;
    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) return;
    Node* newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Xóa đầu
void deleteHead(Node*& head) {
    if (head == NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Xóa cuối
void deleteTail(Node*& head) {
    if (head == NULL) return;
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL) temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}

// Xóa tại vị trí i
void deleteAt(Node*& head, int pos) {
    if (pos == 0) {
        deleteHead(head);
        return;
    }
    Node* temp = head;
    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) return;
    Node* del = temp->next;
    temp->next = del->next;
    delete del;
}

// Duyệt xuôi
void traverseForward(Node* head) {
    for (Node* temp = head; temp != NULL; temp = temp->next) {
        cout << temp->data << " ";
    }
    cout << endl;
}

// Duyệt ngược (đệ quy)
void traverseBackward(Node* head) {
    if (head == NULL) return;
    traverseBackward(head->next);
    cout << head->data << " ";
}
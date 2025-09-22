#include <iostream>
using namespace std;

const int MAX = 100; // kích thước tối đa của danh sách

struct List {
    int a[MAX];
    int count; // số phần tử hiện có
};

// Khởi tạo danh sách rỗng
void init(List &L) {
    L.count = 0;
}

// Truy cập phần tử tại vị trí i
int get(List L, int i) {
    if (i >= 0 && i < L.count) return L.a[i];
    return -1; // Báo lỗi
}

// Chèn phần tử vào đầu
void insertFirst(List &L, int x) {
    if (L.count >= MAX) return;
    for (int i = L.count; i > 0; i--)
        L.a[i] = L.a[i-1];
    L.a[0] = x;
    L.count++;
}

// Chèn phần tử vào cuối
void insertLast(List &L, int x) {
    if (L.count >= MAX) return;
    L.a[L.count++] = x;
}

// Chèn vào vị trí i
void insertAt(List &L, int i, int x) {
    if (L.count >= MAX || i < 0 || i > L.count) return;
    for (int j = L.count; j > i; j--)
        L.a[j] = L.a[j-1];
    L.a[i] = x;
    L.count++;
}

// Xóa phần tử đầu
void deleteFirst(List &L) {
    if (L.count == 0) return;
    for (int i = 0; i < L.count-1; i++)
        L.a[i] = L.a[i+1];
    L.count--;
}

// Xóa phần tử cuối
void deleteLast(List &L) {
    if (L.count == 0) return;
    L.count--;
}

// Xóa tại vị trí i
void deleteAt(List &L, int i) {
    if (i < 0 || i >= L.count) return;
    for (int j = i; j < L.count-1; j++)
        L.a[j] = L.a[j+1];
    L.count--;
}

// Duyệt xuôi
void traverseForward(List L) {
    for (int i = 0; i < L.count; i++)
        cout << L.a[i] << " ";
    cout << endl;
}

// Duyệt ngược
void traverseBackward(List L) {
    for (int i = L.count-1; i >= 0; i--)
        cout << L.a[i] << " ";
    cout << endl;
}

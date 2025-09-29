#include <iostream>
using namespace std;

const int MAX = 100; // kích thước tối đa của danh sách

//Cấu trúc List
struct List {
    int a[MAX];
    int count; // số phần tử hiện có

    // Khởi tạo danh sách rỗng
    List() {
        count = 0;
    }

    // Truy cập phần tử tại vị trí i
    int get(int i) {
        if (i >= 0 && i < count) return a[i];
        return -1; // Báo lỗi
    }

    // Chèn phần tử vào cuối
    void insertLast(int x) {
        if (count >= MAX) return;
        a[count++] = x;
    }

    // Xóa phần tử cuối
    void deleteLast() {
        if (count == 0) return;
        count--;
    }
};

//Cấu trúc Stack (cài đặt bằng List)
struct Stack {
    List L;

    // Kiểm tra stack rỗng: O(1)
    bool isEmpty() {
        return L.count == 0;
    }

    // Thêm phần tử vào đỉnh stack: O(1)
    void push(int x) {
        L.insertLast(x);
    }

    // Xóa và trả về phần tử ở đỉnh stack: O(1)
    int pop() {
        if (isEmpty()) {
            cout << "Stack rong!" << endl;
            return -1;
        }
        int val = L.get(L.count - 1);
        L.deleteLast();
        return val;
    }
    
    // Trả về phần tử ở đỉnh stack: O(1)
    int top() {
        if (isEmpty()) {
            cout << "Stack rong!" << endl;
            return -1;
        }
        return L.get(L.count - 1);
    }

    // Trả về số phần tử trong stack: O(1)
    int size() {
        return L.count;
    }
};
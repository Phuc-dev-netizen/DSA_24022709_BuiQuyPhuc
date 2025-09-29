#include <iostream>
using namespace std;

const int MAX = 100; // Kích thước tối đa của danh sách

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

    // Xóa phần tử đầu
    void deleteFirst() {
        if (count == 0) return;
        for (int i = 0; i < count - 1; i++)
            a[i] = a[i + 1];
        count--;
    }

    // Trả về kích thước
    int size() {
        return count;
    }

    // Kiểm tra rỗng
    bool isEmpty() {
        return count == 0;
    }
};

// Cấu trúc Queue (cài đặt bằng List)
struct Queue {
    List L;

    // Kiểm tra queue có rỗng không: O(1)
    bool isEmpty() {
        return L.isEmpty();
    }

    // Thêm phần tử vào cuối queue: O(1)
    void enqueue(int item) {
        L.insertLast(item);
    }

    // Xóa phần tử đầu queue và trả về giá trị đó: O(n) vì deleteFirst phải dịch chuyển n-1 phần tử
    int dequeue() {
        if (L.isEmpty()) return -1;
        int front = L.get(0);   // lấy phần tử đầu
        L.deleteFirst();        // dịch chuyển toàn bộ mảng sang trái
        return front;
    }

    // Trả về giá trị phần tử đầu: O(1)
    int front() {
        if (L.isEmpty()) return -1;
        return L.get(0);
    }

    // Trả về số phần tử hiện có trong queue: O(1)
    int size() {
        return L.size();
    }
};

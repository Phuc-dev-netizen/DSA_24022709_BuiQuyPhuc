#include <iostream>
using namespace std;

//MAX HEAP
struct MaxHeap {
    int pq[101];   // mảng tĩnh, chỉ dùng chỉ số từ 1 trở đi
    int n;         // số phần tử hiện có

    // Khởi tạo
    void init() {
        n = 0;
    }

    // Kiểm tra rỗng
    bool isEmpty() {
        return n == 0;
    }

    // Chèn phần tử vào cây
    void insert(int key) {
        if (n >= 100) return;   // tránh tràn mảng
        pq[++n] = key;
        swim(n);
    }

    // Xóa phần tử lớn nhất
    int delMax() {
        if (isEmpty()) return -1;
        int maxVal = pq[1];
        exch(1, n--);
        sink(1);
        return maxVal;
    }

    // HeapifyUp (Bơi)
    void swim(int k) {
        while (k > 1 && less(k / 2, k)) {
            exch(k, k / 2);
            k = k / 2;
        }
    }

    // HeapifyDown (Chìm)
    void sink(int k) {
        while (2 * k <= n) {
            int j = 2 * k;
            if (j < n && less(j, j + 1)) j++;
            if (!less(k, j)) break;
            exch(k, j);
            k = j;
        }
    }

    // Kiểm tra phần tử bé hơn
    bool less(int i, int j) {
        return pq[i] < pq[j];
    }

    // Hoán đổi phần tử
    void exch(int i, int j) {
        int t = pq[i];
        pq[i] = pq[j];
        pq[j] = t;
    }
};


//MIN HEAP
struct MinHeap {
    int pq[101];
    int n;

    void init() {
        n = 0;
    }

    bool isEmpty() {
        return n == 0;
    }

    void insert(int key) {
        if (n >= 100) return;
        pq[++n] = key;
        swim(n);
    }

    // Xóa phần tử bé nhất
    int delMin() {
        if (isEmpty()) return -1;
        int minVal = pq[1];
        exch(1, n--);
        sink(1);
        return minVal;
    }

    void swim(int k) {
        while (k > 1 && greater(k / 2, k)) {
            exch(k, k / 2);
            k = k / 2;
        }
    }

    void sink(int k) {
        while (2 * k <= n) {
            int j = 2 * k;
            if (j < n && greater(j, j + 1)) j++;
            if (!greater(k, j)) break;
            exch(k, j);
            k = j;
        }
    }

    // Kiểm tra phần tử lớn hơn
    bool greater(int i, int j) {
        return pq[i] > pq[j];
    }

    void exch(int i, int j) {
        int t = pq[i];
        pq[i] = pq[j];
        pq[j] = t;
    }
};

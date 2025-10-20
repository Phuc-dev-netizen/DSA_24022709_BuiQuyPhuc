#include "BinaryHeap.h"
using namespace std;

//PRIORITY QUEUE
struct PriorityQueue {
    MaxHeap heap;  // dùng max heap bên trong

    // Khởi tạo
    void init() {
        heap.init();
    }

    // Chèn 1 phần tử
    void insert(int value) {
        heap.insert(value);
    }

    // Xóa phần tử lớn nhất và trả về giá trị đó
    int delMax() {
        return heap.delMax();
    }

    // Kiểm tra PQ có rỗng không
    bool isEmpty() {
        return heap.isEmpty();
    }

    // Trả về giá trị lớn nhất (phần tử ở đỉnh heap)
    int max() {
        if (heap.isEmpty()) return -1;
        return heap.pq[1];
    }

    // Trả về số phần tử hiện có
    int size() {
        return heap.n;
    }
};

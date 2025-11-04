#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

struct Entry {
    string key;
    string value;
};

struct SymbolTable {
    Entry entries[MAX];
    int count;

    // Khởi tạo bảng rỗng
    SymbolTable() {
        count = 0;
    }

    // Thêm hoặc cập nhật cặp key-value
    void put(string key, string value) {
        for (int i = 0; i < count; i++) {
            if (entries[i].key == key) {
                entries[i].value = value; // Ghi đè giá trị cũ
                return;
            }
        }
        if (count < MAX) {
            entries[count].key = key;
            entries[count].value = value;
            count++;
        } else {
            cout << "Symbol Table đầy!" << endl;
        }
    }

    // Lấy giá trị theo key
    string get(string key) {
        for (int i = 0; i < count; i++) {
            if (entries[i].key == key) {
                return entries[i].value;
            }
        }
        return "Không tìm thấy";
    }

    // Kiểm tra key có tồn tại không
    bool contains(string key) {
        return get(key) != "";
    }

    // Xóa một key khỏi bảng
    void deleteKey(string key) {
        for (int i = 0; i < count; i++) {
            if (entries[i].key == key) {
                for (int j = i; j < count - 1; j++) {
                    entries[j] = entries[j + 1];
                }
                count--;
                return;
            }
        }
    }

    // Kiểm tra bảng có rỗng không
    bool isEmpty() {
        return count == 0;
    }

    // Trả về số lượng cặp key-value
    int size() {
        return count;
    }

    // In ra tất cả các key
    void keys() {
        for (int i = 0; i < count; i++) {
            cout << entries[i].key << " ";
        }
        cout << endl;
    }
};

// Sử dụng SymbolTable
int main() {
    SymbolTable st;

    st.put("A", "Apple");
    st.put("B", "Banana");
    st.put("C", "Cherry");

    cout << "Giá trị của B: " << st.get("B") << endl;

    st.deleteKey("D");

    cout << "Các key còn lại: ";
    st.keys();

    cout << "Số lượng phần tử: " << st.size() << endl;

    return 0;
}

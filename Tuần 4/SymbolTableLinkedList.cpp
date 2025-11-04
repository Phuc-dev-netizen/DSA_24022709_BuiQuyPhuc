#include <iostream>
#include <string>
using namespace std;

struct Node {
    string key;
    string value;
    Node* next;
};

struct SymbolTable {
    Node* head;
    int count;

    // Khởi tạo bảng rỗng
    SymbolTable() {
        head = NULL;
        count = 0;
    }

    // Thêm hoặc cập nhật cặp key-value
    void put(string key, string value) {
        Node* current = head;
        while (current != NULL) {
            if (current->key == key) {
                current->value = value; // Ghi đè giá trị cũ
                return;
            }
            current = current->next;
        }
        Node* newNode = new Node;
        newNode->key = key;
        newNode->value = value;
        newNode->next = head;
        head = newNode;
        count++;
    }

    // Lấy giá trị theo key
    string get(string key) {
        Node* current = head;
        while (current != NULL) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return "Không tìm thấy";
    }

    // Kiểm tra key có tồn tại không
    bool contains(string key) {
        return get(key) != "";
    }

    // Xóa một key khỏi bảng
    void deleteKey(string key) {
        Node* current = head;
        if(head!= NULL && head -> key == key){
            head = head -> next;
            delete current;
            count --;
            return;
        }
        while(current != NULL && current -> next != NULL){
            if(current -> next -> key == key){
                Node* nodeToDel = current -> next;
                current -> next = nodeToDel -> next;
                delete nodeToDel;
                count -- ;
                return;
            }
            current = current -> next;
        }
        // Nếu không tìm thấy key
        cout << "Không tìm thấy key: " << key << " để xóa." << endl;
    }

    // Kiểm tra bảng có rỗng không
    bool isEmpty() {
        return count == 0;
    }

    // Trả về số lượng phần tử
    int size() {
        return count;
    }

    // In ra tất cả các key
    void keys() {
        Node* current = head;
        while (current != NULL) {
            cout << current->key << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Giải phóng bộ nhớ
    ~SymbolTable() {
        Node* current = head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        cout << "SymbolTable đã được hủy và giải phóng bộ nhớ." << endl;
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
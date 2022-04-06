#include<bits/stdc++.h>

using namespace std;

struct HocVien{
    int ma_hoc_vien;
    string ten_hoc_vien;
    string lop;
    string chuyen_nganh;
    double diem_tong_ket;
};

// 1) khoi tao danh sach 
struct Node{
    HocVien hoc_vien;
    struct Node *next;
    struct Node *prev; 
};
struct Node *head, *tail; // Khởi tạo Node head global của dslk đôi.


// 2) Tao mot node moi 
struct Node* GetNewNode(HocVien hoc_vien) {
    struct Node* newNode
        = (struct Node*)malloc(sizeof(struct Node));
    newNode->hoc_vien = hoc_vien;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

    
// 3) Chen nut vao cuoi danh sach 
void InsertAtTail(HocVien hoc_vien) {
    struct Node* newNode = GetNewNode(hoc_vien);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}
 
// 4) Duyet danh sach 
void InDanhSach(){
    struct Node* temp = head;
    cout << "Danh Sach Sinh Vien Da Nhap:" << endl;
    while(temp != NULL) {
        cout << "ten hoc vien: " << temp->hoc_vien.ten_hoc_vien << endl;
        cout << "ma hoc vien: " << temp->hoc_vien.ma_hoc_vien << endl;
        cout << "chuyen nganh: " << temp->hoc_vien.chuyen_nganh << endl;
        cout << "lop: " << temp->hoc_vien.lop << endl;
        cout << "diem tong ket: " << temp->hoc_vien.diem_tong_ket << endl;
        cout << "---------------" << endl;
        temp = temp->next;
    }
    cout << endl;
}


void LietKe(){
    struct Node* temp = head;
    cout << "Danh Sach Sinh Vien thuoc chuyen nganh Thuong Mai Dien Tu va co diem tong ket >= 8.0:" << endl;
    while(temp != NULL) {
        if (temp->hoc_vien.chuyen_nganh == "Thuong Mai Dien Tu" && temp->hoc_vien.diem_tong_ket >= 8.0){
            cout << "ten hoc vien: " << temp->hoc_vien.ten_hoc_vien << endl;
            cout << "ma hoc vien: " << temp->hoc_vien.ma_hoc_vien << endl;
            cout << "chuyen nganh: " << temp->hoc_vien.chuyen_nganh << endl;
            cout << "lop: " << temp->hoc_vien.lop << endl;
            cout << "diem tong ket: " << temp->hoc_vien.diem_tong_ket << endl;
            cout << "---------------" << endl;
        }
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    int n;
    cout << "Nhap danh so luong hoc vien: " << endl;
    cin >> n;   
    for(int i=0;i<n;i++){
        HocVien hoc_vien;
        cout << "nhap ten hoc vien: " << endl;
        cin >> hoc_vien.ten_hoc_vien;
        cout << "nhap ma hoc vien: " << endl;
        cin >> hoc_vien.ma_hoc_vien;
        cout << "nhap chuyen nganh: " << endl;
        cin >> hoc_vien.chuyen_nganh;
        cout << "nhap lop: " << endl;
        cin >> hoc_vien.lop;
        cout << "nhap diem tong ket: " << endl;
        cin >> hoc_vien.diem_tong_ket;
        InsertAtTail(hoc_vien);        
    }
    InDanhSach();
    LietKe();

}
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
struct LinkedList{
    HocVien hoc_vien;
    struct LinkedList *next;
};

typedef struct LinkedList *node; 

// 2) Tao mot node moi 
node CreateNode(HocVien hoc_vien){
    node temp; 
    temp = (node)malloc(sizeof(struct LinkedList));
    temp->next = NULL;
    temp->hoc_vien = hoc_vien; 
    return temp; 
}

// 3) Chen nut vao dau danh sach 
node AddHead(node head, HocVien hoc_vien){
    node temp = CreateNode(hoc_vien); // Khởi tạo node temp với data = value
    if(head == NULL){
        head = temp; // //Nếu linked list đang trống thì Node temp là head luôn
    }else{
        temp->next = head; // Trỏ next của temp = head hiện tại
        head = temp; // Đổi head hiện tại = temp(Vì temp bây giờ là head mới mà)
    }
    return head;
}

// 4) Duyet danh sach 
void Traverser(node head){
    cout << endl;
    for(node p = head; p != NULL; p = p->next){
        cout << p->hoc_vien.ma_hoc_vien << " " << p->hoc_vien.ten_hoc_vien << endl;
    }
}

int main(){
    


}
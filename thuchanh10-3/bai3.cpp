#include<bits/stdc++.h>

using namespace std; 

struct VanDongVien{
    int ma;
    string ten;
    int tuoi;
    string que_quan;
    double luong;
};


struct Node{
  VanDongVien van_dong_vien;
  Node *pNext;
};
   

struct SingleList{
  Node *pHead; 
  Node *pTail; 
};

// 1) Khoi Tao Danh Sach
void Initialize(SingleList &list){
  list.pHead=list.pTail=NULL;
}

// 2) Tao 1 node chua du lieu
Node *CreateNode(VanDongVien van_dong_vien){
    Node *pNode=new Node; 
    if(pNode!=NULL){
       pNode->van_dong_vien=van_dong_vien; 
       pNode->pNext=NULL;
    }
    else {
      cout<<"Error allocated memory";
    }
    return pNode;
}
  
// 3) chen node vao cuoi danh sach
void InsertLast(SingleList &list,VanDongVien van_dong_vien){ 
  Node *pNode=CreateNode(van_dong_vien);
  if(list.pTail==NULL){
    list.pHead=list.pTail=pNode;
  }
  else{
    list.pTail->pNext=pNode;
    list.pTail=pNode;
  }
}

// 4) Tim kiem phan tu
VanDongVien PrintList(SingleList list, VanDongVien van_dong_vien){
  VanDongVien van_dong_vien;
  Node *pTmp=list.pHead;
  if(pTmp==NULL){
    cout<<"The list is empty!";
    return;
  }
  while(pTmp!=NULL){
    if (pTmp->van_dong_vien.ma == van_dong_vien.ma){
        return pTmp->van_dong_vien;
    } 
    pTmp=pTmp->pNext;
  }
}

// 5) Duyet Danh Sach
void PrintList(SingleList list){
  Node *pTmp=list.pHead;
  if(pTmp==NULL){
    cout<<"The list is empty!";
    return;
  }
  while(pTmp!=NULL){
    cout << "Ma van dong vien: " << pTmp->van_dong_vien.ma << endl;
    cout << "Ten van dong vien: " << pTmp->van_dong_vien.ten << endl;
    cout << "Tuoi van dong vien" << pTmp->van_dong_vien.tuoi << endl;
    cout << "Que quan:" << pTmp->van_dong_vien.que_quan << endl;
    cout << "Luong: " << pTmp->van_dong_vien.luong << endl;
    pTmp=pTmp->pNext;
  }
}

// Liệt kê ra màn hình danhsách những Vận động viên quê ở “Nghệ An”.
void PrintListInConditionCountry(SingleList list){
  cout << "danh sach van dong vien que o Nghe An" << endl;
  Node *pTmp=list.pHead;
  if(pTmp==NULL){
    cout<<"The list is empty!";
    return;
  }
  while(pTmp!=NULL){
    if (pTmp->van_dong_vien.que_quan == "Nghe An"){
        cout << "Ma van dong vien: " << pTmp->van_dong_vien.ma << endl;
        cout << "Ten van dong vien: " << pTmp->van_dong_vien.ten << endl;
        cout << "Tuoi van dong vien" << pTmp->van_dong_vien.tuoi << endl;
        cout << "Que quan:" << pTmp->van_dong_vien.que_quan << endl;
        cout << "Luong: " << pTmp->van_dong_vien.luong << endl;
    }
    pTmp=pTmp->pNext;
  }
}

//Tìm trong danh sách tất cả những vận động viênđã hết tuổi thi đấu (từ 50 tuổi trở lên).
void PrintListInConditionAge(SingleList list){
  cout << "danh sach van dong vien lon hon 50 tuoi" << endl;
  Node *pTmp=list.pHead;
  if(pTmp==NULL){
    cout<<"The list is empty!";
    return;
  }
  while(pTmp!=NULL){
    if (pTmp->van_dong_vien.tuoi >= 50){
        cout << "Ma van dong vien: " << pTmp->van_dong_vien.ma << endl;
        cout << "Ten van dong vien: " << pTmp->van_dong_vien.ten << endl;
        cout << "Tuoi van dong vien" << pTmp->van_dong_vien.tuoi << endl;
        cout << "Que quan:" << pTmp->van_dong_vien.que_quan << endl;
        cout << "Luong: " << pTmp->van_dong_vien.luong << endl;
    }
    pTmp=pTmp->pNext;
  }
}


int main(){
    SingleList list;
    Initialize(list);
    int n; 
    cout << "Nhap so luong van dong vien: "; 
    cin >> n;
    for(int i=0;i<n;i++){
        VanDongVien van_dong_vien;
        cout << "Nhap thong tin Van dong vien so: " << i+1 << endl;
        cout << "Nhap ma van dong vien: " << endl;
        cin >> van_dong_vien.ma;
        cout << "Nhap ten van dong vien: " << endl;
        cin >> van_dong_vien.ten;
        cout << "Nhap tuoi van dong vien: " << endl;
        cin >> van_dong_vien.tuoi;
        cout << "Nhap que quan van dong vien: " << endl;
        cin >> van_dong_vien.que_quan;
        InsertLast(list, van_dong_vien);
    }       
    PrintList(list);
    PrintListInConditionCountry(list);
    PrintListInConditionAge(list);
}
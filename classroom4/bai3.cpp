#include<bits/stdc++.h>

using namespace std;

struct NhanVien {
    int ma;
    string ten; 
    int tuoi; 
    double hsl;
};

struct Node{
  NhanVien nhan_vien;
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
Node *CreateNode(NhanVien nhan_vien){
    Node *pNode=new Node; 
    if(pNode!=NULL){
       pNode->nhan_vien=nhan_vien; 
       pNode->pNext=NULL;
    }
    else {
      cout<<"Error allocated memory";
    }
    return pNode;
}
  
// 3) chen node vao dau danh sach
void InsertFirst(SingleList &list,NhanVien nhan_vien){
  Node *pNode=CreateNode(nhan_vien);
  if(list.pHead==NULL){
    list.pHead=list.pTail=pNode;
  }
  else{
    pNode->pNext=list.pHead;
    list.pHead=pNode;
  }
}



// 4) Sap xep phan tu trong danh sach theo he so luong tang dan
void SortList(SingleList &list){
 for(Node *pTmp=list.pHead;pTmp!=NULL;pTmp=pTmp->pNext){
  for(Node *pTmp2=pTmp->pNext;pTmp2!=NULL;pTmp2=pTmp2->pNext){
    if(pTmp->nhan_vien.hsl>pTmp2->nhan_vien.hsl){
       NhanVien tmp=pTmp->nhan_vien;
       pTmp->nhan_vien=pTmp2->nhan_vien;
       pTmp2->nhan_vien=tmp;
    }
  }
 }
}
 
  
// 5) Duyet danh sach
void PrintList(SingleList list){
  Node *pTmp=list.pHead;
  if(pTmp==NULL){
    cout<<"The list is empty!";
    return;
  }
  while(pTmp!=NULL){
    cout << pTmp->nhan_vien.ten << " " << pTmp->nhan_vien.ma;
    pTmp=pTmp->pNext;
  }
}



void InNhanVienLonHon60(SingleList list){
   Node *pTmp=list.pHead;
  if(pTmp==NULL){
    cout<<"The list is empty!";
    return;
  }
  while(pTmp!=NULL){
    if (pTmp->nhan_vien.tuoi >= 60){
        cout << "Ma nhan vien: " << pTmp->nhan_vien.ma << endl; 
        cout << "Ten Nhan Vien: " << pTmp->nhan_vien.ten << endl;
        cout << "Tuoi: " << pTmp->nhan_vien.tuoi << endl;
        cout << "He so luong: " << pTmp->nhan_vien.hsl << endl;
    }
    cout << pTmp->nhan_vien.ten << " " << pTmp->nhan_vien.ma;
    pTmp=pTmp->pNext;
  } 
}
  
int main() {
    SingleList list;
    Initialize(list);
    // 1) nhap so luong nhan vien 
    int n;
    cout << "Nhap so luong nhan vien: " << endl;
    cin >> n;
    for(int i=0;i<n;i++){
        NhanVien nhan_vien; 
        cout << "Nhap ten nhan vien"; 
        cin >> nhan_vien.ten;
        cout << "Nhap ma nhan vien"; 
        cin >> nhan_vien.ma;
        cout << "Nhap tuoi nhan vien"; 
        cin >> nhan_vien.tuoi;
        cout << "Nhap he so luong"; 
        cin >> nhan_vien.hsl;   
        InsertFirst(list, nhan_vien);
    }
    // 2) Hien thi danh sach nhan vien da nhap ra man hinh;
    PrintList(list);

    // 3) Liet ke thong tin day du cua nhan vien co tuoi >= 60
    InNhanVienLonHon60(list);

    // 4) Sap xep nhan vien theo he so luong tang dan 
    SortList(list);
    PrintList(list);

    return 0;
}
#include<bits/stdc++.h>

using namespace std;

struct NhanVien{
    int ma; 
    string ten;
    int tuoi;
    float he_so_luong;
};



struct Node{
  NhanVien nhan_vien;
  Node *pNext;
};
   

struct List{
  Node *pTail; 
};
   
// 1) Khoi Tao Danh Sach
void Initialize(List &list){
  list.pTail=NULL;
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
  
// 3) chen node vao cuoi danh sach
void InsertLast(List &list, NhanVien nhan_vien){ 
  Node *pNode=CreateNode(nhan_vien);
  if(list.pTail==NULL){
    list.pTail=pNode;
  }
  else{
    list.pTail->pNext=pNode;
    list.pTail=pNode;
  }
}

  
// 4) Duyet danh sach
void PrintList(List list){
  Node *pTmp=list.pTail;
  if(pTmp==NULL){
    cout<<"The list is empty!";
    return;
  }
  while(pTmp!=NULL){
    cout << "Ma nhan vien: " << pTmp->nhan_vien.ma << endl;
    cout << "Ten nhan vien: " << pTmp->nhan_vien.ten << endl;
    cout << "Tuoi nhan vien: " << pTmp->nhan_vien.tuoi << endl;
    cout << "He so luong nhan vien: " << pTmp->nhan_vien.he_so_luong << endl;
    cout << pTmp->nhan_vien.ten << " " << pTmp->nhan_vien.ma;
    cout << "--------------------";
    pTmp=pTmp->pNext;
  }
}
  

// 5) Liet ke danh sach nhan vien > 60 tuoi
void PrintListWithCondition(List list){
  Node *pTmp=list.pTail;
  if(pTmp==NULL){
    cout<<"The list is empty!";
    return;
  }
  while(pTmp!=NULL){
    if (pTmp->nhan_vien.tuoi > 60){
        cout << "Ma nhan vien: " << pTmp->nhan_vien.ma << endl;
        cout << "Ten nhan vien: " << pTmp->nhan_vien.ten << endl;
        cout << "Tuoi nhan vien: " << pTmp->nhan_vien.tuoi << endl;
        cout << "He so luong nhan vien: " << pTmp->nhan_vien.he_so_luong << endl;
        cout << pTmp->nhan_vien.ten << " " << pTmp->nhan_vien.ma;
        cout << "--------------------";
    }
    pTmp=pTmp->pNext;
  }
}

// 6) sap xep danh sach  theo he so luong 
void SortList(List &list){
 for(Node *pTmp=list.pTail;pTmp!=NULL;pTmp=pTmp->pNext){
  for(Node *pTmp2=pTmp->pNext;pTmp2!=NULL;pTmp2=pTmp2->pNext){
    if(pTmp->nhan_vien.he_so_luong>pTmp2->nhan_vien.he_so_luong){
       NhanVien tmp=pTmp->nhan_vien;
       pTmp->nhan_vien=pTmp2->nhan_vien;
       pTmp2->nhan_vien=tmp;
    }
  }
 }
}

int main(){
    int n;
    List list; 
    Initialize(list);
    cout << "Nhap so luong nhan vien: "; cin >> n;
    for(int i=0;i<n;i++){
        NhanVien nhan_vien;
        cout << "Nhap ma nhan vien: "; cin >> nhan_vien.ma;
        cout << "Nhap ten nhan vien: "; cin >> nhan_vien.ten;
        cout << "Nhap tuoi nhan vien: "; cin >> nhan_vien.tuoi;
        cout << "Nhap he so luong nhan vien: "; cin >> nhan_vien.he_so_luong;
        InsertLast(list, nhan_vien);
    }
    PrintList(list);
    PrintListWithCondition(list);
    SortList(list);
    PrintList(list);

}
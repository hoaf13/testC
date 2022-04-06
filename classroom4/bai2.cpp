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
  
int main() {
    
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

struct MatHang {
    int ma;
    string ten; 
    string loai_hang; 
    int nam_san_xuat;
    string xuat_xu;
    double gia_ban;
};


struct Node{
  MatHang mat_hang;
  Node *pNext;
};
   

struct SingleList{
  Node *pTail; 
};
   
// 1) Khoi Tao Danh Sach
void Initialize(SingleList &list){
  list.pTail=NULL;
}

// 2) Tao 1 node chua du lieu
Node *CreateNode(MatHang mat_hang){
    Node *pNode=new Node; 
    if(pNode!=NULL){
       pNode->mat_hang=mat_hang; 
       pNode->pNext=NULL;
    }
    else {
      cout<<"Error allocated memory";
    }
    return pNode;
}
  
// 3) chen node vao cuoi danh sach
void InsertLast(SingleList &list, MatHang mat_hang){ 
  Node *pNode=CreateNode(mat_hang);
  if(list.pTail==NULL){
    list.pTail=pNode;
  }
  else{
    list.pTail->pNext=pNode;
    list.pTail=pNode;
  }
}


  
// 4) Duyet danh sach
void PrintList(SingleList list){
  Node *pTmp=list.pTail;
  if(pTmp==NULL){
    cout<<"The list is empty!";
    return;
  }
  while(pTmp!=NULL){
    cout << pTmp->mat_hang.ten << " " << pTmp->mat_hang.ma;
    pTmp=pTmp->pNext;
  }
}
  

int main(){


}
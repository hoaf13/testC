#include<bits/stdc++.h>

using namespace std; 

struct TaiLieu{
    int ma;
    string ten; 
    string loai;
    int nam_xuat_ban;
    string noi_xuat_ban;
};

struct Node{
  TaiLieu tai_lieu;
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
Node *CreateNode(TaiLieu tai_lieu){
    Node *pNode=new Node; 
    if(pNode!=NULL){
       pNode->tai_lieu=tai_lieu; 
       pNode->pNext=NULL;
    }
    else {
      cout<<"Error allocated memory";
    }
    return pNode;
}
  
// 3) chen node vao cuoi danh sach
void InsertLast(SingleList &list,TaiLieu tai_lieu){ 
  Node *pNode=CreateNode(tai_lieu);
  if(list.pTail==NULL){
    list.pTail=pNode;
  }
  else{
    list.pTail->pNext=pNode;
    list.pTail=pNode;
  }
}



// 4) Sap xep phan tu trong danh sach theo nam xuat ban
void SortList(SingleList &list){
 for(Node *pTmp=list.pTail;pTmp!=NULL;pTmp=pTmp->pNext){
  for(Node *pTmp2=pTmp->pNext;pTmp2!=NULL;pTmp2=pTmp2->pNext){
    if(pTmp->tai_lieu.nam_xuat_ban>pTmp2->tai_lieu.nam_xuat_ban){
       TaiLieu tmp=pTmp->tai_lieu;
       pTmp->tai_lieu=pTmp2->tai_lieu;
       pTmp2->tai_lieu=tmp;
    }
  }
 }
}

// 5) tim kiem phan tu trong danh sach theo ma tai lieu
Node * SearchNode(SingleList list,TaiLieu tai_lieu){
  Node *pTmp=list.pTail; 
  while(pTmp!=NULL){
    if(pTmp->tai_lieu.ma == tai_lieu.ma) 
      break; 
    pTmp=pTmp->pNext;
  }
  return pTmp;
}

 
  
// 6) Duyet danh sach
void PrintList(SingleList list){
  Node *pTmp=list.pTail;
  if(pTmp==NULL){
    cout<<"The list is empty!";
    return;
  }
  while(pTmp!=NULL){
    cout << pTmp->tai_lieu.ten << " " << pTmp->tai_lieu.ma;
    pTmp=pTmp->pNext;
  }
}
  
int main() {
 
    
    return 0;
}
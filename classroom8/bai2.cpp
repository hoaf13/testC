#include<bits/stdc++.h>

using namespace std;

struct CongTrinh{
    int ma;
    string ten;
    string quy_mo;
    double chi_phi;
};


struct Node{
  CongTrinh cong_trinh;
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
Node *CreateNode(CongTrinh cong_trinh){
    Node *pNode=new Node; 
    if(pNode!=NULL){
       pNode->cong_trinh=cong_trinh; 
       pNode->pNext=NULL;
    }
    else {
      cout<<"Error allocated memory";
    }
    return pNode;
}
  
// 3) chen node vao dau danh sach
void InsertFirst(SingleList &list,CongTrinh cong_trinh){
  Node *pNode=CreateNode(cong_trinh);
  if(list.pHead==NULL){
    list.pHead=list.pTail=pNode;
  }
  else{
    pNode->pNext=list.pHead;
    list.pHead=pNode;
  }
}

// 4) Duyet danh sach
void PrintList(SingleList list){
  Node *pTmp=list.pHead;
  if(pTmp==NULL){
    cout<<"The list is empty!";
    return;
  }
  while(pTmp!=NULL){
    cout << pTmp->cong_trinh.ten << " " << pTmp->cong_trinh.ma;
    pTmp=pTmp->pNext;
  }
}
  

int main(){


}
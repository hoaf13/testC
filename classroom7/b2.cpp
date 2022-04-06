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


// 5) Duyet Danh Sach
void PrintList(SingleList list){
  Node *pTmp=list.pHead;
  if(pTmp==NULL){
    cout<<"The list is empty!";
    return;
  }
  while(pTmp!=NULL){
    cout << "Ma con trinh: " << pTmp->cong_trinh.ma << endl;
    cout << "Ten cong trinh: " << pTmp->cong_trinh.ten << endl;
    cout << "Quy mo cong trinh: " << pTmp->cong_trinh.quy_mo << endl;
    cout << "Tong kinh phi: " << pTmp->cong_trinh.chi_phi << endl;
    pTmp=pTmp->pNext;
  }
}

int main(){
    
}
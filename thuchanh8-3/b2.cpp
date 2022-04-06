#include<bits/stdc++.h>

using namespace std; 

struct DuAn {
    int ma;
    string ten;
    string quy_mo;
    double kinh_phi;
};


struct Node{
  DuAn du_an;
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
Node *CreateNode(DuAn du_an){
    Node *pNode=new Node; 
    if(pNode!=NULL){
       pNode->du_an=du_an; 
       pNode->pNext=NULL;
    }
    else {
      cout<<"Error allocated memory";
    }
    return pNode;
}
  
// 3) chen node vao dau danh sach
void InsertFirst(SingleList &list,DuAn du_an){
  Node *pNode=CreateNode(du_an);
  if(list.pHead==NULL){
    list.pHead=list.pTail=pNode;
  }
  else{
    pNode->pNext=list.pHead;
    list.pHead=pNode;
  }
}

// 4) xoa node khoi danh sach theo ma du an 
void RemoveNode(SingleList &list, DuAn du_an){
  Node *pDel = list.pHead; 
  if(pDel == NULL){
    cout<<"Danh sách rỗng!!";
  }
  else{
    Node *pPre = NULL;
    while(pDel != NULL){
      if(pDel -> du_an.ma == du_an.ma){
        break;
      }
      pPre = pDel;
      pDel = pDel -> pNext;
    }
    if(pDel == NULL){
      cout<<"Không tìm thấy số cần xóa";
    }
    else{
      if(pDel == list.pHead){
        list.pHead = list.pHead -> pNext;
        pDel -> pNext = NULL;
        delete pDel;
        pDel = NULL;
      }
      else if(pDel -> pNext == NULL){
        list.pTail = pPre;
        pPre -> pNext = NULL;
        delete pDel;
        pDel = NULL;
      }
      else{
        pPre -> pNext = pDel -> pNext;
        pDel -> pNext = NULL;
        delete pDel;
        pDel = NULL; 
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
    cout << pTmp->du_an.ten << " " << pTmp->du_an.ma;
    pTmp=pTmp->pNext;
  }
}

int main(){
    
}
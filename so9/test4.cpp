#include<bits/stdc++.h>

using namespace std;

struct MonHoc{
    char ID[6];
    char ten[50];
    int  so_tc;
    char khoa_ql[50];
    int hoc_ky;
};

void nhap(MonHoc *mon_hoc){
    char _;
    cout << "Nhap ma mon hoc: ";
    cin.getline(mon_hoc->ID, 6);
    cout << mon_hoc->ID << endl;

    cout << "Nhap ten mon hoc: ";
    cin.getline(mon_hoc->ten, 50);
    cout << mon_hoc->ten << endl;

    cout << "Nhap so tin chi mon hoc: ";
    cin >> mon_hoc->so_tc;
    cin.ignore();

    cout << "Nhap khoa ql: ";
    cin.get(mon_hoc->khoa_ql, 50);
    
    cout << "Nhap hoc ki: ";
    cin >> mon_hoc->hoc_ky;
    
    cout << "-----------------------";
}

void xuat(MonHoc *mon_hoc){
    cout << "Ma mon hoc: ";
    cout << mon_hoc->ID << endl;
    cout << "Ten mon hoc: ";
    cout << mon_hoc->ten << endl;
    cout << "So tin chi mon hoc: ";
    cout << mon_hoc->so_tc << endl;
    cout << "Khoa ql: ";
    cout << mon_hoc->khoa_ql << endl;
    cout << "Hoc ki: ";
    cout << mon_hoc->hoc_ky << endl;
}

struct Node{
  MonHoc mon_hoc;
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
Node *CreateNode(MonHoc mon_hoc){
    Node *pNode=new Node; 
    if(pNode!=NULL){
       pNode->mon_hoc=mon_hoc; 
       pNode->pNext=NULL;
    }
    else {
      cout<<"Error allocated memory";
    }
    return pNode;
}
  
// 3) chen node vao dau danh sach
void InsertFirst(SingleList &list,MonHoc mon_hoc){
  Node *pNode=CreateNode(mon_hoc);
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
    if (pTmp->mon_hoc.khoa_ql == "Cong Nghe Thong Tin"){
        MonHoc mon_hoc = pTmp->mon_hoc;
        xuat(&mon_hoc);
    }
    pTmp=pTmp->pNext;
  }
}

// 5) Sap xep phan tu trong danh sach mon hoc theo hoc ki tang dan
void SortList(SingleList &list){
 for(Node *pTmp=list.pHead;pTmp!=NULL;pTmp=pTmp->pNext){
  for(Node *pTmp2=pTmp->pNext;pTmp2!=NULL;pTmp2=pTmp2->pNext){
    if(pTmp->mon_hoc.hoc_ky > pTmp2->mon_hoc.hoc_ky){
       MonHoc tmp=pTmp->mon_hoc;
       pTmp->mon_hoc=pTmp2->mon_hoc;
       pTmp2->mon_hoc=tmp;
    }
  }
 }
}

int main(){ 
    SingleList list;
    Initialize(list);
    int n;
    cout << "Nhap so luong mon hoc:"; 
    cin >> n;
    for(int i=0;i<n;i++){
        MonHoc mon_hoc;
        nhap(&mon_hoc);
        InsertFirst(list, mon_hoc);
    }
    SortList(list);
    PrintList(list);
}
#include <iostream>
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
  Node *pHead; 
  Node *pTail; 
};
   
// 1) Khoi Tao Danh Sach
void Initialize(SingleList &list){
  list.pHead=list.pTail=NULL;
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
    list.pHead=list.pTail=pNode;
  }
  else{
    list.pTail->pNext=pNode;
    list.pTail=pNode;
  }
}
  

// 5) Sap xep phan tu trong danh sach tai lieu theo ma tai lieu giam dan 
void SortList(SingleList &list){
 for(Node *pTmp=list.pHead;pTmp!=NULL;pTmp=pTmp->pNext){
  for(Node *pTmp2=pTmp->pNext;pTmp2!=NULL;pTmp2=pTmp2->pNext){
    if(pTmp->tai_lieu.nam_xuat_ban>pTmp2->tai_lieu.nam_xuat_ban){
       TaiLieu tmp=pTmp->tai_lieu;
       pTmp->tai_lieu=pTmp2->tai_lieu;
       pTmp2->tai_lieu=tmp;
    }
  }
 }
}
 
  
// 6) Duyet danh sach
void PrintList(SingleList list){
  Node *pTmp=list.pHead;
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
    SingleList list;
    Initialize(list);
    int n;
    cout << "Nhap so luong tai lieu: " << endl; 
    cin >> n;
    for(int i=0;i<n;i++){
        TaiLieu tai_lieu; 
        cout << "Nhap ma tai lieu: " << endl;
        cin >> tai_lieu.ma;
        cout << "Nhap ten tai lieu: " << endl;
        cin >> tai_lieu.ten;
        cout << "Nhap loai tai lieu: " << endl;
        cin >> tai_lieu.loai;
        cout << "Nhap nam xuat ban: " << endl;
        cin >> tai_lieu.nam_xuat_ban;
        cout << "Nhap noi xuat ban: " << endl;
        cin >> tai_lieu.noi_xuat_ban;
        InsertLast(tai_lieu);
    }
    PrintList(list);
    SortList(list);
    PrintList(list);
    return 0;
}
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
  Node *pHead; 
  Node *pTail; 
};
   
// 1) Khoi Tao Danh Sach
void Initialize(SingleList &list){
  list.pHead=list.pTail=NULL;
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
void InsertLast(SingleList &list,MatHang mat_hang){ 
  Node *pNode=CreateNode(mat_hang);
  if(list.pTail==NULL){
    list.pHead=list.pTail=pNode;
  }
  else{
    list.pTail->pNext=pNode;
    list.pTail=pNode;
  }
}

// 4) Duyet Danh Sach
void PrintList(SingleList list){
  Node *pTmp=list.pHead;
  if(pTmp==NULL){
    cout<<"The list is empty!";
    return;
  }
  while(pTmp!=NULL){
    if (pTmp->mat_hang.loai_hang == "gia dung" && pTmp->mat_hang.gia_ban >= 500000 && pTmp->mat_hang.gia_ban <= 1000000){        
        cout << "Ma mat hang: " << pTmp->mat_hang.ma << endl;
        cout << "Ten mat hang: " << pTmp->mat_hang.ten << endl;
        cout << "Loai mat hang: " << pTmp->mat_hang.loai_hang << endl;
        cout << "Nam san xuat: " << pTmp->mat_hang.nam_san_xuat << endl;
        cout << "Xuat xu: " << pTmp->mat_hang.xuat_xu << endl;
        cout << "Gia ban: " << pTmp->mat_hang.gia_ban << endl;
        cout << "----------------------------------" << endl;
    }
    pTmp=pTmp->pNext;
  }
}
  

int main(){

    SingleList list;
    Initialize(list);
    int n;
    cout << "Nhap so luong mat hang: " << endl; 
    cin >> n;
    for(int i=0;i<n;i++){
        MatHang mat_hang;
        cout << "Nhap ma mat hang: " << endl;
        cin >> mat_hang.ma;
        cout << "Nhap ten mat hang: " << endl;
        cin >> mat_hang.ten;
        cout << "Nhap loai mat hang: " << endl;
        cin >> mat_hang.loai_hang;
        cout << "Nhap nam san xuat: " << endl;
        cin >> mat_hang.nam_san_xuat;
        cout << "Nhap noi xuat xu: " << endl;
        cin >> mat_hang.xuat_xu;
        cout << "Nhap gia ban: " << endl;
        cin >> mat_hang.gia_ban;
        InsertLast(list, mat_hang);
    }
    PrintList(list);

}
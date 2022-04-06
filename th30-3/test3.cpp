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
   

struct DoubleList{
  Node *pHead; 
  Node *pTail; 
};
   
// 1) Khoi Tao Danh Sach
void Initialize(DoubleList &list){
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
void InsertLast(DoubleList &list,MatHang mat_hang){ 
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
void PrintList(DoubleList list){
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

// 5) Duyet Danh Sach cac mat hang co gia ban tu 500000 - 1000000
void PrintListWithCondition1(DoubleList list){
  Node *pTmp=list.pHead;
  if(pTmp==NULL){
    cout<<"The list is empty!";
    return;
  }
  while(pTmp!=NULL){
    if (pTmp->mat_hang.gia_ban >= 500000 && pTmp->mat_hang.gia_ban <= 1000000){        
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

// 6) Xoa mat hang xuat xu khoi danh sach
void RemoveFromList(DoubleList list){
    Node *pDel = list.pHead; 
  if(pDel == NULL){
    cout<<"Danh sách rỗng!!";
  }
  else{
    Node *pPre = NULL;
    while(pDel != NULL){
      if(pDel -> mat_hang.xuat_xu == "Trung Quoc"){
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

int main(){

    DoubleList list;
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
    PrintListWithCondition1(list);

    RemoveFromList(list);
    PrintList(list);
}
#include<bits/stdc++.h>

using namespace std;

struct date{
    int ngay , thang , nam;
};

struct MonAn{
    char ID[6];
    char ten[50];
    date ngay_sx;
    int han_sd;
    float gia;
};

void nhap(MonAn *mon_an){
    char _;
    cout << "Nhap ma mon an: ";
    cin.getline(mon_an->ID, 6);
    cout << mon_an->ID << endl;

    cout << "Nhap ten mon an: ";
    cin.getline(mon_an->ten, 50);
    cout << mon_an->ten << endl;

    date d;
    cout << "Nhap ngay san xuat: ";
    cin >>d.ngay;
    cout << "Nhap thang san xuat: ";
    cin >>d.thang;
    cout << "Nhap nam san xuat: ";
    cin >>d.nam;
    mon_an->ngay_sx = d;

    cout << "Nhap han su dung: ";
    cin >> mon_an->han_sd;
    
    cout << "Nhap gia thanh mon an: ";
    cin >> mon_an->gia;
}

void xuat(MonAn *mon_an){
    cout << "Ma mon an: ";
    cout << mon_an->ID << endl;
    cout << "Ten mon an: ";
    cout << mon_an->ten << endl;
    cout << "Ngay thang nam sinh: ";
    cout << mon_an->ngay_sx.ngay << " " << mon_an->ngay_sx.thang << " " << mon_an->ngay_sx.nam << endl;
    cout << "Han su dung: ";
    cout << mon_an->han_sd << endl;
    cout << "Gia: ";
    cout << mon_an->gia << endl;
}


struct Node{
  MonAn mon_an;
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
Node *CreateNode(MonAn mon_an){
    Node *pNode=new Node; 
    if(pNode!=NULL){
       pNode->mon_an=mon_an; 
       pNode->pNext=NULL;
    }
    else {
      cout<<"Error allocated memory";
    }
    return pNode;
}
  
// 3) chen node vao dau danh sach
void InsertFirst(SingleList &list,MonAn mon_an){
  Node *pNode=CreateNode(mon_an);
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
    MonAn mon_an;
    mon_an = pTmp->mon_an;
    xuat(&mon_an);
    pTmp=pTmp->pNext;
  }
}

// 5) Hien thi thong tin day du cac mon an san xuat ngay “05/10/2019”.
void PrintList2(SingleList list){
  Node *pTmp=list.pHead;
  if(pTmp==NULL){
    cout<<"The list is empty!";
    return;
  }
  while(pTmp!=NULL){
    MonAn mon_an;
    mon_an = pTmp->mon_an;
    if (mon_an.ngay_sx.ngay == 05 && mon_an.ngay_sx.thang == 10 && mon_an.ngay_sx.nam == 2019){
        xuat(&mon_an);
    }
    
    pTmp=pTmp->pNext;
  }
}

int main(){ 
    SingleList list;
    Initialize(list);
    cout << "Nhap so luong mon an: " << endl;
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        MonAn mon_an;
        nhap(&mon_an);    
        InsertFirst(list, mon_an);
    }
    PrintList(list);
    PrintList2(list);
}
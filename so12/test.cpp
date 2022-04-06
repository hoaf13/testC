#include<bits/stdc++.h>

using namespace std; 

struct date{
    int ngay, thang, nam;
};

struct Hang{
    char ID[6];
    char ten[256];
    date ngay_xuat;
    float gia_xuat;
};


struct Node{
  Hang hang;
  Node *pNext;
};
   

void nhap(Hang *hang){
    char _;
    cout << "Nhap ma hang: ";
    cin.getline(hang->ID, 6);
    cout << hang->ID << endl;

    cout << "Nhap ten hang: ";
    cin.getline(hang->ten, 50);
    cout << hang->ten << endl;

    date d;
    cout << "Nhap ngay san xuat: ";
    cin >>d.ngay;
    cout << "Nhap thang san xuat: ";
    cin >>d.thang;
    cout << "Nhap nam san xuat: ";
    cin >>d.nam;

    cin.ignore();
    cout << "Nhap gia xuat: ";
    cin >> hang->gia_xuat;
}

void xuat(Hang *hang){
    cout << "Ma hang: ";
    cout << hang->ID << endl;
    cout << "Ten hang: ";
    cout << hang->ten << endl;
    cout << "Ngay thang nam sinh: ";
    cout << hang->ngay_xuat.ngay << " " << hang->ngay_xuat.thang << " " << hang->ngay_xuat.nam << endl;
    cout << "Gia xuat: ";
    cout << hang->gia_xuat << endl;
}



struct Queue{
  Node *pHead; 
  Node *pTail; 
};

// 1) Khoi Tao Danh Sach
void Initialize(Queue &list){
  list.pHead=list.pTail=NULL;
}

// 2) Tao 1 node chua du lieu
Node *CreateNode(Hang hang){
    Node *pNode=new Node; 
    if(pNode!=NULL){
       pNode->hang=hang; 
       pNode->pNext=NULL;
    }
    else {
      cout<<"Error allocated memory";
    }
    return pNode;
}
  
// 3) chen node vao dau danh sach
void InsertLast(Queue &list,Hang hang){
  Node *pNode=CreateNode(hang);
  if(list.pTail==NULL){
    list.pHead=list.pTail=pNode;
  }
  else{
    pNode->pNext=list.pTail;
    list.pTail = pNode;
  }
}

// 4) Duyet danh sach
void PrintList(Queue list){
  Node *pTmp=list.pHead;
  if(pTmp==NULL){
    cout<<"The list is empty!";
    return;
  }
  while(pTmp!=NULL){
    Hang hang;
    hang = pTmp->hang;
    xuat(&hang);
    pTmp=pTmp->pNext;
  }
}

// 5) Duyet danh sach truong ID la 001
void PrintListWithCondition(Queue list){
  Node *pTmp=list.pHead;
  if(pTmp==NULL){
    cout<<"The list is empty!";
    return;
  }
  while(pTmp!=NULL){
    Hang hang;
    hang = pTmp->hang;
    if (hang.ID == "001") xuat(&hang);
    pTmp=pTmp->pNext;
  }
}

int main(){
    Queue queue;
    Initialize(queue);
    int n;
    cout << "Nhap so luong hang hoa: "; cin >> n;
    for(int i=0;i<n;i++){
        Hang hang;
        cout << "Nhap ID: "; cin >> hang.ID;
        cout << "Nhap ten: "; cin >> hang.ten;
        cout << "Nhap ngay: "; cin >> hang.ngay_xuat.ngay;
        cout << "Nhap thang: "; cin >> hang.ngay_xuat.thang;
        cout << "Nhap nam: "; cin >> hang.ngay_xuat.nam;
        cout << "Gia xuat: "; cin >> hang.gia_xuat;
        cout << "---------";
        InsertLast(queue, hang);
    }
    PrintList(queue);
    PrintListWithCondition(queue);
}
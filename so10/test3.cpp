#include<bits/stdc++.h>

using namespace std;

struct date{
    int ngay , thang , nam;
};

struct CongNhan{
    char ID[6];
    char ten[50];
    date ngay_sinh;
    char que_quan[100];
    float luong;
};

struct Node{
  CongNhan cong_nhan;
  Node *pNext;
};
   

void nhap(CongNhan *cong_nhan){
    char _;
    cout << "Nhap ma cong nhan: ";
    cin.getline(cong_nhan->ID, 6);
    cout << cong_nhan->ID << endl;

    cout << "Nhap ten cong nhan: ";
    cin.getline(cong_nhan->ten, 50);
    cout << cong_nhan->ten << endl;

    date d;
    cout << "Nhap ngay sinh: ";
    cin >>d.ngay;
    cout << "Nhap thang sinh: ";
    cin >>d.thang;
    cout << "Nhap nam sinh: ";
    cin >>d.nam;

    cin.ignore();
    cout << "Nhap que quan: ";
    cin.get(cong_nhan->que_quan, 50);
    
    cout << "Nhap luong cong nhan: ";
    cin >> cong_nhan->luong;
}

void xuat(CongNhan *cong_nhan){
    cout << "Ma cong nhan: ";
    cout << cong_nhan->ID << endl;
    cout << "Ten cong nhan: ";
    cout << cong_nhan->ten << endl;
    cout << "Ngay thang nam sinh: ";
    cout << cong_nhan->ngay_sinh.ngay << " " << cong_nhan->ngay_sinh.thang << " " << cong_nhan->ngay_sinh.nam << endl;
    cout << "que quan: ";
    cout << cong_nhan->que_quan << endl;
    cout << "luong: ";
    cout << cong_nhan->luong << endl;
}


struct SingleList{
  Node *pHead; 
  Node *pTail; 
};

// 1) Khoi Tao Danh Sach
void Initialize(SingleList &list){
  list.pHead=list.pTail=NULL;
}

// 2) Tao 1 node chua du lieu
Node *CreateNode(CongNhan cong_nhan){
    Node *pNode=new Node; 
    if(pNode!=NULL){
       pNode->cong_nhan=cong_nhan; 
       pNode->pNext=NULL;
    }
    else {
      cout<<"Error allocated memory";
    }
    return pNode;
}
  
// 3) chen node vao dau danh sach
void InsertFirst(SingleList &list,CongNhan cong_nhan){
  Node *pNode=CreateNode(cong_nhan);
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
    CongNhan cong_nhan;
    cong_nhan = pTmp->cong_nhan;
    xuat(&cong_nhan);
    pTmp=pTmp->pNext;
  }
}

// 5) Sap xep danh sach cong nhan theo luong tang dan
void SortList(SingleList &list){
 for(Node *pTmp=list.pHead;pTmp!=NULL;pTmp=pTmp->pNext){
  for(Node *pTmp2=pTmp->pNext;pTmp2!=NULL;pTmp2=pTmp2->pNext){
    if(pTmp->cong_nhan.luong > pTmp2->cong_nhan.luong){
       CongNhan tmp=pTmp->cong_nhan;
       pTmp->cong_nhan=pTmp2->cong_nhan;
       pTmp2->cong_nhan=tmp;
    }
  }
 }
}

int main(){
    SingleList list;
    Initialize(list);
    int n; 
    cout << "Nhap so luong cong nhan: "; 
    cin >> n;
    for(int i=0;i<n;i++){
        CongNhan cong_nhan;
        nhap(&cong_nhan);
        InsertFirst(list, cong_nhan);
    }       
    PrintList(list);

    SortList(list);
    PrintList(list);
}
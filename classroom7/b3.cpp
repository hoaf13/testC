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


struct Node{
  CongTrinh cong_trinh;
  Node *pNext;
};
   

struct SingleList{
  Node *pTail; 
};
   
// 1) Khoi Tao Danh Sach
void Initialize(SingleList &list){
  list.pTail=NULL;
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
  
// 3) chen node vao cuoi danh sach
void InsertLast(SingleList &list, CongTrinh cong_trinh){ 
  Node *pNode=CreateNode(cong_trinh);
  if(list.pTail==NULL){
    list.pTail=pNode;
  }
  else{
    list.pTail->pNext=pNode;
    list.pTail=pNode;
  }
}


  
// 4) Duyet danh sach
void PrintList(SingleList list){
  Node *pTmp=list.pTail;
  if(pTmp==NULL){
    cout<<"The list is empty!";
    return;
  }
  while(pTmp!=NULL){
    cout << pTmp->cong_trinh.ten << " " << pTmp->cong_trinh.ma;
    pTmp=pTmp->pNext;
  }
}

// Hien thi con trinh co kinh phi tu 5000 - 10.000 ty

void PrintListInCondition(SingleList list){
    Node *pTmp=list.pTail;
    if(pTmp==NULL){
        cout<<"The list is empty!";
        return;
    }
    while(pTmp!=NULL){
        if (pTmp->cong_trinh.chi_phi >= 5000 && pTmp->cong_trinh.chi_phi <= 10000){
            cout << pTmp->cong_trinh.ma << endl;
            cout << pTmp->cong_trinh.ten << endl;
            cout << pTmp->cong_trinh.quy_mo << endl;
            cout << pTmp->cong_trinh.chi_phi << endl;
        }
        pTmp=pTmp->pNext;
    } 
}


int main(){
    SingleList list;
    Initialize(list);
    int n;
    cout << "Nhap so luong cong trinh: " << endl;
    cin >> n;
    for(int i=0;i<n;i++){
        CongTrinh cong_trinh;
        cout << "Nhap ma cong trinh: " << endl; 
        cin >> cong_trinh.ma;
        cout << "Nhap ten cong trinh: " << endl; 
        cin >> cong_trinh.ten;
        cout << "Nhap quy mo cong trinh: " << endl; 
        cin >> cong_trinh.quy_mo;
        cout << "Nhap kinh phi cong trinh: " << endl; 
        cin >> cong_trinh.chi_phi;
        InsertLast(list, cong_trinh);
    }
    PrintList(list);
    PrintListInCondition(list);
    return 0;
}
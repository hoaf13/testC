#include <iostream>
using namespace std;

struct KhachHang {
    int ma;
    string ten;
    string dia_chi;
    string sdt;
    double tong_tien;
};

struct Node{
  KhachHang khach_hang;
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
Node *CreateNode(KhachHang khach_hang){
    Node *pNode=new Node; 
    if(pNode!=NULL){
       pNode->khach_hang=khach_hang; 
       pNode->pNext=NULL;
    }
    else {
      cout<<"Error allocated memory";
    }
    return pNode;
}
  
// 3) chen node vao cuoi danh sach
void InsertLast(SingleList &list,KhachHang khach_hang){ 
  Node *pNode=CreateNode(khach_hang);
  if(list.pTail==NULL){
    list.pHead=list.pTail=pNode;
  }
  else{
    list.pTail->pNext=pNode;
    list.pTail=pNode;
  }
}
  

// 4) tim kiem phan tu trong danh sach
Node * SearchNode(SingleList list,KhachHang khach_hang){
  Node *pTmp=list.pHead; 
  while(pTmp!=NULL){
    if(pTmp->khach_hang==khach_hang) 
      break; 
    pTmp=pTmp->pNext;
  }
  return pTmp;
}

// 5) Sap xep phan tu trong danh sach theo thu tu giam dan  
void SortList(SingleList &list){
 for(Node *pTmp=list.pHead;pTmp!=NULL;pTmp=pTmp->pNext){
  for(Node *pTmp2=pTmp->pNext;pTmp2!=NULL;pTmp2=pTmp2->pNext){
    if(pTmp->khach_hang.tong_tien>pTmp2->khach_hang.tong_tien){
       KhachHang tmp=pTmp->khach_hang;
       pTmp->khach_hang=pTmp2->khach_hang;
       pTmp2->khach_hang=tmp;
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
    cout << pTmp->khach_hang.ten << " " << pTmp->khach_hang.ma;
    pTmp=pTmp->pNext;
  }
}

// 6) hien thi khach hang tai ha noi 
void PrintListHaNoi(SingleList list){
  Node *pTmp=list.pHead;
  if(pTmp==NULL){
    cout<<"The list is empty!";
    return;
  }
  while(pTmp!=NULL){
    if (pTmp->khach_hang.dia_chi == "Ha Noi"){
        cout << "ma: " << pTmp->khach_hang.ma << endl;
        cout << "ho ten: " << pTmp->khach_hang.ten << endl;
        cout << "dia chi: " << pTmp->khach_hang.dia_chi << endl;
        cout << "so dien thoai: " << pTmp->khach_hang.sdt << endl;
        cout << "tong tien: " << pTmp->khach_hang.tong_tien << endl;
    }
    pTmp=pTmp->pNext;
  }
}



int n; 

int main() {

    SingleList list;
    Initialize(list);

    cout << "Nhap so luong khach hang: " << endl; 
    cin >> n;

    for(int i=0;i<n;i++){
        KhachHang khach_hang;
        cout << "nhap ma khach hang: " << endl;
        cin >> khach_hang.ma;
        cout << "nhap ten khach hang: " << endl;
        cin >> khach_hang.ten;
        cout << "nhap dia chi: " << endl;
        cin >> khach_hang.dia_chi;
        cout << "nhap sdt: " << endl;
        cin >> khach_hang.sdt;
        cout << "nhap tong tien: " << endl;
        cin >> khach_hang.tong_tien;
        // them khach hang vao cuoi danh sach 
        InsertLast(list, khach_hang);
    }       
    // hien thi danh sach da nhap
    PrintList(list);    

    // hien thi danh sach khach hang tai ha noi 
    PrintListHaNoi(list);
    
    // Sap xep theo tong tien thanh toan giam dan
    SortList(list);
    // hien thi danh sach sau khi sap xep
    PrintList(list);
    
    return 0;
}

#include<bits/stdc++.h>

using namespace std; 

struct CongTrinh{
    int ma;
    string ten;
    string quy_mo;
    double kinh_phi;
};



struct Node{
  CongTrinh cong_trinh;
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
  
// 3) chen node vao dau danh sach
void InsertFirst(SingleList &list,CongTrinh cong_trinh){
  Node *pNode=CreateNode(cong_trinh);
  if(list.pHead==NULL){
    list.pHead=list.pTail=pNode;
  }
  else{
    pNode->pNext=list.pHead;
    list.pHead=pNode;
  }
}

// 4) xoa node khoi danh sach theo ma du an 
void RemoveNode(SingleList &list, CongTrinh cong_trinh){
  Node *pDel = list.pHead; 
  if(pDel == NULL){
    cout<<"Danh sách rỗng!!";
  }
  else{
    Node *pPre = NULL;
    while(pDel != NULL){
      if(pDel -> cong_trinh.ma == cong_trinh.ma){
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
        if (pTmp->cong_trinh.kinh_phi >= 5000 && pTmp->cong_trinh.kinh_phi <= 10000){
            cout << pTmp->cong_trinh.ma << endl;
            cout << pTmp->cong_trinh.ten << endl;
            cout << pTmp->cong_trinh.quy_mo << endl;
            cout << pTmp->cong_trinh.kinh_phi << endl;
        }
        pTmp=pTmp->pNext;
    } 
}

int main(){
    SingleList list;
    Initialize(list);
    int n; 
    cout << "Nhap so luong du an: "; 
    cin >> n;
    for(int i=0;i<n;i++){
        CongTrinh cong_trinh;
        cout << "Nhap thong tin Du An so: " << i+1 << endl;
        cout << "Nhap ma du an: " << endl;
        cin >> cong_trinh.ma;
        cout << "Nhap ten du an: " << endl;
        cin >> cong_trinh.ten;
        cout << "Nhap quy mo du an: " << endl;
        cin >> cong_trinh.quy_mo;
        cout << "Nhap kinh phi du an: " << endl;
        cin >> cong_trinh.kinh_phi;
        InsertFirst(list, cong_trinh);
    }       
    PrintList(list);
    PrintListInCondition(list);

    cout << "nhap vao du an bat ki va kiem tra da co trong danh sach chua" << endl;
    CongTrinh cong_trinh;
    cout << "Nhap ma du an: " << endl;
    cin >> cong_trinh.ma;
    cout << "Nhap ten du an: " << endl;
    cin >> cong_trinh.ten;
    cout << "Nhap quy mo du an: " << endl;
    cin >> cong_trinh.quy_mo;
    cout << "Nhap kinh phi du an: " << endl;
    cin >> cong_trinh.kinh_phi;
    RemoveNode(list, cong_trinh);
    PrintList(list);

}
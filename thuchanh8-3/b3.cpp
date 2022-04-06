#include<bits/stdc++.h>

using namespace std; 

struct DuAn {
    int ma;
    string ten;
    string quy_mo;
    double kinh_phi;
};


struct Node{
  DuAn du_an;
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
Node *CreateNode(DuAn du_an){
    Node *pNode=new Node; 
    if(pNode!=NULL){
       pNode->du_an=du_an; 
       pNode->pNext=NULL;
    }
    else {
      cout<<"Error allocated memory";
    }
    return pNode;
}
  
// 3) chen node vao dau danh sach
void InsertFirst(SingleList &list,DuAn du_an){
  Node *pNode=CreateNode(du_an);
  if(list.pHead==NULL){
    list.pHead=list.pTail=pNode;
  }
  else{
    pNode->pNext=list.pHead;
    list.pHead=pNode;
  }
}

// 4) xoa node khoi danh sach theo ma du an 
void RemoveNode(SingleList &list, DuAn du_an){
  Node *pDel = list.pHead; 
  if(pDel == NULL){
    cout<<"Danh sách rỗng!!";
  }
  else{
    Node *pPre = NULL;
    while(pDel != NULL){
      if(pDel -> du_an.ma == du_an.ma){
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
    
    cout << pTmp->du_an.ten << " " << pTmp->du_an.ma;
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
        if (pTmp->du_an.kinh_phi >= 5000 && pTmp->du_an.kinh_phi <= 10000){
            cout << pTmp->du_an.ma << endl;
            cout << pTmp->du_an.ten << endl;
            cout << pTmp->du_an.quy_mo << endl;
            cout << pTmp->du_an.kinh_phi << endl;
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
        DuAn du_an;
        cout << "Nhap thong tin Du An so: " << i+1 << endl;
        cout << "Nhap ma du an: " << endl;
        cin >> du_an.ma;
        cout << "Nhap ten du an: " << endl;
        cin >> du_an.ten;
        cout << "Nhap quy mo du an: " << endl;
        cin >> du_an.quy_mo;
        cout << "Nhap kinh phi du an: " << endl;
        cin >> du_an.kinh_phi;
        InsertFirst(list, du_an);
    }       
    PrintList(list);
    PrintListInCondition(list);

    cout << "nhap vao du an bat ki va kiem tra da co trong danh sach chua" << endl;
    DuAn du_an;
    cout << "Nhap ma du an: " << endl;
    cin >> du_an.ma;
    cout << "Nhap ten du an: " << endl;
    cin >> du_an.ten;
    cout << "Nhap quy mo du an: " << endl;
    cin >> du_an.quy_mo;
    cout << "Nhap kinh phi du an: " << endl;
    cin >> du_an.kinh_phi;
    RemoveNode(list, du_an);
    PrintList(list);

}
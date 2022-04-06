#include<bits/stdc++.h>

using namespace std;

struct PhanSo {
    int tu;
    int mau;
};

struct Stack
{
    PhanSo phan_so;
    Stack *next;
};

Stack *TOS = NULL;  // 1) Khoi Tao
 
bool is_stack_empty(){    // 2) Kiem tra rong
    if (TOS == NULL){
        return true;
    }
    return false;
}

void Push(PhanSo phan_so)   // 4) dua 1 phan so vao ngan xep
{
    Stack *new_node = new Stack();
    new_node -> phan_so = phan_so;
    new_node -> next = TOS;
    TOS = new_node;
}
 
void Pop() // 5) lay mot phan tu ra khoi ngan xep
{
    if(TOS == NULL)
        cout << "Stack is empty" << endl;
    else
    {
        Stack *temp;
        temp = TOS;
        TOS = TOS -> next;
        temp -> next = NULL;
        delete temp;
    }
}

int ucln(int a, int b){
    int r;
    while (a%b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return b;
}

void Print_Stack()
{
    if(TOS == NULL)
        cout << "Stack is empty" << endl;
    else
    {
        PhanSo tong = TOS -> phan_so;
        cout << "Top of stack is " << TOS -> phan_so.tu << "/" << TOS->phan_so.mau << endl;
        if(TOS -> next != NULL)
        {
            cout << "Other Elements are : ";
            Stack *current = TOS -> next;
            while(current)
            {
                cout << current -> phan_so.tu << "/" << current->phan_so.mau << endl;
                tong.tu = tong.tu*current->phan_so.mau + tong.mau*current->phan_so.tu;
                tong.mau = tong.mau*current->phan_so.mau;
                int z = ucln(tong.tu, tong.mau);
                tong.tu /=z;
                tong.mau /=z;
                current = current -> next;
            }
            cout << endl;
        }
        cout << "Tong cac phan so la: " << tong.tu << "/" << tong.mau << endl; 
    }
}

int main(){
    cout << "Nhap so luong phan so: ";
    int n;
    cin >> n; 
    for(int i=0;i<n;i++){
        PhanSo phan_so;
        cout << "Nhap tu so: "; cin >> phan_so.tu;
        cout << "Nhap mau so: "; cin >> phan_so.mau;
        cout << "------" << endl;
        Push(phan_so);    
    }
    Print_Stack();
}
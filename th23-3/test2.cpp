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
 
void Print_Stack()
{
    if(TOS == NULL)
        cout << "Stack is empty" << endl;
    else
    {
        cout << "Top of stack is " << TOS -> phan_so.tu << "/" << TOS->phan_so.mau << endl;
        if(TOS -> next != NULL)
        {
            cout << "Other Elements are : ";
            Stack *current = TOS -> next;
            while(current)
            {
                cout << current -> phan_so.tu << "/" << current->phan_so.mau << endl;
                current = current -> next;
            }
 
            cout << endl;
        }
    }
}

int main(){
    bool empty_flag = is_stack_empty();
    cout << "Is stack empty ? " << endl;
    if (empty_flag == false){
        cout << "No";
    }else{
        cout << "Yes";
    }
    PhanSo phan_so = {3,4};
    Push(phan_so);
    Print_Stack();
    empty_flag = is_stack_empty();
    cout << "Is stack empty ? " << endl;
    if (empty_flag == false){
        cout << "No";
    }else{
        cout << "Yes";
    }
}
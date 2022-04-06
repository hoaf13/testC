#include<bits/stdc++.h>

using namespace std;

struct MonHoc{
    char ID[6];
    char ten[50];
    int  so_tc;
    char khoa_ql[50];
    int hoc_ky;
};

void nhap(MonHoc *mon_hoc){
    char _;
    cout << "Nhap ma mon hoc: ";
    cin.getline(mon_hoc->ID, 6);
    cout << mon_hoc->ID << endl;

    cout << "Nhap ten mon hoc: ";
    cin.getline(mon_hoc->ten, 50);
    cout << mon_hoc->ten << endl;

    cout << "Nhap so tin chi mon hoc: ";
    cin >> mon_hoc->so_tc;
    cin.ignore();

    cout << "Nhap khoa ql: ";
    cin.get(mon_hoc->khoa_ql, 50);
    
    cout << "Nhap hoc ki: ";
    cin >> mon_hoc->hoc_ky;
}

void xuat(MonHoc *mon_hoc){
    cout << "Ma mon hoc: ";
    cout << mon_hoc->ID << endl;
    cout << "Ten mon hoc: ";
    cout << mon_hoc->ten << endl;
    cout << "So tin chi mon hoc: ";
    cout << mon_hoc->so_tc << endl;
    cout << "Khoa ql: ";
    cout << mon_hoc->khoa_ql << endl;
    cout << "Hoc ki: ";
    cout << mon_hoc->hoc_ky << endl;
}

int main(){ 
    MonHoc mon_hoc;

    nhap(&mon_hoc);
    xuat(&mon_hoc);   
}
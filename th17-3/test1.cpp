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

int main(){ 
    MonAn mon_an;

    nhap(&mon_an);
    xuat(&mon_an);   
}
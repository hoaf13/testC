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

int main(){ 
    CongNhan cong_nhan;

    nhap(&cong_nhan);
    xuat(&cong_nhan);   
}
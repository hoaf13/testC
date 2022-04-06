#include<bits/stdc++.h>

using namespace std;

struct NhanVien{
    int ma; 
    string ten;
    int tuoi;
    float he_so_luong;
};

int main(){
    NhanVien nhan_vien; 
    cout << "nhap ma nhan vien: "; cin >> nhan_vien.ma;
    cout << "nhap ten nhan vien: "; cin >> nhan_vien.ten;
    cout << "nhap tuoi nhan vien: "; cin >> nhan_vien.tuoi;
    cout << "nhap he so luong nhan vien: "; cin >> nhan_vien.he_so_luong;
    
}
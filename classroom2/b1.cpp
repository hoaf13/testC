#include<bits/stdc++.h>

using namespace std;

struct HocVien{
    int ma_hoc_vien;
    string ten_hoc_vien;
    string lop;
    string chuyen_nganh;
    double diem_tong_ket;
};

int main(){
    HocVien *hocvien = new HocVien();
    hocvien->diem_tong_ket = 6.3;
    cout << hocvien->diem_tong_ket;
}
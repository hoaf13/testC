#include<stdio.h>

void bai3(){
    float eps = -1;
    int i;
    for(;;){
        scanf("%f", &eps);
        if (eps > 0 && eps < 1){
            printf("nhap dung dinh dang! thoat chuong trinh");
            break;
        }
        else{
            printf("chua dung dinh dang. moi nhap lai!\n");
        }
    }
}

int main(){

    bai3();

    return 0;
}
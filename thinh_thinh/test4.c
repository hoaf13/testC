#include<stdio.h>
#include<math.h>

double bai2(double a, double b, double eps){
	int i=0;
	int n=1/eps;
	double delta = (b-a)/n;
	double ans=0;
	while(i<n){
        double tmp = (a+delta*i);
		ans += tmp * tmp * sin(tmp);
		i++;
	}
    return ans *= delta;

}

double bai3(double eps){
    double res;
    for(;;){
        printf("Nhap gia tri eps: ");
        scanf("%lf", &eps);
        if (eps > 0 && eps < 1){
            res = eps;
            printf("Ban da nhap dung dinh dang cua eps!\n");
            break;
        }
        else{
            printf("Nhap chua dung dinh dang eps. eps la so thuc nam trong khoang (0;1) Moi nhap lai!\n");
        }
    }
    return res;
}

int main(){

    for (;;){
        double a,b;
        double eps=-1;
        int flag = 1;

        printf("Nhap gia tri a: ");
        scanf("%lf", &a);
        printf("Nhap gia tri b: ");
        scanf("%lf", &b);
        eps = bai3(eps);
        double res = bai2(a,b,eps);
        printf("Ket qua tich phan la: %lf\n", res);


        while(1){
            printf("Ban co muon bat dau lai khong ? An 1 de tiep tuc. An phim khac phim 1 de thoat!");
            int choice;
            scanf("%d", &choice);
            printf("Lua chon cua ban la: %d\n", choice);
            switch (choice){
                case 1:
                    flag = 1;
                    break;
                
                default:
                    flag = 0;
                    break;
            }
            break;
        }
        if (flag == 0){
            printf("Ket thuc chuong trinh !");
            break;
        }
        printf("---------------------------------------------");
    }
    return 0;
}
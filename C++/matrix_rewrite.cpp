#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
struct matrix {
    private:
        int c,r;
        
    public:
    	int m[10][10];
        matrix(){
            c=0;
            r=0;
        }
        matrix(int n1, int n2){
            c=n1;
            r=n2;
        }
        matrix operator+(matrix a){
            matrix n;
            n.c = a.c;
            n.r = a.r;
            for(int i=0;i<a.r;i++)
                for(int j=0;j<a.c;j++){
                    n.m[i][j]=m[i][j]+a.m[i][j];
                }
            return n;
        }
        matrix operator*(matrix a){
            matrix n;
            for(int i=0;i<a.r;i++)
                for(int j=0;j<c;j++)
                {
                    n.m[i][j]=0;
                    for(int k=0;k<a.c;k++)
                        n.m[i][j]=n.m[i][j]+(m[i][k]*a.m[k][j]);
                }
            return n;
        }
		matrix operator*(int h)
		{
			matrix n;
            for(int i=0;i<r;i++)
                for(int j=0;j<c;j++)
                {
                    n.m[i][j]=0;
                    n.m[i][j]=n.m[i][j]+(m[i][j]*h);
                }
            return n;
		}
        matrix operator-(matrix a){
            matrix n;
            n.c = a.c;
            n.r = a.r;
            for(int i=0;i<a.r;i++)
                for(int j=0;j<a.c;j++){
                    n.m[i][j]=m[i][j]-a.m[i][j];
                }
            return n;
        }
        bool operator==(matrix a){
            if((c==a.c)&&(r==a.r))
                return true;
            return false;
        }           
};

int main(){
    matrix c1(2,2),c2(2,2);
    //Nhap gia tri cho ma tran c1
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
        {
            printf("Nhap gia tri cho phan tu [%d][%d]: ",i,j);
            scanf("%d", &c1.m[i][j]);
        }
    //Nhap gia tri cho ma tran c2
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
        {
            printf("Nhap gia tri cho phan tu [%d][%d]: ",i,j);
            scanf("%d", &c2.m[i][j]);
        }
    //Tinh tong hai ma tran
    matrix c3=c1+c2;
    //In ra ma tran tong
    printf("Ma tran tong cua hai ma tran tren la:\n");
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++)
            printf("%d ",c3.m[i][j]);
        printf("\n");
    }
    //Tinh tich hai ma tran
    matrix c4=c1*c2;
    //In ra ma tran tich
    printf("Ma tran tich cua hai ma tran tren la:\n");
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++)
            printf("%d ",c4.m[i][j]);
        printf("\n");
    }
    
    matrix c5=c1-c2;
    //In ra ma tran tru
    printf("Ma tran tru cua hai ma tran tren la:\n");
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++)
            printf("%d ",c5.m[i][j]);
        printf("\n");
    }

	//Tich ma tran voi 1 so
	int h;
	printf("Nhap gia tri cho phan tu h: ");
    scanf("%d",&h);
    matrix c6=c1*h;
    //In ra ma tran tich
    printf("Ma tran tich cua hai ma tran tren la:\n");
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++)
            printf("%d ",c6.m[i][j]);
        printf("\n");
    }
    return 0;
}


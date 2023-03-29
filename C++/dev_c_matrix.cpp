#include<iostream>
#include<stdio.h>
#include<math.h>
struct matrix {
	private:
		int c,r;
        int m[10][10];
	public:
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
};
int main(){
	matrix c1(2,3),c2(3,3);
	printf("Tich 2 ma tran la: \n");
//	(c1*c2).print();
	return 0;
}

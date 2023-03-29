#include<iostream>

using namespace std;

class matrix{

     private:

          int a[10][10];

          int n;

     public:

          matrix();

          friend ostream& operator<<(ostream&, matrix);

          friend istream& operator>>(istream&, matrix&);

          matrix operator+(matrix);

};

 

matrix::matrix(){

     n=0;

}   

ostream& operator<<(ostream& os, matrix m){

     for(int i=0;i<m.n;i++){

        for(int j=0;j<m.n;j++){

          cout<<m.a[i][j]<<"    ";

         }

          cout<<endl;  

        }

 return os;

}

 

istream& operator>>(istream& is, matrix& m){

   int tam;

   cout<<"Nhap kich thuoc ma tran: ";cin>>m.n;

   for(int i=0;i<m.n;i++)

     for(int j=0;j<m.n;j++){

        cout<<"a["<<i<<"]["<<j<<"]: ";

        cin>>tam;

        m.a[i][j]=tam;

     }

     return is;   

}

 

matrix matrix::operator+(matrix u){

matrix v;

v.n=u.n;

 for(int i=0;i<u.n;i++)

    for(int j=0;j<u.n;j++){

     v.a[i][j]=this->a[i][j]+u.a[i][j];

    }

   return v;

}

 

int main(){

matrix mt1, mt2;

cout<<"Nhap ma tran 1: "<<endl;

cin>>mt1;

cout<<mt1;

cout<<"Nhap ma tran 2: "<<endl;

cin>>mt2;

cout<<mt2;

cout<<"Tong hai ma tran: "<<endl;

cout<<mt1+mt2;

return 0;

}
#include <stdio.h>
#include <iostream>
#include <string>
#include <time.h>
using namespace std;
class Phanso {
  private:
    int t, m;
  public:
    Phanso(int x,int y) {
      t=x; m=y;
    }
    Phanso() {t = 0; m - 1; }
    void display(){
      cout<< t<< '/'<< m;
    }
    void operator=(Phanso a) {
     t=a.t;
     m=a.m;
	}
    Phanso operator+(Phanso a){
			Phanso n;
			if(m==a.m){
				n.t=t+a.t;
				n.m=m;	
			}
			else{
				n.t=a.m*t+m*a.t;
				n.m=m*a.m;
			}
			return n;
			
		}
		Phanso operator*(Phanso a){
			Phanso n;
			n.t=t*a.t;
			n.m=m*a.m;
			return n;
			
		}
		Phanso operator-(Phanso a){
			Phanso n;
			if(m==a.m){
				n.t=t-a.t;
				n.m=m;	
			}
			else{
				n.t=a.m*t-m*a.t;
				n.m=m*a.m;
			}
			return n;
		}
		Phanso operator/(Phanso a){
			Phanso n;
			n.t=t*a.m;
			n.m=m*a.t;
			return n;	
		}
		bool operator==(Phanso a){
			if((t==a.t)&&(m==a.m))
				return true;
			return false;
		}
int main () {
       Phanso a = Phanso(3, 10);
       Phanso b = Phanso(5, 6);
       Phanso c,d;
       c=a+b; d=b+c;
       cout<<"\n A="; a.display();
       cout<<"\n B="; b.display();
       cout<<"\n C="; c.display();
       cout<<"\n D="; d.display();
       cout<<"\n A+B ="; (a + b).display;
       cout<<"\n 5+b ="; (5+b).display();
       cout<<"\n B+5 ="; (b+5).display();
       cout<<"\n A-B="; (a-b).display();
       cout<<"\n 5-B ="; (5-b).display();
       cout<<"\n B-5 ="; (b-5).display();
       cout<<"\n A*B="; (a*b).display();
       cout<<"\n B*5 ="; (b*5).display();
       cout<<"\n 5*b ="; (5*b).display();
       cout<<"\n A/B="; (a/b).display();
       cout<<"\n B/5 ="; (b/5).display();
       cout<<"\n 5/b ="; (5/b).display();
	   cout<<"\n A<B:"<< ((a<b)?" Dung":" Sai");
	   cout<<"\n A==B:"<< (a=b)?" Dung":" Sai");
	   cout<<"\n A!=B:"<< ((a!=b)?" Dung":" Sai");
	   cout<<"\n A>=B:"<< ((a>=b)?" Dung":" Sai");
	   cout<<"\n A<=B:"<< ((a<=b)?" Dung":" Sai");
	   cout<<"\n A< B:"<< ((a<b)?" Dung":" Sai");
	   cout<<"\n A> B:"<< ((a>b)?" Dung":" Sai");
return 0;
}


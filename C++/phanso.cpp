#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string>

struct phanso {
	private:
		int t,m;
	public:
	    phanso(int s){
	        t=s;
	        m=1;
	    }
	    
		phanso(){
			t=0;
			m=1;
			
		}
		phanso(int n1, int n2){
			t=n1;
			m=n2;
		}
		phanso operator+(phanso a){
			phanso n;
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
		
		phanso operator-(phanso a){
			phanso n;
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
		
		phanso operator*(phanso a){
			phanso n;
			n.t=t*a.t;
			n.m=m*a.m;
			return n;
			
		}

		phanso operator/(phanso a){
			phanso n;
			n.t=t*a.m;
			n.m=m*a.t;
			return n;	
		}
		
		bool operator==(phanso a){
			if((t==a.t)&&(m==a.m))
				return true;
			return false;
		}
		
		bool operator!=(phanso a){
			if((t==a.t)&&(m==a.m))
				return true;
			return false;
		}
		
		bool operator >(phanso a){
			if(m!=a.m){
				t=t*a.m;
				a.t=a.t*m;
				m=m*a.m;
				a.m=a.m*m;}
			if((t>a.t)&&(m=a.m))
					return true;
				return false;
		}
		
		bool operator <(phanso a){
			if(m!=a.m){
				t=t*a.m;
				a.t=a.t*m;
				m=m*a.m;
				a.m=a.m*m;}
			if((t>=a.t)&&(m=a.m))
					return true;
				return false;
		}
		
		bool operator >=(phanso a){
			if(m!=a.m){
				t=t*a.m;
				a.t=a.t*m;
				m=m*a.m;
				a.m=a.m*m;}
			if((t>=a.t)&&(m=a.m))
					return true;
				return false;
		}
		
		bool operator <=(phanso a){
			if(m!=a.m){
				t=t*a.m;
				a.t=a.t*m;
				m=m*a.m;
				a.m=a.m*m;}
			if((t<=a.t)&&(m=a.m))
					return true;
				return false;
		}
		
		void rgps(){
			int a,b;
			a=abs(t);
			b=abs(m);
			
			while (a*b != 0){ 
				if (a > b){ 
					a %= b; 
				}else{ 
				b %= a; 
				} 
			}
			
			t/=(a+b);
			m/=(a+b);
			if(m==1){
			printf("Ket qua la: %d \n",t);
			}
			else{
	
			printf("Phan so la: %d/%d \n",t,m);}
		}

					
};
int main(){
	phanso c1(5),c2(10,6),c3(10,3),c4(6),c5(6),c6(10,6);
	(c2+c3).rgps();//cong 2 phan so
	(c2-c3).rgps();//tru
	(c2*c3).rgps();//nhan
	(c2/c3).rgps();//chia
	(c1+c2).rgps();//cong phan so voi 1 so
	(c2-c1).rgps();//tru
	(c2*c1).rgps();//nhan
	(c2/c1).rgps();//chia
	(c1+c5).rgps();//cong 2 so
	(c1-c5).rgps();//tru
	(c1*c5).rgps();//nhan
	(c1/c5).rgps();//chia
	printf("so sanh c2==c3 %s\n",c2==c3?"Dung":"Sai");
	printf("so sanh c2==c6 %s\n",c2==c3?"Dung":"Sai");
	printf("so sanh c2!=c3 %s\n",c2!=c3?"Dung":"Sai");
	printf("so sanh c2!=c6 %s\n",c2==c3?"Dung":"Sai");
	printf("so sanh c2>c3 %s\n",c2>c3?"Dung":"Sai");
	printf("so sanh c3>c2 %s\n",c3>c2?"Dung":"Sai");
	printf("so sanh c2<c3 %s\n",c2<c3?"Dung":"Sai");
	printf("so sanh c3<c2 %s\n",c3<c2?"Dung":"Sai");
	printf("so sanh c2>=c3 %s\n",c2>=c3?"Dung":"Sai");
	printf("so sanh c3>=c2 %s\n",c3>=c2?"Dung":"Sai");
	printf("so sanh c2<=c3 %s\n",c2<=c3?"Dung":"Sai");
	printf("so sanh c3<=c2 %s\n",c2<=c3?"Dung":"Sai");
	return 0;
}

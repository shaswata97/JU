/*
NAME: SHASWATA SAHA
ROLL: 001610501010
CLASS: BCSE-II
GROUP: A1
*/

#include <iostream>

using namespace std;

class Complex{
	int r;
	int im;
	public:
		Complex(int re=0, int i=0){
			r=re;
			i=im;
		}

		//function to perform complex addition
		Complex operator +(Complex const &c){
			Complex sum;
			sum.r=r+c.r;
			sum.im=im+c.im;
			return sum;
		}

		//function to perform subtraction
		Complex operator -(Complex const &c){
			Complex diff;
			diff.r=r-c.r;
			diff.im=im-c.im;
			return diff;
		}
		friend istream& operator >>(istream &in, Complex &c);
		friend ostream& operator <<(ostream &o, Complex const &c);
};

//function to take complex object as input
istream& operator >>(istream &in, Complex &c){
	string s;
	in>>s;
	int len;
	len=s.length();
	int i,st_re=0,st_im=len,sgn=1;
	int re=0,ima=0;
	
	if(s[0]=='-'){
		sgn=-1;
		st_re=1;
	}
	if(s[st_re]=='i'){
		st_re=len;
		st_im=st_re+1;
	}
	for(i=st_re;i<len;i++){
		if(s[i]>='0' && s[i]<='9')
			re=re*10+(s[i]-'0');
		else if(s[i]=='+' || s[i]=='-'){
			c.r=re*sgn;
			sgn=1;
			st_im=i+1;
			if(s[i]=='-')  //setting the sign for the imaginary part
				sgn=-1;
			break;
		}
		else{
			cout<<"Wrong input\n";
			return in;
		}
	}
	if(st_im==len){ //if only real part is given
		c.r=re*sgn;
		c.im=0;
		return in;
	}
	if(s[st_im]!='i'){ //if input is of the form a+bcde
		cout<<"Wrong input\n";
		return in;
	}
	if(st_im==len-1){ //if there is no value after i, i.e., if the input is of the form a+i
		cout<<"Wrong input\n";
		return in;
	}
	st_im++;
	for(i=st_im;i<len;i++){
		if(s[i]>='0' && s[i]<='9')
			ima=ima*10+(s[i]-'0');
		else{
			cout<<"Wrong input\n";
			return in;
		}
	}
	c.im=ima*sgn;
	return in;
}

//function to print complex object
ostream& operator <<(ostream &o, Complex const &c){
	o<<c.r;
	if(c.im<0)
		o<<"-i"<<(-1*c.im)<<"\n";
	else if(c.im>0)
		o<<"+i"<<c.im<<"\n";
	return o;
}

int main(){
	Complex c1,c2,c3;
	int ch;
	do{
		cout<<"Enter choice\n";
		cout<<"1. Enter complex number\n";
		cout<<"2. Add two complex numbers\n";
		cout<<"3. Subtract one complex number from another\n";
		cout<<"4. Exit\n";
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"Enter value(a+ib format)\n";
				cin>>c1;
				cout<<c1;
				break;
			case 2:
				cout<<"Enter first complex number(a+ib format)\n";
				cin>>c1;
				cout<<c1;
				cout<<"Enter second complex number(a+ib format)\n";
				cin>>c2;
				cout<<c2;
				c3=c1+c2;
				cout<<c3;
				break;
			case 3:
				cout<<"Enter complex number from which another complex is to be subtracted(a+ib format)\n";
				cin>>c1;
				cout<<c1;
				cout<<"Enter complex number to be subtracted(a+ib format)\n";
				cin>>c2;
				cout<<c2;
				c3=c1-c2;
				cout<<c3;
				break;
			case 4:
				cout<<"Exiting\n";
				break;
			default:
				cout<<"Wrong input\nEnter once again\n";
		}
	}while(ch!=4);
}
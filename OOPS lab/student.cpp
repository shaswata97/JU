/*
NAME: SHASWATA SAHA
ROLL: 001610501010
CLASS: BCSE-II
GROUP: A1
*/

#include <iostream>
#include <string>

using namespace std;

class Date{
	int d;
	int m;
	int y;
	public:
		//function to receive date
		int readDate();

		//function to print data
		void dispDate();
};

class Student{
	static int count;
	string roll;
	string name;
	string course;
	Date adm_date;
	float marks[5];
	public:
		//friend function used to get admission date 
		friend int Date::readDate();

		//function to receive student data
		void readData(){
			int res=0;
			cout<<"Enter roll\n";
			cin>>roll;
			cout<<"Enter name\n";
			cin>>name;
			cout<<"Enter course of study\n";
			cin>>course;
			cout<<"Enter admission date\n";
			do{
				res=adm_date.readDate();
			}while(res!=1);
			int i=0;
			for(;i<5;i++)
				marks[i]=0.0;
			count++;
		}

		//function to receive marks
		void recMarks(){
			cout<<"Enter marks of 5 subjects\n";
			int i;
			for(i=0;i<5;i++){
				cout<<"Subject "<<(i+1)<<" : ";
				cin>>marks[i];
			}
		}

		//function to create marksheet
		void prepSheet(){
			int i;
			float sum=0.0,avg=0.0;
			for(i=0;i<5;i++)
				sum+=marks[i];
			avg=sum/5;
			cout<<"=========================================================="<<"\n";
			cout<<"Name : "<<name<<"\n";
			cout<<"Roll : "<<roll<<"\n";
			cout<<"Course of study : "<<course<<"\n";
			cout<<"Admission date : ";
			adm_date.dispDate();
			cout<<"Total marks :"<<sum<<"\n";
			cout<<"Average marks : "<<avg<<"\n";
			cout<<"=========================================================="<<"\n";
		}
};

int Date::readDate(){
	string dat;
	int len=-1;
	cout<<"Enter date(dd/mm/yyyy) Year should be within 1900 and 2018(both inclusive)\n";
	cin>>dat;
	len=dat.length();
	if(len!=10 || dat[2]!='/' || dat[5]!='/'){
		cout<<"Wrong input\nEnter once again\n";
		return 0;
	}
	d=10*(dat[0]-'0')+(dat[1]-'0');
	m=10*(dat[3]-'0')+(dat[4]-'0');
	y=1000*(dat[6]-'0')+100*(dat[7]-'0')+10*(dat[8]-'0')+(dat[9]-'0');

	//validating date
	if(y<1900 || y>2018 || m<1 || m>31 || d<0 || d>31){
		cout<<"Wrong date\nEnter once again\n";
		return 0;
	}
	if(m==2 && ((y%4==0 && d>29) || (y%4!=0 && d>28))){
		cout<<"Wrong date\nEnter once again\n";
		return 0;
	}
	if((m==4 || m==6 || m==9 || m==11) && d>30){
		cout<<"Wrong date\nEnter once again\n";
		return 0;
	}
	return 1;
}

void Date::dispDate(){
	if(d<10)
		cout<<"0";
	cout<<d<<"/";
	if(m<10)
		cout<<"0";
	cout<<m<<"/"<<y<<"\n";
}

int Student::count=0;
int main(){
	int ch;
	Student s;
	do{
		cout<<"Enter choice\n";
		cout<<"1. Enter student details\n";
		cout<<"2. Enter marks\n";
		cout<<"3. Display marksheet\n";
		cout<<"4. Exit\n";
		cin>>ch;
		switch(ch){
			case 1:
				s.readData();
				break;
			case 2:
				s.recMarks();
				break;
			case 3:
				s.prepSheet();
				break;
			case 4:
				cout<<"Exiting\n";
				break;
			default:
				cout<<"Wrong choice!\nEnter once again\n";
		}
	}while(ch!=4);
}
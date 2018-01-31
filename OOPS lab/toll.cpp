/*
NAME: SHASWATA SAHA
ROLL: 001610501010
CLASS: BCSE-II
GROUP: A1
*/

#include <iostream>
#include <string>

using namespace std;

class TollTax{
	static int count;
	static float tollTot;
	public:
		static void readData(){
			float toll;
			cout<<"Enter toll\n";
			cin>>toll;
			while(toll<=0.0){
				cout<<"Wrong input\n Enter toll again\n";
				cin>>toll;
			}
			tollTot+=toll;
			count+=1;
			cout<<"Toll valued Rs. "<<toll<<" received successfully\n";
		}
		static void dispCars(){
			cout<<"Number of cars crossed : "<<count<<"\n";
		}
		static void dispToll(){
			cout<<"Amount of tax collected : "<<tollTot<<"\n";
		}
};

int TollTax::count=0;
float TollTax::tollTot=0.0;
int main(){
	TollTax t;
	int ch;
	do{
		cout<<"Enter choice\n";
		cout<<"1. Receive toll\n";
		cout<<"2. Display number of cars crossed\n";
		cout<<"3. Display Amount of tax collected\n";
		cout<<"4. Exit\n";
		cin>>ch;
		switch(ch){
			case 1:
				t.readData();
				break;
			case 2:
				t.dispCars();
				break;
			case 3:
				t.dispToll();
				break;
			case 4:
				cout<<"Exiting\nThank you!\n";
				break;
			default:
				cout<<"Wrong choice!\nEnter once again\n";
		}
	}while(ch!=4);
}
/*
NAME: SHASWATA SAHA
ROLL: 001610501010
CLASS: BCSE-II
GROUP: A1
*/

#include <iostream>
#include <string>

using namespace std;

class Item{
	string code;
	string name;
	float rate;
	int qty;
	public:
		//constructor
		Item(string c="", string n="", float r=0.0, int q=1){
			code=c;
			name=n;
			rate=r;
			qty=q;
		}

		//overloaded function to update price
		void update(float r){
			rate=r;
		}

		//overloaded function to update quantity
		void update(int q){
			qty+=q;
		}

		//function to get quantity of item
		int getQty(){
			return qty;
		}

		//function to get price of item
		float getPrice(){
			return rate;
		}

		//function to get item code
		string getCode(){
			return code;
		}

		//function to get item name
		string getName(){
			return name;
		}

		//function to display stock of an item
		void dispStock(){
			cout<<"Item name : "<<name<<"\n";
			cout<<"Item code : "<<code<<"\n";
			cout<<"Quantity : "<<qty<<"\n";
			cout<<"Price per item : "<<rate<<"\n";
		}
};

class ItemList{
	Item list[1024];
	int count;
	public:
		//constructor to initialize item list
		ItemList(){
			count=0;
		}

		
		//function to find the item in the list for a given code
		int search(string cd){
			int i,pos=-1;
			for(i=0;i<count;i++){
				if(list[i].getCode()==cd){
					pos=i;
					break;
				}
			}
			return pos;
		}

		//function to add item
		void addItem(Item i){
			int pos=search(i.getCode());
			if(pos==-1){
				cout<<"New item...Entering in list!\n";
				list[count++]=i;
			}
			else{
				cout<<"Item exists in stock...Updating list\n";
				list[pos].update(i.getQty());
			}
		}

		//function to issue item
		void issue(string cd, int q){
			int pos=search(cd);
			if(pos==-1){
				cout<<"Item does not exist\n";
			}
			else if(list[pos].getQty()<q){
				cout<<"Less items in stock\n";
			}
			else{
				cout<<"Item name : "<<list[pos].getName()<<"\n";
				cout<<"Item code : "<<list[pos].getCode()<<"\n";
				cout<<"Count : "<<q<<"\n";
				cout<<"Price per qty : "<<list[pos].getPrice()<<"\n";
				cout<<"Total cost : "<<(list[pos].getPrice()*q)<<"\n";
				list[pos].update(-q);
				cout<<"Item remaining in stock : "<<list[pos].getQty()<<"\n";
			}
		}

		//function to update price of item
		void updatePrice(string cd, float p){
			int pos=search(cd);
			if(pos==-1)
				cout<<"Item not found\n";
			else
				list[pos].update(p);
		}

		//function to display item stock
		void disp(string cd){
			int pos=search(cd);
			if(pos==-1)
				cout<<"Item not found\n";
			else
				list[pos].dispStock();
		}
};

int main(){
	ItemList i;
	int ch;
	string s,n;
	int qt;
	float pr;
	do{
		cout<<"Enter choice\n";
		cout<<"1. Enter items in stock\n";
		cout<<"2. Update price of item in stock\n";
		cout<<"3. Issue item to customer\n";
		cout<<"4. Display stock of item\n";
		cout<<"5. Exit\n";
		cin>>ch;
		switch(ch){
			case 1:{
				cout<<"Enter item details\nCode : ";
				cin>>s;
				cout<<"Name : ";
				cin>>n;
				cout<<"Price : ";
				cin>>pr;
				cout<<"Quantity : ";
				cin>>qt;
				Item i1(s,n,pr,qt);
				i.addItem(i1);
				}break;
			case 2:
				cout<<"Enter item code : ";
				cin>>s;
				cout<<"Enter updated price : ";
				cin>>pr;
				i.updatePrice(s,pr);
				break;
			case 3:
				cout<<"Enter item code : ";
				cin>>s;
				cout<<"Enter items to be dispersed : ";
				cin>>qt;
				i.issue(s,qt);
				break;
			case 4:
				cout<<"Enter item code : ";
				cin>>s;
				i.disp(s);
				break;
			case 5:
				cout<<"Exiting!\n";
				break;
			default:
				cout<<"Wrong choice...Enter once again\n";
				break;
		}
	}while(ch!=5);
}
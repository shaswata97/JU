/*
NAME: SHASWATA SAHA
ROLL: 001610501010
CLASS: BCSE-II
GROUP: A1
*/

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Time{
  int hr;
  int min;
  int sec;
  string mode; //to denote AM/PM
  public:
    //function to read and store data in object
    int readData(){
      string t,md;
      int h,m,s,len;
      cout<<"Enter time\n";
      cin>>t;
      if(t[2]==':' && t[5]==':'){
        len=t.length();
        //cout<<len<<"\n";
        if(len!=8 && len!=10){
          cout<<"Wrong input\nEnter once again\n";
          return 0;
        }
        h=10*(t[0]-'0')+(t[1]-'0');
        m=10*(t[3]-'0')+(t[4]-'0');
        s=10*(t[6]-'0')+(t[7]-'0');
        //cout<<h<<"\n"<<m<<"\n"<<s<<"\n";
        if(len==10){
          md=t[8];
          md+=t[9];
        }
        //cout<<md<<"\n";
        if((m>=0 && m<=59) && (s>=0 && s<=59) && ((md=="" && h>=0 && h<=59) || ((md=="am" || md=="AM" || md=="pm" || md=="PM") && (h>=1 && h<=12)))){
          hr=h;
          min=m;
          sec=s;
          mode=md;
          if(mode=="am")
            mode="AM";
          else if(mode=="pm")
            mode="PM";
          return 1;
        }
        else{
          cout<<"Wrong input\nEnter once again\n";
          return 0;
        }
      }
      else{
        cout<<"Wrong input\nEnter once again\n";
        return 0;
      }
    }

    //convert to 24 hour format
    void conv24(){
      if(mode=="PM" || (mode=="AM" && hr==12))
        hr+=12;
      if(hr==24)
        hr=0;
      mode="";
    }

    //convert to 12 hour format
    void conv12(){
      if(hr<=11){
        if(hr==0)
          hr=12;
        mode="AM";
      }
      else{
        hr-=12;
        if(hr==0)
          hr=12;
        mode="PM";
      }
    }

    //adding m minutes to a Time object
    void add(int m){
      min+=m;
      if(min>=60){
        hr+=min/60;
        min=min%60;
        hr=hr%24;
        if(mode!=""){
          if(hr>=12){
            mode="PM";
            if(hr!=12)
              hr-=12;
          }
          else{
            mode="AM";
            if(hr==0)
              hr+=12;
          }
        }
      }
    }

    //display time object
    void disp(){
      if(hr<10)
        cout<<"0";
      cout<<hr<<":";
      if(min<10)
        cout<<"0";
      cout<<min<<":";
      if(sec<10)
        cout<<"0";
      cout<<sec<<mode<<"\n";
    }
};

int main(){
  Time t;
  int ch,val;
  do{
    cout<<"Enter your choice\n";
    cout<<"1. Enter time\n";
    cout<<"2. Convert to 24 hrs\n";
    cout<<"3. Convert to 12 hrs\n";
    cout<<"4. Add minutes\n";
    cout<<"5. Exit\n";
    cin>>ch;
    switch(ch){
      case 1:
        do{
          val=t.readData();
        }while(val==0);
        cout<<"Time is valid\n";
        t.disp();
      break;
      case 2:
        t.conv24();
        t.disp();
        break;
      case 3:
        t.conv12();
        t.disp();
        break;
      case 4:
        int m;
        char c;
        do{
          cout<<"Enter minutes to add\n";
          cin>>m;
          t.add(m);
          t.disp();
          cout<<"Enter Y to continue. To stop press any other key\n";
          cin>>c;
        }while(c=='Y' || c=='y');
        break;
      case 5:
        cout<<"Exiting\n";
        break;
      default:
        cout<<"Wrong choice\nEnter once again";
    }
  }while(ch!=5);
}

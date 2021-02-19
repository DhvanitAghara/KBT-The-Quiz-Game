#include<iostream>
#include<conio.h>
#include<fstream>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
void line()
{
    for(int i=0;i<120;i++)
    {
        cout<<"-";
    }
}
void line1()
{
    for(int i=0;i<120;i++)
    {
        cout<<"_";
    }
}
class contest
{
private:
    string id;
    float x;
    char name[20];
    char s[100],ans[10],real[10]={'d','b','a','b','b','c','c','c','a','b'};

public:
    contest()
    {
        x=0;
    }
    void init();
    void define();
    void display();

};
void   contest :: define()
{
   fstream in;
   char a;
      int i=0;
      static int j=0;
   in.open("questions.txt");
    while(in.eof()==0)
    {
    in.getline(s,120);
    cout<<endl<<s;
   if(i==5)
   {
   in.get(a);
   cout<<"\nans:";

    cin>>ans[j];
   i=-1;
    if(ans[j]==real[j])
       {
       x=x+5;
       cout<<" * correct ans.\n";
       line1();
       j++;
       }
    else
       {
       if(x>0)
       cout<<" # Wrong ans.\n";
       line1();
       j++;
       }
    }
    i++;
    }
    ofstream f;
    f.open("data.txt",ios::app);
    f<<"Score:"<<x<<endl;
    f.close();

   in.close();
}
     void contest :: init()
       {
     cout<<"\t\t\t   Contestant Name:";
     cin>>name;
     cout<<"\t\t\t   Contenstant ID no:";
     cin>>id;

       ofstream f;
       f.open("data.txt",ios::app);
       f<<endl<<"Name:"<<name<<endl;
       f<<"ID:"<<id<<endl;
       f.close();

     line();
       }
     void contest :: display()
       {
     cout<<endl<<endl<<"\n **Result:\n";
     cout<<"\t"<<name<<" you got total "<<x<<" marks,out of 50.\n";
       }

 main()
{

    contest r;
    cout<<"      \t\t\t~~~*** KBT - The Quiz Game ***~~~\t      Total Marks:50\n\n";
    cout<<"\t\t\t\t\t\t\t\t  *5 marks per Question"<<endl;
    line();
    r.init();
       L:
    cout<<"\n\n\tselect your choice:\n"
        <<"\n\tY for start exam"
        <<"\n\tN for quit the exam :"<<endl;
       char c;
       cin>>c;
       line1();
       switch(c)
       {
       case 'y':
       case 'Y':
        r.define();
        r.display();
        break;
       case 'n':
        case 'N':
        exit(1);
       default:
        cout<<"invalid choice!";
        goto L;
       }
       getch();
}

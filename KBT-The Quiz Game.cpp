#include<iostream>
#include<fstream>
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
    char s[120],s2[50],s3[50],s4[50],s5[50],s6[50],ans[10],real[10]={'d','b','a','b','b','c','c','c','a','b'};
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
    fstream f;
    int i=0;
    static int j=0;
    f.open("questions.txt");
    while(f.eof()==0)
    {
        f.getline(s,120);
        f.getline(s2,50);
        f.getline(s3,50);
        f.getline(s4,50);
        f.getline(s5,50);
        f.getline(s6,50);
        cout<<endl<<s<<endl<<s2<<endl<<s3<<endl<<s4<<endl<<s5<<endl<<s6;

            cout<<"\nans:";
            cin>>ans[j];
            if(ans[j]==real[j] || ans[j]==real[j]-32)
            {
                x=x+5;
                cout<<" * correct ans.\n";
                line1();
                j++;
            }
            else
            {
                cout<<" # Wrong ans.\n";
                line1();
                j++;
            }
    }
    f.close();
    ofstream f2;
    f2.open("data.txt",ios::app);
    f2<<"Score:"<<x<<endl;
    f2.close();
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

int main()
{

    contest r;
    cout<<"      \t\t\t~~~*** KBT - The Quiz Game ***~~~\t      Total Marks:50\n\n";
    cout<<"\t\t\t\t\t\t\t\t  *5 marks per Question"<<endl;
    line();
    r.init();

    Lable:

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
            goto Lable;
    }
}

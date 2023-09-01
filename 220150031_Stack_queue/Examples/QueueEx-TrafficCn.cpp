#include <iostream>
#include <string>
/* Traffic Controller (Example of Queue)*/
/*
 Following are the areas where traffic signals are to be monitored
 1. Barakhamba Road
 2. Safdarjung Road
 3. Yamuna Expressway
 4. Chandini Chowk
 5. Lal Quila
 6. Hazrat Nizamuddin Metro
 7. Akshardham Road
 8. Mughal Garden
 */
/* Queue contain details of places where RED light is on
 currently and when the controller wants to turn on GREEN light
 then automatically the first place where RED light was turned on
 becomes GREEN hence reducing human effort of scheduling the task.
 */
/*
Soumya Savarn
220150031
DSAI
*/
using namespace std;
string str[9];



struct node{
    struct node *prev;
    int data;
    struct node *next;
}*rear,*Front;




class Queue
{
    public:
    void enqueue(int info){
        struct node *tmp = new struct node;
        if (!tmp) {
            cout << "\nQueue Overflow";
            return;
        }
        else {
        tmp->data=info;
        tmp->prev=rear;
        tmp->next=NULL;
        
            rear->next=tmp;
            rear=tmp;
        
        }
    }
    
    
    
    bool isEmpty()
    {
        if( Front == rear) return 1;
        else return 0 ;
    }
    
    
    
    
    void dequeue()
    {
 
        
        if (Front->next == NULL) {
            cout << "\nQueue Underflow" << endl;
            return;
        }
        else {
            
            struct node *tmp = Front;
            Front = Front->next;
            Front->prev=NULL;
            free(tmp);
        }
    }
    
    int front(){
        if (Front->next==0) {cout<<"Operation failed due to empty queue\n";return -1; }
        return Front->next->data;
        
    }
       
    
    
    
    
    
    void display()
    {
        struct node *tmp = Front;
        
        if (Front->next == NULL) {
            cout << "No places to show\n" << endl;
        }
        else {
            tmp=tmp->next;
            while(tmp!=NULL) {cout<<str[tmp->data]<<endl;tmp=tmp->next;}
            cout<<endl;
        }
        
    }
    
    
    void clear()
    {
        while (rear!=Front) dequeue();
    }
};


Queue q;

bool check_presence(int x)
{
    struct node *tmp = Front;
    
    if (Front->next == NULL) {
        return 0;
    }
    else {
        tmp=tmp->next;
        bool flag=0;
        while(tmp!=NULL) {if (tmp->data==x) flag=1;tmp=tmp->next;}
        return flag;
    }
    
}



void places(string str[])
{
    for (int i=1;i<=8;i++) {if (check_presence(i)==0)cout<<i<<". "<<str[i]<<endl;}
    cout<<endl;
    cout<<endl;
}
void menu()
{
    cout<<endl;
        cout<<"Press the key for the  following actions\n";
        cout<<"1. Turn on GREEN light again priority wise\n2. Turn on RED light \n3. Display Current RED light traffic zones\n4. Exit\n";
        cout<<endl;
        cout<<endl;
}
 
            
int main()
{

    Front= new struct node;
    Front->next=NULL;
    Front->prev=NULL;
    rear=Front;
    
    //mapping int to place name
    str[1]="Barakhamba Road";
    str[2]="Safdarjung Road";
    str[3]="Yamuna Expressway";
    str[4]="Chandini Chowk";
    str[5]="Lal Quila";
    str[6]="Hazrat Nizamuddin Metro";
    str[7]="Akshardham Road";
    str[8]="Mughal Garden";
    
    
    
    cout<<"Welcome to Traffic Control: \n";
    cout<<"---------------------------\n";
    while (1)
    {
        menu();
        int a;
        cin>>a;
        if (a==1)
        {
            if (q.isEmpty()) {cout<<"All places are already free !"<<endl;continue;}
            cout<<"GREEN light turned on at: ";
            cout<<str[q.front()]<<endl;
            q.dequeue();
        }
        if (a==2){
            cout<<"Press the key where you want to turn on RED light\n\n";
            places(str);
            int x;
            cin>>x;
            q.enqueue(x);
            
        }
    
    if (a==3) {cout<<"RED light is on at:\n ";q.display();}
    if (a==4) {break;}
        if (a<1||a>4) cout<<"Invalid Input\n";
    }
    
    //Memory clear at the end
    q.clear();
    



return 0;
}

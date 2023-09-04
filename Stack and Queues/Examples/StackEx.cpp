//Soumya Savarn
//Stack Example: Browser Navigation
#include <iostream>
#include <iomanip>
#include <string>
/*
 You are free to navigate between web pages and my stack keeps
 a record of your history and if you click "back", last
 record gets popped and you are redirected to the top
 element of the stack i.e, the previous page
 */

using namespace std;

struct node{
    struct node *prev;
    string data;
    struct node *next;
}*top=0;




class Stack
{
    
    public:
    
    void push(string info){
        struct node *tmp = new struct node;
        if (!tmp) {
            cout << "\nStack Overflow";
            return;
        }
        else {
        tmp->data=info;
        tmp->prev=top;
        tmp->next=NULL;
        if (isEmpty()) top=tmp;
        else {
            top->next=tmp;
            top=tmp;
        }
        }
    }
    
    
    
    bool isEmpty()
    {
      if (top==NULL) return 1 ;
      else return 0 ;
    }
    
    
    
    
    void pop()
    {
 
        
        if (top == NULL) {
            cout << "\nStack Underflow" << endl;
            return;
        }
        else {
            
            struct node *tmp = top;
            top = top->prev;
            if (top!=NULL) top->next=NULL;
            free(tmp);
        }
    }
    
    string on_top()
    {
       
    if (top==NULL) return "No Sites to show";
    else return top->data;
        
    }
    
    
    void display()
    {
        struct node *tmp = top;
        if (top == NULL) {
            cout << "Stack is empty\n" << endl;
        }
        else {
            while (tmp->prev != NULL) tmp=tmp->prev;
            while(tmp!=NULL) {cout<<tmp->data<<" ";tmp=tmp->next;}
            cout<<endl;
        }
        
    }
    
    
    void clear()
    {
        while (top!=NULL) pop();
    }
};


void menu()
{
    cout<<endl;
    cout<<"Press the key for the  following actions\n";
    cout<<"1. Next Page\n2. Previous Page\n3. Display Current site name\n4. Exit\n";
    cout<<endl;
    cout<<endl;

}
 
            
int main()
{


    Stack s;
    cout<<"Welcome to browser navigation !"<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"You can enter the site name like 'Amazon.com' while navigating forward"<<endl;
    
    
    
    
    while (1)
    {
    
    
    menu();
    int a;
    cin>>a;
    if (a==1) {cout<<"Enter the site name: ";string k;cin>>k;s.push(k);}
    if (a==2) {s.pop();cout<<"You are currently on: "<<s.on_top()<<endl;}
    if (a==3) {cout<<"You are currently on: "<<s.on_top()<<endl;}
    if (a==4) {break;}
    
    }
    
    //Memory clear at the end
    s.clear();
    



return 0;
}

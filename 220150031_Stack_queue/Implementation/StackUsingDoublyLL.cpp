//Soumya Savarn
//Building Stack using doubly linked list

#include <bits/stdc++.h>
using namespace std;

struct node{
    struct node *prev;
    int data;
    struct node *next;
}*top=0;




class Stack
{
    
    public:
    
    void push(int info){
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
      return 1 ? top == NULL:0 ;
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
            top->next=NULL;
            free(tmp);
        }
    }
    
    int on_top(){return top->data;}
    
    
    
    
    
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
    cout<<"Press the key for the  following\n";
    cout<<"1. Pop\n2. Push\n3. Is empty check\n 4. Get Top element\n5. Display\n6. Exit\n";
    cout<<endl;
    cout<<endl;

}
 
            
int main()
{


    Stack s;
    cout<<"Enter the elements (press -1 to stop): \n";
    while(1)
    {
        int x;
        cin>>x;
        if (x==-1) break;
        s.push(x);
    }
    
    
    while (1)
    {
    
    
    menu();
    int a;
    cin>>a;
    if (a==1) s.pop();
    if (a==2) {cout<<"Enter the element: ";int k;cin>>k;s.push(k);}
    if (a==3) {if (s.isEmpty()) cout<<"Empty"<<endl;else cout<<"Not Empty\n";}
    if (a==4) {cout<<s.on_top()<<endl;}
    if (a==5) {s.display();}
    if (a==6) {break;}
    
    }
    
    //Memory clear at the end
    s.clear();
    



return 0;
}

#include <iostream>
#include <iomanip>
#include <vector>
#include <chrono>


/*
Check after line 103, where I have implemented all
standard functions of QUEUE USING STACK.
After that using chrono library, I recorded time for
operartions varying input values from 1 - 10000
*/

/*Soumya Savarn
 220150031
 */
using namespace std;

struct node{
    struct node *prev;
    int data;
    struct node *next;
};

struct Stack
{
    
    struct node *top=NULL;
    
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
      if (top==NULL) return 1 ;
      else return 0;
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
            if (top!=0) top->next=NULL;
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

struct Queue_using_stack
{
    struct Stack s,s_buff;
    
    //Directly pushes value into stack s
    //Time Complexity: O(1)
    void enqueue(int x)
    {
        s.push(x);
    }
    
    /* Transfers all entries to buffer stack s_buff
    and then pops the top element(front element of queue)
    Then again transfers s_buff values to s */
    //Time Complexity: O(n)
    void dequeue()
    {
        while(s.isEmpty()==0) {s_buff.push(s.on_top());s.pop();}
        s_buff.pop();
        while(s_buff.isEmpty()==0) {s.push(s_buff.on_top());s_buff.pop();}
    }
    
    void display()
    {
        s.display();
    }
    int front()
    {
        while(s.isEmpty()==0) {s_buff.push(s.on_top());s.pop();}
        int retval=s_buff.on_top();
        while(s_buff.isEmpty()==0) {s.push(s_buff.on_top());s_buff.pop();}
        return retval;
    }
    void clear()
    {
        s.clear();
    }
};
 
            
int main()
{
    struct Queue_using_stack Q_stack;
    
    int target=1;
    vector <float> v1,v2;
    while(target<=10000){
        auto S_build = chrono::high_resolution_clock::now();
        for (int i=1;i<=target;i++) Q_stack.enqueue(i);
        auto E_build = chrono::high_resolution_clock::now();
        
        float Time_1 =
        chrono::duration_cast<chrono::nanoseconds>(E_build - S_build).count();
        Time_1 *= 1e-9;
        
        v1.push_back(Time_1);
        target*=10;
    }
    Q_stack.clear();
    
    target=1;
    while(target<=10000){
        
        for (int i=1;i<=target;i++) Q_stack.enqueue(i);
        
        auto S_de = chrono::high_resolution_clock::now();
        for (int i=1;i<=target;i++) Q_stack.dequeue();
        auto E_de = chrono::high_resolution_clock::now();
        
        
        float Time_2 =
        chrono::duration_cast<chrono::nanoseconds>(E_de - S_de).count();
        Time_2 *= 1e-9;
        v2.push_back(Time_2);
        
        target*=10;
    }
    cout<<"INPUT CHARACTERISTICS of Queue using stack: \n";
    cout<<"-------------------------------------------\n";
    cout<<"Time taken in Enqueue (in sec* 10e5):\n";
    int tar=1;
    for (auto x:v1) {cout<<"n="<<tar<<" "<<x*10e5<<"\n";tar*=10;}
    cout<<endl<<endl;
    tar=1;
    cout<<"Time taken in Dequeue (in sec* 10e5):\n";
    for (auto x:v2) {cout<<"n="<<tar<<" "<<x*10e5<<"\n";tar*=10;}
    cout<<endl;
   
    //Memory clear at the end
    Q_stack.clear();
    



return 0;
}

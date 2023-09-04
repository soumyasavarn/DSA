//Soumya Savarn
/*Efficiency comparision between STL and self implemented queues and stacks using chrono library*/
#include <bits/stdc++.h>
using namespace std;

struct node{
    struct node *prev;
    int data;
    struct node *next;
};


struct node *rear=0,*Front=0;


struct Queue
{
    
   
    
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
    
    
    void clear()
    {
        while (rear!=Front) dequeue();
    }
}Q;

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
    
    void clear()
    {
        while (top!=NULL) pop();
    }
}S;

    
    
 
            
int main()
{
    cout<<"Performing automated experiment of pushing 1000 numbers to both queues & stacks and popping 1000 numbers"<<endl;
    
    queue <int> q;
    auto S_build = chrono::high_resolution_clock::now();
    for (int i=1;i<1000;i++) q.push(i);
    auto E_build = chrono::high_resolution_clock::now();
    
    auto S_de = chrono::high_resolution_clock::now();
    for (int i=1;i<1000;i++) q.pop();
    auto E_de = chrono::high_resolution_clock::now();
    
    float Time_1 =
    chrono::duration_cast<chrono::nanoseconds>(E_build - S_build).count();
    Time_1 *= 1e-9;
    
    float Time_2 =
    chrono::duration_cast<chrono::nanoseconds>(E_de - S_de).count();
    Time_2 *= 1e-9;
    
    cout<<setprecision(9);
    cout<<"SUMMARY for STL QUEUE:"<<endl;
    cout<<"-----------------------------------"<<endl;
    cout<<"TIME TAKEN: "<<endl;
    cout<<"In ENQUEUE: "<<Time_1<<"sec"<<endl;
    cout<<"In DEQUEUE: "<<Time_2<<"sec"<<endl<<endl;
   
   
    Front= new struct node;
    Front->next=NULL;
    Front->prev=NULL;
    rear=Front;
   
    auto s_build = chrono::high_resolution_clock::now();
    for (int i=1;i<=1000;i++) Q.enqueue(i);
    auto e_build = chrono::high_resolution_clock::now();
    
    auto s_de = chrono::high_resolution_clock::now();
    for (int i=1;i<1000;i++) Q.dequeue();
    auto e_de = chrono::high_resolution_clock::now();
    
    float time_1 =
    chrono::duration_cast<chrono::nanoseconds>(e_build - s_build).count();
    time_1 *= 1e-9;
    
    float time_2 =
    chrono::duration_cast<chrono::nanoseconds>(e_de - s_de).count();
    time_2 *= 1e-9;
    
    cout<<setprecision(9);
    cout<<"SUMMARY for self implemented QUEUE :"<<endl;
    cout<<"-----------------------------------"<<endl;
    cout<<"TIME TAKEN: "<<endl;
    cout<<"In ENQUEUE: "<<time_1<<"sec"<<endl;
    cout<<"In DEQUEUE: "<<time_2<<"sec"<<endl<<endl;
    
    stack <int> s;
    S_build = chrono::high_resolution_clock::now();
    for (int i=1;i<1000;i++) s.push(i);
    E_build = chrono::high_resolution_clock::now();
    
    S_de = chrono::high_resolution_clock::now();
    for (int i=1;i<1000;i++) s.pop();
    E_de = chrono::high_resolution_clock::now();
    
    Time_1 =
    chrono::duration_cast<chrono::nanoseconds>(E_build - S_build).count();
    Time_1 *= 1e-9;
    
    Time_2 =
    chrono::duration_cast<chrono::nanoseconds>(E_de - S_de).count();
    Time_2 *= 1e-9;
    
    cout<<setprecision(9);
    cout<<"SUMMARY for STL STACK:"<<endl;
    cout<<"-----------------------------------"<<endl;
    cout<<"TIME TAKEN: "<<endl;
    cout<<"In PUSH: "<<Time_1<<"sec"<<endl;
    cout<<"In POP: "<<Time_2<<"sec"<<endl<<endl;
   
  
   
    s_build = chrono::high_resolution_clock::now();
    for (int i=1;i<=1000;i++) S.push(i);
    e_build = chrono::high_resolution_clock::now();
    
    s_de = chrono::high_resolution_clock::now();
    for (int i=1;i<1000;i++) S.pop();
    e_de = chrono::high_resolution_clock::now();
    
    time_1 =
    chrono::duration_cast<chrono::nanoseconds>(e_build - s_build).count();
    time_1 *= 1e-9;
    
    time_2 =
    chrono::duration_cast<chrono::nanoseconds>(e_de - s_de).count();
    time_2 *= 1e-9;
    
    cout<<setprecision(9);
    cout<<"SUMMARY for self implemented STACK :"<<endl;
    cout<<"-----------------------------------"<<endl;
    cout<<"TIME TAKEN: "<<endl;
    cout<<"In PUSH: "<<time_1<<"sec"<<endl;
    cout<<"In POP: "<<time_2<<"sec"<<endl<<endl;
    
    
    
    
   
    
    
    //Memory clear at the end

    Q.clear();
    S.clear();


return 0;
}

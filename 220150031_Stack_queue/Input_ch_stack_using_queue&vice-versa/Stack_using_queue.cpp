#include <iostream>
#include <chrono>
#include <iomanip>
#include <vector>


using namespace std;

struct node{
    struct node *prev;
    int data;
    struct node *next;
};




class Queue
{
    struct node *rear=0,*Front=0;
    public:
    Queue()
    {
        Front= new struct node;
        Front->next=NULL;
        Front->prev=NULL;
        rear=Front;
    }
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
};

struct Stack_using_queue{
    Queue q,q_buff;
    void push(int x)
    {
        q_buff.enqueue(x);
        while(!q.isEmpty())
        {
            q_buff.enqueue(q.front());
            q.dequeue();
        }
        //q is empty
        
        Queue temp;
        temp=q_buff;
        q_buff=q;
        q=temp;
    }
    void pop()
    {
        if (q.isEmpty()) {cout<<"Underflow"<<endl;return;}
        q.dequeue();
    }
    
    void clear()
    {
        q.clear();
    }
    
};
 
            
int main()
{

    
    
    
    struct Stack_using_queue S_queue;
        
        int target=1;
        vector <float> v1,v2;
        while(target<=10000){
            auto S_build = chrono::high_resolution_clock::now();
            for (int i=1;i<=target;i++) S_queue.push(i);
            auto E_build = chrono::high_resolution_clock::now();
            
            float Time_1 =
            chrono::duration_cast<chrono::nanoseconds>(E_build - S_build).count();
            Time_1 *= 1e-9;
            
            v1.push_back(Time_1);
            target*=10;
        }
        S_queue.clear();
        
        target=1;
        while(target<=10000){
            
            for (int i=1;i<=target;i++) S_queue.push(i);
            
            auto S_de = chrono::high_resolution_clock::now();
            for (int i=1;i<=target;i++) S_queue.pop();
            auto E_de = chrono::high_resolution_clock::now();
            
            
            float Time_2 =
            chrono::duration_cast<chrono::nanoseconds>(E_de - S_de).count();
            Time_2 *= 1e-9;
            v2.push_back(Time_2);
            
            target*=10;
        }
        cout<<"INPUT CHARACTERISTICS of Stack using queue: \n";
        cout<<"-------------------------------------------\n";
        cout<<"Time taken in Push (in sec* 10e5):\n";
        int tar=1;
        for (auto x:v1) {cout<<"n="<<tar<<" "<<x*10e5<<"\n";tar*=10;}
        cout<<endl<<endl;
        tar=1;
        cout<<"Time taken in Pop (in sec* 10e5):\n";
        for (auto x:v2) {cout<<"n="<<tar<<" "<<x*10e5<<"\n";tar*=10;}
        cout<<endl;
       
        //Memory clear at the end
        S_queue.clear();
        



return 0;
}

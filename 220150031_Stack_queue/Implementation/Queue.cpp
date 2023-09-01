#include <iostream>

using namespace std;

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
            cout << "Queue is empty\n" << endl;
        }
        else {
            tmp=tmp->next;
            while(tmp!=NULL) {cout<<tmp->data<<" ";tmp=tmp->next;}
            cout<<endl;
        }
        
    }
    
    
    void clear()
    {
        while (rear!=Front) dequeue();
    }
};


void menu()
{
    cout<<endl;
    cout<<"Press the key for the  following\n";
    cout<<"1. Dequeue\n2. Enqueue\n3. Is empty check\n 4. Get Front element\n5. Display\n6. Exit\n";
    cout<<endl;
    cout<<endl;

}
 
            
int main()
{

    Front= new struct node;
    Front->next=NULL;
    Front->prev=NULL;
    rear=Front;
    
    Queue q;
    cout<<"Enter the elements (press -1 to stop): \n";
    while(1)
    {
        int x;
        cin>>x;
        if (x==-1) break;
        q.enqueue(x);
    }
    
    
    while (1)
    {
    
    
    menu();
    int a;
    cin>>a;
    if (a==1) q.dequeue();
    if (a==2) {cout<<"Enter the element: ";int k;cin>>k;q.enqueue(k);}
    if (a==3) {if (q.isEmpty()) cout<<"Empty"<<endl;else cout<<"Not Empty\n";}
    if (a==4) {cout<<q.front()<<endl;}
    if (a==5) {q.display();}
    if (a==6) {break;}
    
    }
    
    //Memory clear at the end
    q.clear();
    



return 0;
}

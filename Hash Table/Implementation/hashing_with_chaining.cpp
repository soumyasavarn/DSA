//Implementing Hash-table with chaining using doubly LL
/*Here key is generated automatically using hash function*/
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;
/*
Soumya Savarn
220150031
DSAI
*/

int bucket=1;

class hash_table{
  private:
    struct node{
    struct node *prev;
    int data;
    struct node *next;
    };
    node **a;
  public:  
    hash_table()
    {
        a=new node*[bucket];
        for (int i=0;i<bucket;i++) a[i]=NULL;
    };
    
    int hash_key(int n)
    {
        return n%bucket;
    }
    
    void insert(int n)
    {
        int key=hash_key(n);
        node *temp = new node;
        temp->data=n;
        temp->next=NULL;
        
        node *trav=a[key];
        if (trav==NULL) {temp->prev=NULL; a[key]=temp; return;}
        
        while(trav->next != NULL) trav=trav->next;
        
        temp->prev=trav;
        trav->next=temp;
    }
    
    void delete_val(int n)
    {
       int key=hash_key(n);
       node *trav=a[key];
       if (trav==0) {cout<<"Not found !!"<<endl; return;}
       while(trav!= NULL) {if (trav->data==n) break; trav=trav->next;}
       if (trav==0) {cout<<"Not found !!"<<endl; return;}
       if (trav->prev==NULL) {a[key]=trav->next; if (trav->next!=NULL) trav->next->prev=NULL; free(trav);return;}
       node *curr =trav;
       trav=trav->prev;
       trav->next=curr->next;
       if (curr->next != NULL)
       curr->next->prev=trav;
       free (curr);
       
    }
    
    void search(int n)
    {
       int key=hash_key(n);
       node *trav=a[key];
       if (!trav) {cout<<"Not found !!"<<endl; return;}
       while(trav->data != n && trav->next!= NULL) trav=trav->next;
       if (!trav) {cout<<"Not found !!"<<endl; return;}
       cout<<"Found at key "<<key<<endl;
       
    }
    
    void display()
    {
        for (int i=0;i<bucket;i++)
        {
            node *t = a[i];
            cout<<"Key "<<i<<": ";
            while (t!=NULL) {
            if (t->next==NULL) cout<<t->data; 
            else cout<<t->data<<" -> "; 
            t=t->next;
            }
            cout<<endl;
        }
    }
    
    void clear()
    {
        for (int i=0;i<bucket;i++) free(a[i]);
        free(a);
    }
    
    
};    

void menu()
{
    cout<<endl;
    cout<<"Press the key for the  following\n";
    cout<<"1. Insert\n2. Search\n3. Delete\n 4. Display\n5. Exit\n";
    cout<<endl;
    cout<<endl;

}

int main()
{
    
    cout<<"Enter bucket size: ";
    cin>>bucket;
    
    hash_table h;
    
    
    cout<<"HASH TABLE CREATED SUCCESFULLY !"<<endl;
    
    while (1)
    {
    
    
    menu();
    int v;
    cin>>v;
    if (v==1) {int x; cout<<"Enter the number: "; cin>>x; h.insert(x);}
    if (v==2) {int x; cout<<"Enter the number: "; cin>>x; h.search(x);}
    if (v==3) {int x; cout<<"Enter the number: "; cin>>x; h.delete_val(x);}
    if (v==4) {h.display();}
    if (v==5) {break;}
    
    
    }
    
    /*Memory clear at the end*/
    h.clear();
    
    
    return 0;
}




/*
Soumya Savarn
220150031
DSAI
*/

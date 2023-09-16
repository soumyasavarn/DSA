//Soumya Savarn
/*Efficiency comparision between STL and self implemented hash table using chrono library*/

/* !! Directly run this program !!*/

#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <list>



using namespace std;

/*
Soumya Savarn
220150031
DSAI
*/

int bucket=1000;

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
       if (!trav) { return;}
       while(trav->data != n && trav->next!= NULL) trav=trav->next;
       if (!trav) { return;}
       
       
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
    
 
            
int main()
{
    cout<<"Performing automated experiment of pushing 1000 numbers to both unordered_map(STL) and self-implemented hash table and performing some operations"<<endl;
    
    unordered_map<int,list<int>> m;
    
    auto S_build = chrono::high_resolution_clock::now();
    for (int i=1;i<1000;i++) m[i%1000].push_back(i);
    auto E_build = chrono::high_resolution_clock::now();
    
    auto S_s = chrono::high_resolution_clock::now();
    for (int i=1;i<100;i++)
    {
        for (auto x:m[i%1000]) if (x==i) break;
    }
        
    auto E_s = chrono::high_resolution_clock::now();
    
    
    
    auto S_de = chrono::high_resolution_clock::now();
    for (int i=1;i<1000;i++)
        
    {
        m[i%1000].remove(i);
    }
        
        
    auto E_de =
    chrono::high_resolution_clock::now();
    
    
    
    
    float Time_1 =
    chrono::duration_cast<chrono::nanoseconds>(E_build - S_build).count();
    Time_1 *= 1e-9;
    
    float Time_2 =
    chrono::duration_cast<chrono::nanoseconds>(E_de - S_de).count();
    Time_2 *= 1e-9;
    
    float Time_3 =
    chrono::duration_cast<chrono::nanoseconds>(E_s - S_s).count();
    Time_3 *= 1e-9;
    
    cout<<setprecision(9);
    cout<<"SUMMARY for STL HASH-TABLE:"<<endl;
    cout<<"-----------------------------------"<<endl;
    cout<<"TIME TAKEN: "<<endl;
    cout<<"In INSERT: "<<Time_1<<"ms"<<endl;
    cout<<"In SEARCH: "<<Time_3<<"ms"<<endl;
    cout<<"In DELETE:"<<Time_2<<"ms"<<endl<<endl;

    hash_table h;
   
    auto s_build = chrono::high_resolution_clock::now();
    for (int i=1;i<=1000;i++) h.insert(i);
    auto e_build = chrono::high_resolution_clock::now();
    
    auto s_s = chrono::high_resolution_clock::now();
    for (int i=1;i<100;i++) h.search(i);
    auto e_s = chrono::high_resolution_clock::now();
    
    auto s_de = chrono::high_resolution_clock::now();
    for (int i=1;i<1000;i++) h.delete_val(i);
    auto e_de = chrono::high_resolution_clock::now();
    
    float time_1 =
    chrono::duration_cast<chrono::nanoseconds>(e_build - s_build).count();
    time_1 *= 1e-9;
    
    float time_2 =
    chrono::duration_cast<chrono::nanoseconds>(e_de - s_de).count();
    time_2 *= 1e-9;
    
    float time_3 =
    chrono::duration_cast<chrono::nanoseconds>(e_s - s_s).count();
    time_2 *= 1e-9;
    
    cout<<setprecision(9);
    cout<<"SUMMARY for self implemented HASH-TABLE :"<<endl;
    cout<<"-----------------------------------"<<endl;
    cout<<"TIME TAKEN: "<<endl;
    cout<<"In INSERT: "<<time_1<<"ms"<<endl;
    cout<<"In SEARCH: "<<time_3<<"ms"<<endl;
    cout<<"In DELETE: "<<time_2<<"ms"<<endl<<endl;
    
    cout<<"NOTE:"<<endl;
    cout<<"This does not mean that our table is better at insertion because \nour table is implemented using arrays and that of STL is\n done using trees which are more dynamic and flexible \nin multiple queries\n"<<endl;
    //Memory clear at the end

    h.clear();

return 0;
}

/*Soumya Savarn
 220150031
 DSAI*/

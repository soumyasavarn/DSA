/*Soumya Savarn
220150031
DSAI
*/

/*Implementation of graph using adjacency list built using dynamic memory allocation.
Planarity check is based on Euler's Theorem which rules out the possibility of planarity
if edges > 3 * vertices - 6 else it can't give a guarantee of non-Planarity.
For that we need some advanced techniques using Kuratowski's Theorem or C++ Boost libraries*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>


using namespace std;


class graph{
  public:
  
  class node{
    public:
    int data;
    node *next;
  };
  int n,ncopy;
  int m,mcopy;
  node **arr;
  
  void add_edge (int a,int b)
  {
      
      /*check for already existing*/
      node *tr=arr[a];
      while(tr!=0)
      {
          if (tr->data==b) return;
          tr=tr->next;
      }
      
      
        node *t1=arr[a],*t2=arr[b];
        node *t11=new node,*t22=new node;
        t11->next=NULL;
        t11->data=b;
        
        t22->next=NULL;
        t22->data=a;
        
        if (t1==NULL) arr[a]=t11;
        else {
        while(t1->next!=NULL)
        {
            t1=t1->next;
        }
        t1->next=t11;
        }
        
        if (t2==NULL) arr[b]=t22;
        else {
        while(t2->next!=NULL)
        {
            t2=t2->next;
        }
        t2->next=t22;
        }
       
        
        
        
        
  }
  
  graph()
  {
      cout<<"Enter number of nodes: ";
      cin>>n;
      cout<<"Enter number of edges: ";
      cin>>m;
      arr =new node *[n+4];
      ncopy=n;
      mcopy=m;
      for (int i=1;i<=n;i++)
      {
          arr[i]=NULL;
          
      }
      cout<<"Start entering edge pairs: "<<endl;
      for (int i=0;i<m;i++)
      {
          int x,y;
          cin>>x>>y;
          add_edge(x,y);
        //   cout<<"done";
      }
          
  }
  
   void remove_edge (int a,int b)
  {
      
       node *t1=arr[a],*t2=arr[b];
       
       node *tail=arr[a];
        
        while(t1!=NULL)
        {
            if (t1->data==b)
            {
                if (tail==arr[a]) {arr[a]=tail->next;break;}
                tail->next=t1->next;
                
                break;
            }
            tail=t1;
            t1=t1->next;
        }
           
       tail=arr[b];
        while(t2!=NULL)
        {
            if (t2->data==a)
            {
                if (tail==arr[b]) {arr[b]=tail->next;break;}
                tail->next=t2->next;
                
                break;
            }
            tail=t2;
            t2=t2->next;
        }
        mcopy--;
        
        
        
  }
  
  void remove_vertex(int a)
  {
       node *t1=arr[a];
       int c=0;
       while(t1!=NULL)
        {
            c++;
            t1=t1->next;
        }
        for (int i=1;i<=n;i++)
        {
            if (i==a) continue;
            node *t=arr[i],*tail=arr[i];
            while (t!=0)
            {
                if (t->data==a)
                {
                    if (tail==arr[i]) {arr[i]=tail->next;break;}
                    tail->next=t->next;
                    
                    break;
                }
                tail=t;
                t=t->next;
            }
        }
        ncopy--;
        mcopy-=c;
        arr[a]=NULL;
  }
  
  void planarity()
  {
      if (mcopy > 3 * ncopy - 6) cout<<"Definately Non-Planar"<<endl;
      else cout<<"Maybe Planar"<<endl;
  }
  
  void display_graph()
  {
      for (int i=1;i<=n;i++) if (arr[i]!=NULL) {
          node *trav=arr[i];
          cout<<i<<": ";
          while(trav!=0) {cout<<trav->data<<" ";trav=trav->next;}
          cout<<endl;
          
         }
     
  }
    void clear()
    {
        for (int i=1;i<=n;i++)
        {
            free(arr[i]);
        }
        free (arr);
    }
};



int main()
{
    graph g;
    cout<<"Graph inintialised successfully !"<<endl;
    
    while(1)
    {
        cout<<"Choose from below"<<endl;
        cout<<"1. Add an edge"<<endl;
        cout<<"2. Remove an edge"<<endl;
        cout<<"3. Remove a vertex"<<endl;
        cout<<"4. Display the graph"<<endl;
        cout<<"5. Check for Planarity (Euler's Theorem)"<<endl;
        cout<<"6. Exit"<<endl;
        int k;
        cin>>k;
        if (k==1)
        {
        cout<<"Enter edge pair: ";
        int a,b;
        cin>>a>>b;
        g.add_edge(a,b);
        }
        if (k==2)
        {
        cout<<"Enter edge pair: ";
        int a,b;
        cin>>a>>b;
        g.remove_edge(a,b);
        }
        if (k==3)
        {
        cout<<"Enter vertex: ";
        int a;
        cin>>a;
        g.remove_vertex(a);
        }
        if (k==4)
        {
            g.display_graph();
        }
        if (k==5)
        {
            g.planarity();
        }
            
        if (k==6) break;
        

    }
    
    cout<<"Thank You !!"<<endl;

    //memory clear
    g.clear();
    
    
    return 0;
}
/*Soumya Savarn
220150031
DSAI
*/

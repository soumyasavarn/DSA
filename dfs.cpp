/*Soumya Savarn
220150031
DSAI
*/

/*Implementation of graph using adjacency list built using dynamic memory allocation.
Planarity check is based on Euler's Theorem which rules out the possibility of planarity 
if edges > 3 * vertices - 6 else it can't give a guarantee of non-Planarity.
For that we need some advanced techniques using Kuratowski's Theorem or C++ Boost libraries*/

#include <bits/stdc++.h>
using namespace std;

bool vis[1000001];
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
  
  void DFS(int a)
  {
      if (vis[a]) return;
      vis[a]=1;
      cout<<a<<" - ";
      node *t=arr[a];
      while (t!=0)
      {
          DFS(t->data);
          t=t->next;
      }
      
  }
 
  
  
  
  void is_tree()
  {
      for (int i=1;i<=n;i++)
      {
          DFS2(i);
          
      }
  }
  
  
  
  void display_graph()
  {
      int c=0;
      for (int i=1;i<=n;i++) if (arr[i]!=NULL) {
          node *trav=arr[i];
          cout<<i<<": ";
          while(trav!=0) {cout<<trav->data<<" ";trav=trav->next;}
          cout<<endl;
          
         }
     
  }
};



int main()
{
    graph g;
    cout<<"Graph inintialised successfully !"<<endl;
    
    while(1)
    {
        cout<<"Choose from below"<<endl;
        cout<<"1. Run DFS"<<endl;
        cout<<"2. Run BFS"<<endl;
        cout<<"3. Check for Tree"<<endl;
        cout<<"4. Display the graph"<<endl;
        cout<<"5. Exit"<<endl;
        int k;
        cin>>k;
        if (k==1) 
        {
        cout<<"Enter vertex: "; 
        int a;
        cin>>a;
        g.DFS(a);
        cout<<endl;
        for (auto &x:vis) x=0;
        }
        if (k==2) 
        {
        cout<<"Enter vertex: "; 
        int a;
        cin>>a;
        // g.BFS(a);
        for (auto &x:vis) x=0;
        }
        if (k==3) 
        {
        cout<<"Enter vertex: "; 
        int a;
        cin>>a;
        // g.remove_vertex(a);
        }
        
        if (k==4)
        {
            g.display_graph();
        }
      
            
        if (k==5) break;
        

    }
    
    cout<<"Thank You !!"<<endl;

    return 0;
}
/*Soumya Savarn
220150031
DSAI
*/

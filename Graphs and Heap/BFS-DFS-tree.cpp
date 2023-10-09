/*Soumya Savarn
220150031
DSAI
*/

/*Implementation of graph using adjacency list built using dynamic memory allocation.
Implementation of DFS and BFS after that check whether the graph is a tree or not
by cycle detection using DFS
*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <queue>


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
  
  void DFS(int a)
  {
      if (vis[a]) return;
      vis[a]=1;
      cout<<a<<"-";
      node *t=arr[a];
      while (t!=0)
      {
          DFS(t->data);
          t=t->next;
      }
      
  }
  
  void BFS(int a)
  {
      queue <int> q;
      q.push(a);
      
      while(!q.empty())
      {
          int s=q.front();
          q.pop();
          
          if (vis[s]==0)cout<<s<<"-";
          vis[s]=1;
          node *trav=arr[s];
          while(trav!=0)
          {
              if (vis[trav->data]==0) q.push(trav->data);
              trav=trav->next;
          }
          
      }
      cout<<endl;
      
  }
  
  void cycle_check_dfs(int a)
  {
     
      if (vis[a]) return ;
      vis[a]=1;
      node *t=arr[a];
      while (t!=0)
      {
          cycle_check_dfs(t->data);
          t=t->next;
      }
      return ;
      
  }
  
  
  
  bool is_tree()
  {
      cycle_check_dfs(1);
      for (int i=2;i<=n;i++) if (vis[i]==0) return 0;
      //Since whole graph is connected
      if (m==n-1) return 1;
      else return 0;
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
        g.BFS(a);
        for (auto &x:vis) x=0;
        }
        
        if (k==3)
        {
        if (g.is_tree()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        for (auto &x:vis) x=0;
        }
        
        if (k==4)
        {
            g.display_graph();
        }
      
            
        if (k==5) break;
        

    }
    
    cout<<"Thank You !!"<<endl;
    
    //Memory clear at end
    g.clear();
    
    
    return 0;
}
/*Soumya Savarn
220150031
DSAI
*/

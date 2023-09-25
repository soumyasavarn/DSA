#include <bits/stdc++.h>
using namespace std;


class graph{
  public:
  
  class node{
     public:
    int data;
    node *next;
  };
  int n;
  int m;
  node **arr;
  
  void add_edge (int a,int b)
  {
      
        node *t1=arr[a],*t2=arr[b];
        node *t11=new node,*t22=new node;
        t11->next=NULL;
        t11->data=b;
        
        t22->next=NULL;
        t22->data=a;
        
        if (t1==NULL) t1=t11;
        else {
        while(t1->next!=NULL)
        {
            t1=t1->next;
        }
        t1->next=t11;
        }
        
        if (t2==NULL) t2=t22;
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
      arr =new node *[n+1];
      
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
          
      } 
  }
  
  void display_vertices()
  {
      int c=0;
      for (int i=1;i<=n;i++) if (arr[i]->next!=NULL) {cout<<arr[i]->data<<endl;c++;}
      cout<<"Total: "<<c<<endl;
  }
  
//   void display_all()
//   {
//       for (int i=1;i<=n;i++) {
//           if (x.next!=NULL) {
//               node *t=x;
//               cout<<t->data<<": ";
//               while(t!=NULL) cout<<t->data<<" ";
//               cout<<endl;
//           }
          
//       }
//   }
      
  
  
};



int main()
{
    graph g;
    g.display_vertices();

    return 0;
}

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <stdlib.h>
#include <chrono>
#include <climits>
#include <vector>
#include <cmath>

#include "time.h"

#define inf INT_MAX
using namespace std;

/*Soumya Savarn
220150031
DSAI
*/
int mini(int a,int b)
{
    if (a<b) return a;
    else return b;
}
void BellmanFord(vector <pair < int,int> > v[],int n,int s)
{
    int dis[n+1];
    for (int i=0;i<=n;i++) dis[i]=inf;
    dis[s]=0;
    for (int i=0;i<n-1;i++)
    {
        for (int j=1;j<=n;j++)
        {
            for (int k=0;k<v[j].size();k++)
                dis[v[j][k].first]=mini(dis[v[j][k].first],dis[j]+v[j][k].second);
        }
    }
    cout<<"Shortest Path from "<<s<<" to all other nodes: "<<endl;
    for (int i=1;i<=n;i++) cout<<"Node "<<i<<": "<<dis[i]<<endl;
    
}

void Dijkstra (vector <pair < int,int> > v[],int n,int s)
{
    int vis[n+1];
    int dis[n+1];
    for (int i = 1; i <= n; i++) {dis[i] = inf;vis[i]=0;}
    dis[s] = 0;
    priority_queue <pair<int,int> > q;
        q.push(make_pair(0,s));
    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (vis[a]) continue;
        vis[a] = 1;
        for (int k=0;k<v[a].size();k++) {
            int b = v[a][k].first, w = v[a][k].second;
            if (dis[a]+w < dis[b]) {
                dis[b] = dis[a]+w;
                q.push(make_pair(-dis[b],b));
                /*We are adding negative of distance because by default priority is minimum in STL */
            }
        }
    }
    
    cout<<"Shortest Path from "<<s<<" to all other nodes: "<<endl;
    for (int i=1;i<=n;i++) cout<<"Node "<<i<<": "<<dis[i]<<endl;
}

void FloydWarshall(vector <pair < int,int> > v[],int n,int s)
{
    int a[n+1][n+1];
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (i==j) a[i][j]=0;
            else a[i][j]=inf;
        }
    }
    
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<v[i].size();j++)
        {
            a[i][v[i][j].first]=v[i][j].second;
        }
    }
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                a[i][j] = mini(a[i][j],a[i][k]+a[k][j]);
            }}}
    
    cout<<"Shortest Path from "<<s<<" to all other nodes: "<<endl;
    for (int i=1;i<=n;i++) cout<<"Node "<<i<<": "<<a[s][i]<<endl;
    
    
}

signed main()
{


    while(1)
    {
        int n,m;
        cout<<"Enter the no. of nodes you want to enter: ";
        cin>>n;
        cout<<"Enter the no. of edges you want to enter: ";
        cin>>m;
        vector < pair <int,int> > v[n+1];
        for (int i=0;i<m;i++)
        {
            cout<<"Enter edge pair along with weights as (a,b,w) : ";
            int a,b,w;
            cin>>a>>b>>w;
            v[a].push_back(make_pair(b,w));
        }
        
        int choose,node;
        
        cout<<"Algorithms:"<<endl;
        cout<<"-----------"<<endl;
        cout<<"1. Bellman-Ford"<<endl;
        cout<<"2. Djikstra's"<<endl;
        cout<<"3. Floyd Warshall"<<endl;
        cout<<"Enter your choice: ";
        cin>>choose;
        cout<<"Enter the node from which you want to find shortest path: ";
        cin>>node;
        
        if (choose==1)
        {
            BellmanFord(v,n,node);
        }
        
        if (choose==2)
        {
            Dijkstra(v,n,node);
        }
        
        if (choose==3)
        {
            FloydWarshall(v,n,node);
        }



        //Memory clear at the end
            for (int i=1;i<=n;i++)
            {
                v[i].clear();
            }


        cout<<"Do you wish to continue? (Y/N)"<<endl;
        char x;
        cin>>x;
        if (x=='N') break;
        
    

    }
    cout<<"Want to do Nodes vs input size comparision? (Y/N)"<<endl;
    char x;
    cin>>x;
    if (x=='Y') time_analysis();

    cout<<endl;
    cout<<"THANK YOU!"<<endl;

    return 0;
}
/*Soumya Savarn
220150031
DSAI
*/

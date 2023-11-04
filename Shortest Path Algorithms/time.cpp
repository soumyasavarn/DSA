#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
#include <chrono>
#include <climits>
#include <vector>
#include <queue>
#include <cmath>
#include "algo.h"

#define inf INT_MAX
#define int long long

using namespace std;

int mini2(int a,int b)
{
    if (a<b) return a;
    else return b;
}

vector <pair<int,int> > v[1000001];

void BellmanFord2(int n,int s)
{
    int dis[n+1];
    for (int i=0;i<=n;i++) dis[i]=inf;
    dis[s]=0;
    for (int i=0;i<n-1;i++)
    {
        for (int j=1;j<=n;j++)
        {
            for (int k=0;k<v[j].size();k++)
                dis[v[j][k].first]=mini2(dis[v[j][k].first],dis[j]+v[j][k].second);
        }
    }

}

    int vis[1000001];
    int dis[1000001];
void Dijkstra2 (int n,int s)
{
    
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
    
    

}
void FloydWarshall2(int n,int s)
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
                a[i][j] = mini2(a[i][j],a[i][k]+a[k][j]);
            }}}
    
    
    
    
}


void time_analysis()
{
    vector <float> b,d,f;
    int n;
    int data_points[5];
    data_points[0]=100;
    data_points[1]=1000;
    data_points[2]=10000;
    data_points[3]=100000;
    data_points[4]=1000000;

    for (int z=0;z<5;z++)
    {
        n=data_points[z];
        for (int i=1;i<n;i++)
        {
            v[i].push_back(make_pair(i+1,rand()%1911) ) ;
        }
        
        
        
        
        
        
            std::chrono::time_point<std::chrono::system_clock> S_stl, E_stl;
            S_stl = std::chrono::system_clock::now();
            if (data_points[z]<=10000) BellmanFord2(n,1);
            E_stl = std::chrono::system_clock::now();
        
            std::chrono::time_point<std::chrono::system_clock> S_insert, E_insert;
             S_insert = std::chrono::system_clock::now();
            Dijkstra2(n,1);
            E_insert = std::chrono::system_clock::now();
            
        
             std::chrono::time_point<std::chrono::system_clock> S_select, E_select;
             S_select = std::chrono::system_clock::now();
             if (data_points[z]<=1000)FloydWarshall2(n,1);
             E_select = std::chrono::system_clock::now();
            
        
        
        
        
        
        
                float Time_1 =
                chrono::duration_cast<chrono::nanoseconds>(E_stl - S_stl).count();
                Time_1 *= 1e-9;
        
                float Time_2 =
                chrono::duration_cast<chrono::nanoseconds>(E_insert - S_insert).count();
                Time_2 *= 1e-9;
        
                float Time_3 =
                chrono::duration_cast<chrono::nanoseconds>(E_select - S_select).count();
                Time_3 *= 1e-9;
        
        b.push_back(Time_1*10e3);
        d.push_back(Time_2*10e3);
        f.push_back(Time_3*10e3);

        
        for (int i=1;i<=n;i++) v[i].clear();
        
        
        
        
        
    }
        
        
        
        

        cout<<setprecision(9);
        cout<<"SUMMARY for Efficiency vs input:"<<endl;
        cout<<"--------------------------------"<<endl;
    cout<<"Input Size     | 100         | 1000              | 10000       | 100000         | 1000000"<<endl;
    cout<<"Bellman-Ford   | ";
    for (int i=0;i<b.size();i++) {if (b[i]>1 || i==0) cout<<b[i]<<"       "; else cout<<"TLE             ";}
    cout<<endl;
    cout<<"Dijkstra's     | ";
    for (int i=0;i<d.size();i++) cout<<d[i]<<"       ";
    cout<<endl;
    cout<<"Floyd-Warshall | ";
    for (int i=0;i<f.size();i++) {if (f[i]>1 || i==0) cout<<f[i]<<"        "; else cout<<"TLE             ";}
    cout<<endl;

    cout<<"NOTE: Data is in 10e3 seconds"<<endl;
    cout<<"END OF PROGRAM"<<endl<<endl;

}

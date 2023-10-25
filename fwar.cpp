#include <iostream>
#include <climits>
using namespace std;

#define INF INT_MAX
int mini (int a,int b)
{
    if (a>b) return b;
    else return a;
}
int main()
{
    int n,e;
    cout<<"Enter number of vertices: "<<endl;
    cin>>n;
    cout<<"Enter number of edges: "<<endl;
    cin>>e;
    int a[n+1][n+1],distance[n+1][n+1];
    for (int i=0;i<e;i++)
    {
        int v1,v2,w;
        cout<<"Enter edge pair separated with space: ";
        cin>>v1>>v2;
        cout<<"Enter weight: ";
        cin>>w;
        a[v1][v2]=w;
    }

        for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
        if (i == j) distance[i][j] = 0;
        else if (a[i][j]) distance[i][j] = a[i][j];
        else distance[i][j] = INF;
        }
    }
    
    for (int k=1;k<=n;k++)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                distance[i][j] = mini(distance[i][j],distance[i][k]+distance[k][j]);
            }
        }
    }
    
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout<<distance[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    
    
    return 0;
}

/*Soumya Savarn
220150031
DSAI
*/

/*Efficiency comparision with STL*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <vector>
#include <chrono>
#include <algorithm>
#include <bits/stdc++.h>


using namespace std;

//Following are the standard functions:

void max_insert(int a[],int pos)
{
    int temp=a[pos];
    int i=pos/2;
    int prev=pos;
    while (i>=1 && a[i]<temp)
    {
        swap(a[i],a[prev]);
        prev=i;
        i/=2;
    }
}

void min_insert(int a[],int pos)
{
    int temp=a[pos];
    int i=pos;
    int prev=pos;
    while (i>1 && a[i]>temp)
    {
        swap(a[i],a[prev]);
        prev=i;
        i/=2;
    }
    a[i]=temp;
}

void disp(int a[],int k)
{
    for (int i=1;i<=k;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void peek_root(int a[])
{
    cout<<"Root element: "<<a[1]<<endl;
}

void delete_root_max(int A[],int n)
{
    int i,j,x,temp,val;
    val=A[1];
    x=A[n];
    A[1]=A[n];
    A[n]=val;
    i=1;j=i*2;
    while(j<=n-1)
    {
        if(j<n-1 && A[j+1]>A[j])
            j=j+1;
        if(A[i]<A[j])
        {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            i=j;
            j=2*j;
        }
        
        else break;
    }
}
    
void delete_root_min(int A[],int n)
{
    int i,j,x,temp,val;
    val=A[1];
    x=A[n];
    A[1]=A[n];
    A[n]=val;
    i=1;j=i*2;
    while(j<=n-1)
    {
        if(j<n-1 && A[j+1]<A[j])
            j=j+1;
        if(A[i]>A[j])
        {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            i=j;
            j=2*j;
        }
        
        else break;
    }
}



int main()
{
    int *a=new int [100001];
    
    vector<int> v;
    
    
    for (int i=1;i<=10000;i++)
        a[i]=i;
    int last=10000;
    
    auto S_build = chrono::high_resolution_clock::now();
    for (int i=1;i<=10000;i++)
        v.push_back(i);
    make_heap(v.begin(),v.end());
    auto E_build = chrono::high_resolution_clock::now();
    
    auto S_de = chrono::high_resolution_clock::now();
    for (int i=1;i<=10000;i++)
        v.pop_back();
    auto E_de = chrono::high_resolution_clock::now();
    
    auto S = chrono::high_resolution_clock::now();
    for (int i=0;i<1000;i++) int k=v.front();
    auto E = chrono::high_resolution_clock::now();
    
    float Time_1 =
    chrono::duration_cast<chrono::nanoseconds>(E_build - S_build).count();
    Time_1 *= 1e-9;
    
    float Time_2 =
    chrono::duration_cast<chrono::nanoseconds>(E_de - S_de).count();
    Time_2 *= 1e-9;
    
    float Time_3 =
    chrono::duration_cast<chrono::nanoseconds>(E - S).count();
    Time_3 *= 1e-9;
    
    cout<<setprecision(9);
    cout<<"SUMMARY for STL HEAP:"<<endl;
    cout<<"-----------------------------------"<<endl;
    cout<<"TIME TAKEN: "<<endl;
    cout<<"In Insert: "<<Time_1*10e5<<" (in 10e5 sec)"<<endl;
    cout<<"In Delete: "<<Time_2*10e5<<" (in 10e5 sec)"<<endl;
    cout<<"In Displaying root node: "<<Time_3*10e5<<" (in 10e5 sec)"<<endl<<endl;
    
    
    auto s_build = chrono::high_resolution_clock::now();
    for (int i=1;i<=10000;i++) max_insert(a, i);
    auto e_build = chrono::high_resolution_clock::now();
    
    auto s_de = chrono::high_resolution_clock::now();
    for (int i=1;i<10000;i++) {delete_root_max(a, last);
    last--;}
    auto e_de = chrono::high_resolution_clock::now();
        
    auto s = chrono::high_resolution_clock::now();
    for (int i=1;i<1000;i++) {int k=a[1];}
    auto e = chrono::high_resolution_clock::now();
    
        float time_1 =
        chrono::duration_cast<chrono::nanoseconds>(e_build - s_build).count();
        time_1 *= 1e-9;
        
        float time_2 =
        chrono::duration_cast<chrono::nanoseconds>(e_de - s_de).count();
        time_2 *= 1e-9;
    
        float time_3 =
        chrono::duration_cast<chrono::nanoseconds>(e - s).count();
        time_3 *= 1e-9;
        
        cout<<setprecision(9);
        cout<<"SUMMARY for self implemented HEAP :"<<endl;
        cout<<"-----------------------------------"<<endl;
        cout<<"TIME TAKEN: "<<endl;
        cout<<"In Insert: "<<time_1*10e5<<" (in 10e5 sec)"<<endl;
        cout<<"In Delete: "<<time_2*10e5<<" (in 10e5 sec)"<<endl;
        cout<<"In Displaying Root Node: "<<time_3*10e5<<" (in 10e5 sec)"<<endl<<endl;
    
    cout<<endl;
    
    
    
    
    //Memory clear at end
    free(a);
    v.clear();
    
    return 0;
}
/*Soumya Savarn
220150031
DSAI
*/


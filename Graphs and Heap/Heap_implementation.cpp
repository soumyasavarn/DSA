/*Soumya Savarn
220150031
DSAI
*/

/*Implementation of max and min heap using dynamic memory allocation (arrays) .
 Note: 1 based indexing is followed
*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>



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
    
    //last keeps track of last element position
    int last=0;
    cout<<"Start entering the elements and press -1 if done: "<<endl;
    while(1)
    {
        int x;
        cin>>x;
        if (x==-1) break;
        a[++last]=x;
        
    }
    cout<<"Press 1 for Max Heap \n Press 2 for Min Heap: "<<endl;
    int c;
    cin>>c;
    
    //Max Heap Implementation
    if (c==1)
    {
        //Max Heapify
        for (int i=1;i<=last;i++)
        {
            
            max_insert(a,i);
        }

        cout << "Corresponding Max-Heap : "<<endl;
        disp(a,last);
        
        while(1)
        {
            cout<<"Choose from below"<<endl;
            cout<<"------------------"<<endl;
            cout<<"1. Insert"<<endl;
            cout<<"2. Delete root"<<endl;
            cout<<"3. Peek for root"<<endl;
            cout<<"4. Display Heap"<<endl;
            cout<<"5. Exit"<<endl;
            
            int k;
            cin>>k;
            
            
            if (k==1)
            {
            cout<<"Enter the value to be inserted: ";
            int val;
            cin>>val;
                a[++last]=val;
                max_insert(a,last);
            }
            
            if (k==2)
            {
                delete_root_max(a,last);
                last--;
            }
            
            if (k==3)
            {
                peek_root(a);
            }
          
            if (k==4)
            {
                disp(a,last);
            }
            if (k==5) break;
            

        }
    }
    
    
    //Min Heap Implementation
    else if (c==2)
    {
        //Min Heapify
        for (int i=1;i<=last;i++)
        {
            
            min_insert(a,i);
        }
        cout << "Corresponding Min-Heap : "<<endl;
        disp(a,last);
        
        while(1)
        {
            cout<<"Choose from below"<<endl;
            cout<<"------------------"<<endl;
            cout<<"1. Insert"<<endl;
            cout<<"2. Delete root"<<endl;
            cout<<"3. Peek for root"<<endl;
            cout<<"4. Display Heap"<<endl;
            cout<<"5. Exit"<<endl;
            
            int k;
            cin>>k;
            
            
            if (k==1)
            {
            cout<<"Enter the value to be inserted: ";
            int val;
            cin>>val;
                a[++last]=val;
                min_insert(a,last);
            }
            
            if (k==2)
            {
                delete_root_min(a, last);
                last--;
            }
            
            if (k==3)
            {
                peek_root(a);
            }
          
            if (k==4)
            {
                disp(a,last);
            }
            if (k==5) break;
            

        }
    }
    
    
    
    cout<<"Thank You !!"<<endl;
    
    //Memory clear at end
    free(a);
    
    
    return 0;
}
/*Soumya Savarn
220150031
DSAI
*/

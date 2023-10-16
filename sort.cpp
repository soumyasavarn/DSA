#include <bits/stdc++.h>

using namespace std;

/*Soumya Savarn
220150031
DSAI
*/


int rand_int(int a,int b)
{
    return a+rand()%(b-a);
}

void disp(int a[],int n)
{
    for (int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
}

void selection_sort(int a[],int n)
{
    int smallest_index=0;
    int smallest_element=INT_MAX;
    for (int i=0;i<n;i++)
    {
        smallest_index=i;
        for (int j=i;j<n;j++)
        {
            if (a[j]<=smallest_element) 
            {
            smallest_element=a[j];
            smallest_index=j;
            }
        }
        swap(a[smallest_index],a[i]);
    }
        
}
        
        
        

void insertion_sort(int a[],int n)
{
    
}

void bubble_sort(int a[],int n)
{
    int flag=1;
    while(flag==1)
    {
        flag=0;
    
        for (int i=0;i<n-1;i++)
        {
            if (a[i]>a[i+1]) {swap(a[i],a[i+1]);flag=1;}
            
        }
    
    }
}
int partition (int a[],int l,int r)
{
	int ptr=l-1;
	
	for (int i=l;i<r;i++)
	{
		if (a[i]<a[r])
		{
			ptr++;
			swap(a[i],a[ptr]);
		
		}
	
	}
	
	swap(a[r],a[ptr+1]);
	return ptr+1;
}


void quicksort(int a[],int l,int r)
{
	if (l<r)
	{
		int part_ind=partition(a,l,r);
		quicksort(a,l,part_ind-1);
		quicksort(a,part_ind+1,r);
	}	
}
	
	


int main()
{
    
    
    while(1)
    {
    cout<<"Enter how many numbers you want to input: "<<endl;
    int n;
    cin>>n;
    int *a;
    a=new int[n];
    cout<<"1. Random Generation"<<endl;
    cout<<"2. Manual Input"<<endl;
    int k;
    cin>>k;
    if (k==1)
    {
        for (int i=0;i<n;i++) a[i]=rand_int(10,10000);
        cout<<"Your Array is: "<<endl;
        disp(a,n);
    }
        
    else if (k==2)
    {
        cout<<"Start Entering the numbers: "<<endl;
        for (int i=0;i<n;i++) cin>>a[i];
        
        cout<<"Your Array is :"<<endl;
        disp(a,n);
    }
    
    cout<<"1. Selection Sort"<<endl;
    cout<<"2. Insertion Sort"<<endl;
    cout<<"3. Bubble Sort"<<endl;
    cout<<"4. Quicksort"<<endl;
    
    int choose;
    cin>>choose;
    
    if (choose==1)
    {
        selection_sort(a,n);
        cout<<"Your sorted array: "<<endl;
        disp(a,n);
    }
    
    else if (choose==2)
    {
        insertion_sort(a,n);

    }
    
    else if (choose==3)
    {
        bubble_sort(a,n);
        cout<<"Your sorted array: "<<endl;
        disp(a,n);

    }
    
    else if (choose==4)
    {
        quicksort(a,0,n-1);
        cout<<"Your sorted array: "<<endl;
        disp(a,n);

    }
    
    
    cout<<"Do you wish to continue? (Y/N)"<<endl;
    char x;
    cin>>x;
    if (x=='N') break;
    





    //Memory clear
    free(a);
    
    }
    cout<<"THANK YOU!"<<endl;

    return 0;
}
/*Soumya Savarn
220150031
DSAI
*/

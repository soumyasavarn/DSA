#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
#include <chrono>
#include <climits>
#include <vector>
#include <cmath>

#include "time.h"


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
    for (int i=0;i<n;i++)
        {
            int smallest_element=INT_MAX;
            int smallest_index=i;
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
    for (int i = 1; i < n; i++) {
            int key = a[i];
            int j = i - 1;
            while (j >= 0 && a[j] > key) {
                a[j + 1] = a[j];
                j = j - 1;
            }
            a[j + 1] = key;
        }
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

void merge(int a[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = a[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int a[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergesort(a, left, mid);
        mergesort(a, mid + 1, right);

        merge(a, left, mid, right);
    }
}

void count(int a[],int n,int place)
{
    int bucket[10];
    for (int i=0;i<10;i++) bucket[i]=0;
    for (int i=0;i<n;i++) bucket[(a[i]/(int)pow(10,place))%10]++;

    for (int i=1;i<10;i++) bucket[i]+=bucket[i-1];
    int out[n];
    for (int i = n - 1; i >= 0; i--) {
    out[bucket[(a[i] / (int)pow(10,place)) % 10] - 1] = a[i];
    bucket[(a[i] / (int)pow(10,place)) % 10]--;
  }

    for (int i=0;i<n;i++) a[i]=out[i];
}

void radix(int a[],int n)
{
    int pass=0;
    int max=-1;
    for (int i=0;i<n;i++) if (a[i]>max) max=a[i];
    while(max>0) {max/=10;pass++;}
    int place=0;
    for (int i=0;i<pass;i++)
    {
        count(a,n,place);
        place++;
    }
}

void bucketsort(int a[], int n)
{
    int min=INT_MAX;

    for (int i=0;i<n;i++) if (a[i]<min) min=a[i];
    vector<int> b[n/min+1];

    for (int i = 0; i < n; i++) {
        int bi = n / a[i];
        b[bi].push_back(a[i]);
    }

    for (int i = 0; i < n/min +1; i++)
        sort(b[i].begin(), b[i].end());

    int index = 0;
    for (int i = 0; i < n/min +1; i++)
        for (int j = 0; j < b[i].size(); j++)
            a[index++] = b[i][j];
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
    cout<<"4. Quick Sort"<<endl;
    cout<<"5. Merge Sort"<<endl;
    cout<<"6. Radix Sort"<<endl;
    cout<<"7. Bucket Sort"<<endl;


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
        cout<<"Your sorted array: "<<endl;
        disp(a,n);
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

    else if (choose==5)
    {
        mergesort(a,0,n-1);
        cout<<"Your sorted array: "<<endl;
        disp(a,n);

    }else if (choose==6)
    {
        radix(a,n);
        cout<<"Your sorted array: "<<endl;
        disp(a,n);

    }else if (choose==7)
    {
        bucketsort(a,n);
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
    cout<<"Perform Efficiency comparision? (Y/N)"<<endl;
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

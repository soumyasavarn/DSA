/*Soumya Savarn
220150031
DSAI
*/

/* Example of Heap: Tour Planner according to budget
User Shares his budget with the program and it suggests him places around his budget.
under his where he can visit . This program uses Max Heap.
 ADVANTAGE: When database is large this program will answer queries in log n time.
*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>



using namespace std;

//Following are the standard functions:

int insert(int a[],int pos)
{
    
    
    int i=8;
    while (i>=1 && a[i]<pos)
    {
        
        i/=2;
    }
    return i;
    
}




int main()
{
    string a[1001];
    int cost[1001];
    cost[0]=0;
    a[0]="";
    int tot=4000;
    int diff=200;
    for (int i=1;i<=15;i++)
    {
        cost[i]=tot-diff;
        diff+=200;
    }
    
        a[1]="Goa";
        a[2]="Manali";
        a[3]="Shimla";
        a[4]="Bombay";
        a[5]="Delhi";
        a[6]="Chandigarh";
        a[7]="Ooty";
        a[8]="Darjeeling";
        a[9]="Gangtok";
        a[10]="Udaipur";
        a[11]="Jaipur";
        a[12]="Kolkata";
        a[13]="Warangal";
        a[14]="Surathkal";
        a[15]="Digha";
        
    
    cout<<"Welcome to Travel Advisor"<<endl;
    cout<<"--------------------------"<<endl;
    cout<<endl;
    cout<<"You Have to enter budget and this program \n will suggest you places depending on your budget"<<endl;
    cout<<"You can press -1 and exit"<<endl;
        while(1)
        {
            cout<<"Enter budget amount (Rs. 0 - 5k) : ";
            int val;
            cin>>val;
            if (val==-1) break;
            int p=insert(cost,val);
            cout<<"You can Plan a visit to: "<<endl;
            for (int j=p+1;j<=15;j++)
            {
                cout<<a[j]<<" ";
            }
            cout<<endl;
            
        }
    cout<<"Thank You !"<<endl;
    
    
    
    
    return 0;
}
/*Soumya Savarn
220150031
DSAI
*/

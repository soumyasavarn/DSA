#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int n=8;
const int width=sqrt(n+1);

int rand_int(int a,int b)
{
	return a+rand()%(b-a);
}

void generate_random_pair(int a[width][width],int b[width][width])
{
	vector <int> v1,v2;
	v1.pb(-1);
	v2.pb(-1);
	for (int i=1;i<=n;i++) v1.pb(i),v2.pb(i);
	
	for (int i=0;i<n+1;i++) swap(v1[i],v1[rand_int(0,n)]);
	for (int i=0;i<n+1;i++) swap(v2[i],v2[rand_int(0,n)]);
	
	int cnt=0;
	for (int i=0;i<width;i++)
	{
		for (int j=0;j<width;j++)
		{a[i][j]=v1[cnt]; b[i][j]=v2[cnt]; cnt++;}
	}
}

int calculate_inv (int a[width][width])
{
	vector <int> v;
	for (int i=1;i<=width;i++)
	for (int j=1;j<=width;j++) if (a[i][j]!=-1)v.pb(a[i][j]);
	
	int cnt=0;
	for (int i=0;i<v.size();i++)
	{
		for (int j=i+1;j<v.size();j++)
		{
			if (v[i]>v[j]) cnt++;
		}
	}
	return cnt;
}
	
signed main() {
	srand(time(0));
	
	for (int examples=1;examples<=10;examples++)
	{
	cout<<"Example Number: "<<examples<<endl;
	int a[width][width],b[width][width];
	
	generate_random_pair(a,b);
	
	cout<<"Start State: \n";
	for (int i=0;i<width;i++)
	{
		for (int j=0;j<width;j++){cout<<a[i][j]<<" ";}
		cout<<endl;
	}
	vector <int> v;
	cout<<"Total Inversions: "<<calculate_inv(a)<<endl;
	cout<<endl;
	
	cout<<"Goal State: \n";
	for (int i=0;i<width;i++)
	{
		for (int j=0;j<width;j++){cout<<b[i][j]<<" ";}
		cout<<endl;
	}
	cout<<"Total Inversions: "<<calculate_inv(b)<<endl;
	cout<<"Verdict: ";
	if (calculate_inv(a)%2==0) cout<<"YES! It is solvable"<<endl;
	else cout<<"NO! It can't be solved"<<endl;
	cout<<"--------------------------------------------------"<<endl;
	cout<<endl;
	
    
	}	
	return 0;
}

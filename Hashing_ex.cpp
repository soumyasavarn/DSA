//Implementing Password generator using secure hash
//and retrieval using Hash-table

/*
 Hash function := sum (ASCII values of all letters in first name)
 Of course there is chance of collision therefore, therefore
 keeping values using chaining.
 Whenever user enters the password we look - up the table
 */

#include <iostream>
#include <string>

using namespace std;
/*
Soumya Savarn
220150031
DSAI
*/

/*
 lower range: 1 for (eg. a)
 upper range: 1000 for (eg. zzzz... )
 */


class hash_table{
  private:
    struct node{
    struct node *prev;
    string data;
    struct node *next;
    };
    node **a;
  public:
    hash_table()
    {
        a=new node*[1000];
        for (int i=0;i<1000;i++) a[i]=NULL;
    };
    
    int hash_key(string str)
    {
        int s=0;
        for (int i=0;i<str.length();i++)
        {
            if (str[i]>=97) s+=str[i]-96;
            else if (str[i]>=65 && str[i]<97) s+=str[i]-64;
        }
        return s;
    }
    
    void insert(string str)
    {
        int key=hash_key(str);
        node *temp = new node;
        temp->data=str;
        temp->next=NULL;
        
        node *trav=a[key];
        if (trav==NULL) {temp->prev=NULL; a[key]=temp; return;}
        
        while(trav->next != NULL) trav=trav->next;
        
        temp->prev=trav;
        trav->next=temp;
    }
    
    
    
    
    bool search(string str)
    {
       int key=hash_key(str);
       node *trav=a[key];
       if (!trav) {return 0;}
       while(trav->data != str && trav->next!= NULL) trav=trav->next;
       if (!trav) {return 0;}
       return  1;
       
    }
    
    void display()
    {
        cout<<"Password is displayed as ****"<<endl;
        for (int i=1;i<1000;i++)
        {
            node *t = a[i];
            if (t==NULL) continue;
            cout<<"Password "<<"****"<<": ";
            while (t!=NULL) {
            if (t->next==NULL) cout<<t->data;
            else cout<<t->data<<" -> ";
            t=t->next;
            }
            cout<<endl;
        }
    }
    
    void clear()
    {
        for (int i=0;i<1000;i++) free(a[i]);
        free(a);
    }
    
    
};

void menu()
{
    cout<<endl;
    cout<<"Press the key for the  following\n";
    cout<<"1. Generate Password \n2. Check Password for registerd user\n3. Display User Database\n 4. Reveal password list \n 5. Exit\n";
    cout<<endl;
    cout<<endl;

}

int main()
{
    
    
    cout<<"PASSWORD DATABASE MANAGEMENT"<<endl;
    cout<<"-----------------------------"<<endl;
    hash_table h;
    
    while (1)
    {
    
    
    menu();
    int v;
    cin>>v;
    if (v==1)
    {
        string x;
        cout<<"Enter your first name "; cin>>x;
        cout<<"Your Password is: "<<h.hash_key(x)<<endl;
        h.insert(x);
    }
        
        if (v==2)
        {
            string x; cout<<"Enter your name: "; cin>>x;
            if (h.search(x)==0) {cout<<"Please register first !\n";continue;}
            int q;
            cout<<"Enter password: ";
            cin>>q;
            if (q==h.hash_key(x)) cout<<"Matched !!\n";
            else cout<<"Not Matched !! \n";
        }
        if (v==3) {h.display();}
        if (v==4) {cout<<"You cannot access the password list :)\nThat's the point of hash funtion.\n"<<endl;}
    if (v==5) {break;}
    
    
    }
    
    cout<<"THANK YOU !"<<endl;
    /*Memory clear at the end*/
    h.clear();
    
    
    return 0;
}




/*
Soumya Savarn
220150031
DSAI
*/

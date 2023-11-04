#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
#include <chrono>
#include <climits>
#include <vector>
#include <set>
#include <cmath>

#include "bst.h"

using namespace std;


void searchNode2(TreeNode* node, int value) {
    if (node == NULL)
        return;
    else if (node->val==value) return;
    else if (value < node->val) searchNode2(node->left, value);
    else searchNode2(node->right, value);
}

void time_analysis()
{
    set <int> s;
    int n=10000;

    std::chrono::time_point<std::chrono::system_clock> S_ins, E_ins;
    S_ins = std::chrono::system_clock::now();
    for (int i=0;i<n;i++) s.insert(i);
    E_ins = std::chrono::system_clock::now();
    
    
    set<int>::iterator it;
    
    std::chrono::time_point<std::chrono::system_clock> S_find, E_find;
    S_find = std::chrono::system_clock::now();
    for (int i=0;i<n;i++) it = s.find(rand()%(n-1));
    E_find = std::chrono::system_clock::now();
    
    std::chrono::time_point<std::chrono::system_clock> S_del, E_del;
    S_del = std::chrono::system_clock::now();
    for (int i=0;i<n;i++) s.erase(i);
    E_del = std::chrono::system_clock::now();
    
    
    
    TreeNode* root=NULL;

    std::chrono::time_point<std::chrono::system_clock> s_ins, e_ins;
    s_ins = std::chrono::system_clock::now();
    for (int i=0;i<n;i++) root = insertNode(root, i);
    e_ins = std::chrono::system_clock::now();
   
    std::chrono::time_point<std::chrono::system_clock> s_find, e_find;
    s_find = std::chrono::system_clock::now();
    for (int i=0;i<n;i++) searchNode2(root, i);
    e_find = std::chrono::system_clock::now();
    
    
    std::chrono::time_point<std::chrono::system_clock> s_del, e_del;
    s_del = std::chrono::system_clock::now();
    for (int i=0;i<n;i++) root = deleteNode(root, i);
    e_del = std::chrono::system_clock::now();
    
    
    
    

        float Time_1 =
        chrono::duration_cast<chrono::nanoseconds>(E_ins - S_ins).count();
        Time_1 *= 1e-9;

        float Time_2 =
        chrono::duration_cast<chrono::nanoseconds>(E_del - S_del).count();
        Time_2 *= 1e-9;

        float Time_3 =
        chrono::duration_cast<chrono::nanoseconds>(E_find - S_find).count();
        Time_3 *= 1e-9;
    
        float Time_4 =
        chrono::duration_cast<chrono::nanoseconds>(e_ins - s_ins).count();
        Time_4 *= 1e-9;

        float Time_5 =
        chrono::duration_cast<chrono::nanoseconds>(e_del - s_del).count();
        Time_5 *= 1e-9;

        float Time_6 =
        chrono::duration_cast<chrono::nanoseconds>(e_find - s_find).count();
        Time_6 *= 1e-9;
    
        

        cout<<setprecision(9);
        cout<<"SUMMARY for Binary Search Tree:"<<endl;
        cout<<"-----------------------------------"<<endl;
        cout<<"TIME TAKEN: "<<endl;
    cout<<"STL set (Binary Balanced search Tree): "<<endl;
        
    cout<<"Insert: "<<Time_1*10e5<<" (in 10e5 sec)"<<endl;
    cout<<"Search: "<<Time_3*10e5<<" (in 10e5 sec)"<<endl;
    cout<<"Delete: "<<Time_2*10e5<<" (in 10e5 sec)"<<endl;
    
    cout<<endl;
    
    cout<<"Self Implemented (Binary Search Tree): "<<endl;

    cout<<"Insert: "<<Time_4*10e5<<" (in 10e5 sec)"<<endl;
    cout<<"Search: "<<Time_6*10e5<<" (in 10e5 sec)"<<endl;
    cout<<"Delete: "<<Time_5*10e5<<" (in 10e5 sec)"<<endl;
    
    cout<<"END OF PROGRAM"<<endl<<endl;

}

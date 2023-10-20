#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
#include <chrono>
#include <climits>
#include <vector>
#include <cmath>

#include "algo.h"

using namespace std;

void time_analysis()
{
    int n=5000;
    int a[n];
    for (int i=0;i<n;i++) a[i]=rand();

    std::chrono::time_point<std::chrono::system_clock> S_stl, E_stl;
    S_stl = std::chrono::system_clock::now();
    sort(a,a+n);
    E_stl = std::chrono::system_clock::now();
    for (int i=0;i<n;i++) a[i]=rand();

    std::chrono::time_point<std::chrono::system_clock> S_insert, E_insert;
     S_insert = std::chrono::system_clock::now();
    insertion_sort(a,n);
    E_insert = std::chrono::system_clock::now();
    for (int i=0;i<n;i++) a[i]=rand();

    std::chrono::time_point<std::chrono::system_clock> S_select, E_select;
     S_select = std::chrono::system_clock::now();
    selection_sort(a,n);
     E_select = std::chrono::system_clock::now();
    for (int i=0;i<n;i++) a[i]=rand();

    std::chrono::time_point<std::chrono::system_clock> S_bubble, E_bubble;
     S_bubble = std::chrono::system_clock::now();
    bubble_sort(a,n);
     E_bubble = std::chrono::system_clock::now();
    for (int i=0;i<n;i++) a[i]=rand();

    std::chrono::time_point<std::chrono::system_clock> S_quick, E_quick;
     S_quick = std::chrono::system_clock::now();
    quicksort(a,0,n-1);
     E_quick = std::chrono::system_clock::now();
    for (int i=0;i<n;i++) a[i]=rand();

    std::chrono::time_point<std::chrono::system_clock> S_merge, E_merge;
     S_merge = std::chrono::system_clock::now();
    mergesort(a,0,n-1);
    E_merge = std::chrono::system_clock::now();
    for (int i=0;i<n;i++) a[i]=rand()%100000;

    std::chrono::time_point<std::chrono::system_clock> S_radix, E_radix;
     S_radix = std::chrono::system_clock::now();
    radix(a,n);
     E_radix = std::chrono::system_clock::now();
    for (int i=0;i<n;i++) a[i]=rand()%100000;

    std::chrono::time_point<std::chrono::system_clock> S_bucket, E_bucket;
     S_bucket = std::chrono::system_clock::now();
    bucketsort(a,n);
     E_bucket = std::chrono::system_clock::now();
    for (int i=0;i<n;i++) a[i]=rand();

        float Time_1 =
        chrono::duration_cast<chrono::nanoseconds>(E_stl - S_stl).count();
        Time_1 *= 1e-9;

        float Time_2 =
        chrono::duration_cast<chrono::nanoseconds>(E_insert - S_insert).count();
        Time_2 *= 1e-9;

        float Time_3 =
        chrono::duration_cast<chrono::nanoseconds>(E_select - S_select).count();
        Time_3 *= 1e-9;

        float Time_4 =
        chrono::duration_cast<chrono::nanoseconds>(E_bubble - S_bubble).count();
        Time_4 *= 1e-9;

        float Time_5 =
        chrono::duration_cast<chrono::nanoseconds>(E_quick - S_quick).count();
        Time_5 *= 1e-9;

        float Time_6 =
        chrono::duration_cast<chrono::nanoseconds>(E_merge - S_merge).count();
        Time_6 *= 1e-9;

        float Time_7 =
        chrono::duration_cast<chrono::nanoseconds>(E_radix - S_radix).count();
        Time_7 *= 1e-9;

        float Time_8 =
        chrono::duration_cast<chrono::nanoseconds>(E_bucket - S_bucket).count();
        Time_8 *= 1e-9;

        cout<<setprecision(9);
        cout<<"SUMMARY for sorting algorithms:"<<endl;
        cout<<"-----------------------------------"<<endl;
        cout<<"TIME TAKEN: "<<endl;
        cout<<"STL custom sort: "<<Time_1*10e5<<" (in 10e5 sec)"<<endl;
    cout<<"Insertion sort: "<<Time_2*10e5<<" (in 10e5 sec)"<<endl;
    cout<<"Selection sort: "<<Time_3*10e5<<" (in 10e5 sec)"<<endl;
    cout<<"Bubble sort: "<<Time_4*10e5<<" (in 10e5 sec)"<<endl;
    cout<<"Quick sort: "<<Time_5*10e5<<" (in 10e5 sec)"<<endl;
    cout<<"Merge sort: "<<Time_6*10e5<<" (in 10e5 sec)"<<endl;
    cout<<"Radix sort: "<<Time_7*10e5<<" (in 10e5 sec)"<<endl;
    cout<<"Bucket sort: "<<Time_8*10e5<<" (in 10e5 sec)"<<endl;

    cout<<"END OF PROGRAM"<<endl<<endl;

}

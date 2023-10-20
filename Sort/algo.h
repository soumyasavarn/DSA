#ifndef ALGO_H
#define ALGO_H

int partition (int a[],int l,int r);
void count(int a[],int n,int place);
void merge(int a[], int left, int mid, int right);
void selection_sort(int a[],int n);
void insertion_sort(int a[],int n);
void bubble_sort(int a[],int n);
void quicksort(int a[],int l,int r);
void mergesort(int a[],int left,int right);
void radix(int a[],int n);
void bucketsort(int a[],int n);


#endif

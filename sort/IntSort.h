/*
 * This header file is for IntSort.c and include some statement
 */
#ifndef INT_SORT_H
#define INT_SORT_H

void BubbleSort(int a[],int len);
void InsertSort(int a[],int len);
void SelectSort(int a[],int len);
void ShellSort(int a[],int len);
void MergeSort(int a[],int start,int end);
void QuickSort(int a[],int start,int end);
void HeapSort(int a[],int len);

void BucketSort(int a[],int len);
void RadixSort(int a[],int len);

#endif


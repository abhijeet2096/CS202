#ifndef SORTING
#define SORTING

#include <iostream>
#include "seqLinearList.hpp"

namespace cs202 {
  template<class T>
  class Sort{
    public:
      void insertionSort(LinearList<T>& A, int low, int high);
      void bubbleSort(LinearList<T>& A, int low, int high);
      void rankSort(LinearList<T>& A, int low, int high);
      void selectionSort(LinearList<T>& A, int low, int high);
      void mergeSort(LinearList<T>& A, int low, int high);
      void quickSort(LinearList<T>& A, int low, int high);
  };


template <class T> void Sort <T> :: insertionSort(LinearList<T>& A, int low, int high)
{
    int j,temp;
    
  for (int i = low; i<=high; i++){
    j = i;
    
    while (j > low && A[j] < A[j-1]){
        temp = A[j];
        A[j] = A[j-1];
        A[j-1] = temp;
        j--;
        }
    }
}

template <class T> void Sort <T> :: selectionSort(LinearList<T>& A, int low, int high)
{
  int n = high;
  int pos;
  double temp;

  for (int i=low; i < n; i++)
  {
      pos = i;//set pos_min to the current index of array
    
    for (int j=i+1; j <= n; j++)
    {

    if (A[j] < A[pos])
                   pos=j;
  //pos_min will keep track of the index that min is in, this is needed when a swap happens
    }
    
  //if pos_min no longer equals i than a smaller value must have been found, so a swap must occur
            if (pos != i)
            {
                 temp = A[i];
                 A[i] = A[pos];
                 A[pos] = temp;
            }
  }
}

template <class T> void Sort <T> :: bubbleSort(LinearList<T>& A, int low, int high)
{
  int i,j;
  //cout<<"\nIn bubble sort\n";
  int n = high;
  double temp;
      for(i=low;i<=n;i++)
    {
        for(j=low;j<(n-i);j++)
            if(A[j]>A[j+1])
            {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
    }
}


template <class T> void Sort <T> :: rankSort(LinearList<T>& A, int low, int high)      //  Rank Sort Definition
{
  int i,j;
    double b[high];
    int rank[high];
        for(i=low;i<=high;i++)
                rank[i]=0;
        for(i=low;i<=high;i++)
                for(j=1;j<=i;j++)
                        if(A[j]>A[i])  rank[j]++;
                        else rank[i]++;
        for(i=low;i<=high;i++)
                b[rank[i]]=A[i];
        for(i=low;i<=high;i++)
                A[i]=b[i];
}

/*template <class T> void Sort <T> :: mergeSort(LinearList<T>& A, int low, int high)
{
      if (low < high)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = low+(high-low)/2;
 
        // Sort first and second halves
        mergeSort(A, low , m);
        mergeSort(A, m+1, high);
 
    int i, j, k;
    int n1 = m - low + 1;
    int n2 =  high - m;

    double L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = A[low + i];
    for (j = 0; j < n2; j++)
        R[j] = A[m + 1+ j];

    i = 0; 
    j = 0; 
    k = low;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        A[k] = R[j];
        j++;
        k++;
    }
        
}
}
*/

template<class T>void merge(LinearList<T>& arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    T L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
template <class T> void Sort <T> :: mergeSort(LinearList<T>& arr, int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}


template<class T> void swap(T *a, T *b)
{
    T t = *a;
    *a = *b;
    *b = t;
}

template<class T> int partition(LinearList<T>& A, int low, int high) 
{
    T pivot = A[(high+low)/2];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (A[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[high]);
    return (i + 1);
}

template<class T> void Sort<T>::quickSort(LinearList<T>& A, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(A, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(A, low, pi - 1);
        quickSort(A, pi + 1, high);
    }
}

/*int i,j;

template<class T> void Sort<T>::quickSort(LinearList<T>& a, int l, int u)
{
   T p,temp;
   if(l<u)
   {
   p=a[u];
   i=l;
   j=u;
    while(i<j)
   {
      while(a[i] <= p && i<j )
   i++;
      while(a[j]>p && i<=j )
     j--;
      if(i<=j)
      {
      temp=a[i];
      a[i]=a[j];
      a[j]=temp;}
  }
  temp=a[j];
  a[j]=a[l];
  a[l]=temp;
  quickSort(a,l,j-1);
  quickSort(a,j+1,u); 
 }
}*/

}

#endif  /* _SORTING_HPP */

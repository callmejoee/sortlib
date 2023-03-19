#include<iostream>
using namespace std;

// function to partiton the elements of array before and after pivot
template <class T>
int partition(T arr[], int l, int r) {
    // setting the pivot
    T p = arr[l];
    // setting counter for the returned mid value
    int i = l;
    // adding the elements that is less than the pivot before the pivot
    for(int j = l+1; j <= r; j++) {
        if (arr[j] < p) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    // adding the pivot in it's right place
    swap(arr[i], arr[l]);
    return i;
}

// function to divide the arrays into two parts and sort them independantly
template <class T>
void quickSort(T arr[], int l, int r) {
    // base case to run is that there is more than one element
    if(l < r) {
        // setting the mid value
        int mid = partition(arr,l,r);
        // sort the left half
        quickSort(arr, l, mid-1);
        // sort the right half
        quickSort(arr, mid+1, r);
    }
}

#include<iostream>
using namespace std;

// function to merge the divided arrays in sorted way
template <class T>
void merge(T arr[], int l, int r) {
    // get the mid value
    int mid = (l+r) / 2;
    // temp arr
    T tmp[r-l+1];
    // set counter from left and from mid for the first and second sub arrays respectively
    int i = l, j = mid + 1, k = 0;
    // sorting the two sub arrays into the temp array
    while(i <= mid && j <= r) {
        if (arr[i] < arr[j]) {
            tmp[k++] = arr[i++];
        } else {
            tmp[k++] = arr[j++];
        }
    }

    // adding the remaining data of the first sub array
    while(i <= mid) {
        tmp[k++] = arr[i++];
    }
    // adding the remaining data of the second sub array
    while(j <= r) {
        tmp[k++] = arr[j++];
    }

    // copying the temp array value to the original array
    for(int c = l; c <= r; c++) {
        arr[c] = tmp[c-l];
    }

}

// function to divide the arrays into two parts and merge the sorted return
template <class T>
void mergeSort(T arr[], int l, int r) {
    // base case to run is that there is more than one element
    if(l < r) {
        // setting the mid value 
        int mid = l + (r-l) / 2;
        // sort the left half
        mergeSort(arr, l, mid);
        // sort the right half
        mergeSort(arr, mid+1, r);
        // merge the two halves
        merge(arr,l,r);
    }
}

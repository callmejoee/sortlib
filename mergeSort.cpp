#include<iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

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
// fun to auto genrate an array
template <typename T>
void autoGen (int size, T arr[]) {
    srand(time(0));
    for (int i=0; i<=size; i++) {
        arr[i] = rand();
    }
}
// fun to test whether an array is sorting or not
template <typename T>
bool test (int size, T arr[]) {
    for (int i=0; i<size-1; i++) {
        if (arr [i] > arr [i+1]) return 0;
    }
    return 1;
}

// fun to print an array
template <typename T>
void display (int size, T arr []) {
    for (int i=0; i<size; i++) 
        cout << arr [i] << " ";
    cout << "\n";
}

int main () {

    clock_t start_time,end_time;
	double running_time; 	

    cout << "\nHere're some test cases on random generated arrays of different sizes:\n\n";
    int arr200 [200];
    autoGen(200,arr200);
    start_time = clock();    //to calculate the time:    
    mergeSort (arr200, 0, 200 - 1);
    end_time = clock();
    if (test (200,arr200)) cout <<"The array of size 200 is sorted\n";
    else cout << "The array of size 200 is not sorted\n";
    running_time = (double)(end_time - start_time);
    cout << "The running time spent on a random array of size 200 sorted with Merge-Sort algorithm is: " << running_time << " milli seconds\n\n";

    int arr500 [500];       
    autoGen(500,arr500);
    start_time = clock();
    mergeSort (arr500, 0, 500 - 1);
    end_time = clock();
    if (test (500,arr500)) cout <<"The array of size 500 is sorted\n";
    else cout << "The array of size 500 is not sorted\n";
    running_time = (double)(end_time - start_time);
    cout << "The running time spent on a random array of size 500 sorted with Merge-Sort algorithm is: " << running_time << " milli seconds\n\n";

    int arr1000 [1000];
    autoGen(1000,arr1000);
    start_time = clock();
    mergeSort (arr1000, 0, 1000 - 1);
    end_time = clock();
    if (test (1000,arr1000)) cout <<"The array of size 1000 is sorted\n";
    else cout << "The array of size 1000 is not sorted\n";
    running_time = (double)(end_time - start_time);
    cout << "The running time spent on a random array of size 1000 sorted with Merge-Sort algorithm is: " << running_time << " milli seconds\n\n";

    int arr5000 [5000];
    autoGen(5000,arr5000);
    start_time = clock();
    mergeSort (arr5000, 0, 5000 - 1);
    end_time = clock();
    if (test (5000,arr5000)) cout <<"The array of size 5000 is sorted\n";
    else cout << "The array of size 5000 is not sorted\n";
    running_time = (double)(end_time - start_time);
    cout << "The running time spent on a random array of size 5000 sorted with Merge-Sort algorithm is: " << running_time << " milli seconds\n\n";

    int arr10000 [10000];   
    autoGen(10000,arr10000);
    start_time = clock();
    mergeSort (arr10000, 0, 10000 - 1);
    end_time = clock();
    if (test (10000,arr10000)) cout <<"The array of size 10000 is sorted\n";
    else cout << "The array of size 10000 is not sorted\n";
    running_time = (double)(end_time - start_time);
    cout << "The running time spent on a random array of size 10000 sorted with Merge-Sort algorithm is: " << running_time << " milli seconds\n\n";
    
    int arr20000 [20000];
    autoGen(20000,arr20000);
    start_time = clock();
    mergeSort (arr20000, 0, 20000 - 1);
    end_time = clock();
    if (test (20000,arr20000)) cout <<"The array of size 20000 is sorted\n";
    else cout << "The array of size 20000 is not sorted\n";
    running_time = (double)(end_time - start_time);
    cout << "The running time spent on a random array of size 20000 sorted with Merge-Sort algorithm is: " << running_time << " milli seconds\n\n"; 

    int arr50000 [50000];
    autoGen(50000,arr50000);
    start_time = clock();
    mergeSort (arr50000, 0, 50000 - 1);
    end_time = clock();
    if (test (50000,arr50000)) cout <<"The array of size 50000 is sorted\n";
    else cout << "The array of size 50000 is not sorted\n";
    running_time = (double)(end_time - start_time);
    cout << "The running time spent on a random array of size 50000 sorted with Merge-Sort algorithm is: " << running_time << " milli seconds\n\n";
    return 0;
}


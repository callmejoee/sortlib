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
    quickSort (arr200, 0, 200 - 1);
    end_time = clock();
    if (test (200,arr200)) cout <<"The array of size 200 is sorted\n";
    else cout << "The array of size 200 is not sorted\n";
    running_time = (double)(end_time - start_time); 
    cout << "The running time spent on a random array of size 200 sorted with Quick-Sort algorithm is: " << running_time << " milli seconds\n\n";

    int arr500 [500];       
    autoGen(500,arr500);
    start_time = clock();
    quickSort (arr500, 0, 500 - 1);
    end_time = clock();
    if (test (500,arr500)) cout <<"The array of size 500 is sorted\n";
    else cout << "The array of size 500 is not sorted\n";
    running_time = (double)(end_time - start_time); 
    cout << "The running time spent on a random array of size 500 sorted with Quick-Sort algorithm is: " << running_time << " milli seconds\n\n";

    int arr1000 [1000];
    autoGen(1000,arr1000);
    start_time = clock();
    quickSort (arr1000, 0, 1000 - 1);
    end_time = clock();
    if (test (1000,arr1000)) cout <<"The array of size 1000 is sorted\n";
    else cout << "The array of size 1000 is not sorted\n";
    running_time = (double)(end_time - start_time); 
    cout << "The running time spent on a random array of size 1000 sorted with Quick-Sort algorithm is: " << running_time << " milli seconds\n\n";

    int arr5000 [5000];
    autoGen(5000,arr5000);
    start_time = clock();
    quickSort (arr5000, 0, 5000 - 1);
    end_time = clock();
    if (test (5000,arr5000)) cout <<"The array of size 5000 is sorted\n";
    else cout << "The array of size 5000 is not sorted\n";
    running_time = (double)(end_time - start_time); 
    cout << "The running time spent on a random array of size 5000 sorted with Quick-Sort algorithm is: " << running_time << " milli seconds\n\n";

    int arr10000 [10000];   
    autoGen(10000,arr10000);
    start_time = clock();
    quickSort (arr10000, 0, 10000 - 1);
    end_time = clock();
    if (test (10000,arr10000)) cout <<"The array of size 10000 is sorted\n";
    else cout << "The array of size 10000 is not sorted\n";
    running_time = (double)(end_time - start_time); 
    cout << "The running time spent on a random array of size 10000 sorted with Quick-Sort algorithm is: " << running_time << " milli seconds\n\n";
    
    int arr20000 [20000];
    autoGen(20000,arr20000);
    start_time = clock();
    quickSort (arr20000, 0, 20000 - 1);
    end_time = clock();
    if (test (20000,arr20000)) cout <<"The array of size 20000 is sorted\n";
    else cout << "The array of size 20000 is not sorted\n";
    running_time = (double)(end_time - start_time);
    cout << "The running time spent on a random array of size 20000 sorted with Quick-Sort algorithm is: " << running_time << " milli seconds\n\n"; 

    int arr50000 [50000];
    autoGen(50000,arr50000);
    start_time = clock();
    quickSort (arr50000, 0, 50000 - 1);
    end_time = clock();
    if (test (50000,arr50000)) cout <<"The array of size 50000 is sorted\n";
    else cout << "The array of size 50000 is not sorted\n";
    running_time = (double)(end_time - start_time); 
    cout << "The running time spent on a random array of size 50000 sorted with Quick-Sort algorithm is: " << running_time << " milli seconds\n\n";
    return 0;
}


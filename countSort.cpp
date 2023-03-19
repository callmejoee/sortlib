#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

//Count Sorting algorithm impelementaion 
template<typename T>
void countSort(int size, T arr[]) {
    // Find the maximum element in the array
    T max = arr[0];
    for (int i=1; i<size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    // Create a count array to store the count of each element
    T* count = new T[max+1]();
    // Store the count of each element in the count array
    for (int i=0; i<size; i++) {
        count[arr[i]]++;
    }
    // making the count array to store the actual position of each element in the sorted array
    for (int i=1; i<=max; i++) {
        count[i] += count[i-1];
    }
    // Create a temp array to store the sorted elements
    T* temp = new T[size];
    // Sort the elements by placing them in their correct position in the temp array
    for (int i=size-1; i>=0; i--) {
        temp[--count[arr[i]]] = arr[i];
    }
    // Copy the sorted elements from the temp array to original array
    for (int i=0; i<size; i++) {
        arr[i] = temp[i];
    }
    delete [] count;
}
// fun to auto genrate an array
template <typename T>
void autoGen (int size, T arr[]) {
    for (int i=0; i<size; i++) {
        arr [i] = rand() % size; // values in the range from 0 to array size-1
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

    // char arrChar [] = {'b','c','A','d','a','E','e','g','F','f','v'};
    // int s = sizeof (arrChar) / sizeof (arrChar[0]);
    // countSort (s,arrChar);
    // cout << "The char array after sorting with Count-Sort:\n";
    // display (s,arrChar);
    //Counting Sort works only with integer numbers.
    // float arrFloat [] = {1.0,2.6,2.2,3.6,6.2,0.4}; 
    // s = sizeof (arrFloat) / sizeof (arrFloat [0]);
    // countSort (s,arrFloat);
    // cout << "The float arrray after sorting with Count-Sort:\n";
    // display (s,arrFloat);

    //to calculate the time:
    clock_t start_time,end_time;
    double running_time;

    cout << "\nHere're some test cases on random generated arrays of different sizes:\n\n";
    int arr200 [200];
    autoGen(200,arr200);
    start_time = clock();     
    countSort (200,arr200);
    end_time = clock();
    if (test (200,arr200)) cout <<"The array of size 200 is sorted\n";
    else cout << "The array of size 200 is not sorted\n";
    running_time = (double)(end_time - start_time) / CLOCKS_PER_SEC; 
    cout << "The running time spent on a random array of size 200 sorted with Counting-Sort algorithm is: " << running_time << " seconds\n\n";

    int arr500 [500];       
    autoGen(500,arr500);
    start_time = clock();
    countSort (500,arr500);
    end_time = clock();
    if (test (500,arr500)) cout <<"The array of size 500 is sorted\n";
    else cout << "The array of size 500 is not sorted\n";
    running_time = (double)(end_time - start_time) / CLOCKS_PER_SEC; 
    cout << "The running time spent on a random array of size 500 sorted with Counting-Sort algorithm is: " << running_time << " seconds\n\n";

    int arr1000 [1000];
    autoGen(1000,arr1000);
    start_time = clock();
    countSort (1000,arr1000);
    end_time = clock();
    if (test (1000,arr1000)) cout <<"The array of size 1000 is sorted\n";
    else cout << "The array of size 1000 is not sorted\n";
    running_time = (double)(end_time - start_time) / CLOCKS_PER_SEC; 
    cout << "The running time spent on a random array of size 1000 sorted with Counting-Sort algorithm is: " << running_time << " seconds\n\n";

    int arr5000 [5000];
    autoGen(5000,arr5000);
    start_time = clock();
    countSort (5000,arr5000);
    end_time = clock();
    if (test (5000,arr5000)) cout <<"The array of size 5000 is sorted\n";
    else cout << "The array of size 5000 is not sorted\n";
    running_time = (double)(end_time - start_time) / CLOCKS_PER_SEC; 
    cout << "The running time spent on a random array of size 5000 sorted with Counting-Sort algorithm is: " << running_time << " seconds\n\n";

    int arr10000 [10000];   
    autoGen(10000,arr10000);
    start_time = clock();
    countSort (10000,arr10000);
    end_time = clock();
    if (test (10000,arr10000)) cout <<"The array of size 10000 is sorted\n";
    else cout << "The array of size 10000 is not sorted\n";
    running_time = (double)(end_time - start_time) / CLOCKS_PER_SEC; 
    cout << "The running time spent on a random array of size 10000 sorted with Counting-Sort algorithm is: " << running_time << " seconds\n\n";
    
    int arr20000 [20000];
    autoGen(20000,arr20000);
    start_time = clock();
    countSort (20000,arr20000);
    end_time = clock();
    if (test (20000,arr20000)) cout <<"The array of size 20000 is sorted\n";
    else cout << "The array of size 20000 is not sorted\n";
    running_time = (double)(end_time - start_time) / CLOCKS_PER_SEC; 
    cout << "The running time spent on a random array of size 20000 sorted with Counting-Sort algorithm is: " << running_time << " seconds\n\n";

    int arr50000 [50000];
    autoGen(50000,arr50000);
    start_time = clock();
    countSort (50000,arr50000);
    end_time = clock();
    if (test (50000,arr50000)) cout <<"The array of size 50000 is sorted\n";
    else cout << "The array of size 50000 is not sorted\n";
    running_time = (double)(end_time - start_time) / CLOCKS_PER_SEC; 
    cout << "The running time spent on a random array of size 50000 sorted with Counting-Sort algorithm is: " << running_time << " seconds\n\n";
    return 0;
}


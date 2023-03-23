#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

#define SIZE 300

namespace sortlib{
    // Youssef Karam 20210480
    // Insertion sort and Shell sort

    template <typename T> void InsertionSort (T arr[], int n)
    {
        for (int i = 1; i < n; i++)
        {
            int j = i;
            while (j > 0 && arr[j - 1] > arr[j])
            {
                swap(arr[j], arr[j - 1]);
                j--;
            }
        }
    }


    template <typename T> void shell_sort(T arr[], int n)
    {
        // main difference between shell and insertion is the interval loop
        for (int interval = n / 2; interval > 0; interval /= 2)
        {
            // basically insertion sort but fixing the variables
            for (int i = interval; i < n; i++) // instead of starting at 1 start at the interval which will save you some iterations
            {
                int j = i;
                while (j >= interval && arr[j - interval] > arr[j])  // instead of j > 0 like insertion which might give negative check for the interval length
                {
                    swap(arr[j], arr[j - interval]);
                    j -= interval;
                }
            }
        }
    }








    // Seif Ibrahim Ramadan	20210164
    // Merge Sort and Quick Sort

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



    // Yasseen Emad-Eldeen Saber 20200635

    //Bubble Sorting algorithm impelementaion
    bool flag = 1;
    template <typename T>
    void bubbleSort (int size, T arr []) {
        for (int i=0; i<size-1; i++) {
            for (int j=0; j<size-i-1; j++) {
                if (arr [j] > arr [j+1]) {
                    swap (arr [j] , arr [j+1]);
                    flag = 0;
                }
            }
            if (flag == 1) break;
        }
    }
    // fun to auto genrate an array
    template <typename T>
    void autoGen (int size, T arr[]) {
        for (int i=0; i<=size; i++) {
            //arr [i] = (rand()%2101)-100;
            arr [i] = -size + rand() % (size - (-size)+1);
        }
    }
    // fun to auto genrate an array for Counting Sort (Positive numbers only)
    template <typename T>
    void autoGen_countSort (int size, T arr[]) {
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




    // Selection Sort algorithm impelementaion
    template <typename T>
    void selectionSort (int size,T arr []) {
        for (int i = 0; i<size-1; i++) {
            for (int j=i+1; j<size; j++) {
                if (arr [j] < arr [i]) {
                    swap (arr [i] , arr[j]);
                }
            }
        }
    }

}

using namespace sortlib;

int main() {
    int arr[SIZE];
    autoGen(SIZE, arr);
    cout << "Unsorted Array" << endl;
    display(SIZE, arr);
    cout << "Selection sort: \n";
    selectionSort(SIZE, arr);
    display(SIZE, arr);

    int arrCount [SIZE];
    cout << "Unsorted Array" << endl;
    display (SIZE,arrCount);
    cout << "Count sort: \n";
    countSort (SIZE,arrCount);
    display (SIZE,arrCount);

    return 0;
}

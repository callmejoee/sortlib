#include <iostream>

using namespace std;

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

int main() {

    // Test case 1


//    int arr1[200];
//    for (int i = 0; i < 200; i++)
//    {
//        arr1[i] = rand();
//    }
//    cout << "First array of size 200 unsorted \n";
//    for (int i = 0; i < 200; i++)
//    {
//        cout << arr1[i] << " ";
//    }
//    cout << endl;
//    InsertionSort(arr1, 200);
//    cout << "First array of size 200 sorted\n";
//    for (int i = 0; i < 200; i++)
//    {
//        cout << arr1[i] << " ";
//    }
//    cout << endl;
//


    // Test case 2

//
//    int arr2[500];
//    for (int i = 0; i < 500; i++)
//    {
//        arr2[i] = rand();
//    }
//    cout << "First array of size 500 unsorted \n";
//    for (int i = 0; i < 500; i++)
//    {
//        cout << arr2[i] << " ";
//    }
//    cout << endl;
//    InsertionSort(arr2, 500);
//    cout << "Second array of size 500 sorted\n";
//    for (int i = 0; i < 500; i++)
//    {
//        cout << arr2[i] << " ";
//    }
//    cout << endl;

//
//    // Test case 3
//
//    int arr3[1000];
//    for (int i = 0; i < 1000; i++)
//    {
//        arr3[i] = rand();
//    }
//    cout << "Third array of size 1000 unsorted \n";
//    for (int i = 0; i < 1000; i++)
//    {
//        cout << arr3[i] << " ";
//    }
//    cout << endl;
//    InsertionSort(arr3, 1000);
//    cout << "Third array of size 1000 sorted\n";
//    for (int i = 0; i < 1000; i++)
//    {
//        cout << arr3[i] << " ";
//    }
//    cout << endl;


    // Test Case 4

    int arr4[5000];
    for (int i = 0; i < 5000; i++)
    {
        arr4[i] = rand();
    }
    cout << "Fourth array of size 5000 unsorted \n";
    for (int i = 0; i < 5000; i++)
    {
        cout << arr4[i] << " ";
    }
    cout << endl;
    InsertionSort(arr4, 5000);
    cout << "Fourth array of size 5000 sorted\n";
    for (int i = 0; i < 5000; i++)
    {
        cout << arr4[i] << " ";
    }
    cout << endl;

    return 0;
}

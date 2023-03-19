#include <iostream>

using namespace std;

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

int main() {


    // Test case 1


    int arr1[200];
    for (int i = 0; i < 200; i++)
    {
        arr1[i] = rand();
    }
    cout << "First array of size 200 unsorted \n";
    for (int i = 0; i < 200; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    shell_sort(arr1, 200);
    cout << "First array of size 200 sorted\n";
    for (int i = 0; i < 200; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;


    return 0;
}

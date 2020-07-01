#include <iostream>
#include <ctime>

using namespace std;

int partition (int array[], int low, int high){
    int pivot = array[high]; 
    int i = (low-1);

    for(int j = low; j < high; ++j){
        if(array[j] < pivot){
            ++i;
            int t = array[i];
            array[i] = array[j];
            array[j] = t;
        }
    }

    ++i;
    int t = array[i];
    array[i] = array[high];
    array[high] = t;

    return i;
}

void quicksort (int array[], int low, int high){
    if(low < high){
        int partition_index = partition(array, low, high);
        quicksort(array, low, partition_index - 1);
        quicksort(array, partition_index + 1, high);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int array[n];
    srand(time(0));
    //make the array
    for(int i = 0; i < n; array[i] = rand() % 256, ++i);
    //sort & show the array
    quicksort(array, 0, n - 1);
    for(int i = 0; i < n; cout << array[i] << "\t", ++i);
    cout << "\n";
    //binary search
    int target, left = 0, right = n - 1, mid = n / 2;
    cin >> target;
    while (target != array[mid])
    {
        if(target > array[mid]){
            left = mid;
            mid = (left + right) / 2 + (left + right) % 2;
        }
        else{
            right = mid;
            mid = (left + right)/ 2;
        }
    }
    cout << mid;
    return 0;
}

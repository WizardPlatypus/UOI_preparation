#include <iostream>

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
    cin>>n; 
    int array[n]; 
    srand(0);

    for(int i = 0; i < n; ++i){
        array[i] = rand() % 256;
        cout << array[i] << "\t";
    }
    
    quicksort(array, 0, n - 1);

    cout << "\n";
    for(int i = 0; i < n; ++i){
        cout << array[i] << "\t";
    }
    system(wait)
    return 0;
}

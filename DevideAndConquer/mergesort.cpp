#include <iostream>
#include <ctime>

using namespace std;

void merge(int array[], int left, int middle, int right) 
{ 
	int l_size = middle - left + 1; 
	int r_size = right - middle; 

	int l_array[l_size];
    for(int i = 0; i < l_size; l_array[i] = array[left + i], ++i);
    int r_array[r_size];
    for(int i = 0; i < r_size; r_array[i] = array[middle + 1 + i], ++i);

    int l_index = 0, r_index = 0, index = left; 

	while ((l_index < l_size)&&(r_index < r_size)) { 
        if(l_array[l_index] <= r_array[r_index]){
            array[index] = l_array[l_index];
            l_index++;
        }
        else
        {
            array[index] = r_array[r_index];
            r_index++;
        }
        index++;
	} 

    while (l_index < l_size)
    {
        array[index] = l_array[l_index];
        l_index++;
        index++;
    } 

	while (r_index < r_size)
    {
        array[index] = r_array[r_index];
        r_index++;
        index++;
    } 
} 

void mergeSort(int array[], int left, int right) 
{ 
	if (left < right) { 
		int middle = left + (right - left) / 2; 

		mergeSort(array, left, middle); 
		mergeSort(array, middle + 1, right); 

		merge(array, left, middle, right); 
	} 
}

int main() 
{
    int n; 
    cin >> n; 
    int array[n];
    srand(time(0));
    for(int i = 0; i < n; *(array + i) = rand() % 256, cout << *(array + i) << "\t", ++i);
    cout << "\n";

	mergeSort(array, 0, n - 1); 

	for(int i = 0; i < n; cout << *(array + i) << "\t", ++i);

	return 0; 
} 

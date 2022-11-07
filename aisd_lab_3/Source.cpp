#include <iostream>
#include <chrono>
#include <algorithm>
#include <iterator>

using namespace std;

void InsertionSort(int* temp_arr, int length) {
	int i, key, j;

	for (i = 1; i < length; i++){
		key = temp_arr[i];
		j = i - 1;
		while (j >= 0 && temp_arr[j] > key){
			temp_arr[j + 1] = temp_arr[j];
			j = j - 1;
		}
		temp_arr[j + 1] = key;
	}
}

void swap(int* xp, int* yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void SelectionSort(int* temp_arr, int length){
	int i, j, min_idx;

	for (i = 0; i < length - 1; i++) {
		min_idx = i;
		for (j = i + 1; j < length; j++)
			if (temp_arr[j] < temp_arr[min_idx])
				min_idx = j;
		if (min_idx != i)
			swap(&temp_arr[min_idx], &temp_arr[i]);
	}
}

void BubbleSort(int* temp_arr, int length) {
	int temp;
	for (int i = 0; i < (length - 1); i++){
		for (int j = 0; j < (length - i - 1); j++){
			if (temp_arr[j] > temp_arr[j + 1]){
				temp = temp_arr[j];
				temp_arr[j] = temp_arr[j + 1];
				temp_arr[j + 1] = temp;
			}
		}
	}
}

void merge(int* temp_arr, int l, int m, int length){
	int i = 0, j = 0, k = l;
	int n1 = m - l + 1;
	int n2 = length - m;
	int* L = new int[n1]();
	int* R = new int[n2]();

	for (int i = 0; i < n1; i++)
		L[i] = temp_arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = temp_arr[m + 1 + j];

	while (i < n1 && j < n2){
		if (L[i] <= R[j]){
			temp_arr[k] = L[i];
			i++;
		} else{
			temp_arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1){
		temp_arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2){
		temp_arr[k] = R[j];
		j++;
		k++;
	}
	delete[] L;
	delete[] R;
}

void MergeSort(int* temp_arr, int l,  int length){
	int m = l + (length - l) / 2;
	if (l < length){
		MergeSort(temp_arr, l, m);
		MergeSort(temp_arr, m + 1, length);

		merge(temp_arr, l, m, length);
	}
}

void ShellSort(int* temp_arr, int length) {
	for (int gap = length / 2; gap > 0; gap /= 2){
		for (int i = gap; i < length; i += 1){
			int temp = temp_arr[i];
			int j;
			for (j = i; j >= gap && temp_arr[j - gap] > temp; j -= gap)
				temp_arr[j] = temp_arr[j - gap];
			temp_arr[j] = temp;
		}
	}
}

int partition(int* temp_arr, int low, int high){
	int pivot = temp_arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++){
		if (temp_arr[j] < pivot){
			i++;
			swap(&temp_arr[i], &temp_arr[j]);
		}
	}
	swap(&temp_arr[i + 1], &temp_arr[high]);
	return (i + 1);
}

void QuickSort(int* temp_arr, int low, int high){
	if (low < high){
		int pi = partition(temp_arr, low, high);

		QuickSort(temp_arr, low, pi - 1);
		QuickSort(temp_arr, pi + 1, high);
	}
}

void show(int* arr, int length) {
	for (int i = 0; i < length; i++)
		cout << arr[i] << ' ';
	cout << endl;
}

int main() {
	setlocale(0, "RUS");

	int const length = 10;
	int arr[length];
	int temp_arr[length];
	for (int i = 0; i < length; i++) {
		arr[i] = rand() % 100;
		cout << arr[i] << ' ';
	}
	cout << endl << endl;

	copy(begin(arr), end(arr), begin(temp_arr));
	InsertionSort(temp_arr, length);
	show(temp_arr, length);

	copy(begin(arr), end(arr), begin(temp_arr));
	SelectionSort(temp_arr, length);
	show(temp_arr, length);

	copy(begin(arr), end(arr), begin(temp_arr));
	BubbleSort(temp_arr, length);
	show(temp_arr, length);

	copy(begin(arr), end(arr), begin(temp_arr));
	MergeSort(temp_arr, 0, length - 1);
	show(temp_arr, length);

	copy(begin(arr), end(arr), begin(temp_arr));
	ShellSort(temp_arr, length);
	show(temp_arr, length);

	copy(begin(arr), end(arr), begin(temp_arr));
	QuickSort(temp_arr, 0, length - 1);
	show(temp_arr, length);
}
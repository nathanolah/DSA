#include <iostream>
#include <cstdlib>
using namespace std;

const int threshold = 3;

void populate(int* arr, int size) {
   for (int i = 0; i < size; i++)
      arr[i] = rand() / 100;
}

void print(int* arr, int size) {
   for (int i = 0; i < size; i++)
      cout << arr[i] << " ";
   cout << endl;
}

void insertionSort(int arr[], int left, int right) {
   int curr, i, j;
   for (i = left + 1; i <= right; i++) {
      curr = arr[i];
      for (j = i; j > 0 && arr[j - 1] > curr; j--) {
         arr[j] = arr[j - 1];
      }
      arr[j] = curr;
   }
}

int partition(int arr[], int left, int right) {
   int location = left + (rand() % (right - left + 1));
   int pivot = arr[location];
   arr[location] = arr[right];
   arr[right] = pivot; // move the pivot out of the way
   
   int i = left - 1;
   for (int j = left; j < right; j++) {
      if (arr[j] <= pivot) {
         i = i + 1;
         int tmp = arr[i];
         arr[i] = arr[j];
         arr[j] = tmp;
      }
   }

   int tmp = arr[i + 1];
   arr[i + 1] = arr[right];
   arr[right] = tmp;

   return i + 1;
}

void quickSort(int arr[], int left, int right) {
   if (right - left <= threshold) {
      insertionSort(arr, left, right);
   }
   else {
      int i = partition(arr, left, right);
      quickSort(arr, left, i-1);
      quickSort(arr, i + 1, right);
   }
}

void quickSort(int* arr, int size) {
   quickSort(arr, 0, size-1);
}

int main() {
   int size = 0;
   int* arr = nullptr;

   cout << "Enter size: ";
   cin >> size;
   
   arr = new int[size];
   populate(arr, size);

   cout << "Before sorting: ";
   print(arr, size);

   quickSort(arr, size);

   cout << "After sorting: ";
   print(arr, size);

   delete[] arr;

   return 0;
}
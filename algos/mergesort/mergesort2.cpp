#include <iostream>
#include <cstdlib>
using namespace std;

void printArray(int arr[], int size) {
   for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
   }
   cout << endl;
}

void populateArray(int* arr, int size) {
   for (unsigned i = 0; i < size; i++) {
      arr[i] = rand() / 100;
   }
}

void merge(int* arr, int* tmp, const int startA, const int startB, const int endB) {
   int aPtr = startA;
   int bPtr = startB;
   int idx = startA;

   // sort the elements by comparing both partitions and create new tmp array
   while (aPtr < startB && bPtr < endB + 1) {
      if (arr[aPtr] < arr[bPtr]) { // comparing from start of first array and start of second array (mid)
         tmp[idx] = arr[aPtr];
         idx++;
         aPtr++;
      }
      else {
         tmp[idx] = arr[bPtr];
         idx++;
         bPtr++;
      }
   }

   // copy the remaining elements on the left side if there are any
   while (aPtr < startB) {
      tmp[idx] = arr[aPtr];
      idx++;
      aPtr++;
   }

   // copy the remaining elements from the mid to right side if there are any
   while (bPtr < endB + 1) {
      tmp[idx] = arr[bPtr];
      idx++;
      bPtr++;
   }

   // copy sorted element into original array
   for (int i = 0; i < endB + 1; i++) {
      arr[i] = tmp[i];
   }
}

void mergeSort(int* arr, int* tmp, const int start, const int end) {
   if (start < end) {
      int mid = start + (end - start) / 2;
      mergeSort(arr, tmp, start, mid);
      mergeSort(arr, tmp, mid + 1, end);
      merge(arr, tmp, start, mid + 1, end);
   }
}

int main() {
   /*int arr[] = { 12, 2, 14, 19, 3, 8, 7,2,2,2,2,2,2 };
   unsigned arrSize = sizeof(arr) / sizeof(arr[0]);*/
   unsigned arrSize = 0;
   cout << "Array size: ";
   cin >> arrSize;

   int* arr = new int[arrSize];
   populateArray(arr, arrSize);

   cout << "Given array: ";
   printArray(arr, arrSize);

   int* tmp = new int[arrSize];
   /*
      minus n by 1 because the array starts at index 0
      this allows us to get the mid of the array
   */
   mergeSort(arr, tmp, 0, arrSize - 1);

   delete[] tmp;

   cout << "Sorted array: ";
   printArray(arr, arrSize);

   delete[] arr;

   return 0;
}
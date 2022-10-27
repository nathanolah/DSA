#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
   for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
   }
   cout << endl;
}

void merge(int arr[], const int left, const int mid, const int right) {
   const int subArrayOne = mid - left + 1;
   const int subArrayTwo = right - mid;

   // temp arrays
   int* leftArray = new int[subArrayOne];
   int* rightArray = new int[subArrayTwo];

   // copy data into temp arrays
   for (int i = 0; i < subArrayOne; i++) {
      leftArray[i] = arr[left + i];
   }

   for (int i = 0; i < subArrayTwo; i++) {
      rightArray[i] = arr[mid + 1 + i];
   }

   int indexOfSubArrayOne = 0; // initial index of first sub-array
   int indexOfSubArrayTwo = 0; // initial index of second sub-array
   int indexOfMergedArray = left; // initial index of merged array

   // merge the temp arrays back into array[left...right]
   while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
      if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
         arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
         indexOfSubArrayOne++;
      }
      else {
         arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
         indexOfSubArrayTwo++;
      }
      
      indexOfMergedArray++;
   }

   // copy the remaining elements of left[], if there are any
   while (indexOfSubArrayOne < subArrayOne) {
      arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
      indexOfSubArrayOne++;
      indexOfMergedArray++;
   }

   // copy the remaining elements of right[], if there are any
   while (indexOfSubArrayTwo < subArrayTwo) {
      arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
      indexOfSubArrayTwo++;
      indexOfMergedArray++;
   }

   delete[] leftArray;
   delete[] rightArray;

}

void mergeSort(int arr[], const int begin, const int end) {
   if (begin >= end) {
      return; // returns recursively
   }

   int mid = begin + (end - begin) / 2;
   mergeSort(arr, begin, mid);
   mergeSort(arr, mid + 1, end);
   merge(arr, begin, mid, end);
}

//int main() {
//   // int sort
//   int arr[] = { 12, 2, 14, 19, 3, 8, 7,2,2,2,2,2,2 };
//   unsigned arrSize = sizeof(arr) / sizeof(arr[0]);
//
//   cout << "Given array: ";
//   printArray(arr, arrSize);
//
//   /* 
//      minus n by 1 because the array starts at index 0
//      this allows us to get the mid of the array
//   */
//   mergeSort(arr, 0, arrSize - 1); 
//
//   cout << "Sorted array: ";
//   printArray(arr, arrSize);
//
//   return 0;
//}
#include <iostream>
using namespace std;

void swap(int arr[], int a, int b) {
   int tmp = arr[a];
   arr[a] = arr[b];
   arr[b] = tmp;
}

int partition(int arr[], int l, int r, string val) {
   int pivot = arr[r]; // pivot element
   int p = r; 

   for (int i = l; i < p; i++) {
      // largest
      if (val == "largest") {
         if (arr[i] > pivot) {
            swap(arr, i, p - 1);
            swap(arr, p, p - 1);
            i--;
            p--;
         }
      }
      else {
         // smallest
         if (arr[i] < pivot) {
            swap(arr, i, p - 1);
            swap(arr, p, p - 1);
            i--;
            p--;
         }
      }
   }

   return p;
}

int quickSelect(int arr[], int l, int r, int k, string val) {
   int p = partition(arr, l, r, val);

   if (p < k) {
      return quickSelect(arr, p + 1, r, k, val);
   }

   if (p > k) {
      return quickSelect(arr, l, p - 1, k, val);
   }

   return arr[p];
}

int kthElement(int arr[], int size, int k, string val) {
   return quickSelect(arr, 0, size - 1, size - k, val);
}

int main() {
   int arr[] = { 27, 4, 5, 8, 6, 11, 26, 34 };
   int size = sizeof(arr) / sizeof(arr[0]);
   int k = 1;

   cout << k << " - k-th largest element is: "
      << kthElement(arr, size, k, "largest");

   cout << endl;

   cout << k << " - k-th smallest element is: "
      << kthElement(arr, size, k, "smallest");
   
   return 0;
}
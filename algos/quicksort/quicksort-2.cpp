#include <iostream>
using namespace std;

void swap(int* a, int* b) {
   int tmp = *a;
   *a = *b;
   *b = tmp;
}

int partition(int arr[], int l, int r) {
   while (l < r) {
      if (arr[l + 1] <= arr[l]) {
         swap(&arr[l + 1], &arr[l]);
         l++;
      }
      else if (arr[r] >= arr[l]) {
         r--;
      }
      else {
         swap(&arr[r], &arr[l + 1]);
      }
   }

   return l;
}

void sortSegment(int arr[], int l, int r) {
   if (l >= r) {
      return;
   }
   else {
      int position = partition(arr, l, r);
      sortSegment(arr, l, position - 1); // left segment
      sortSegment(arr, position + 1, r); // right segment
   }
}

void quickSort(int arr[], int n) {
   sortSegment(arr, 0, n - 1);
}

int main() {
   int arr[] = { 7,2,8,4,3,6,9 };
   int n = sizeof(arr) / sizeof(arr[0]);

   quickSort(arr, n);

   for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
   }
   cout << endl;

   return 0;
}
#include <iostream>
using namespace std;

void swap(int* a, int* b) {
   int tmp = *a;
   *a = *b;
   *b = tmp;
}

// partitions the array around the pivot
int partition(int nums[], int n) {
   // randomize pivot incase array is sorted to avoid O(n^2) runtime
   int j = rand() % n;
   swap(&nums[0], &nums[j]);

   // nums[l] is the pivot, the pivot begins at index 0
   int l = 0;
   int r = n - 1;

   while (l < r) {
      // case 1 - The element after the pivot is less than the pivot, swap the elements
      if (nums[l + 1] <= nums[l]) {
         swap(&nums[l + 1], &nums[l]);
         l++; 
      }
      // case 2 - The element at r is greater than the pivot we keep it on the right side of the array and decrease r.
      else if (nums[r] > nums[l]) {
         r--;
      }
      // case 3 - The element at position l + 1 is greater than the pivot and the element at position r is smaller than the pivot. Swap the elements.
      else {
      // case 3 - The element at r is less than the pivot and the element after the pivot is greater than the pivot, then we swap the two elements.
         swap(&nums[r], &nums[l + 1]);
      }
   }

   return l;
}

int qs(int nums[], int n, int k) {
   // returns the postition of the pivot
   int p = partition(nums, n); 

   if (k == p) {
      return nums[p];
   }
   else if (k < p) {
      return qs(nums, p, k); // left segment of the array
   }
   else { // k > p
      return qs(nums + p+1, n - (p + 1), k - (p+1)); // right segment of the array
   }
}

int main() {
   int nums[] = { 7,2,1,9,3,6,8 };
   
   int n = sizeof(nums) / sizeof(nums[0]);
   int k = 2; // base 0

   cout << qs(nums, n, k);

   return 0;
}
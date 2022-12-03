#include <iostream>
using namespace std;

int binarySearch(int nums[], int n, int k) {
   int l = 0;
   int r = n - 1;
   
   while (l <= r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] == k) {
         return mid;
      }
      else if (nums[mid] < k) {
         l = mid + 1;
      }
      else {
         r = mid - 1;
      }
   }

   return -1;
}

int main() {
   int nums[] = { 1,2,3,4,5,6,7,8,9 };
   int n = sizeof(nums) / sizeof(nums[0]);
   int k = 0;

   cout << "Enter value to find: ";
   cin >> k;

   int index = binarySearch(nums, n, k);

   if (index == -1) {
      cout << "element not found" << endl;
   }
   else {
      cout << "element " << k << " is at index: " << index;
   }

   return 0;
}
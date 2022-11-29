#include <iostream>
using namespace std;

// returns the sum in sub-array of size "k"
int maxSumFixed(int arr[], int n, int k, int& start, int& end) {
   // array size is less than window size
   if (k > n) {
      cout << "invalid";
      return -1; 
   }

   int maxSum = 0;
   int currentSum = 0;
   for (int i = 0; i < k; i++) {
      currentSum += arr[i];
   }

   maxSum = currentSum;

   // store index positions
   start = 0; 
   end = k - 1;

   // sliding the window and updating the maxSum
   for (int i = k; i < n; i++) {
      // add the rightmost element to the window and discard the leftmost element from the window
      currentSum += arr[i] - arr[i - k];

      if (currentSum > maxSum) {
         maxSum = currentSum;

         // store index positions
         start = i - k + 1; // the window starts one ahead of the element that was removed from the left
         end = i; // the window goes upto the position of the newly added ellment from the right
      }
   }

   return maxSum;
}
//
int main() {
   int start = 0; 
   int end = 0;
   int arr[] = { 1, 4, 2, 10, 2, 3, 1, 0, 20 };
   int k = 4; // fixed sized window
   int n = sizeof(arr) / sizeof(arr[0]);

   int max = maxSumFixed(arr, n, k, start, end);
   cout << "Maximum sum is: " << max << endl;
   cout << "From position " << start << " till " << end << endl;

   return 0;
}
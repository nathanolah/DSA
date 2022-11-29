#include <iostream>
using namespace std;

//int smallestSubArray(int arr[], int arrSize, int targetSum, int& start, int& end) {
//   int minWindowSize = INT_MAX;
//   int currentWindowSum = 0;
//   int windowStart = 0;
//
//   for (int windowEnd = 0; windowEnd < arrSize; windowEnd++) {
//      currentWindowSum += arr[windowEnd];
//
//      while (currentWindowSum >= targetSum) {
//         if (minWindowSize > (windowEnd - windowStart + 1)) {
//            minWindowSize = (windowEnd - windowStart + 1);
//         }
//
//         currentWindowSum -= arr[windowStart];
//         windowStart++;
//      }
//   }
//   
//
//   return minWindowSize;
//}

int smallestSubArray(int arr[], int n, int targetSum, int& start, int& end) {
   int minSize = INT_MAX; 
   int currSum = 0;
   int l = 0, r = 0;
   for (l, r; r < n; r++) {
      currSum += arr[r];
      
      while (currSum >= targetSum) {
         
         if (minSize > (r - l + 1)) {
            minSize = (r - l + 1);
         }

         currSum -= arr[l];
         l++;
      }
   }

   return minSize;
}

int main() {
   int arr[] = { 3, 1, 5, 2, 4, 7, 1 };
   int n = sizeof(arr) / sizeof(arr[0]);
   int target = 7;
   int start = 0;
   int end = 0;

   cout << smallestSubArray(arr, n, target, start, end);

}

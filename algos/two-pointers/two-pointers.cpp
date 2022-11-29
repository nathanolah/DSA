#include <iostream>
#include <vector>

using namespace std;

// Array must be sorted for two-pointer technique

int main() {
   // [0, 2] is the answer 
   vector<int> nums = { 3, 2, 4 };
   int target = 6;

   // two pointer
   int l = 0;
   int r = nums.size() - 1;
   int* res = new int[2];
   int sum = 0;

   while (l < r) {
      sum = nums[l] + nums[r];

      if (sum == target) {
         cout << l << endl;
         cout << r;
         break;
      }
      else if (sum <= target) {
         l++;
      }
      else {
         r--;
      }
   }

   cout << sum << endl;

  /* for (int i = 0; i < 2; i++) {
      cout << res[i] << " ";
   }
   cout << endl;*/
   
   delete[] res; 

   return 0;
}
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

template <class TYPE>
void print(vector<TYPE>& arr) {
   for (auto& i : arr) {
      cout << i << " ";
   }
   cout << endl;
}

template <class TYPE>
void merge(vector<TYPE>& arr, vector<TYPE>& tmp, int startA, int startB, int endB) {
   int aPtr = startA;
   int bPtr = startB;
   int idx = startA;

   while (aPtr < startB && bPtr < endB + 1) {
      if (arr[aPtr] < arr[bPtr]) {
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

   while (aPtr < startB) {
      tmp[idx] = arr[aPtr];
      idx++;
      aPtr++;
   }

   while (bPtr < endB + 1) {
      tmp[idx] = arr[bPtr];
      idx++;
      bPtr++;
   }

   // copy sorted tmp to arr
   for (int i = 0; i < endB + 1; i++) {
      arr[i] = tmp[i];
   }

}

template <class TYPE>
void mergeSort(vector<TYPE>& arr, vector<TYPE>& tmp, int start, int end) {
   if (start < end) {
      int mid = start + (end - start) / 2;
      mergeSort(arr, tmp, start, mid);
      mergeSort(arr, tmp, mid+1, end);
      merge(arr, tmp, start, mid + 1, end);
   }
}

template <class TYPE>
void mergeSort(vector<TYPE>& arr) {
   vector<TYPE> tmp(arr.size());
   mergeSort(arr, tmp, 0, arr.size() - 1);
}

int main() {
   vector<string> words = { "hello", "apple", "donut", "trout", "programming", "merge", "merge", "sort" };
   ///vector<char> words = { 'h', 'a', 'd', 't', 'p', 'm', 's'};
   //vector<int> words = {1,2,3,3,4,55,6,67,7};

   cout << "before sort: ";
   print(words);

   mergeSort(words);

   cout << "after sort: ";
   print(words);
  
   return 0; 
}
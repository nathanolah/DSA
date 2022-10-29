#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

const unsigned threshold = 3;

template <class TYPE>
void print(vector<TYPE>& data) {
   for (int i = 0; i < data.size(); i++) {
      cout << data[i] << " ";
   }
   cout << endl;
}

template <class TYPE>
void insertionSort(vector<TYPE>& data, int left, int right) {
   TYPE curr;
   int i, j;
   for (i = left + 1; i <= right; i++) {
      curr = data[i];
      for (j = i; j > 0 && data[j - 1] > curr; j--) {
         data[j] = data[j - 1];
      }
      data[j] = curr;
   }
}

template <class TYPE>
int partition(vector<TYPE>& data, int left, int right) {
   int location = left + (rand() % (right - left + 1)); // get pivot location
   TYPE pivot = data[location]; // "pivot" is assigned the pivot element

   data[location] = data[right]; 
   data[right] = pivot; // move the pivot out of the way

   int i = left - 1;
   for (int j = left; j < right; j++) { 
      if (data[j] <= pivot) {
         i = i + 1;
         TYPE tmp = data[i];
         data[i] = data[j];
         data[j] = tmp;
      }
   }

   TYPE tmp = data[i + 1];
   data[i + 1] = data[right];
   data[right] = tmp;

   return i + 1;
}

template <class TYPE>
void quickSort(vector<TYPE>& data, int left, int right) {
   if (right - left <= threshold) {
      insertionSort(data, left, right);
   }
   else {
      int i = partition(data, left, right);
      quickSort(data, left, i - 1);
      quickSort(data, i + 1, right);
   }
}

template <class TYPE>
void quickSort(vector<TYPE>& data) {
   quickSort(data, 0, data.size() - 1);
}

int main() {
   vector<string> data = {"quick", "sort", "algorithm", "trout", "salmon", "steelhead", "walleye", "pike", "musky", "hello"};
   //vector<int> data = {123, 3, 9, 3, 0, 94, 5, 7, 65, 10, 23};
   
   cout << "Before sorting: ";
   print(data);

   quickSort(data);

   cout << "After sorting: ";
   print(data);

   return 0;
}
#include <iostream>
#include <vector>
using namespace std;

vector<int> decimalToBinary(int decimal) {
   vector<int> binaryNum;
  
   while (decimal > 0) {
      binaryNum.push_back(decimal % 2); // store the remainder into the vector, either 1 or 0.
      decimal /= 2; // divide by 2 until the new "decimal" is 0.
   }

   return binaryNum;
}

int main() {
   int decimal = 0;
   vector<int> binary;

   cout << "Enter a decimal number: ";
   cin >> decimal;
   binary = decimalToBinary(decimal);

   // print the vector in reverse order
   for (int i = binary.size() - 1; i >= 0; i--) {
      cout << binary[i];
   }
   cout << endl;

   return 0;
}
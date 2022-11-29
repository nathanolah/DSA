#include <iostream>
using namespace std;

int binaryToDecimal(int binary) {
   int binaryNum = binary;
   int decimalNum = 0;

   // initialize base value to 1, i.e 2^0
   int base = 1;

   while (binaryNum) {
      int lastDigit = binaryNum % 10;
      binaryNum = binaryNum / 10;

      decimalNum += lastDigit * base;

      base = base * 2; // move base to binary value
   }

   return decimalNum;
}

int main() {
   int binary = 0;
   int decimal = 0;

   cout << "Enter a binary number: ";
   cin >> binary;

   decimal = binaryToDecimal(binary);
   cout << "The decimal number is: " << decimal << endl;

   return 0;
}
// Maazin Ahmed - COMSC 260 - Professor Melvin

// NOTE: The ONLY files that should be #included for this assignment are iostream, vector, and string
// No other files should be #included

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int bin_to_dec(string);
string dec_to_bin(int);
int hex_to_dec(string);
string dec_to_hex(int);

int main()
{
  
  cout<<"10000011 binary = "<<bin_to_dec("10000011")<<" decimal\n"; // you should get 131
  cout<<"01010101 binary = "<<bin_to_dec("01010101")<<" decimal\n"; // you should get 85
  cout<<"1111111111111111 binary = "<<bin_to_dec("1111111111111111")<<" decimal\n"; // you should get 65,535
  cout<<"0111111111111111 binary = "<<bin_to_dec("0111111111111111")<<" decimal\n\n"; // you should get 32,767
  
  cout<<"255 decimal = "<<dec_to_bin(255)<<" binary\n"; //you should get 11111111
  cout<<"65532 decimal = "<<dec_to_bin(65532)<<" binary\n"; //you should get 1111111111111100
  cout<<"12 decimal = "<<dec_to_bin(12)<<" binary\n"; //you should get 1100
  cout<<"1000000 decimal = "<<dec_to_bin(1000000)<<" binary\n\n"; //you should get 11110100001001000000
  
  cout<<"ABC hexadecimal = "<<hex_to_dec("ABC")<<" decimal\n"; //you should get 2,748
  cout<<"F5 hexadecimal = "<<hex_to_dec("F5")<<" decimal\n"; //you should get 245
  cout<<"1234 hexadecimal = "<<hex_to_dec("1234")<<" decimal\n"; //you should get 4,660
  cout<<"FDECB hexadecimal = "<<hex_to_dec("FDECB")<<" decimal\n\n"; //you should get 1,040,075
  
  cout<<"512 decimal = "<<dec_to_hex(512)<<" hexadecimal\n"; //you should get 200
  cout<<"5000 decimal = "<<dec_to_hex(5000)<<" hexadecimal\n"; //you should get 1388
  cout<<"900000 decimal = "<<dec_to_hex(900000)<<" hexadecimal\n"; //you should get DBBA0
  cout<<"65525 decimal = "<<dec_to_hex(65525)<<" hexadecimal\n\n"; //you should get FFF5
  
  // system("PAUSE");
  return 0;
}

// Converts any UNsigned binary number to decimal

 int bin_to_dec(string s)
 {
   int decimalvalue = 0;
   for (int i = 0; i < s.size(); i++)
   {
     if (s[i] == '1')
     {
       decimalvalue += (pow(2, s.size() - i))/2;
     }
   }
   return decimalvalue;
 }

 //Converts any non-negative decimal number to binary
 
 string dec_to_bin(int n)
 {
   string decimalvalue = "";
   int binary[100];
   
   int counter = 0;
   while (n > 0)
   {
     binary[counter] = n%2;
     n = n/2;
     counter++;
   }
   for (int i = (counter - 1); i >= 0; i--)
   {
     decimalvalue += to_string(binary[i]);
   }
   return decimalvalue;
 }
 
 //Converts any UNsigned hexadecimal number to decimal
 
 int hex_to_dec(string s)
 {
   int decimalvalue = 0;
   int baseincrement = 1;
   
   for (int i = (s.length()-1); i >= 0; i--)
   {
     if (s[i] >= '0' && s[i] <= '9')
     {
       decimalvalue += (s[i]-48)*baseincrement;
       baseincrement = baseincrement * 16;
     }
     else if (s[i] >= 'A' && s[i] <= 'F')
     {
       decimalvalue += (s[i] - 55) * baseincrement;
       baseincrement = baseincrement * 16;
     }
   }
   return decimalvalue;
  }
 
 //Converts any non-negative decimal number to hexadecimalConverts any non-negative decimal number to hexadecimal

string dec_to_hex(int n)
{
  string hexvalue = "";
  char hexadecimal[100];
  int counter = 0;
  
  while (n > 0)
  {
    int storage = 0;
    storage = n % 16;
  
  if(storage < 10)
  {
    hexadecimal[counter] = storage + 48;
    counter++;
  }
  else
  {
    hexadecimal[counter] = storage + 55;
    counter++;
  }
    n = n/16;
  }
  
  for (int j = counter - 1; j >= 0; j--)
  {
    hexvalue += hexadecimal[j];
  }
  
  return hexvalue;
}

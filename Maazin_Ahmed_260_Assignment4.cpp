// NOTE: The ONLY files that should be #included for this assignment are iostream, vector, and string
// No other files should be #included

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;


string addbin(string, string);
string addhex(string, string);

string multbin(string, string);
string multhex(string, string);

int main()
{
  
  cout<<"binary 10001 * 11 = "<<multbin("10001", "11")<<endl; //you should get 110011
  cout<<"binary 100 * 110001 = "<<multbin("100", "11001")<<endl; //you should get 1100100
  cout<<"binary 110 * 1010 = "<<multbin("110", "1010")<<endl; //you should get 111100
  cout<<"binary 11111111 * 10 = "<<multbin("11111111", "10")<<endl; //you should get 111111110
  cout<<"binary 10101010 * 1 = "<<multbin("10101010", "1")<<endl;  //you should get 10101010
  cout<<"binary 0 * 11110000 = "<<multbin("0", "11110000")<<endl<<endl; //you should get 0
  
  cout<<"hexadecimal F * A = "<<multhex("F", "A")<<endl; //you should get 96
  cout<<"hexadecimal 1A * 5 = "<<multhex("1A", "5")<<endl; //you should get 82
  cout<<"hexadecimal FF * 2 = "<<multhex("FF", "2")<<endl; //you should get 1FE
  cout<<"hexadecimal 104 * 3 = "<<multhex("104", "3")<<endl; //you should get 30C
  cout<<"hexadecimal FABC * 1 = "<<multhex("FABC", "1")<<endl; //you should get FABC
  cout<<"hexadecimal 0 * EFDCAB = "<<multhex("0", "EFDCAB")<<endl<<endl; //you should get 0
  
  // system("PAUSE");
  return 0;
}

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

string addbin(string bin1, string bin2)
{
  string result = "";
  int sum = 0;
  
  int i = (bin1.size() - 1);
  int j = (bin2.size() - 1);
  
  while (i >= 0 || j >= 0 || sum == 1)
  {
    if (i >= 0)
      sum += (bin1[i] - '0');
    else
      sum += 0;
    
    if (j >= 0)
      sum += (bin2[j] - '0');
    else
      sum += 0;
    
    result = char(sum % 2 + '0') + result;
    sum /= 2;
    
    i--;
    j--;
  }
  return result;
}

string addhex(string hex1, string hex2)
{
  int sum;
  int carry = 0;
  int get_hex1;
  int get_hex2;
  
  int i = hex1.length();
  int j = hex2.length();
  
  while (i > 0)
  {
    if (hex1 [i - 1] >= 'A')
      get_hex1 = hex1[i - 1] - 55;
    else
      get_hex1 = hex1[i - 1] - '0';
    
    
    if (j > 0)
    {
      if (hex2[j - 1] >= 'A')
        get_hex2 = hex2[j - 1] - 55;
      else
        get_hex2 = hex2[j - 1] - '0';
    }
    
    else
      get_hex2 = 0;
    
    sum = get_hex1 + get_hex2 + carry;
    
    if (sum >= 16)
    {
      int left = sum % 16;
      if (left >= 10)
        hex1[i - 1] = 'A' + left % 10;
      else
        hex1[i - 1] = '0' + left;
      carry = 1;
    }
    else
    {
      if (sum >= 10)
        hex1[i - 1] = 'A' + sum % 10;
      else
        hex1[i - 1] = '0' + sum;
      carry = 0;
    }
    i--;
    j--;
  }
  
  if (carry == 1)
    return "1" + hex1;
  else
    return hex1;
}

string multbin(string bin1, string bin2)
{
  string result = "";
  string null = "0";
  string bigger;
  int smaller;
  
  int binary1, binary2;
  
  binary1 = stoi(bin1);
  binary2 = stoi(bin2);
  
  if (binary1 > binary2)
  {
    smaller = bin_to_dec(bin2);
    bigger = bin1;
  }
  else
  {
    smaller = bin_to_dec(bin1);
    bigger = bin2;
  }
  
  if (bin1 == "0" || bin2 == "0")
    return null;
  if (bin1 == "1")
    return bin2;
  if (bin2 == "1")
    return bin1;
  
  result = addbin(bigger, bigger);
  
  while (smaller > 2)
  {
    result = addbin(result, bigger);
    smaller--;
  }
  return result;
}

string multhex(string hex1, string hex2)
{
  string result = "";
  string null = "0";
  string bigger;
  int smaller;
  
  int hexadecimal1 = hex_to_dec(hex1);
  int hexadecimal2 = hex_to_dec(hex2);
 
 if (hex1 == "0" || hex2 == "0")
   return null;
 if (hex1 == "1")
   return hex2;
 if (hex2 == "1")
   return hex1;
  
  if (hexadecimal1 > hexadecimal2)
  {
    bigger = hex1;
    smaller = hexadecimal2;
  }
  else
  {
    bigger = hex2;
    smaller = hexadecimal1;
  }

  result = addhex(bigger, bigger);

  while (smaller > 2)
  {
    result = addhex(result, bigger);
    smaller--;
  }
  return result;
}

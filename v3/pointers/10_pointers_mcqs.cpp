#include <iostream>
using namespace std;

void update(int *p)
{
  *p = (*p) * 2;
}

void increment(int **p)
{
  ++(**p);
}

int main()
{
  // 1st (output: 8 9)
  // int first = 8;
  // int second = 18;
  // int *ptr = &second;
  // *ptr = 9;
  // cout << "first: " << first << " Second: " << second << endl;

  // 2nd (output: 6 7)
  // int first = 6;
  // int *p = &first;
  // int *q = p;
  // cout << (*q)++ << " ";
  // cout << first << endl;

  // 3rd (output: Segmentation fault)
  // int *p = 0;
  // int first = 110;
  // *p = first;
  // cout << *p << endl;

  // 4th (output: 11 13)
  // int first = 8;
  // int second = 11;
  // int *third = &second;
  // first = *third;
  // *third = *third + 2;
  // cout << first << " " << second << endl;

  // 5th (output: 21.5 21.5 21.5)
  // float f = 12.5;
  // float p = 21.5;
  // float *ptr = &f;
  // (*ptr)++;
  // *ptr = p;
  // cout << *ptr << " " << f << " " << p << endl;

  // 6th (output: 20 8)
  // int arr[5];
  // int *ptr;
  // cout << arr << endl;
  // cout << sizeof(arr) << " " << sizeof(ptr) << endl;

  // 7th (output: 11 21)
  // int arr[] = {11, 21, 13, 14};
  // cout << *(arr) << " " << *(arr + 1) << endl;

  // 8th (output: print same memory address)
  // int arr[] = {11, 12, 31};
  // cout << arr << " " << &arr << " " << &arr[0] << endl;

  // 9th (output: print memory address of the second element)
  // int arr[6] = {11, 21, 13};
  // cout << (arr + 1) << endl;

  // 10th (output: 31)
  // int arr[6] = {11, 21, 31};
  // int *p = arr;
  // cout << p[2] << endl;

  // 11th (output: 11 14)
  // int arr[] = {11, 12, 13, 14, 15};
  // cout << *(arr) << " " << *(arr + 3) << endl;

  // 12th (output: Will not run address cannot update on single table)
  // int arr[] = {11, 21, 31, 41};
  // int *ptr = arr++;
  // cout << *ptr << endl;

  // 13th (output: b)
  // char ch = 'a';
  // char *ptr = &ch;
  // ch++;
  // cout << *ptr << endl;

  // 14th (output: abcde) (char array print entire string instead of address)
  // char arr[] = "abcde";
  // char *p = &arr[0];
  // cout << p << endl;

  // 15th (output: bcde)
  // char arr[] = "abcde";
  // char *p = &arr[0];
  // p++;
  // cout << p << endl;

  // 16th (output: C C)
  // char str[] = "Coding";
  // char *p = str;
  // cout << str[0] << " " << p[0] << endl;

  // 17th (output: 20)
  // int i = 10;
  // update(&i);
  // cout << i << endl;

  // 18th (output: 111 119)
  // int first = 110;
  // int *p = &first;
  // int **q = &p;
  // int second = (**q)++ + 9;
  // cout << first << " " << second << endl;

  // 19th (output: 102  101)
  // int first = 100;
  // int *p = &first;
  // int **q = &p;
  // int second = ++(**q);
  // int *r = *q;
  // ++(*r);
  // cout << first << " " << second << endl;

  // 20th (output: 111)
  int num = 110;
  int *ptr = &num;
  increment(&ptr);
  cout << num << endl;

  return 0;
}

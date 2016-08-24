#include<iostream>
#include<memory>
#include<set>
#include <algorithm>
 using namespace std;
 bool Increment(char *number);
 void PrintNum(char *number);
 void Print1ToMaxOfDigits(int n)
 {
	 if (n<0)
	 {
		 return;
	 }
	 char *number = new char[n + 1];
	 memset(number, '0', n);
	 number[n] = '\0';
	 while (!Increment(number))
	 {
		 PrintNum(number);
	 }
	 delete[]number;
 }
 bool Increment(char *number)
 {
	 bool isOverFlow = false;//number是否越界
	 int nTakeOver = 0;//该位为9时下一位进1；
	 int length = strlen(number);
	 for (int i = length - 1; i >= 0;i--)
	 {
		 int nSum = number[i] - '0' + nTakeOver;
		 if (i == length - 1)
			 nSum++;
		 if (nSum>=10)
		 {
			 if (i==0)
			 {
				 isOverFlow = true;
			 }
			 else
			 {
				 nSum -= 10;
				 nTakeOver = 1;
				 number[i] = nSum + '0';
			 }
		 }
		 else
		 {
			 number[i] = nSum + '0';
			 break;
		 }
	 }
	 return isOverFlow;
 }
 void PrintNum(char *number)
 {
	 bool isBegining0 = true;
	 int length = strlen(number);
	 for (int i = 0; i < length;++i)
	 {
		 if (isBegining0&&number[i]!='0')
		 {
			 isBegining0 = false;
		 }
		 if (!isBegining0)
		 {
			 printf("%c",number[i]);
		 }
	 }
 }
 int main()
 {
	 Print1ToMaxOfDigits(3);
	 return 0;
 }

#include<iostream>
#include<memory>
#include<set>
#include <algorithm>
 using namespace std;
 bool g_InvailInput = false;
 double Power(double base, int exponent) {
	 g_InvailInput = false;
	 if (equal(base,0)&&exponent<0)
	 {
		 g_InvailInput = true;
		 return 0.0;
	 }
	 unsigned int absExponent = (unsigned int)exponent;
	 if (exponent<0)
	 {
		 absExponent = (unsigned int)(-exponent);
	 }
	 double result = PowerWithUnsignedExponent(base, absExponent);
	 if (exponent<0)
	 {
		 result = 1.0 / result;
	 }
	 return result;

 }
 //常规的for循环
 double PowerWithUnsignedExponent(double base,unsigned int exponent)
 {
	 double result = 1.0;
	 for (int i = 1; i <= exponent;i++)
	 {
		 result *= base;
	 }
	 return result;
 }
 //递归
 double PowerWithUnsignedExponent(double base, unsigned int exponent)
 {
	 if (exponent==0)
	 {
		 return 1.0;
	 }
	 if (exponent==1)
	 {
		 return base;
	 }
	 double result = PowerWithUnsignedExponent(base, exponent >> 1);
	 result *= result;
	 if (exponent&1==1)//为奇数
	 {
		 result *= base;
	 }
	 return result;
 }
 bool equal(double num1, double num2)
 {
	 if ((num1 - num2 > -0.0000001)&&(num1-num2 < 0.0000001))
		 return true;
	 else
		 return false;
 }
 int main()
 {

	 return 0;
 }

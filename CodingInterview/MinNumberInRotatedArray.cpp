#include<iostream>
#include<memory>
 using namespace std;
 int Mininorder(int *R, int index1, int index2);
 int Min(int *R, int length)
 {
	 if (R==NULL||length<=0)
	 {
		 throw new exception("");
	 }
	 int index1 = 0;
	 int index2 = length - 1;
	 int indexmid = index1;
	 while (R[index1] >= R[index2])
	 {
		 if (index2-index1==1)
		 {
			 indexmid = index2;
			 break;
		 }
		 indexmid = (index1 + index2) / 2;
		 if (R[index1] == R[index2] && R[index1] == R[indexmid])
		 {
			 return Mininorder(R,index1,index2);
		 }
		 if (R[indexmid] >= R[index1])
			 index1 = indexmid;
		 if (R[indexmid] <= R[index2])
			 index2 = indexmid;
	 }
	 return R[indexmid];
 }
 int Mininorder(int *R, int index1, int index2)
 {
	 int result = R[index1];
	 for (int i = index1 + 1; i < index2;i++)
	 {
		 if (result>R[i])
			 result = R[i];
	 }
	 return result;
 }
 int main()
 {
	 int a[] = { 23,26,45,77,89,8,9,14,20 };
	 int min = Min(a,9);
	 return 0;
 }

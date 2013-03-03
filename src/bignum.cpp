#include<iostream>
#include<memory.h>
#include<cstring>
using namespace std;
const int cnt = 10000;
void Mul(char num1[], char num2[])
{
   int len1 = strlen(num1);
   int len2 = strlen(num2);
   int i, j, k = 0, carry = 0, l, len = len1 + len2;
   int res[len];
   memset(res,0,len*sizeof(int));
   for (i = len1 - 1; i >= 0; i--,k++) {
      l = k;
      for (j = len2 - 1; j >= 0; j--) {
           res[l++] +=  (num2[j] - '0') * (num1[i] - '0');
	   cout<<l-1<<","<<(res[l-1])<<endl;
      }
   } 

   for (i = 0; i < len - 1; ++i) {
       res[i] += carry;
       carry = res[i] / 10;
       res[i] %= 10;
       //res[i] += '0';
       //cout<<i<<","<<res[i]<<endl;
   }
   for (i = 0; i < len - 1; ++i) {
       cout<<res[i]<<endl;
   }
   if (carry) { 
       res[i] = carry;
       cout<<carry<<endl;
   }
   //res[len] = '\0';
   //cout<<res<<endl;
}
void Add(char num1[], char num2[])
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int ntemp = 0, k = 0, carry = 0;
    int rlen = len2 > len1 ? len2 + 1 : len1 + 1;
    char res[rlen];
    while (--len1 >= 0&&--len2 >= 0) {
        res[ntemp++] = (num2[len2] - '0') + (num1[len1] - '0');
    }
    while (--len1 >= 0) {res[ntemp++] = num1[len1] - '0';}
    while (--len2 >= 0) {res[ntemp++] = num1[len2] - '0';}
    while (k < ntemp) {
        res[k] += carry;  
        carry = res[k] / 10;
	res[k] %= 10;
	res[k++] += '0';
    }
    if (carry) { 
        res[ntemp++] = '1';
    }
    res[ntemp] = '\0';
    cout<<res<<endl;

}
int main()
{
    char num1[cnt], num2[cnt];
    cin>>num1>>num2;
    //Add(num1, num2);
    //cout<<endl<<"Mul = ";
    Mul(num1, num2);
    return 0;
}

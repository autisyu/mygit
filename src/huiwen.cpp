#include<iostream>
#include<cstring>
using namespace std;
int huiwen(char array[])
{
    int max = -1, id = -1, k, j, l;
    int len = strlen(array);
    for (int i = 0; i < len; ++i) {
        for (k = 1; i-k>=0&&i+k<len; ++k) {
	   if (array[i-k] == array[i + k]) {
	       continue;
	   } else {
	       break;
	   } 
	}
	    l = k;
        for (k = 1,j = 0; i-j>=0&&i+k<len; ++k,j++) {
	   if (array[i-j] == array[i + k]) {
	       continue;
	   } else {
	       break;
	   } 
	}
	k--;
	k = 2*(l - 1) + 1 < 2*k ? 2*k:2*(l-1) + 1;
	if (k  > max) {
	    max = k , id = i;
	}
    }
    for (int i=id-max; i<=id+max; ++i) {
        cout<<array[i];
    }
    cout<<endl;
    return max;
}
int main()
{
    char array[200000];
    cin>>array;
    cout<<huiwen(array);
    return 0;
}

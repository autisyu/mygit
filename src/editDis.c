#include<iostream>
#include<cstring>
using namespace std;
const int maxLen = 1000;
int Dis[maxLen][maxLen];
int min3(int a, int b, int c)
{
    int max = a > b ? b : a;
    return (max > c ? c : max);
}

int getStrDis(const char* str1, int start1, int end1, const char* str2, int start2, int end2)
{
    if (Dis[start1][start2] != -1) {
        //cout<<start1<<" "<<start2<<"  "<<Dis[start1][start2]<<endl;
	//cout<<end1<<" "<<end2<<" "<<endl;
        //return Dis[start1][start2];
    }
    if (start1 > end1 ) {
        return end2 - start2 + 1;
    }
    if (start2 > end2 ) {
        return end1 - start1 + 1;
    }
    if ( str1[start1] == str2[start2] ) {
        int lent = getStrDis(str1, start1 + 1, end1, str2, start2 + 1, end2);
	return lent;
    }
    int len1 = getStrDis(str1, start1 + 1, end1, str2, start2, end2);
    Dis[start1 + 1][start2] = len1;

    int len2 = getStrDis(str1, start1 , end1, str2, start2 + 1, end2);
    Dis[start1][start2 + 1] = len2;

    int len3 = getStrDis(str1, start1 + 1, end1, str2, start2 + 1, end2);
    Dis[start1 + 1][start2 + 1] = len3;
    int len = min3(len1, len2, len3) + 1;
    Dis[start1][start2] = len;
    return len;
}

int main()
{
    const char *s1 = "gfasfasfabce";
    const char *s2 = "cacabcfasfddasfasfasfdsafe";
    int lenofstr1  = strlen(s1);
    int lenofstr2  = strlen(s2);
    for (int i = 0; i < lenofstr1 + 1; ++i) {
        for (int j = 0; j < lenofstr2 + 1; ++j) {
	    Dis[i][j] = -1;
	}
    }
    cout<<getStrDis(s1, 0, lenofstr1 - 1, s2, 0, lenofstr2 - 1)<<endl;
    cout<<Dis[0][0]<<endl;
    return 0;
}

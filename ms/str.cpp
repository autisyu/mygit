#include<map>
#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
using namespace std;
map<string, string> translate;
map<string, vector<string> > strlist;
map<string ,int> strcnt;
string words[101];
char s[101];
char sentence[102];
string ss;
int main()
{
    int i = 0, j = 0, k = 0, index = 0, T, M, N;
    cin>>ss;
    getchar();
    gets(sentence);
    i = strlen(sentence);
    cout<<i<<endl;
    for (j = 0; j < i ;j++) {
        if (sentence[j] == ' ') {
	    s[index] = '\0';
	    //cout<<s<<endl;
	    words[k].assign(s, strlen(s));
	    cout<<words[k]<<endl;
	    k++;
	    index = 0;
	    continue;
	} else {
	    s[index] = sentence[j];
	    index++;
	}
    }
    s[index] = '\0';
    words[k].assign(s, strlen(s));
    cout<<words[k]<<endl;

    //while (gets(words[i++]) && words[i-1][0] != '\n') {}
    return 0;
}


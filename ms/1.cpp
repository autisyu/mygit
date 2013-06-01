#include<map>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
map<string, string> translate;
map<string, vector<string> > strlist;
map<string ,int> strcnt;
string words[101];
string sentence;
string result[200];
char s[102];
int main()
{
    int index = 0, i, j, T, M, N, k = 0, person;
    cin>>T;
    for (i = 0; i < T; ++i) {
        result[i] ="";
        cin>>M>>N;
	person = 0;
	string base, change;
	translate.clear();
	for (j = 0; j < N; ++j) {
	    cin>>base>>change;
	    translate[base] = change;
	}
    getchar();
    getline(cin, sentence);
    int len  = sentence.size();
    index = 0, k = 0;
    /*for (map<string, string>::iterator it = translate.begin(); it != translate.end(); it++) {
    }*/
    for (j = 0; j < len ;j++) {
        if (sentence[j] == ' ') {
	    s[index] = '\0';
	    //cout<<s<<endl;
	    words[k].assign(s, strlen(s));
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
    for (j = 0; j <= k; ++j) {
        for (person = 1; person < M; ++person) {
            if (translate.find(words[j]) != translate.end()) {
	        words[j] = translate[words[j]];
	    } else {
	        if (j != k) {
		    result[i] += words[j];
		    result[i] +=" ";
		} else {
		    result[i] += words[j];
		    result[i] +="\n";
		}
		break;
	    }
	}
	if (person == M) {
	if (j != k) {
	    result[i] += words[j];
            result[i] +=" ";
        } else {
            result[i] += words[j];
            result[i] +="\n";
	}
	}
    }
    k = 0;
    }
    for (i = 0; i < T; ++i) {
        cout<<"Case #"<<i + 1<<": ";
        cout<<result[i];
    }
    return 0;
}


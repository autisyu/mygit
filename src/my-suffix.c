#include<stdio.h>
#define maxlen 100
void sorting(int j)
{
    while (i < maxvalue) { wc[i++] = 0; }
    i = 0;
    while (i < len) { wc[data[i+j]]++; }
    for (i = 1; i < maxvalue; ++i ) { wc[i] += wc[i - 1]; }
    for (i = len - 1; i >= 0; --i) { tsa[wc[data[i + j]]--] = i;}

    while (i < maxvalue) { wc[i++] = 0; }
    i = 0;
    while (i < len) { wc[data[i]]++; }
    for (i = 1; i < maxvalue; ++i ) { wc[i] += wc[i - 1]; }
    for (i = len - 1; i >= 0; --i) { sa[wc[data[tsa[i]]]--] = tsa[i];}

}
void suffix(char* data)
{
    int len = strlen(data), i = 0;
    int wc[maxlen], rank[maxlen];
    while (i < maxvalue) { wc[i++] = 0; }
    i = 0;
    while (i < len) { wc[data[i++]]++; }
    for (i = 1; i < maxvalue; ++i ) { wc[i] += wc[i - 1]; }
    for (i = len - 1; i >= 0; --i) { sa[wc[data[i]]--] = i;}

    for (p = 1; p  < len; p *=2) {
        int r = 0;
        for (i = len - p; i < len; ++i ) y[i] = r++;
	i = 0;
	while (i < maxvalue) { wc[i++] = 0; }
	while (i < len) { wc[y[i++]]++; }
	for (i = len - 1; i >= 0; --i) {rank[]}
    }

}

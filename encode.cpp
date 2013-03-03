#include<iostream>
#include<cstring>
using namespace std;
static unsigned char Decode6BitMask[5] = { 0xff, 0xfe, 0xfd, 0xec, 0xcd };
int memlen(const char *str)
{
    const char *eos = str;
    while (*eos++);
    return ((int)(eos - str));
}
int fnEncode6BitBufA(unsigned char *pszSrc, char *pszDest, int nSrcLen, int nDestLen)
{
	int	nDestPos	= 0;
	int	nRestCount	= 0;
	unsigned char	chMade = 0, chRest = 0;

	for (int i = 0; i < nSrcLen; i++)
	{
		if (nDestPos >= nDestLen) break;
		
		chMade = ((chRest | (pszSrc[i] >> (2 + nRestCount))) & 0x3f);
		chRest = (((pszSrc[i] << (8 - (2 + nRestCount))) >> 2) & 0x3f);

		nRestCount += 2;

		if (nRestCount < 6)
			pszDest[nDestPos++] = chMade + 0x3c;
		else
		{
			if (nDestPos < nDestLen - 1)
			{
				pszDest[nDestPos++]	= chMade + 0x3c;
				pszDest[nDestPos++]	= chRest + 0x3c;
			}
			else
				pszDest[nDestPos++] = chMade + 0x3c;

			nRestCount	= 0;
			chRest		= 0;
		}
	}

	if (nRestCount > 0)
		pszDest[nDestPos++] = chRest + 0x3c;

//	pszDest[nDestPos] = '\0';

	return nDestPos;
}

int  fnDecode6BitBufA(char *pszSrc, char *pszDest, int nDestLen)
{
	int	nLen = memlen((const char *)pszSrc) - 1;
	int	nDestPos = 0, nBitPos = 2;
	int	nMadeBit = 0;
	unsigned char	ch, chCode, tmp;

	for (int i = 0; i < nLen; i++)
	{
		if ((pszSrc[i] - 0x3c) >= 0)
			ch = pszSrc[i] - 0x3c;
		else
		{
			nDestPos = 0;
			break;
		}

		if (nDestPos >= nDestLen) break;

		if ((nMadeBit + 6) >= 8)
		{
			chCode = (tmp | ((ch & 0x3f) >> (6 - nBitPos)));
			pszDest[nDestPos++] = chCode;

			nMadeBit = 0;

			if (nBitPos < 6) 
				nBitPos += 2;
			else
			{
				nBitPos = 2;
				continue;
			}
		}

		tmp = ((ch << nBitPos) & Decode6BitMask[nBitPos - 2]);

		nMadeBit += (8 - nBitPos);
	}

//	pszDest[nDestPos] = '\0';

	return nDestPos;
}
int main()
{
    char src[100] = "hello world!";
    char des[100];
    fnEncode6BitBufA((unsigned char*)src, des, strlen(src) + 1, strlen(src) + 1);
    fnDecode6BitBufA(des, src, strlen(src) + 1);
    cout<<src<<endl;
    return 0;
}

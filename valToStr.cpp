#include<iostream>
using namespace std;
void CharToStr(unsigned int value, char* str)
{
    char *ptr   = str;
    unsigned digval; 
    while (value > 0) {
        digval = (unsigned)(value % 10);
	value /= 10;
	if (digval > 9) {
            *ptr   = (char)(digval -  10 + 'a');
	} else {
	    *ptr   = (char)(digval + '0');
	}
	ptr++;
    }
    *ptr = '\0';
}
int main()
{
    char buf[100];
    CharToStr(-6788, buf);
    cout<<buf<<endl;
    return 0;
}

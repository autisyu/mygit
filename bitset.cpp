#include<iostream>
using namespace std;
const int g_shift = 5;
const int g_mask    = 0x1f;
const int g_size    = 8 * 1024;
unsigned int bitmap[g_size];

void BitClear(unsigned int* bitmap)
{
    for (int i = 0; i < g_size; ++i) {
        bitmap[i] &= 0;
    }
}

void BitSet(unsigned int* bitmap, unsigned int position)
{
    bitmap[position >> g_shift] |= (1<<(position&g_mask)); 
}

void BitClean(unsigned int* bitmap,unsigned int position)
{
    bitmap[position >> g_shift] &= ((1<<(position&g_mask)) ^ 0xffffffff); 
}

int BitGet(unsigned int* bitmap, unsigned int position)
{
    return (bitmap[position >> g_shift] &  (1<<(position&g_mask))); 
}
int main()
{
    
    BitClear(bitmap);

    BitSet(bitmap, 1234);
    cout<<BitGet(bitmap, 1234)<<endl;
    BitClean(bitmap, 1234);
    cout<<BitGet(bitmap, 1234)<<endl;;
    return 0;
}

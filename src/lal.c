#include<stdio.h>
#include<memory.h>
const int maxlen =  1000;
static inline int max(int a, int b) { return a > b ? a: b; }
int lal(int *data, int len)
{
    int assend[maxlen];
    int routin[maxlen];
    int index = 1, before_index, temp_index;
    int max_value = -1, max_index;
    for (temp_index = 0; temp_index < maxlen; ++temp_index) {
        assend[temp_index] = 1;
	routin[temp_index] = -1;
    }
    assend[0] = 1;
    for (; index < len; ++index) {
        for (before_index = index - 1; assend[before_index] >= assend[index] && before_index >=0; --before_index) {
	    if (data[index] >= data[before_index]) {
	      assend[index] = max(assend[index], 1 + assend[before_index]);
	      routin[index] = before_index;
	    }
	}
    }
    temp_index = 0;
    for (;temp_index < len; ++temp_index) {
        if (assend[temp_index] > max_value) {
          max_value  = assend[temp_index];
	  max_index  = temp_index;
	  temp_index++;
	}
    }
    temp_index = max_index;
    while (temp_index >= 0) {
        printf("%d ", data[temp_index]);
	temp_index = routin[temp_index];
    }
    printf("\n");
    return max_value; 
}
int main()
{
    int data[] = {1, 4, 3, 7, 9, 5};
    
    printf("lal = %d", lal(data, 6));
    return 0;
}

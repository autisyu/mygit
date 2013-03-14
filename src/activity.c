#include<stdio.h>
#include "utility.h"
const int maxlen = 100;

int activity(int *start_time, int *end_time, int len)
{
    start_time[0]       = -1;
    end_time[0]         = -1;
    start_time[len + 1] = 0xfffff;
    end_time[len + 1]   = 0xfffff;

    int count[maxlen][maxlen];
    int activity_size, start, end, index;
    count[0][1] = 0, count[len][len + 1] = 0;

    for (start = 2; start <= len; ++start) {
	  count[start - 1][start] = 0;
	  //printf("start = %d, count =  %d\n",start - 1, count[start - 1][start] );
    }
    for (activity_size = 3; activity_size <= len + 2; ++activity_size) {
        for (start = 0; start + activity_size - 1<= len+1; ++start) {
	    for (index = start + 1; index < start + activity_size - 1; ++index) {
	        if (start_time[index] >= end_time[start] && end_time[index] <= start_time[start + activity_size - 1]) {
	          count[start][start + activity_size - 1] = max(count[start][start + activity_size - 1], count[start][index] + count[index][start + activity_size - 1] + 1);
	          printf("start = %d, activity_size = %d, count =  %d\n",start, activity_size, count[start][start + activity_size - 1] );
		}
	    }
	}
    }
    return count[0][len + 1];
}

int main()
{
    int start_time[maxlen];
    int end_time[maxlen];
    int len, temp_index;
    scanf("%d", &len);
    for (temp_index = 1; temp_index <= len; ++temp_index) {
        scanf("%d %d", &start_time[temp_index], &end_time[temp_index]);
    }
    printf("big = %d\n", activity(start_time, end_time, len));
    return 0;
}

#include<stdio.h>
#define MAX 100
int queue[MAX],rear, front;
void QInit()
{
    rear = front = 0;
}
int Enqueue(int value)
{
    if ((front + 1)  % MAX ==  rear) {
      return -1;
    }
    queue[front] = value;
    front = (front + 1) % MAX;
    return 0;
}
int Dequeue(int& value)
{
    if (rear == front) {
      return -1;    
    }
    value = queue[rear];
    rear = (rear + 1) % MAX;
    return 0;
}
int main()
{
    QInit();
    int i = 0;
    for (; i < 100; ++i) {
        if (Enqueue(i) == -1) {
	  printf("queue overflow\n");
	  break;
	}
	printf("%d, %d\n", front, rear);
    }
    for (i = 0; i < 100; ++i) {
        int value;
	if (Dequeue(value) == -1) {
	  printf("queue empty!\n");
	  break;
	}
	printf("%d ", value);
    }

}

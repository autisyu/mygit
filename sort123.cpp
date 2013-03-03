#include<iostream>
using namespace std;
void swap(int& left_point, int& right_point)
{
    left_point  = left_point ^ right_point;
    right_point = left_point ^ right_point;
    left_point  = right_point ^ left_point;
}
void sort123(int *array, int n)
{
    for (int i = 2, left_point = 0, right_point = n - 1; i >= 1; --i) {
        while (left_point < right_point) {
	    while (right_point > left_point && array[right_point] == i) {
	        --right_point;
	    }
	    while (left_point < right_point && array[left_point]  != i) {
	        ++left_point;
	    }
	    swap( array[left_point], array[right_point]);
	}
	left_point = 0;
    }
}
int main()
{
    int array[] = {1, 2, 0, 2, 0, 1, 1, 2};
    for (int i = 0; i < sizeof(array) / sizeof(int); ++i) {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    sort123(array, sizeof(array) / sizeof(int));
    for (int i = 0; i < sizeof(array) / sizeof(int); ++i) {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    return 0;
}

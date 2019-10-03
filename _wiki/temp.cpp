```c++
#include <iostream>
using namespace std;

void SelectSort(int *a, size_t n){
    int begin = 0;
    int end = n-1;
    while(begin < end){
        int minvalueIndex = begin;
        int maxvalueIndex = begin;
        for(size_t i=begin; i<=end; i++){
            if(a[minvalueIndex] > a[i])
                minvalueIndex = i;
            if(a[maxvalueIndex] < a[i])
                maxvalueIndex = i;
        }
        int temp1 = a[begin];
        int temp2 = a[end];
        a[begin] = a[minvalueIndex];
        a[end] = a[maxvalueIndex];
        a[minvalueIndex] = temp1;
        a[maxvalueIndex] = temp2;
        begin++;
        end--;
    }
}
```
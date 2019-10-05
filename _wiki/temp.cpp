```c++
#include <iostream>
#include <algorithm>
using namespace std;

void BubbleSort(int *a, size_t n){
    size_t end = n;
    int exchange = 0;
    while(end > 0){
        for(int i=1; i<end; i++){
            if(a[i-1] > a[i]){
                swap(a[i-1], a[i]);
                exchange = 1;
            }
        }
        // exchange等于0表明数组本身已经是升序，所以程序结束。
        if(exchange == 0){
            break;
        }
        end--;
    }
}
```
---
layout: wiki
title: 排序算法的实现
categories: C/C++
description: 
keywords: 链表, 队列, 容器
---

常用的排序算法的C++实现，并总结算法的时空复杂度。

<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>

![](/images/ALGO/M2.png)

## 常见的排序算法的时空复杂度

|排序方法|平均时间|最好时间|最坏时间|空间复杂度|稳定性|
|插入排序|$$O(N^2)$$|$$O(N)$$|$$O(N^2)$$|$$O(1)$$|稳定|
|希尔排序|$$O(N^{1.3})$$|$$O(N)$$|$$O(N^2)$$|$$O(1)$$|不稳定|
|选择排序|$$O(N^2)$$|$$O(N^2)$$|$$O(N^2)$$|$$O(1)$$|不稳定|
|堆排序|$$O(N\times lgN)$$|$$O(N\times lgN)$$|$$O(N\times lgN)$$|$$O(1)$$|不稳定|
|冒泡排序|$$O(N^2)$$|$$O(N)$$|$$O(N^2)$$|$$O(1)$$|不稳定|
|快速排序|$$O(N\times lgN)$$|$$O(N\times lgN)$$|$$O(N^2)$$|$$O(lgN)$$|稳定|
|归并排序|$$O(N\times lgN)$$|$$O(N\times lgN)$$|$$O(N\times lgN)$$|$$O(N)$$|不稳定|

## 插入排序

![](/images/WiKi/wiki1.png)

思路：待排序的元素（红色）左区域（橙色）是已经排序好的元素，右区域（蓝色）是等候排序的元素，重复遍历左区域找到合适的位置插入。

```c++
#include <iostream>
using namespace std;

void InsertSort(int *a, size_t n){
    for(size_t i = 1; i<n; i++){
        int end = i-1;
        int temp = a[i];
        while(end >= 0){
            if(a[end] > temp){
                a[end+1] = a[end];
                end--;
            } else {
                break;
            }
        }
        a[end+1] = temp;
    }
}
```

## 希尔排序

![](/images/WiKi/wiki2.png)

思路：希尔排序维护一个gap，将原数组分成gap份，对每份数组执行插入排序算法，然后减少gap值并重复上述操作，直至gap等于1。其中gap满足：

$$gap = \frac{gap}{3}+1$$

```c++
#include <iostream>
using namespace std;

void ShellSort(int *a, size_t n){
    int gap = n;
    while(gap > 1){
        gap = gap/3 + 1;
        for(size_t i = 0; i<n-gap; i++){
            int end = i;
            int temp = a[end+gap];
            while(end >= 0 && a[end] > temp){
                a[end+gap] = a[end];
                end -= gap;
            }
            a[end+gap] = temp;
        }
    }
}
```

## 选择排序

![](/images/WiKi/wiki3.png)

思路：不断遍历数组找出其最小值和最大值，将最小值交换到数组最前端，将最大值交换到数组最后端，重复操作。

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
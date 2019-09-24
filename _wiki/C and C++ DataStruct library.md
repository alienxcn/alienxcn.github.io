---
layout: wiki
title: C/C++常用数据结构库
categories: C/C++
description: 
keywords: 链表, 队列, 容器
---

这里主要收集在C/C++语言下常用数据结构库的用法，例如队列、容器、字符串、集合、映射等。

![](/images/ALGO/M5.png)

## Stack

### 构造函数

```c++
// 创建一个存放int类型的空栈，默认实现容器是deque。
stack<int> sample;

// 使用双端队列构造栈。
deque<int> temp(3, 100);
stack<int> sample(temp);

// 使用容器构造栈。
vector<int> temp(2, 200);
stack<int, vector<int>> sample(temp);
```

### 属性

```c++
stack<int> sample;

// 栈的大小。
sample.size();

// 增加元素。
sample.push(INT);

// 是否为空。
sample.empty();

// 栈顶元素。
sample.top();

// 退栈。
sample.pop();
```

### 样例

```c++
#include <iostream>
#include <stack>
using namespace std;

struct Node{
    int a, b;
    Node(int x, int y){
        a = x;
        b = y;
    }
};

int main(){
    stack<Node> mystack;
    // emplace传入元素时同时执行结构体的构造函数。
    mystack.emplace(1, 2);

    Node p = mystack.top();
    cout << p.a << " " << p.b << endl;
    return 0;
}
```

## Queue

### 构造函数

```c++
// 创建一个存放int类型的空队列，默认实现容器是deque。
queue<int> sample;

// 使用双端队列构造队列。
deque<int> temp(3, 100);
queue<int> sample(temp);

// 复制拷贝函数。
queue<string> words;
queue<string> copy_words{words};
```

### 属性

```c++
queue<int> sample;

// 返回队列第一个元素的引用。
sample.front();

// 返回队列最后一个元素的引用。
sample.back();

// 在队列的尾部加入元素，这是调用底层容器的push_back()实现的。
sample.push(const T& obj);

// 删除队列的第一个元素。
sample.pop();

// 返回队列的长度。
sample.size();

// 队列是否为空。
sample.empty();

// 使用参数调用T的构造函数，并在队列尾部生成对象。
sample.emplace(T);
```

### queue与deque的区别

1. deque是双向队列，有迭代器，可以在两端扩展和收缩的连续容器；queue是单向容器，没有迭代器。
2. deque的实现是基于动态数组，允许单个元素用随机获取迭代器随机读取，数组容量自动管理。deque的元素并不是严格连续存储的。

## Priority Queue

优先队列具有queue的所有特性，在这基础上添加了一个内部排序，优先队列本质上是堆来实现的。

### 构造函数

```c++
priority_queue<Type, Container, Functional>

// 升序优先队列
priority_queue<int, vector<int>, greater<int> > sample;

// 降序优先队列
priority_queue<int, vector<int>, less<int> > sample;

```

### 样例

```c++
#include <iostream>
#include <queue>
using namespace std;

int main(){
    priority_queue<int> a;
    // 相当于 priority_queue<int, vector<int>, less<int> > a。
    priority_queue<int, vector<int>, greater<int> > c;
    
    for(int i=0; i<5; i++){
        a.push(i);
        c.push(i);
    }

    while(!a.empty()){
        cout << a.top() << endl;
        a.pop();
    }
    cout << endl;

    while(!c.empty()){
        cout << c.top() << endl;
        c.pop();
    }
    cout << endl;
    return 0;
}
```

```c++
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    priority_queue<pair<int, int> > a;
    pair<int, int> p1(1, 2);
    pair<int, int> p2(1, 3);
    pair<int, int> p3(2, 5);
    a.push(p1);
    a.push(p2);
    a.push(p3);
    while(!a.empty()){
        cout << a.top().first << " " << a.top().second << endl;
        a.pop();
    }
    return 0;
}
```
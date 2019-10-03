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

```c++
#include <iostream>
#include <queue>
using namespace std;

struct tmp1{
    int x;
    tmp1(int a){
        x = a;
    }
    bool operator<(const tmp1& a) const{
        return x < a.x;
    }
};

struct tmp2{
    bool operator() (tmp1 a, tmp1 b){
        return a.x < b.x;
    }
};

int main(){
    tmp1 a(1);
    tmp1 b(2);
    tmp1 c(3);
    priority_queue<tmp1> d;
    d.push(b);
    d.push(c);
    d.push(a);
    while(!d.empty()){
        cout << d.top().x << endl;
        d.pop();
    }
    cout << endl;

    priority_queue<tmp1, vector<tmp1>, tmp2> f;
    f.push(c);
    f.push(b);
    f.push(a);
    while(!f.empty()){
        cout << f.top().x << endl;
        f.pop();
    }
    return 0;
}
```

## Set

### 属性

```c++
set<int> sample;

// 迭代器
sample.begin();
sample.rend();
sample.end();
sample.rbegin();

// 清空元素
sample.clear();

// 删除元素
sample.erase(iterator);
sample.erase(iterator, iterator);
sample.erase(key_value);

// 查找元素，如果没找到返回end
sample.find(key_value);

// 插入元素
sample.insert(key_value);

// 判断为空
sample.empty();

// 返回set容器可能包含的元素最大个数
sample.max_size();

// 返回当前set容器中的元素个数
sample.size();

// 返回元素在set容器中出现的次数，或者用来判断元素是否出现。
sample.count();
```

### 样例

```c++
#include <iostream>
#include <set>
using namespace std;

int main(){
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(1);
    cout << s.size() << endl;
    cout << s.max_size() << endl;
    cout << *s.begin() << endl;
    cout << *s.end() << endl;

    for(set<int>::iterator i = s.begin(); i!=s.end(); i++){
        cout << *i << " ";
    }
    cout << endl;

    s.clear();
    return 0;
}
```

```c++
#include <iostream>
#include <set>
using namespace std;

int main(){
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(1);
    s.insert(3);
    cout << s.count(1) << endl;
    cout << s.count(4) << endl;
    return 0;
}
```

```c++
#include <iostream>
#include <set>
using namespace std;

int main(){
    set<int> s;
    set<int>::const_iterator iter;
    set<int>::iterator first;
    set<int>::iterator second;
    for(int i=0; i<10; i++){
        s.insert(i);
    }
    s.erase(s.begin());
    first = s.begin();
    second = s.begin();
    second++;
    second++;
    s.erase(first, second);
    s.erase(8);
    for(iter = s.begin(); iter != s.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;
    // 4 5 6 7 9 10
    return 0;
}
```

```c++
#include <iostream>
#include <set>
#include <string>
using namespace std;

struct Info{
    string name;
    float score;
    bool operator < (const Info& a) const {
        // score降序排序
        return a.score < score;
    }
};

set<Info> s;
set<Info>::iterator it;
```

## Vector

### 构造函数

```c++
// 创建一个存放int类型的容器
vector<int> sample;

// 创建指定空间大小的容器，或者是指定所有元素内容的容器
vector<int> sample(int nSize);
vector<int> sample(int nSize, const int& t);

// 复制构造函数
vector<int> sample(const vector<int>&);
vector<int> sample(vector<int>::iterator begin, vector<int>::iterator end);
sample.assign(vector<int>::iterator begin, vector<int>::iterator end);

// 从数组中复制值
int a[5] = {1,2,3,4,5};
vector<int> sample(a, a+5);
```

### 方法

```c++
// 向容器尾部添加元素
sample.push_back(const T& x);

// 在it位置插入数据x
sample.insert(iterator it, T& x);

// 在it位置插入n个数据x
sample.insert(iterator it, int n, T& x);

// 在it位置插入一段区间[a,b)
sample.insert(iterator it, const iterator a, const iterator b);

// 删除位置it的值
sample.erase(iterator it);

// 删除一段区间[a,b)
sample.erase(iterator a, iterator b);

// 删除最后的元素
sample.pop_back();

// 清空容器
sample.clear();

// 交换
sample.swap(vector<int>& a);
```

### 属性

```c++
// 返回位置it的元素的引用
sample.at(int pos);

// 返回首个元素的引用
sample.front();

// 返回尾部元素的引用
sample.back();

// 返回首个元素的迭代器
sample.begin();

// 返回容器结尾，最后一个元素的后一个迭代器
sample.end();

// 返回容器结尾的迭代器
sample.rbegin();

// 返回首元素前一个迭代器
sample.rend();

// 是否为空
sample.empty();

// 长度
sample.size();
```

### 样例

```c++
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N = 5, M = 6;
    vector<vector<int> > obj(N, vector<int>(M));
    for(int i=0; i<obj.size(); i++){
        for(int j=0; j<obj[0].size(); j++){
            cout << obj[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
```

## Map

标准的STL Map是以红黑树为底层机制完成的，每一个节点的内容是pair。

### 方法

```c++
map<int, int> sample;

// 迭代器
sample.begin();
sample.end();
sample.rbegin();
sample.rend();

sample.clear();

sample.count(pair);

sample.empty();

sample.erase();

sample.find();

sample.insert();

sample.swap();

sample.size();
```

### 样例

```c++
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
    map<string, int> strMap;
    strMap["jjhou"] = 1;
    strMap["jerry"] = 2;
    strMap["jason"] = 3;
    strMap["jimmy"] = 4;

    pair<string, int> value("david", 5);
    strMap.insert(value);

    map<string int>::iterator strmap_iter = strMap.begin();
    for(;strmap_iter != strMap.end(); strmap_iter++){
        cout << strmap_iter->first << " " << strmap_iter->second << endl;
    }
    cout << endl;

    int number = strMap["jjhou"];
    cout << number << endl;
    
    map<string, int>::iterator iter1;
    iter1 = strMap.find("mchen");
    if(iter1 == strMap.end()){
        cout << "mchen no found" << endl;
    }
    cout << endl;

    iter1 = strMap.find("jerry");
    if(iter1 != strMap.end()){
        cout << "jerry found" << endl;
    }
    cout << endl;

    iter1->second = 9;
    int number1 = strMap["jerry"];
    cout << number1 << endl;

    map<string, int>::iterator strmap_iter1 = strMap.begin();
    for(;strmap_iter1 != strMap.end(); strmap_iter1++){
        cout << strmap_iter1->first << " " << strmap_iter1->second << endl;
    }
    cout << endl;

    strMap.erase(iter1);
    strMap.erase("jason");

    map<string, int>::iterator strmap_iter2 = strMap.begin();
    for(;strmap_iter2 != strMap.end(); strmap_iter2++){
        cout << strmap_iter2->first << " " << strmap_iter2->second << endl;
    }
    return 0;
}
```
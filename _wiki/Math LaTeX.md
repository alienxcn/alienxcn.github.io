---
layout: wiki
title: Math LaTeX
categories: C/C++
description: 
keywords: 链表, 队列, 容器
---

LaTeX常用公式表

<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>

![](https://alienx.oss-cn-shenzhen.aliyuncs.com/images/ALGO/M7.png)

## 多行公式

$$\begin{aligned}S_n&=n\times a_1&q=1\\S_n&=a1\times \frac{1-q^n}{1-q}&q\not=1\end{aligned}$$

```
\begin{aligned}
S_n &= n\times a_1 &q=1 \\
S_n &= a1\times \frac{1-q^n}{1-q} &q\not=1
\end{aligned}
```

$$\begin{equation}D(x) = \begin{cases}1, & \\0, &\end{cases}\end{equation}$$

```
\begin{equation}
D(x) = 
\begin{cases}
1, & \\
0, &
\end{cases}
\end{equation}
```

## 求和、乘积

$$\begin{equation}\sum_{i=1}^ni=\frac{n(n-1)}{2}\end{equation}$$

```
\begin{equation}
\sum_{i=1}^ni=\frac{n(n-1)}{2}
\end{equation}
```

$$\begin{equation}\prod_{i=1}^n\frac{n+1}{n}=n+1\end{equation}$$

```
\begin{equation}
\prod_{i=1}^n\frac{n+1}{n}=n+1
\end{equation}
```



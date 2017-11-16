---
layout: page
title: 关于
description: 守正出奇
keywords: 陆茂斌, 小神先生
comments: false
menu: 关于
permalink: /about/
---

## whois

我是小神先生，专注于网络空间安全。

遵守「知行合一，守正出奇」的原则。

坚信熟能生巧，努力改变人生。

## ACMer

大一开始陆续参加ACM程序设计竞赛。

两度参加ACM ICPC，打铁。

学习算法的一种很好实践方式。

## 网络空间安全

对```web安全```，```密码学```，```无线网络安全```感兴趣。

参加大大小小CTF与网络安全运维赛。

主要负责Crypto、MISC方向，辅助位。

## 前端开发

钟爱```Vue.js```侵入式前端框架。

搭配```VUX```创造出兼容微信下的移动端网站。

## 软件开发

用```winForm```框架在windows下创建应用。

对外观样式敏锐，喜欢简介、易读的界面。

## 网络服务

十分喜欢捣腾服务器。

持有alienx.cn、alienx.top、alienx.me域名。

使用```wireshark```进行网络审计与流量审计。

## 爱好

中长距离骑行，累计里程已经超过```4000```公里。

最先进、前沿的计算产品，例如Apple全家桶。

波音、空客的全系列客机，大爱```空客A320-200```。

CASIO的航空系智慧型电波手表。

一场说走就走的旅行。

## 履历

拜尔口腔公司（广州），协作开发口腔医疗信息管理系统。

中国南方航空电子商务部（广州），划水实习。

广东省建设信息中心（广州），主要负责微信端的网站全栈开发。

## 联系

{% for website in site.data.social %}
* {{ website.sitename }}：[@{{ website.name }}]({{ website.url }})
{% endfor %}

## 技能树

{% for category in site.data.skills %}
### {{ category.name }}
<div class="btn-inline">
{% for keyword in category.keywords %}
<button class="btn btn-outline" type="button">{{ keyword }}</button>
{% endfor %}
</div>
{% endfor %}

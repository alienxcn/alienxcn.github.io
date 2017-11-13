---
layout: page
title: About
description: 守正出奇
keywords: 陆茂斌, 小神先生
comments: false
menu: 关于
permalink: /about/
---

我是陆茂斌，专注于网络空间安全。

遵守「知行合一，守正出奇」。

坚信熟能生巧，努力改变人生。

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

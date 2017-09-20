---
permalink: /about/
title: "За курса"
layout: single
author_profile: true
---

{% include toc icon="gears" title="За курса" %}

## Програмиране за 10 клас

### Цели

В целите на този курс са:

- да разшири знанието на учениците за езика C от 9-ти клас
- да развие критичното мислене на учениците
- да въведе учениците в работа с основни структури от данни, алгоритми и шаблони за разработка на софтуер

### Академична честност

Важно е да се има предвид, че курса по програмиране на С за 10 клас се уповава на официалното [ръководство за академична честност на Технологично училище "Електронни системи"](https://docs.google.com/document/d/1iGholl9nUg3zkAkjjhLq2XK91BKkZFxmAg8rBY17xWU/edit?usp=sharing)

### Полезни линкове

- [Официалната страница на училището](http://www.elsys-bg.org/)
- [Материали по програмиране от минали години](http://lubo.elsys-bg.org/)

### Survival Guide

Съществува т.нар. "Наръчник за оцеляване по програмиране в 10 клас" -
сборник от полезни линкове, материали и отговори на често задавани от учениците въпроси.
Той е в изключително начална фаза, но все пак може да бъде намерен тук:

- [Survival Guide (draft)](https://www.gitbook.com/book/elsys/survival-guide/details)
- [Survival Guide (source)](https://github.com/elsys/survival-guide)

> При желание учениците могат да се включат в развиването на този наръчник.

### Как да се свържете с нас

[elsys-po@googlegroups.com](mailto:elsys-po@googlegroups.com)

## През годините

{% for post in site.years %}
  {% include archive-single.html %}
{% endfor %}

# Roots of an Arbitrary Polynomial

This repository contains a solution to a challenging mathematical problem. 

**RU**

## Условие Задачи

Однажды гениальный мальчик Герман решал домашнее задание по алгебре и забыл, как вычислять корни многочленов. Добрая учительница математики задала ему многочлен 6 степени в качестве примера на дом, и теперь Герман, спустя несколько мучительных часов, уже почти дойдя до аналога формулы Кардано-Феррари общего решения для многочлена 4 степени, отчаялся. К счастью, он очень увлекается информатикой и хорошо знает рекурсию, потому он решил написать код, решающий поставленную доброй учительницей математики задачу в общем случае:
Для переменной $x \in R$ на вещественной прямой задан многочлен с вещественными коэффициентами:
$p(x) = a_nx^n + a_{n - 1}x^{n - 1} + \ldots + a_1x + a_0, a_i \in R, 0 \leqslant i \geqslant n, a_n \ne 0$

Найти все его корни на заданном полуинтервале
$[ A, B )$, где $A, B \in R$, $A < B$

Помогите Герману перестать отчаиваться и идеально решить свое домашнее задание

## Формат Ввода

В первой строке программе подается число $n$ — степень многочлена $p (0 \leqslant n \geqslant 6 )$. Во второй строке через пробел перечисляются $n + 1$ чисел — все его коэффициенты  $a_i$ от старшего к младшему ($|a_i| \leqslant 10^5$
). На третьей строчке вводятся числа $A$ и $B$ — границы полуинтервала числовой прямой, на котором требуется найти все корни многочлена $p (−1000 \leq A \leq B \leq 1000)$

## Формат Вывода

Выведите все корни многочлена $p$ на полуинтервале $[ A, B )$ в порядке $\textbf{неубывания}$ (нужно учитывать кратность корней) через пробел с точностью не менее $10^{−6}$. Если многочлен не имеет корней, ничего выводить не нужно

***



**ENG**

## Problem Statement

One day, a brilliant boy named Herman was doing his algebra homework and forgot how to calculate the roots of polynomials. A kind math teacher gave him a 6th degree polynomial as a homework problem, and now Herman, after several agonizing hours, having almost reached the analogue of the Cardano-Ferrari formula of the general solution for a 4th degree polynomial, despaired. Luckily, he is very interested in computer science and knows recursion well, so he decided to write a code that solves the problem set by the kind math teacher in the general case:
For the variable $x \in R$ on the real line, a polynomial with real coefficients is defined:
$p(x) = a_nx^n + a_{n - 1}x^{n - 1} + \ldots + a_1x + a_0, a_i \in R, 0 \leqslant i \geqslant n, a_n \ne 0$

Find all its roots on the given half-interval
$[ A, B )$, where $A, B \in R$, $A < B$

Help Herman stop despairing and solve his homework perfectly

## Input Format

The first line of the program is fed with the number $n$ — the degree of the polynomial $p (0 \leqslant n \geqslant 6 )$. The second line is followed by a space-separated list of $n + 1$ numbers — all it's coefficients $a_i$ from the highest to the lowest ($|a_i| \leqslant 10^5$
). The third line is fed with the numbers $A$ and $B$ — the boundaries of the half-interval of the number line on which it is required to find all the roots of the polynomial $p (−1000 \leq A \leq B \leq 1000)$

## Output Format

Output all roots of the polynomial $p$ on the half-interval $[ A, B )$ in $\textbf{non-decreasing}$ order (you need to take into account the multiplicity of the roots) separated by a space with an accuracy of at least $10^{−6}$. If the polynomial has no roots, you do not need to output anything




## Examples

### Example 1
**Input**:
- 6
- 5 7 -4 11 -10 1 -18
- -10 10

**Output**:
- -2.3498288 1.10086298

***

### Example 2
**Input**:
- 2
- 2 -3 1
- 0.5 1

**Output**:
- 0.5

***

### Example 3
**Input**:
- 6
- 1.0 15.0 20.25 -351.0 -283.5 1458.0 1640.25
- -100 100

**Output**:
- -9.0 -9.0 -1.5 -1.5 3.0 3.0

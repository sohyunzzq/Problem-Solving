# [Bronze I] Смех, да и только! - 29087 

[문제 링크](https://www.acmicpc.net/problem/29087) 

### 성능 요약

메모리: 2392 KB, 시간: 0 ms

### 분류

구현, 다이나믹 프로그래밍, 그리디 알고리즘, 문자열

### 제출 일자

2025년 7월 12일 01:44:26

### 문제 설명

<p>Колобок любит много смеяться. Чтобы подготовиться к встрече с потенциальным противником, Лиса решает изучить его смех. </p>

<p>Лиса считает, что смех  --- это последовательность чередующихся букв <<<code>a</code>>> и  <<<code>h</code>>>. Так например, <<<code>ahahaha</code>>>, <<<code>hah</code>>> и <<<code>a</code>>> являются смехом, а <<<code>abacaba</code>>> и <<<code>hh</code>>> --- нет.</p>

<p>Колобок разговаривает очень быстро, поэтому все его слова сливаются в одно большое. Для исследования Лиса хочет понять, как долго он может смеяться. У неё есть строка --- запись разговора Колобка. Лиса хочет узнать наибольшую длину смеха в этом разговоре.</p>

<p>Лиса просит вас помочь ей с этой задачей. </p>

### 입력 

 <p>В первой строке входного файла находится одно натуральное число <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$n$</span></mjx-container> (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-msup space="4"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.393em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c35"></mjx-c></mjx-mn></mjx-script></mjx-msup></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><mi>n</mi><mo>≤</mo><msup><mn>10</mn><mn>5</mn></msup></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1 \le n \le 10^5$</span></mjx-container>) --- длина строки с разговором колобка. Во второй строке находится строка из строчных латинских букв длины <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45B TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>n</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$n$</span></mjx-container> --- запись разговора колобка.</p>

### 출력 

 <p>В выходной файл выведите одно число --- наибольшую длину смеха в разговоре Колобка.</p>


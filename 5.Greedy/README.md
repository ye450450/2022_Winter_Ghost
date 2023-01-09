# 2023.01.09 
------------
# Greedy

+ ``Greedy Algorithm``은 매 순간마다 최적의 상황만을 따라가 최종적인 해답에 도달하는 방법    
+ 그래서 Dynamic programming과는 다르게 ``지역적 ``       
+ 지역적으로는 최적이지만, 전역적으로는 최적이라고 보장할 수는 없다.
+ 실행시간이 빠르다.

+ 예시

![image](https://user-images.githubusercontent.com/104772331/211333053-dcec90e0-5883-441c-8974-ad0d996c5dd6.png)

-> Greedy는 여기서 **10분 > 20분 >15분**을 선택    
-> 사실 가장 적은 시간은 **10분 > 30분 > 2분**을 선택

>  **Greedy algorithm 문제**
1. 일반적으로 최대한 적은, 최대한 많은 이라는 문구가 문제에 들어가는 경우가 많다. 최대/최소의 경우의 수를 구할것을 요구하는 문제들   
2. 그리디를 사용할 수 있는 조건이 주어진다.   
3. 정렬을 한 뒤 그것을 이용해 푸는 문제가 많다.

-------

## 1026번 문제(보물)
> A 배열과 B 배열을 입력받아 A배열을 재배열하고 각 index를 곱해서 더하는 값의 최솟값을 출력하는 프로그램

1. A배열을 올림차순 정렬
2. B배열을 내림차순 정렬
3. 두 배열을 곱해 출력

--------
## 1946번 문제(신입사원)
> 서류성적과 면접시험 성적을 가지고 두 성적이 모두 어떤 참가자보다 낮으면 탈락이다.(등수를 입력)
  선발할 수 있는 신입사원의 최대 인원 수를 구하는 프로그램을 작성

1. 서류성적으로 올림차순으로 정렬
2. 면접시험 성적을 위에서부터 살피면서 더 크면 탈락
3. 작으면 그 숫자를 가지고 비교하면서(인원 수를  늘려준다.)

--------
## 16953번 문제(A->B)
> A를 B로 바꿀때, 가능한 연산은 2를 곱하거나 1을 수의 가장 오른쪽에 추가하는 것이다.
  A를 B로 바꾸는데 필요한 연산의 최솟값을 구하는 문제

1. B가 A보다 작거나 같아질 때까지 반복
2. B를 2로 나눌 수 있으면 나누어준다.
3. B를 1로 빼서 10으로 나눌 수 없다면, -1 출력
4. B를 1로 빼서 10으로 나눌 수 있으면 나눈다.
5. B와 A가 같다면 반복한 수 출력
6. 아니면 -1 출력
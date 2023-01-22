/*2023.01.22
<카드2>
N장의 카드가 잇다. 1번 카드가 제일 위에, N번 카드가 제일 아래인 상태로 순서대로 카드가 놓여있다.
이제 다음과 같은 동작을 카드가 한 장 남을 때까지 반복
우선, 제일 위에 있는 카드를 바닥에 버린다.
그 다음, 제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로 옮긴다.
예시) N이 4인 경우, 제일 위부터 1234 순서
1을 버리면, 234가 남는다. 2를 제일 아래로 옮기면 342 결국 마지막에 남는 수는 4가 된다.
제일 마지막에 남게 되는 카드를 구하는 프로그램을 작성
*/
#include <iostream>
#include <deque>
using namespace std;

int N;
deque <int> my_deque;//숫자가 들어가는 곳을 설정

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> N;

    for(int i=1; i<=N; i++){
        my_deque.push_back(i);
    }//숫자를 넣어준다.

    while(my_deque.size()!=1){
        my_deque.pop_front();//가장 앞의 수를 제거
        my_deque.push_back(my_deque.front());//가장 앞의 수를 뒤로 보냄
        my_deque.pop_front();
    }//하나 남을 때까지 반복
    cout << my_deque.front();   
    return 0;
}
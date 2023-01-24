/*2023.01.25
<요세푸스 문제0>
1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수가 주어진다.
이제 순서대로 K번째 사람을 제거한다.
한 사람이 제가되면 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다.
이 과정은 N명의 사람이 모두 제거될 때까지 계속된다.
원에서 사람들이 제거되는 순서를 (N,K) - 요세푸스 순열이라고 한다.
*/
#include <iostream>
#include <deque>
using namespace std;

int N,K;
deque <int> q;//숫자들을 저장하는 deque이다.
deque <int> erase_que;//제거하는 순서대로 저장하는 deque

int main(){
    ios :: sync_with_stdio(false); cin.tie(0);

    cin >> N >> K;

    for(int i =1;i<=N;i++)
        q.push_back(i);

    int start=0;//처음에 시작하는 부분을 설정
    while(!q.empty()){
        start=(start+K-1)%q.size();
        erase_que.push_back(q.at(start));
        q.erase(q.begin()+start);
    }//순서대로 deque에 저장한다.
    cout << "<";
    for(int i : erase_que){
        if(erase_que.back()==i) {
            cout << i;
            break;
        }//마지막 부분은 숫자만 출력
        else cout << i << ", ";
    }//출력하는 부분
    cout << ">";
    return 0;
}
/*2023.01.10
<요세푸스 문제>
1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, K번째 사람을 순서대로 제거
N명의 사람이 모두 제거될 때까지 계속한다.
원에서 제거되는 순서를 (N, K) -요세푸스 순열이라고 한다.
예시) (7,3)은 <3,6,2,7,5,1,4>이다.
*/
#include <iostream>
#include <deque>
using namespace std;

deque <int> my_deque;//원에 들어가는 숫자를 저장
int N; //원에 들어오는 사람 수
int K; //제거되는 순서를 저장

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> N >> K;
    
    for(int i =1 ; i<=N ;i++)
        my_deque.push_back(i);//사람 수만큼 숫자를 넣어준다.
    
    cout << "<";
    int start=0;//삭제된 위치를 저장
    while(!my_deque.empty()){
        if(my_deque.size()!= N) cout << ", ";//맨처음 시작이 아니라면
        start = (start+K-1)%my_deque.size();//deque의 사이즈를 넘어가도 계속 진행되록함
        cout << my_deque[start];
        my_deque.erase(my_deque.begin()+start);// 제거한다.
    }//deque가 비어질 때까지 반복
    cout << ">";
}
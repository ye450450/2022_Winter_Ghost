/*2023.01.19
<벌집>
육각형으로 이루어진 벌집
중앙의 방 1부터 시작해서 이웃하는 방에 돌아가면서 1씩 증가하는 번호를 주소로 매길 수 있다.
숫자 N이 주어졌을 때, 벌집 중앙 1에서 N번 방까지 최소  개수의 방을 지나서 갈 때
몇 개의 방을 지나가는지를 계산하는 프로그램을 작성
*/
#include <iostream>
using namespace std;

int N;

int main(){
    ios :: sync_with_stdio(false); cin.tie(0);

    cin >> N;
    int count =0;
    while(N>0){
        if(count==0){
            N-=1;
            count++;
        }//맨 처음만한다.
        else{
            N-= 6*(count);
            count++;
        }
    }
    cout << count;
}
/*2023.01.11
<회전하는 큐>
지민이는 N개의 원소를 포함하고 있는 양방향 순환 큐를 가지고 있다.
지민이는 이 큐에서 몇개의 원소를 뽑아내려 한다.
3가지 연산 가능
1. 첫 원소를 뽑기
2. 왼쪽으로 한칸이동
3. 오른쪽으로 한칸이동
N은 큐의 크기, M은 뽑아내는 수
2,3번 연산의 최솟값을 출력하는 프로그램
*/

#include <iostream>
#include <deque>
using namespace std;

int n;//deque의 크기
int m;//뽑아내는 개수
deque <int> my_deque;

//3번 연산 함수
// int third_cal(int count, int temp , depue& <int> temp){
// while(temp!=temp.front())
// return count;
// }
//2번 연산 함수


int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;

    for(int i=1 ;i<=n;i++)
        my_deque.push_back(i);//숫자를 넣어준다.

    int count;//2,3연산의 수를 계산
    for(int i=0 ;i<m ;i++){
        cout << "-------" <<count<<"\n";
        int temp;
        cin >> temp;
        if(temp==my_deque.front()){
            my_deque.pop_front();//1번연산
            continue;
        }

        int sub = temp - my_deque.front();
        if(sub>0){
            if(sub > my_deque.size()/2){
                while(temp !=my_deque.front()){
                    my_deque.push_front(my_deque.back());
                    my_deque.pop_back();
                    count++;
                }
            }//3번 연산을 함 (오른쪽에 가까운 경우)
            else{
                while(temp !=my_deque.front()){
                my_deque.push_back(my_deque.front());
                my_deque.pop_front();
                count++;
                }
            }//2번 연산 (왼쪽에 가까운 경우)
            continue;
        }//입력값이 앞의 원소보다 큰 경우

        sub = my_deque.back() - temp;
            if(sub < my_deque.size()/2){
                while(temp !=my_deque.front()){
                    my_deque.push_front(my_deque.back());
                    my_deque.pop_back();
                    count++;
                }
            }//3번 연산을 함 (오른쪽에 가까운 경우)
            else{
                while(temp !=my_deque.front()){
                my_deque.push_back(my_deque.front());
                my_deque.pop_front();
                count++;
                }
            }//2번 연산 (왼쪽에 가까운 경우)
    }
    cout <<count;
}
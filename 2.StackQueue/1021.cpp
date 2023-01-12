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

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;

    for(int i=0 ;i<n;i++)
        my_deque.push_back(i+1);//n까지의 숫자를 넣어준다.
    int cal_count=0;//2번과 3번 연산의 횟수를 저장
    int start_point=0;//찾고나서 나온 그 위치에서부터 다시 찾기 때문에 위치는 저장
    
    while(m--){
        int delete_num=0;//입력받는 제거할 숫자
        cin >> delete_num;
        
        int count=0;//제거할 숫자가 나올때까지 걸린 횟수
        for(int i=0 ;i <my_deque.size();i++){
            if(my_deque[(start_point+i)%my_deque.size()]==delete_num) {
                start_point=(start_point+i)%my_deque.size();
                break;
            }
            count++;
        }
        if(count==0) {
            my_deque.erase(my_deque.begin()+start_point);//찾은 숫자를 제거
            continue;
        }
        else if(count<=my_deque.size()/2) cal_count+=count;//2번연산을 진행
        else cal_count+=my_deque.size()-count; // 3번연산을 진행하기 때문에 맨 앞에 자신을 가져와야한다.
        my_deque.erase(my_deque.begin()+start_point);//찾은 숫자를 제거
    }
    cout << cal_count;
    return 0;
}
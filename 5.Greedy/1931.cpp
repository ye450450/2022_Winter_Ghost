/*2023.01.09
회의실 배정
회의시간을 입력받아 알맞는 시간을 배정해 가장 많은 회의를 할 수 있도록 해주는 프로그램 작성
예시)
11
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 14
-> 4출력
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int count; //입력받는 회의 수를 저장
    cin >> count;

    pair <int,int> room [100001];
    for(int i =0; i<count ;i++){
        cin >> room[i].first >> room[i].second;
    }
    sort(room,room + count); //내림차순으로 정렬

    int result =1;
    int temp = room[count-1].first;//뒤에서부터 계산
    for(int i =count-2;i>=0 ;i--){
        if(temp>=room[i].second){
            result++;
            temp=room[i].first;
        }
    }//시작하는 시간이 끝나는 시간보다 크거나 같으면 바꾸어주면서 회의 수를 늘려준다.
    cout<<result;
}
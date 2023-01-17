/*2023.01.17
최대값
9개의 서로 다른 자연수가 주어질 때, 이들 중 최대값을 찾고 그 최댓값이 몇 번째 수인지를 구하는 프로그래므을 작성

*/
#include <iostream>
#define NUM 9
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int max=0, max_index;
    for(int i=0,a; i<NUM;i++){
        cin >> a;
        if(a>max){
            max=a;//최댓값 저장
            max_index=i+1;//위치도 저장
        }
    }
    cout << max << '\n'<<max_index;
}
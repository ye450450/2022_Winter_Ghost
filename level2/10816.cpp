/*2023.01.24
숫자 카드2
숫자 카드는 정수 하나가 적혀져 있는 카드
상근이는 숫자 카드 N개를 가지고 있다.
정수 M개가 주어졌을 때, 이 수가 적혀있는 숫자 카드를
상근이가 몇 개 가지고 있는지 구하는 프로그램을 작성
*/
#include <iostream>
using namespace std;

int N,M;
int num_count[20000010]={0,};//숫자가 들어가는 부분

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    for(int i =0,temp ;i<N; i++){
        cin >> temp;
        num_count[temp+10000000]++;
    }
    cin >> M; 
    for(int i=0,temp; i<M ;i++){
        cin >> temp;
        cout << num_count[temp+10000000] << " ";
    }
    return 0;
}
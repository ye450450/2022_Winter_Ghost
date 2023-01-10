/*2023.01.10
<1로 만들기>
사용할 수 있는 연산
1. x가 3으로 나누어 떨어지면, 3으로 나눈다.
2. X가 2로 나누어 떨어지면, 2로 나눈다.
3. 1을 뺀다.
이 연산들을 활용해 1을 마늗ㄹ려고 한다.
연산을 사용하는 횟수의 최솟값을 출력
*/
#include <iostream>
using namespace std;

int DP[1000001];
int num;//입력받는 값
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> num;
    DP[2]=DP[3]=1;
    for(int i=4;i<=num;i++){
        DP[i]= DP[i-1]+1;
        if(i%3==0) 
            DP[i] = min(DP[i/3]+1,DP[i]);
        if(i%2==0) 
            DP[i] = min(DP[i/2]+1,DP[i]);
    }
    cout<<DP[num]<<endl;
}
/*2023.01.10
피보나치 함수로 값을 계산해라(bottom up 형식이다.)
long long을 해야 큰값을 출력할 수 있다.
더 큰값은 unsinged long long을 사용
*/
#include <iostream>
using namespace std;

int n; //입력받는 수를 저장
long long DP[91];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    DP[0]=0;
    DP[1]=1;

    for(int i=2;i<=n;i++ ){
        DP[i]=DP[i-1]+DP[i-2];
    }
    cout << DP[n] <<endl;
}
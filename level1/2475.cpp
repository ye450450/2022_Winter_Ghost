/*2023.01.17
검증수
6자리 고유번호를 매긴다.
검증수는 고유번호 처음 5자리에 들어가는 5개의 숫자를 각각 제고한 수의 합을 10으로 나눈 나머지
*/
#include <iostream>
using namespace std;
int main(){
    ios :: sync_with_stdio(false); cin.tie(0);
    int sum=0;//제곱한 수들의 합을 저장
    for(int i =0,a ; i<5 ;i ++){
        cin >> a;
        sum+=a*a;
    }
    cout << sum%10;//10으로 나눈 나머지를 출력
}

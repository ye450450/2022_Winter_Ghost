/*2023.01.09 A->B 문제
곱하기 1와 1을  수의 가장 오른쪽에 추가하는 연산만 가능
*/
#include <iostream>
using namespace std;

int a,b;//A와 B에 해당하는 값을 저장하는 변수

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int count;//연산의 최솟값을 저장하는 변수
    
    cin >> a >> b;
    while(b>a){
        if(b%2==0){
            b/=2; //2로 나누어지면 2로 나눈다.
            count++;
        }
        else{
            if((b-1)%10!=0) break;//1을 가장 오른쪽에 더해서 만들 수 없다.
            b= (b-1)/10;//나누어지지 않으면 1을 빼고 2로 나눈다.
            count++;
        }
    }//b가 a보다 작아지거나 같아질 때까지 반복한다.
    if(b==a) cout << count+1;
    else cout << -1;
}
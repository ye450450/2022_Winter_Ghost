/*2032.01.21
<최대공약수와 최소공배수>
두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성
*/
#include <iostream>
using namespace std;

int N, M ; // 두 수를 입력받음

void print_maxdivisor(int num1, int num2){
    int range =min(num1,num2);//더 작은 값까지 비교하면 된다.
    int result=0;
    for(int i=1 ; i<=range ; i++){
        if(num1%i==0 && num2%i==0) result = i;
    }
    cout << result << '\n';
}//최대공약수를 출력하는 함수

void print_minmultiple(int num1,int num2){
    int result1 = num1;
    int result2 = num2;
    
    while(true){
        if(result1==result2) break;
        if(result1 > result2) result2+=num2;
        else result1+=num1;
    }
    cout << result1;
}//최소공배수를 출력하는 함수 

int main(){
    ios:: sync_with_stdio(false); cin.tie(0);

    cin >> N >> M;

    print_maxdivisor(N,M);
    print_minmultiple(N,M);

    return 0;
}
/*2023.01.19
소수 구하기
M이상 N이하의 소수를 모두 출력하는 프로그램을 작성
*/
#include <iostream>
using namespace std;

int M,N; 

bool prime_check(int num){
    int temp =2;
    while( temp < num ){
        if(num % temp==0) return false;
        temp++;
    }//하나씩 증가하면서 나누어지는지를 확인한다.
    return true;
}

int main(){
    ios :: sync_with_stdio(false); cin.tie(0);

    cin >> M >> N;

    long long num[N+1]={0,}; //배열을 선언

    for(int i=2; i<=N ;i++){
        num[i]=i;
    }//초기화

    for(int i=2 ; i<=N ; i++){
       if(num[i]==0) continue;//이미 삭제되었다면 넘어간다.

       for(int j=i*2; j <=N ;j+=i){
            num[j]=0;
       }

    }//특정배수들을 삭제해준다.

    for(int i=M; i<=N ;i++){
        if(num[i]!=0) cout << num[i]<<'\n';
    }//출력

    return 0;

}
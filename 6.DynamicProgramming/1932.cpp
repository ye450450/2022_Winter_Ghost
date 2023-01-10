/* 2023.01.10
<정수 삼각형>
정수 삼각형의 맨 위층에서부터 아래에 있는 수를 하나 선택하여
아래층으로 내려올 때, 이제까지 선택된 수의 합이 최대가 되는 경로를 구하는 프로그램을 작성
삼각형의 크기는 1이상 500이하
*/
#include <iostream>
using namespace std;

int N; //삼각형 사이즈를 입력받음
int n[500*501/2+1]; //입력받을 수 있는 삼각형의 수
int DP[500*501/2+1]; //최대값을 저장하는 변수

int function(int order, int row){
    if(order+row > (N-1)*N/2 ) return (max(n[order+row],n[order+row+1]) + n[order]); //밑에 있는 숫자가 마지막열인 경우 비교해서 최대값을 준다.

    if(DP[order+row]==0)    DP[order+row]= function(order+row, row+1);//왼쪽 대각선이 계산되지 않은 경우
    if(DP[order+row+1]==0)  DP[order+row+1]= function(order+row+1, row+1); //오른쪽 대각선이 계산되지 않은 경우

    DP[order]= max(DP[order+row],DP[order+row+1])+n[order];
    
    return DP[order];
}//최대값을 저장해주는 함수

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for(int i =1 ; i<= (N*(N+1))/2 ; i++){
        cin >> n[i];
    }
    cout << function(1,1);

}
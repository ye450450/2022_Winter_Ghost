#include <iostream>
using namespace std; 

int kg;//상근이가 배달한는 섵탕 무게
int DP[50001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> kg;
    DP[3]=DP[5]=1;//3KG과 5KG 봉지만 존재

    for(int i =6;i<=kg;i++){
        if(DP[i-3]) DP[i]=DP[i-3]+1; //3kg봉지로 이어서 표현가능하면 1을 더해 추가
        if(DP[i-5]) DP[i]=DP[i]? min(DP[i],DP[i-5]+1) : DP[i-5]+1; //5kg봉지로 이어서 표현 가능하면 5를 더해 추가, 만약 3으로도 표현이 가능하면 비교하여서 더 적은 값을 선택
    }
    if(DP[kg]!=0) cout<<DP[kg];
    else cout << -1;
}
/*2023.01.10
피보나치 함수
0과 1이 몇번 출력되는지를 구하는 프로그램
*/
#include<iostream>
using namespace std;

int T;//case수를 입력받음

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> T;
    
    pair <int,int> count[41];//f(0)을 호출하는 수, f(1)을 호출하는 수를 저장

    count[0].first=1; count[0].second=0;
    count[1].first=0; count[1].second=1;

    for(int i =0;i<T;i++){
        int input;
        cin >> input;
        for(int i = 2; i <=input;i++){
            if(count[i].first!=0 && count[i].second!=0) continue;
            count[i].first = count[i-1].first + count[i-2].first;
            count[i].second = count[i-1].second + count[i-2].second; 
        }
        cout<< count[input].first <<" "<<count[input].second<<endl;
    }

}
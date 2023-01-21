/*2023.01.21
<소수 찾기>
주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성
첫 줄에 수의 개수 N이 주어진다.
*/
#include <iostream>
#include <vector>
using namespace std;

int N;
int check[1010]={0,};//소수인 수들을 저장
vector <int> input_num;//숫자들을 저장

void prime(int num){
    for(int i=2; i<=num; i++){
        check[i]=i;
    }//초기화
    for(int i=2; i<=num; i++){
        if(check[i]==0) continue;
        for(int j=i*2; j<=num ;j+=i){
            check[j]=0;
        }
    }//배수들을 제거
}//가장 큰 수보다 작은 수들의 소수를 저장

bool prime_check(int num){
    if(check[num]==0) return false;
    else return true;
}//소수인지를 출력해주는 함수

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> N;

    int count=0;
    int max_num=0;
    for(int i=0,temp; i<N ; i++){
        cin  >>  temp;
        max_num= max(temp, max_num);//큰 수를 저장
        input_num.push_back(temp);
    }
    prime(max_num);//가장 큰수를 기준으로 아래의 숫자들의 소수를 저장
    
    for(int i: input_num){
        if(prime_check(i)) count++;
    }

    cout << count;

    return 0;
}
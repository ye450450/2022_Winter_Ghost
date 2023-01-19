/*2023.01.19
<랜선 자르기>
N개의 랜선을 만들어야하는데 너무 바빠서 영식이에게 도움을 청했다.
오영식은 자체적으로 K개의 랜선을 가지고 있다. 그런데 k개의 랜선은 길이가 제각각이다.
최대 랜선의 길이를 구하는 프로그램을 작성
*/
#include <iostream>
#include <vector>
using namespace std;

int N, K ;//K-이미 가지고 있는 랜선의 개수, N - 필요한 랜선의 개수
int line[1000001];//라인에 대한 정보들을 저장

void max_line(int max_line){
    long long right = max_line;
    long long left = 1;
    long long result =0;
    
    while(right >= left){
        long long mid = (right+left)/2;

        long long count=0;//랜선의 개수

        for(int i=0 ; i<N ; i++){
            count += line[i]/mid;
        }

        if(count >= N){
            left = mid+1;
            result = max(result, mid);
        }//필요한 개수보다 크거나 같을 경우
        else
            right = mid-1;
    }
    cout<<result;
}//최대 길이를 계산하는 함수

int main(){
    ios :: sync_with_stdio(false); cin.tie(0);

    cin >> K >> N;

    int max=0;

    for(int i =0 ; i<K ;i++){
        int input;
        cin >> input;
        line[i] = input;
        if(max<input) max=input;
    }

    max_line(max);

    return 0;
}
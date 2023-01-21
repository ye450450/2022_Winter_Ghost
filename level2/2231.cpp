/*2023.01.21
<분해합>
어떤 자연수 N이 있을 때, 그 자연수 N의 분해합은 N과 N을 이루는 각 자리수의 합을 의미
어떤 자연수 M의 분해합은 N인 경우, M을 N의 생성자라 한다.
예시, 245의 분해합은 245+2+4+5
가장 작은 생성자를 구해낸는 프로그램을 작성
*/
#include <iostream>
#include <stack>
using namespace std;

int N;
stack <int> my_stack;//생성자들을 저장
int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> N;
    int num = N;//생성자를 저장하는 변수
    int sum = 0;//분해합을 저장하는 변수
    do{
        sum=0; 
        num--;
        int temp = num;
        sum+=temp;
        while(temp>0){
            sum+=temp%10;//한자리씩 저장
            if(sum>N) break;
            temp/=10;//한자리씩 줄인다.
        }
        if(sum==N) my_stack.push(num);
    }while(num>N/10);//숫자를 하나씩 감소시키면서 확인한다. 만약 분해합이 더 작아지면 종료한다.
    if(!my_stack.empty()) cout << my_stack.top(); 
    else cout << 0;
}
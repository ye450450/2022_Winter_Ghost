/*
2023.01.13
*/
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N;//주어지는 숫자 개수
priority_queue <int> card;//카드뭉치들을 넣어줌

void cal_compare(){
    int sum=0;
    while(card.size()>1){
        int front_sum=0;
    
        front_sum+= -card.top();
        card.pop();
        front_sum+= -card.top();
        card.pop();
        //cout << "front_sum : "<<front_sum<<'\n';
        sum+=front_sum;
        card.push(-front_sum);
    }
    cout << sum;
}

int main(){
    ios:: sync_with_stdio(false); cin.tie(0);
    
    cin >> N;
    int card_input;
    while(N--){
        cin >> card_input;
        card.push(-card_input);
    }
    cal_compare();
}
/*
2023.01.11
*/
#include <iostream>
#include <queue>
using namespace std;

int main(){
    priority_queue <int> que;//큰 수를 맨 앞에 저장하는 priority_queue를 저장
    priority_queue <int, vector <int>, greater <int> > prqueue; // 작은 수를 맨 앞에 저장하는 prioroty_queue를 저장

    que.push(20);
    que.push(40);
    que.push(50);
    que.push(60);

    while(!que.empty()){
        cout << que.top() << "  ";
        
        que.pop();

    }
    cout << '\n';

 }
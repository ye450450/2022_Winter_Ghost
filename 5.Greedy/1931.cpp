#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int count;
    cin >> count;
    pair <int,int> room [100001];
    for(int i =0; i<count ;i++){
        cin >> room[i].first >> room[i].second;
    }
    for(int i =0; i<count ;i++){
        cout << room[i].first <<" " << room[i].second;
    }

}
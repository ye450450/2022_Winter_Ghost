/*2023.01.17
별찍기1
*/
#include<iostream>
using namespace std;
int N;
int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    cin >>N;
    int count=1;
    for(int i =0 ;i<N;i++){
        for(int j=0; j <count; j++){
            cout << "*";
        }
        cout << '\n';
        count++;
    }

    return 0;
}
/*2023.01.17
별찍기 -2
*/
#include <iostream>
using namespace std;
int N;
int main(){
    ios:: sync_with_stdio(false) ; cin.tie(0);

    cin >> N;
    int count=1;
    for(int i=0; i<N; i++){
        for(int k=count;k<N;k++)
            cout << " ";
        for(int j=0;j<count;j++)
            cout << "*";
        count++;
        cout << '\n';
    }
    return 0;
}
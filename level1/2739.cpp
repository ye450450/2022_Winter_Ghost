/*2023.01.24
구구단
N을 입력받고 구구단을 출력하는 프로그램 작성
*/
#include <iostream>
using namespace std;

int N;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> N;

    for(int i=1; i<=9; i++){
        cout << N << " * " << i << " = " << N*i<<'\n';
    }

    return 0;
}

/*2023.01.17
<문자열 반복>
문자열 S를 입력받은 후에, 각 문자를 R번 반복해 새 문자열 P를 만든 후 출력하는 프로그램을 작성
2
3 ABC
5 /HTP
->
AAABBBCCC
/////HHHHHTTTTTPPPPP
*/
#include <iostream>
using namespace std;

int T;//테스트 케이스 개수

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> T;
    while(T--){
        int R;//반복횟수를 저장
        string S;//문자열을 저장
        cin >> R >> S;
        for(int i=0 ; i<S.length();i++){
            for(int j=0; j<R ;j++)
                cout << S[i];
        }
        cout << '\n';
    }
}
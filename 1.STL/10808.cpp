/*2023.01.14
<알파벳 개수>
알파벳 소문자로만 이루어진 단어 S가 주어진다.
각 알파벳이 단어에 몇 개가 포함되어 있는지 구하는 프로그램을 작성
*/
#include <iostream>
using namespace std;

string S;//입력받는 단어
int count_alpha[26];
void cal(string input){
    for(int i=0 ;i<input.length();i++)
        count_alpha[input[i]-'a']++;
}

int main(){
    ios:: sync_with_stdio(false); cin.tie(0);

    cin >> S;

    cal(S);
    for(int i : count_alpha)
        cout << i << " ";
}
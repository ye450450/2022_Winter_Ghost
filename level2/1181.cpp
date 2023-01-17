/*2023.01.18
<단어정렬>
알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성
1. 길이가 짧은 것부터
2. 길이가 같으면 사전 순으로
*/
#include <iostream>
#include <set>
#define SIZE 51
using namespace std;

int N;//단어의 개수
set <string> word[SIZE];//길이에 따라 다르게 저장(중복을 허용하지 않음)

int main(){
    ios :: sync_with_stdio(false); cin.tie(0);

    cin >> N;
    while(N--){
        string input;
        cin >> input;
        word[input.length()].insert(input);
    }

    for(int i =0 ; i<SIZE ; i++){
        if(!word[i].empty()){
            for(string s : word[i])
                cout << s<<'\n';
            }
        }//비어있지 않는 경우

    return 0;
}
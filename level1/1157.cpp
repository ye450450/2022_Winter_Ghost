/*2023.01.06
<단어 공부>
알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이
무엇인지 알아내는 프로그램을 작성
대문자와 소문자를 구분하지 않는다.
가장 많이 사용된 대문자를 출력
가장 많이 사용된 알파벳이 여러 개 존재하는 경우 ?를 출력
*/

#include <iostream>
using namespace std;

int char_count[27]={0};
string input;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> input;

    for(int i=0; i<input.size();i++){
        int result = input.at(i)-'A';
        if(result > 25) result = result - 32;
        char_count[result]++;
    }
    int max=0;//가장 많은 수를 저장
    int max_index=0;//가장 많이 나온 수의 index
    for(int i=0;i<26;i++){
        if(char_count[i]>max){
            max=char_count[i];
            max_index=i;
        } 
    }
    for(int i=0;i<26;i++){
        if(i!=max_index && char_count[i]==max){
            cout <<"?";
            return 0;
        }
    }//가장 많은 알파벳이 여러개인 경우
    cout << (char) ('A'+ max_index);
    return 0;
}
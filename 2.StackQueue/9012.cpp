/* 2023.01.12
<괄호문제>
괄호 문자열은 두 개의 괄호 기호인 "("와")"가 존재
올바른 괄호 문자열을 vps라고 한다.
한 쌍의 괄호 기호로 된 "()" 문자열을 기본 VPS라고 한다.
VPS인지 아닌지를 판단해서 그 결과를 yes와 no로 나타내어야한다.
괄호 문자열의 길이는 2이상 50이하이다.
*/
#include <iostream>
#include <stack>
#include <string>
#include <cstring>
using namespace std;

int T; //테스트 케이스 개수이다.
stack <char> my_stack;//괄호들을 저장하는 스택

int main(){
    cin >> T;
    while(T--){
        while(!my_stack.empty())
            my_stack.pop();
        string s;//괄호들을 입력받아저장
        bool no_check=false;//잘못되었는지를 저장
        cin >> s;
        char c_arr [s.length()];//괄호들을 하나씩 저장
        for(int i =0 ;i <s.length();i++) c_arr[i]=s.at(i);
        
        for(char c : c_arr){
            if(c=='(') my_stack.push(c);//여는 괄호이면 stack에 넣는다.
            else if (c==')'){
                if(my_stack.size()==0) {
                    cout << "NO" << '\n';
                    no_check=true;
                    break;
                }
                else if(my_stack.top()=='(')
                    my_stack.pop();
            }//닫는 괄호인 경우
        }
        if(no_check) continue;
        else if(!no_check && my_stack.empty()) cout << "YES" << '\n';
        else if(!my_stack.empty()) cout << "NO" << '\n';
    }
}

/*2023.01.16
<단어의 개수>
영어 대소문자와 공백으로 이루어진 문자열이 주어진다.
이 문자열에는 몇 개의 단어가 있을까?
이를 구하는 프로그램을 작성하시오.
단, 한 단어가 여러 번 등장하면 등장한 횟수만큼 모두 세어야 한다.
*/
#include <iostream>
#include <string>
using namespace std;

int main(){
    string input_s;

    getline(cin, input_s);//문장을 입력받음

    int count=0;
    for(int i=0;i <input_s.length();i++){
        if((i==0 && input_s[i]==' ')|| (i==input_s.length()-1 && input_s[i]==' ')) 
            continue;//앞이나 뒤가 공백인 경우
        if(input_s[i]==' ') count++;
    }
    if(input_s.length()==0 || (input_s.length()==1&&input_s[0]==' ')) cout << count;//입력이 없거나 공백만 입력되는 경우
    else  cout << count+1;//마지막 단어까지 추가
}
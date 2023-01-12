/*2023.01.12
<AC>
새로운 언어 AC를 만듬
AC는 정수 배열에 연산을 하기 위해 만든 언어
R(뒤집기) - 정수 배열의 순서를 뒤집는다.
D(버리기) - 첫 번째 수를 버린다. 비어있는 경우 에러 발생
T - 테스트 케이스 , 수행할 함수 P, 배열에 들어있는 수 N, 배열에 들어가는 정수
(T<=100) , (1<P<=100,000) , (0<= N <= 100,000), (1<=X <=100)
전체 케이스의 P의 길이의 합과 N의 합은 70만을 넘지 않는다.
*/
/*
시간을 줄이려면 나올때마다 빼주거나 순서를 바꿔주거나 하는 것이 아니라 나중에 한 번에 생각해서 해주는 것이 좋다.
*/
#include <iostream>
#include <string>
#include <deque>
using namespace std;

int T ; //테스트 케이스 수
string funct ;//수행할 함수
int N; //배열에 들어있는 수
string input_num;//배열에 들어가는 정수

void func_result(string f, int n, string num){
    //입력받는 수열을 slicing해서 deque에 넣어준다.
    deque <string> dq;
    string s="";
    int count_R=0;//REVERSE한 횟수를 저장
    int count_FD=0,count_BD=0;//앞에서 제거하는 수와 뒤에서 제거하는 수를 저장ㄴ
    
    for(int i =1 ; i<num.length();i++){
        if(num[i]==','|| num[i]==']') {
            if(s!="") dq.push_back(s);
            s="";
            continue;
        }
        s+=num[i];//숫자만을 저장
    }
    
    for(int i =0 ;i<f.length();i++){
        if(f.at(i)=='R'){
           count_R++;
        }//R을 입력받으면 순서를 바꾸어준다.
        else if(f.at(i)=='D'){
            if(count_R%2==0) count_FD++;
            else count_BD++;
        }
    }
    if(count_FD!=0){
        while(count_FD--){
            if(dq.empty()) {
                    cout << "error";
                    return;
            }//비어있다면 error를 출력
            dq.pop_front();
        }
    }
    if(count_BD!=0){
        while(count_BD--){
            if(dq.empty()) {
                cout << "error";
                return;
            }//비어있다면 error를 출력
            dq.pop_back();
        }
    }
    
    cout << "[";
    while(!dq.empty()){
        if(count_R%2==0) cout << dq.front();
        else cout << dq.back();
        
        if(dq.size()!=1) cout<<",";

        if(count_R%2==0) dq.pop_front();
        else dq.pop_back();
    }
    cout << "]";
}

int main(){
    ios :: sync_with_stdio(false); cin.tie(0);
    cin >> T;

    while(T--){
        cin >> funct;
        cin >> N;
        cin >> input_num;

        func_result(funct, N, input_num);
        cout<<'\n';
    }
    return 0;
}
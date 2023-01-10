/* 2023.01.10
스택 수열
1부터 n까지의 수를 스택에 넣었다가 뽑아서 하나의 수열을 만든다.
스택에 push하는 순서는 오름차순을 지킨다.
수열이 주어졌을 때, 스택을 이용해 그 수열을 만들 수 있는지 없는지
있다면 어떤 순서로 push와 pop연산을 수행해야하는지를 알아낼 수 있다.
이를 계산하는 프로그램을 작성
*/
//endl보다는 '\n'을 사용하여 시간을 단축해라
#include <iostream>
#include <stack>
#include <deque>
using namespace std;

int N;//수열의 수를 저장하는 변수
stack <int> my_stack;//입력받는 수를 저장하는 stack
deque <string> represent;//push연산은 +로, pop연산은 -로 저장하는 deque

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    
    int temp;//입력받는 수
    int max =0;//현재까지 입력받은 값의 최댓값을 저장
    while(N--){
        cin >> temp;
        if(my_stack.empty() || temp >= my_stack.top()){
            if(temp> max){
                for(int i = max+1;i<=temp ; i++){
                    my_stack.push(i);
                    represent.push_back("+");
                }//본인보다 작은 수와 stack에 있는 가장 큰 수 사이만큼은 push
                max = temp;
            }
            my_stack.pop(); //본인을 pop해줌
            represent.push_back("-");
        }//stack에 있는 가장 큰수와 같으면 pop
        else {
            represent.push_front("NO");
        }//stack에 있는 가장 큰 수보다 작으면 연산 불가
    }

    if(represent.front()=="NO"){
        cout << "NO" <<'\n';
        return 0;
    }

    while(!represent.empty()){
        cout<<represent.front()<<'\n';
        represent.pop_front();
    }
}
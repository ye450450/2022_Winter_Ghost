/*2023.01.10
정수를 저장하는 덱을 구현
입력으로 주어지는 명령을 처리하는 프로그램 
*/

#include <iostream>
#include <deque>
using namespace std;

int N; //주어지는 명령의 수를 저장하는 변수
string command[10001]; //주어주는 명령을 저장하는 변수
deque <int> mydeque;

int main(){
    ios:: sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for(int i =0 ; i<N ; i++){
        cin >> command[i];
        if(command[i]=="push_back" || command[i]=="push_front"){
            int temp;
            cin >> temp;
            if(command[i]=="push_back") mydeque.push_back(temp);
            else mydeque.push_front(temp);
        }
        else if(command[i]=="empty"){
            if(mydeque.empty()) cout << 1<<endl;
            else cout << 0 << endl;
        }
        else if(command[i]=="size")
            cout << mydeque.size() << endl;
        else{
            if(mydeque.empty()){
                cout << -1<<endl;
                continue;
            }
            else if(command[i]=="pop_front"){
                cout << mydeque.front() <<endl;
                mydeque.pop_front();
            }
            else if(command[i]=="pop_back"){
                cout << mydeque.back() <<endl;
                mydeque.pop_back();
            }
            else if(command[i]=="front")
                cout << mydeque.front() <<endl;
            else if(command[i]=="back")
                cout << mydeque.back() <<endl;
        }
    }
}
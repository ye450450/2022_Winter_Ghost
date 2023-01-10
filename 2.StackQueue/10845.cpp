/*2023.01.10
정수를 저장하는 큐를 구현하고, 주어지는 명령을 처리하는 프로그램 작성
*/
#include <iostream>
#include <queue>
using namespace std;

string command[10001];
int command_num;
queue <int> my_queue;

int main(){
    ios::sync_with_stdio;
    cin.tie(0);
    
    cin >> command_num;

    for(int i =0 ;i<command_num;i++){
        cin >> command[i];
        if(command[i]=="push"){
            int temp;
            cin>>temp;
            my_queue.push(temp);
        }
        else if(command[i]=="empty"){
            if(my_queue.empty()) cout << 1 <<endl;
            else cout << 0 <<endl;
        }
        else if(command[i]=="size")
            cout<< my_queue.size() <<endl;
        else{
            if(my_queue.empty()){
                cout << -1 <<endl;
                continue;
            }
            else if(command[i]=="front")
                cout << my_queue.front()<<endl;
            else if(command[i]=="back")
                cout<< my_queue.back()<<endl;
            else if(command[i]=="pop"){
                cout<< my_queue.front()<<endl;
                my_queue.pop();
            }
        }
    }
}
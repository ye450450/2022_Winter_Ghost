/*
2023.01.13
*/
#include <iostream>
#include <deque>
using namespace std;

int N=0; //입력받는 숫자 개수
deque <int> input_num;
bool pos_check= false;

void max_sum(){
    int p_sum=0;//음수만나기 전값을 저장
    int n_sum=0;//음수를 만난 후 값을 저장
    int final_sum =0;//
    if(!pos_check){
        int max=-1000;
            for(int i=0 ;i<N;i++)
                if(max < input_num[i]) max=input_num[i];
        cout << max;
        return;
    }//모두 음수인 경우

    for(int i=0 ;i<N;i++){
        int front= input_num.front();
        if(front>=0) {
            n_sum+=front;
            if(n_sum > p_sum) p_sum=0;
            pos_check=true;
        }
        else{
            if(n_sum>p_sum)
                p_sum = n_sum;
            n_sum+=front;
        }//음수를 만나면
        if(n_sum<0) n_sum=0;//합이 음수가 되면 초기화
        input_num.pop_front();
    }
    if(p_sum > n_sum) cout << p_sum;
    else cout << n_sum; 
}

int main(){
    ios :: sync_with_stdio(false); cin.tie(0);

    cin >> N;

    for(int i=0 ; i<N ;i++){
        int input;
        cin >> input;
        if(!pos_check && input>0) pos_check=true;
        input_num.push_back(input);
    }
    max_sum();
    return 0;
}
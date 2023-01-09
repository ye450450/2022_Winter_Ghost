/*2023.01.09
A배열과 B배열을 입력받아 작은 곱 만들어 출력하기
*/
#include <iostream>
#include <algorithm>
#include <vector>
#define NUM 2
using namespace std;


int input_num;//입력하는 수 N
int result;//결과값을 저장하는 변수
vector <int> array_A;
vector <int> array_B;

bool compare(int a, int b){
    return a> b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> input_num;

    for(int i =0; i<input_num;i++){
        int num;
        cin >>num;
        array_A.push_back(num);
    }//A를 입력받음
    
    sort(array_A.begin(), array_A.end());//A를 입력받고 정렬

    for(int i =0; i<input_num;i++){
        int num;
        cin >>num;
        array_B.push_back(num);
    }//B를 입력받으면서 A를 재배열

    sort(array_B.begin(), array_B.end(),compare);//B를 입력받고 내림차순으로 정렬
    
    for(int i =0 ;i<input_num;i++)
        result += array_A[i]*array_B[i];
    cout << result;
}
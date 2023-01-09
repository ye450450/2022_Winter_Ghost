#include <iostream>
#include <algorithm>
#include <vector>
#define NUM 2
using namespace std;


int input_num;//입력하는 수 N
vector <int> array_A;
vector <int> array_B;

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

    // for(int i=0 ;i<array2.size();i++){
    //     for( int temp : array2[i]){
    //         cout << temp ;
    //     }
    //     cout<<endl;
    // }
}
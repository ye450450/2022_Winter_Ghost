/*2023.01.14
N개의 정수가 주어져 있을 때,
이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성
*/
#include <iostream>
#include <algorithm>
using namespace std;

int N;//A에 들어가는정수 개수
int M;//있는지 입력받는 정수 개수

void search(int arr[],int left, int right, int num){
    bool find_check= false;
    while(left<=right){
        int mid = (left+right)/2;
        if(arr[mid]==num) {
            find_check= true;
            break;
        }
        else if(arr[mid]>num)  right=mid-1;
        else left= mid+1;
    }
    if(find_check) cout << "1" <<'\n';
    else cout<< "0"<< '\n'; 
}

int main(){
    ios :: sync_with_stdio(false); cin.tie(0);

    cin >> N;
    int A [N];//정수들을 저장하는 배열

    for(int i=0,a;i<N;i++){
        cin >> a;
        A[i]=a;
    }
    sort(A,A+N);//binary search를 위해 정렬
    
    cin >> M;
    for(int i=0, a;i<M ;i++){
        cin >> a;
        search(A, 0 , N, a);
    }
    
}
/*2023.01.24
음계
다장조는 cdegfabC 총 8개 음으로 이루어져있다.
8개를 숫자로 바꾸면 1에서부터 8이다.
차례대로 연주하면 ascending, 8부터 1은 descending, 둘 다 아니라면 mixed
연주한 순서가 어떤지를 판별하는 프로그램을 작성
*/
#include <iostream>
using namespace std;

int check[1];//0은 descending, 1은 ascending, 2은 mixed이다.

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    for(int i=8,temp; i>0 ;i--){
        cin >> temp;
        if(i==temp){
            if(i==8)    check[0]=0;
            else if(check[0]==1){
                check[0]=2;
                break;
            }
            else continue; 
        }//descending
        else if(9-i==temp) {
            if(i==8) check[0]=1;
            else if(check[0]==0){
                check[0]=2;
                break;
            }
            else continue;
        }//ascending
        else {
            check[0]=2;
            break;
        }//mixed 상태
    }
    if(check[0]==0) cout << "descending";
    else if(check[0]==1) cout << "ascending";
    else cout << "mixed";
    return 0;
}
/*2023.01.18
<영화감독 숌>
666은 종말을 나타낸느 숫자
영화제목을 6이 적어도 3개이상 연속으로 들어가는 수
666 -> 1666 -> 2666 -> 3666
*/
#include <iostream>
using namespace std;

int N;
int num=666;//시작 숫자
int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> N;
    int count=0;//몇 번째인지를 저장
    
    while(true){
        int temp=num;
        while(temp>10){
            if(temp%1000==666) {
                count++;
                break;//666이 연속으로 나오는 경우
            }   
            temp/=10;
        }//맨뒤가 아니라 중간에도 나올 수 있다.
        if(count==N){
            cout << num;
            break;
        } 
        num++;
    }//666을 만날 때까지 반복한다.

    return 0;

}

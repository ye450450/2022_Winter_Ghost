/*2023.01.14
별찍기
출력 예제를 보고 별 찍는 규칙을 유추하여 별을 찍기
3
********
* * * *
**  **
*   *
****
* *
**
*
4
****************
* * * * * * * *
**  **  **  **
*   *   *   *
****    ****
* *     * *
**      **
*       *
********
* * * *
**  **
*   *
****
* *
**
*
*/
#include <iostream>
#include <cmath>
using namespace std;

int N;//별의 개수를 입력받음
int star [1024][1024];//별이 들어가는 위치를 저장

void check_star(int num, int y, int x){
    if(num<0) return;
    star[y][x] = 1;
    
    check_star(num-1, y,x); 
    check_star(num-1,y,x+pow(2,num-1));
    check_star(num-1,y+pow(2,num-1),x);

}//별그려지는 패턴이 그 전것들을 그리고 아래에 그 전 것을 그리는 패턴이다.
void draw_star(){
    for(int i=0; i< pow(2,N);i++){
        for(int j=0; j< pow(2,N)-i;j++){
            if(star[i][j]==1 ) cout << "*";
            else cout << " ";
        }
        cout << '\n';
    }
        
}

int main(){
    ios :: sync_with_stdio(false); cin.tie(0);

    cin >> N;

    check_star(N,0,0);
    draw_star();
    return 0;
}

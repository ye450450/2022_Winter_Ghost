/*2023.01.18
<직사각형에서 탈출>
한수는 지금 (x,y)에 있다.
직사각형은 각 변이 좌표축에 평행, 왼쪽 아래 꼭짓점은 (0,0)
오른쪽 위 꼭지점은 (w,h)에 있다. 직사각형의 경계선까지 가는 거리의 최솟값을 구하는 프로그램을 구하라
*/
#include <iostream>
using namespace std;

int w,h,x,y;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> x >> y >> w >> h;

    int result_x = min(x,w-x);
    int result_y = min(y,h-y);
    cout << min(result_x,result_y);
}
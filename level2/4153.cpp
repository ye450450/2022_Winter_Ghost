/*2032.01.22
<직각삼각형>
과거 이집트인들은 각 변들의 길이로 직각 삼각형인지를 알아냈다.
주어진 세변의 길이로 삼각형이 직각인지 아닌지를 구분
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int>  line;

int main(){
    ios :: sync_with_stdio(false); cin.tie(0);
    while(true){
        int a,b,c;//세변을 저장하는 변수
        cin >> a; line.push_back(a);
        cin >> b; line.push_back(b);
        cin >> c; line.push_back(c);

        if(a==0 && b==0 && c==0) break;

        sort(line.begin(),line.end());//정렬

        if(line[0]*line[0]+line[1]*line[1] == line[2]*line[2]) cout << "right" << '\n';
        else cout << "wrong" << '\n';
        
        line.clear();
    }//0 0 0이 입력될 때까지 반복
    return 0;
}
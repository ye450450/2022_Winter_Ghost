/*2023.01.14
<바이러스>
신종 바이러스인 웜 바이러스는 네트워크를 통해 전파
한 컴퓨터가 웜 바이러스에 걸리면 그 컴퓨터와 네트워크 상에서
연결되어 있는 모든 컴퓨터는 웜 바이러스에 걸리게 된다.
1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 출력하는 프로그램을 작성
*/
#include <iostream>
#include <vector>
using namespace std;

int computer;//컴퓨터 수
int network;//연결되어있는 네트워크 수
vector <int> graph[101];//연결되는 정보들을 저장
int visit_check[101];
int count_virus;//감염된 컴퓨터 수를 저장

void path(int start){
    visit_check[start]=1;
    count_virus++;

    for(int i=0; i<graph[start].size();i++){
        int next_computer=graph[start][i];
        if(visit_check[next_computer]==0) path(next_computer);
    }

}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> computer >> network;

    for(int i =0,a,b ; i <network ;i++){
        cin >> a >> b ;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    path(1);
    cout << count_virus-1;
    return 0;

}
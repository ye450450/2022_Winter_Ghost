/*
2023.01.11
<네트워크 복구>
N개의 컴퓨터로 구성된 네트워크가 존재
회선을 통해 연결
보안 시스템을 위헤 한대의 슈퍼컴퓨터에만 보안 시스템 설치
네트워크 복구 조건
1. 서로 다른 두 컴퓨터 간에 통신이 가능하도록 최소 개수의 회선만을 복구
2. 슈퍼컴퓨터가 다른 컴퓨터들과 통신하는데 걸리는 최소 시간이 원래의 네트워크에서 통신하는데 거리는 시간보다 커져서는 안된다.
N : 컴퓨터 수, M: 회선수 , A ,B C :A컴퓨터와 B컴퓨터간의 통신 시간 C
1번은 보안 시스템을 설치할 슈퍼컴퓨터
출력 : 복귀한 회선 개수 와 회선
*/
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <climits>
#define INF INT_MAX
using namespace std;

int N, M; //N : 컴퓨터 수, M: 회선수
vector <pair<int,int>> graph[1010]; //컴퓨터 회선에 대한 정보를 저장
long long sec[1010];//시작컴퓨터로부터의 본인의 컴퓨터까지의 통신시간을 저장
priority_queue <pair<int,int>> pq;//본인의 짧은 통신시간과 컴퓨터번호를 저장
map <int,int> line; //최소한의 필요한 회선들을 저장 (제거하기가 편한 map사용)

void dijkstra(int start){
    for(int i=1 ;i <=N;i++)
        sec[i]=INF;//통신시간을 초기화
    sec[start]=0;//시작점을 넣어줌
    pq.push({0,start});

    while(!pq.empty()){
        int c_computer = pq.top().second;//현재 컴퓨터번호
        int c_second = pq.top().first*-1;//현재 컴퓨터의 통신시간
        pq.pop();

        for(int i=0;i<graph[c_computer].size();i++){
            int n_computer = graph[c_computer][i].first; //현재 컴퓨터의 인접한 컴퓨터 번호
            int n_second = graph[c_computer][i].second; //인접한 컴퓨터와의 통신시간

            if(sec[n_computer]> c_second+n_second){
                if( sec[n_computer]!=INF )
                    line.erase(n_computer);
                sec[n_computer] = c_second+n_second;//인접한 컴퓨터까지의 통신시간이 짧은 경우 바꾸어준다.
                line.insert({n_computer,c_computer});
                pq.push({sec[n_computer]*-1,n_computer});
            }
        }
    }
    cout << line.size() <<'\n';
    for(auto const &pair : line)
        cout << pair.first <<" "<< pair.second <<'\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> N >> M;

    for(int i =0, a, b, c; i<M ;i++){
        cin >> a >> b >> c; //A ,B C :A컴퓨터와 B컴퓨터간의 통신 시간 C
        graph[a].push_back({b,c});//회선에 대한 정보 입력
        graph[b].push_back({a,c});//회선에 대한 정보 입력(양방향)
    }
    dijkstra(1);//슈퍼컴퓨터를 기준으로 시작

    return 0;
}

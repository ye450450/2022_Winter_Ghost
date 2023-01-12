/*2023.01.12
<타임머신>
N개의 도시가 존재
한 도시에서 출발하여 다른 도시에 도착하는 버스 M개
A는 시작도시, B는 도착도시, C는 버스를 타고 이동하는데 걸리는 시간
C는 양수가 아닌 경우가 존재 
C=0 인 경우, 순간 이동 | C가 0보다 작은 경우는 타임머신으로 시간을 되돌아가는 경우
1번 도시에서 출발해 나머지 도시로 가는 가장 빠른 시간을 구하는 프로그램을 작성
*/
#include <iostream>
#include <vector>
#include <climits>
#define INF INT_MAX
using namespace std;

int N; // 도시의 개수
int M; // 버스의 노선의 개수
vector < pair<pair<int,int>, int> > bus_info;//버스노선의 정보를 저장
long long dist[501];

bool infinite_check(){
    for(int i=0 ; i< bus_info.size();i++){
            int from = bus_info[i].first.first; //edge의 시작점
            int to = bus_info[i].first.second; //edge의 끝나는점
            int weight = bus_info[i].second; //edge의 weight

            if(dist[from]!=INF && (dist[to]> dist[from]+weight)) return true;//거리가 변화하면 무한

        }//모든 edge를 검사
    return false;
}

void cal_sec(int start){
    for(int i =1;i<=N ; i++){
        dist[i]=INF;
    }//거리를 초기화

    dist[start]=0;//시작점은 자기자신이여서 0으로 설정
    
    for(int n =1; n <= N-1; n++){
        for(int i=0 ; i< bus_info.size();i++){
            int from = bus_info[i].first.first; //edge의 시작점
            int to = bus_info[i].first.second; //edge의 끝나는점
            int weight = bus_info[i].second; //edge의 weight

            if(dist[from]!=INF && (dist[to]> dist[from]+weight)) dist[to] = dist[from]+weight; //거리가 짧다면 업데이트

        }//모든 edge를 검사
    }//vertex-1번 반복
    //무한 검사
    if(infinite_check()) {
        cout << -1 ;
        return;
    }
    for(int i=1; i<=N ;i++){
        if(i==start) continue;//시작점과 같으면 출력안함
        else if(dist[i]==INF) cout << -1 <<'\n';
        else cout << dist[i] << '\n';
    }//시간을 출력
}

int main(){
    ios :: sync_with_stdio(false); cin.tie(0);

    cin >> N >> M;

    int A, B, C ; //입력받는 버스노선의 정보를 저장
    while(M--){
        cin >> A >> B >> C; 
        bus_info.push_back({{A,B},C});
    }
    cal_sec(1);//문제에서 시작도시를 1로 설정
}

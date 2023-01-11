/*2023.01.11
<최단경로>
방향그래프가 주어지면 주어진 시작점에서 다른 모든 정점으로의 최단 경로를 구하는 프로그램
가중치는 10이하의 자연수
V - VERTEX수
E - EDGE수
K - 시작 정점의 번호
*/
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#define INF INT_MAX
using namespace std;

long long dist[20001]; //최단 경로 값들을 저장
vector <pair<int,int>> graph[20001]; //입력받는 도착노드와 weight를 저장
priority_queue <pair<int,int>> pq; //weight와 시작지점을 저장
int V, E, K;

void dijkstra(){

    int start = K;//처음 출발노드는 K
    dist[start]=0;//출발노드를 0으로 한다.
    pq.push({0,start});
    
    while(!pq.empty()){
        int current_node=pq.top().second;//현재 node를 저장
        int current_weight= pq.top().first*-1; //현재 노드의 weight를 저장
        pq.pop();
        
        for(int i=0;i<graph[current_node].size();i++){
            int next_node = graph[current_node].at(i).first; //끝나는 node를 저장
            int next_weight = graph[current_node].at(i).second; //weight를 저장

            if(next_weight+current_weight<dist[next_node]) {
                dist[next_node]=next_weight+current_weight;
                pq.push({dist[next_node]*-1,next_node});
            }//거리가 더 가깝다면 바꾸어준다.
        }
    }
}

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin >> V >> E;
    cin >> K;

    for(int i =0,a,b,c ;i<E; i++){
        cin >> a >> b >> c ;
        graph[a].push_back({b,c});//시작노드에 맞게 end지점과 weight를 넣어준다.
    }
    for(int i =1 ;i<=V ;i++){
        dist[i]=INF;
    }//거리값을 INF로 초기화

    dijkstra();
    for(int i =1 ;i<=V ;i++){
        if(dist[i]==INF) {
            cout << "INF"<<'\n';
            continue;
        }
        cout << dist[i]<< '\n';
    }
}
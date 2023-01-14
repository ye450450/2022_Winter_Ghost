/*
2023.01.13
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define INF INT_MAX
using namespace std;

int N,M; //N은 장소 수, M의 도로수
int S,D; //S는 시작점, D는 도착점
vector <pair<int,int>> graph [510];//도로에 대한 정보 저장
long long dist[510];
int fun_count=0;

void almost_short(int start, int end){
    
    priority_queue<pair<int,int>> pq;
    for(int i=0;i<N;i++)
        dist[i]=INF; //초기화

    dist[start];
    pq.push({0,start});

    while(!pq.empty()){
        int c_node = pq.top().second;
        int c_dist = -pq.top().first;
        pq.pop();
        for(int i =0 ;i< graph[c_node].size();i++) {
            int n_node = graph[c_node][i].first;
            int n_dist = graph[c_node][i].second;
            if(dist[n_node] > c_dist+ n_dist){
                graph[c_node].erase(graph[c_node].begin()+i);
                dist[n_node] = c_dist+n_dist;
                pq.push({-dist[n_node],n_node});
            }
        }
    }
}

int main(){
    ios :: sync_with_stdio(false); cin.tie(0);

    while(true){
        cin >> N >> M;
        if(N==0 && M ==0 ) return 0;
        
        cin >> S >> D;
        int U,V,P;

        for(int i =0 ; i< M ; i++){
            cin >> U >> V >> P;
            graph[U].push_back({V,P});
        }

        long long temp;//거의 최단경로를 저장

        almost_short(S,D);
        temp = dist[D];//최단경로를 저장
        if(temp==INF) {
            cout << -1 <<'\n';
            
            for(int i =0 ; i< N ; i++){
            graph[i].clear();
            }
            continue;
        }

        almost_short(S,D);
        temp = dist[D];
        
        if(temp==INF) cout << -1 <<'\n';
        else cout << temp<<'\n';

        for(int i =0 ; i< N ; i++){
            graph[i].clear();
        }
    }
    return 0;
}
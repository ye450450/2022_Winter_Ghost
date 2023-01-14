/*2023.01.23
*/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define INF INT_MAX
using namespace std;

int V,E,P;//정점개수, 간선개수, 건우 위치
vector<pair<int,int>> graph [5010];//간선의 정보를 넣음
long long dist [5010];//길이를 저장
long long sum [2];

long long gun_check(int start, int  end ){
    priority_queue <pair<int,int>> pq;

    for(int i=1;i<=V ;i++)
        dist[i]=INF;//초기화

    dist[start]=0;
    pq.push({0,start});
    
    while(!pq.empty()){
        int c_pos = pq.top().second;
        int c_path = -pq.top().first; 
        pq.pop();

        for(int i =0 ;i< graph[c_pos].size();i++){
            int n_pos = graph[c_pos][i].first;
            int n_path = graph[c_pos][i].second;

            if(dist[n_pos]>c_path + n_path){
                dist[n_pos] = c_path + n_path;
                pq.push({-dist[n_pos], n_pos});
            }
        }
    }//다익스트라로 모든 경로 확인
    return dist[end];
}

int main(){
    ios :: sync_with_stdio(false); cin.tie(0);

    cin >> V >> E >>P;

    for(int i=0, a,b,c ; i<E ; i++){
        cin >> a >> b >> c;
        graph[a].push_back({b,c});//간선의 정보를 넣음
        graph[b].push_back({a,c});
    }
    sum[0] = gun_check(1,P)+gun_check(P,V);
    sum[1] = gun_check(1,V);
    
    if(sum[0]<=sum[1]) cout << "SAVE HIM";
    else cout << "GOOD BYE";
}

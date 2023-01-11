/*2023.01.11
<특정한 최단 경로>
방향성이 없는 그래프
1번부터 N번 정점으로 최단 거리로 이동 
임의로 주어지는 두 edge를 반드시 통과
한번 이동했던 vertex와 edge 이용가능
이 조건을 만족하는 최단 경로 프로그램을 작성
*/
#include <iostream>
#include <queue>
#include <climits>
#define INF INT_MAX
using namespace std;

int N,E;//Vertex 수: N, Edge 수 : E
int V1, V2;//임의의 두 정점을 저장
vector < pair<int,int> > graph[20001];//입력받는 vertex와 weight를 저장
long long dist[801];
long long sum[2];


int dijkstra(int start, int end){
    priority_queue <pair<int,int>> pq;

    for(int i =1 ; i<=N ;i++)
        dist[i]=INF;//무한으로 초기화
    
    dist[start] = 0;
    pq.push({0,start});

    while(!pq.empty()){
        int c_node = pq.top().second;
        int c_weight = pq.top().first*-1;
        pq.pop();
        for(int i =0 ; i< graph[c_node].size(); i++){
            int n_node = graph[c_node][i].first;
            int n_weight = graph[c_node][i].second;

            if(dist[n_node] > n_weight+c_weight){
                dist[n_node] = n_weight+c_weight;
                pq.push({dist[n_node]*-1,n_node});
            }
        } 
    }
    return dist[end];
}

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> E;

    for(int i=0 ,a,b,c; i<E ;i++){
        cin >> a >> b >> c; //a번 정점에서 b정점까지의 양방향 길이 c가 존재
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});//양방향이라 둘다 저장
    }
    cin >> V1 >> V2;

    sum[0]= min(INF,dijkstra(1,V1)+dijkstra(V1,V2)+dijkstra(V2,N));
    sum[1]= min(INF,dijkstra(1,V2)+dijkstra(V2,V1)+dijkstra(V1,N));

    if((sum[0]==INF && sum[1]==INF) || (sum[0]<0 && sum[1]<0) || E==0) cout << -1 << '\n'; //경로가 없는 경우
    else if(sum[0]<sum[1]){
        cout << sum[0] << '\n';
    }
    else cout << sum[1] << '\n';
    //최단경로를 출력한다.
    return 0;
}
/*2023.01.11
<해킹>
서로에 의존하는 컴퓨터들이 전염
a가 b에 의존한다면, b가 감염되면 일정시간 후에 a도 감염
T-> 테스트 수 100개가 최대
컴퓨터 수 N, 의존성 개수 D, 해킹당한 컴퓨터 번호 C (1 ≤ n ≤ 10,000, 1 ≤ d ≤ 100,000, 1 ≤ c ≤ n).
a가 컴퓨터 b를 의존하며, 컴퓨터 b가 감염되면 s초 후 컴퓨터 a도 감염됨을 뜻한다.
테스트 케이스마다 한 줄에 걸쳐 총 감염되는 컴퓨터 수, 마지막 컴퓨터가 감염되기까지 걸리는 시간을 공백으로 구분지어 출력
*/
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#define INF INT_MAX
using namespace std;

int T;//테스트 케이스 수
int N,D,C; //N : 컴퓨터 개수 , D : 의존성 개수, C : 해킹당한 컴퓨터 번호
vector <pair<int,int>> graph[10010];
int count_computer; //감염된 컴퓨터 수 저장
long long max_sec; //마지막 컴퓨터가 감염되기까지 걸리는 시간을 저장
 
void cal_second(int start){
    priority_queue <pair<long long,long long> > pq;
    long long sec[10010];//각 컴퓨터가 감염되는데 걸리는 시간을 저장
    
    for(int i=0 ;i<=N; i++)
        sec[i]= INF; //걸리는 시간을 초기화 

    sec[start]=0;
    pq.push({0,start});//처음들어오는 컴퓨터를 넣어줌

    while(!pq.empty()){
        int c_computer= pq.top().second; //현재있는 컴퓨터 저장
        int c_second = pq.top().first*-1;  //현재까지 걸린 시간 저장
        pq.pop();
    
        for(int i =0; i<graph[c_computer].size();i++){
            int n_computer = graph[c_computer][i].first; //현재 컴퓨터를 의존하는 컴퓨터의 번호를 가져옴
            int n_second = graph[c_computer][i].second; //걸리는 시간을 가져옴. 

            if(sec[n_computer] > c_second+ n_second){
                sec[n_computer] = c_second+ n_second;//짧게 걸리는 시간으로 업데이트
                pq.push({sec[n_computer]*-1, n_computer});
            }
        }
    }

    for(int i =0 ;i<=N ; i++){
        if(sec[i]!=INF) {
            count_computer++;
            if(max_sec < sec[i]) max_sec =sec[i]; 
        }
    }
}//감염되는 컴퓨터 수와 걸리는 시간을 계산하는 함수

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> T;

    while(T--){
        cin >> N >> D >> C;
        for(int i=0 ,a, b ,s ;i <D; i++){
            cin >> a >> b >> s; //a가 b를 의존, b가 감염되면, s초 후에 a가 감염 (b가 시작vertex, a가 도착vertex, s는 weight같은 역할)
            graph[b].push_back({a,s}); //의존성이 컴퓨터와 시간을 저장
        }//의존성 개수만큼 실행(edge개수와 비슷한 원리)
        cal_second(C);
        cout << count_computer << " "<< max_sec <<'\n';

        count_computer = max_sec =0; //초기화
        for(int i =0 ;i<=N ;i++)
            graph[i].clear();//초기화 

    }//테스트 케이스 개수만큼 실행

    return 0;
}
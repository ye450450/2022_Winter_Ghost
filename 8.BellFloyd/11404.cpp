/*2023.01.12
n개의 도시가 있다. 그리고 한 도시에서 출발하여 다른 도시에 도착하는 m(1 <= m <= 100,000)개의 버스
각 버스는 한 번 사용할 때 필요한 비용이 있다.
모든 도시의 쌍(A,B)에 대해서 도시 A에서 B로 가는데 필요한 비용의 최솟값을 구하는 프로그램을 작성
도시의 개수 n, 버스의 개수 m
셋째 줄부터는 버스의 정보 : A - 시작도시, 도착도시 - B , 한번에 타는데 필요한 비용 -C ( 0 < C < 100,000)
시작도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있다.
n개의 줄을 출력, i번째 줄에는 출력하는 j번째 숫자는 도시 i에서 j로 가는데 필요한 최소 비용
i에서 j로 갈 수 없는 경우에는 그 자리에 0을 출력
*/

#include <iostream>
#include <climits>
#define INF INT_MAX
using namespace std;

int N;//도시의 개수
int M;//버스의 개수
long long dist[101][101];//비용의 최솟값을 저장하는 dist

void output(){
    for(int i=0 ; i<N ; i++ ){
        for (int j=0; j<N ;j++){
            if (dist[i][j]==INF) cout << 0 << " ";
            else cout << dist[i][j]<< " ";
        }
        cout << '\n';
    }//거리를 출력
}

void floyd(){
    for(int m =0 ; m<N ;m ++){
        for(int f = 0; f<N ;f++){
            for(int l = 0;l<N;l++){
                dist[f][l]= min(dist[f][l],dist[f][m]+dist[m][l]);//중간다리를 거치는 거리와 비교해서 업데이트
            }
        }
    }
    output();
}

int main(){
    ios :: sync_with_stdio(false); cin.tie(0);

    cin >> N;
    cin >> M;

    for(int i=0 ; i<N ; i++ ){
        for (int j=0; j<N ;j++){
            if(i==j) dist[i][j]=0;
            else dist[i][j]=INF;
        }
    }//거리를 초기화해준다.

    while(M--){
        int a,b;// 시작도시 a, 도착도시 b, 한 번 타는데 필요한 비용 c
        long long c;
        cin >> a >> b >> c;
        dist[a-1][b-1]=min( dist[a-1][b-1] , c);//입력받은 비용을 넣어준다.
    }
    floyd();
}
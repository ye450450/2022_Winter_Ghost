/*2023.01.14
<유기농 배추>
배추흰지렁이를 구입, 이 지렁이는 배추근처에 서식하며 해충을 잡아 먹음
지렁이는 인접한 배추로 이동가능 - 상하좌우로 이동가능
밭에 필요한 최소한의 지렁이 수를 출력하는 프로그램
10 8 17
0 0
1 0
1 1
4 2
4 3
4 5
2 4
3 4
7 4
8 4
9 4
7 5
8 5
9 5
7 6
8 6
9 6
->5 출력
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int T;//테스트 케이스 개수
int M,N,K; // M-배추밭 가로길이, N-배추밭 세로길이 , K-배추가 심어져 있는 위치의 개수 
int worm_count=0;//지렁이가 필요한 횟수를 저장
vector <pair<int,int>> start_point;//지렁이의 출발점이 가능한 곳들을 저장
int row_move[4]={-1,1,0,0};//상하좌우체크를 위해(행이동)
int col_move[4]={0,0,-1,1};//상하좌우체크를 위해(열이동)

void cal_worm(int bachu[][51],int visit[][51],int s_row, int s_column){
    if(visit[s_row][s_column]==1) return; //이미 지렁이가 방문했으면 출발지점설정이 안됨
    queue <pair<int,int>> q;
    
    visit[s_row][s_column];//방문체크
    q.push({s_row,s_column});
    
    while(!q.empty()){
        int c_row=q.front().first;
        int c_col=q.front().second;
        q.pop();
        for(int i=0 ;i<4;i++){
            int n_row=c_row+row_move[i];
            int n_col = c_col+col_move[i];
            if(n_row <0 || n_row > N-1||n_col<0 || n_col > M-1) continue;
            if(bachu[n_row][n_col]==1 && visit[n_row][n_col]==0){
                visit[n_row][n_col]=1;//배추가 있고, 방문하지 않았으면 방문
                q.push({n_row,n_col});
            }
        }//상하좌우 체크
    }
    worm_count++;
}
int main(){
    ios :: sync_with_stdio(false); cin.tie(0);

    cin >> T;
    while(T--){
        int bachu [51][51]={0,};//배추가 들어간 위치를 저장
        int visit [51][51]={0,};//지렁이 방문여부를 저장

        cin >> M >> N >> K;

        for(int i=0,col,row; i<K ;i++){
            cin >> col >> row;
            bachu[row][col]=1;
            start_point.push_back({row,col});
        }
        
        sort(start_point.begin(), start_point.end());//앞에서부터 살펴보기 위해 정렬

        for(pair<int,int>  a : start_point)
            cal_worm(bachu,visit,a.first, a.second);

        cout << worm_count<<'\n';
        //다시 초기화
        worm_count=0;
        start_point.clear();
    }
    return 0;
}
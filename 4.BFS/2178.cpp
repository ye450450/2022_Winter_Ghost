/*2023.01.14
<미로 탐색>
미로에서 1은 이동할 수 있는 칸, 0은 이동할 수 없는 칸
(1,1)에서 출발하여 (N,M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램
한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.
시작 위치와 도착위치도 포함
4 6
110110
110110
111111
111101
-> 9출력
*/
#include <iostream>
#include <queue>
using namespace std;

int N,M; //N은 row, M은 column의 개수
int path[101][101];//지나간 경로를 저장
int maze[101][101];//입력받은 경로를 저장
int row_move[4]={-1,1,0,0};//상하좌우를 볼 때 행의 움직임
int column_move[4]={0,0,-1,1};//상하좌우를 볼 때 열의 움직임

int cal_path(){
 
    queue <pair <int,int>> q;

    path[0][0]=1;
    q.push({0,0});

    while(!q.empty()){
        int row=q.front().first;
        int column=q.front().second;
        q.pop();
        //상하좌우를 살핌
        for(int i=0 ; i<4 ; i++){
            int n_row=row+row_move[i]; 
            int n_col=column+column_move[i];
            if(n_row <0 || n_col <0 || n_row > N-1 || n_col> M-1) continue;//미로의 밖으로 나가는 경우
            
            if(maze[n_row][n_col]==1 && path[n_row][n_col]==0) {
                path[n_row][n_col]=path[row][column]+1;
                if(n_row==N-1 && n_col == M-1) return path[n_row][n_col];//도착위치에 도착하면 종료
                q.push({n_row,n_col});
            }
        }
    }

    return 0;
}

int main(){
    ios :: sync_with_stdio(false); cin.tie(0);

    cin >> N >> M;
    string num;
    for(int i=0 ;i<N ;i++){
        cin >> num;
        for(int j=0; j<M ;j++){
            if(num[j]=='1') maze[i][j]=1;
            else maze[i][j] = 0;
        }
    }

    int result=cal_path();

    cout << result;
}
/*2023.01.15
<단지번호 붙이기>
정사각형의 모양의 지도가 존재(1은 집이 있는 곳, 0은 집이 없는 곳)
연결된 집의 모임인 단지를 저의하고, 단지에 번호를 붙인다.
상하좌우가 연결된 경우이다. 대각선은 해당x
단지수와 그에 해당하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;//지도의 크기
vector <pair<int,int>> apart;//집이 있는 곳의 위치를 저장
int visit[26][26];
int r_move[4]={-1,1,0,0};//상하좌우 체크시 행움직임
int c_move[4]={0,0,-1,1};//상하좌우 체크시 열움직임
int group_count;//단지수를 저장
vector <int> apart_count;//아파트 수를 저장

void cal_group(int input_map[][26],int start_row, int start_col){
    if(visit[start_row][start_col]==1) return;//이미 방문하면 종료

    int count=0;
    queue<pair<int,int>> q;

    visit[start_row][start_col]=1;//방문처리
    count++;
    q.push({start_row,start_col});

    while(!q.empty()){
        int c_row=q.front().first;
        int c_col=q.front().second;
        q.pop();
        for(int i=0 ;i<4;i++){
            int n_row= c_row +r_move[i];
            int n_col= c_col + c_move[i];
            if(n_row<0 || n_col<0 || n_row >= N || n_col >=N ) continue;//벗어나는 경우
            if(input_map[n_row][n_col]==1 && visit[n_row][n_col]==0){
                visit[n_row][n_col]=1;
                q.push({n_row,n_col});
                count++;
            }//방문하지 않고, 집이 있는 경우
        }
    }
    group_count++;
    apart_count.push_back(count);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> N;
    int map[26][26];//지도를 만듬
     
    for(int i =0; i<N ;i++){
        string row_input;
        cin >> row_input;
        for(int j=0;j<N;j++){
            if(row_input[j]=='1') {
                map[i][j]=1;
                apart.push_back({i,j});
            }
            else map[i][j]=0;
        }
    }
    for(pair<int,int> a : apart)
        cal_group(map,a.first,a.second);
    
    cout << group_count << '\n';
    sort(apart_count.begin(),apart_count.end());
    for(int i : apart_count)
        cout << i <<'\n';
}
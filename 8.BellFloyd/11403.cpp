/*2023.01.13
가중치 없는 방향 그래프 G가 주어지면,
I에서 J로 가는 경로가 있는지 없는지 구하는 프로그램을 작성
첫째 줄에 정점의 개수 - N (1<= N <=100)
가는 경로가 있으면 1을 없으면 0을 출력
*/

#include <iostream>
#include <vector>
#include <climits>
#define INF INT_MAX
using namespace std;

int N;//정점의 개수
int path[101][101];
void path_check(){
    
    for(int m=0; m<N; m++){
        for(int s=0;s<N;s++){
            for(int e=0;e<N;e++)
                if(path[s][e]!=1 && path[s][m]==1 &&path[m][e]==1) path[s][e]=1;//중간다리가 존재하면 경로가 있다. 
        }
    }

}

int main(){
    ios :: sync_with_stdio(false); cin.tie(0);

    cin >> N;

    int a;//간선의 존재여부를 받는 변수
    for(int i=0 ;i< N; i++){
        for(int j=0; j<N ; j++){
            cin >> a;
            if(a==1) path[i][j]=1;//존재하면 1로 저장
            else path[i][j]=INF;
        }
    }
    path_check();
    for(int i=0 ;i< N; i++){
        for(int j=0; j<N ; j++){
            if(path[i][j]==INF) cout << 0 << " ";
            else cout << path[i][j] <<" ";
        }
        cout << '\n';
    }
    return 0;
}

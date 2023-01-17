/*2023.01.17
<체스판 다시 칠하기>
지민이는 자신의 저택에서 MN개의 단위 정사각형으로 나누어져 있는 M x N 크기의 보드를 찾았다.
어떤 정사각형은 검은색, 나머지는 흰색
지민이는 이 보드를 잘라서 8 X 8 크기의 체스판으로 만들려고 한다.
체스판은 검은색과 흰색이 번갈아서 칠해져 있어야한다.
변을 공유하는 두개의 사각형은 다른 색으로 칠해져 있어야 한다.
8x8 크기의 체스판으로 잘라낸 후에 몇 개의 정사각형을 다시 칠해야겠다고 생각
당연히 아무데서나 골라도 된다. 지민이가 다시 칠해야 하는 정사각형의 최소 개수를 구하는 프로그램을 작성
*/
#include <iostream>
#define SIZE 8
using namespace std;

int M, N ;// N과 M은 8보다 크거나 같고, 50보다 작거나 같은 자연수
char chess1 [8][8];//체스판을 저장 (type1)
char chess2 [8][8];//체스판을 저장 (type2)
void reset(){
    for(int i =0; i<SIZE ; i++){
        for(int j=0; j<SIZE ; j++)
            if((j+i)%2==0) chess1[i][j]='W';
            else chess1[i][j]='B';
    }//타입1
    for(int i =0; i<SIZE ; i++){
        for(int j=0; j<SIZE ; j++)
            if((j+i)%2==0) chess2[i][j]='B';
            else chess2[i][j]='W';
    }//타입2
}//정답 체스판을 초기화
void compare_tile(char arr[][50],int row, int col){
    reset();
    int row_diff = row-SIZE;
    int col_diff = col-SIZE;
    int min_diff=64;//차이를 저장하는 변수

    for(int i=0; i<=row_diff ; i++){
        for(int j=0; j<=col_diff ; j++){
            int count=0;
            for(int k =0; k<SIZE ; k++){
                for(int l=0; l<SIZE ; l++)
                    if(chess1[k][l]!=arr[k+i][l+j]) count++;//틀린개수를 저장
            }
            min_diff=min(min_diff,count);//작은 개수를 저장
        }
    }//타입1과 비교

    for(int i=0; i<=row_diff ; i++){
        for(int j=0; j<=col_diff ; j++){
            int count=0;
            for(int k =0; k<SIZE ; k++){
                for(int l=0; l<SIZE ; l++)
                    if(chess2[k][l]!=arr[k+i][l+j]) count++;//틀린개수를 저장
            }//타입2
            min_diff=min(min_diff,count);//작은 개수를 저장
        }
    }//타입2와 비교
    cout << min_diff;
}//타입1과 타입2와 비교
int main(){
    ios :: sync_with_stdio(false); cin.tie(0);
    cin >> M >> N;
    char input[M][50];//들어오는 값들을 저장
    for(int i=0; i<M;i++){
        string s;
        cin >> s;
        for(int j=0;j<N;j++)
            input[i][j]=s[j];
    }
    compare_tile(input,M,N);
    return 0;
}
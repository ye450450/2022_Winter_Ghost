#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int case_num;//테스트 케이스 수
pair <int,int> score [100001];//성적은 저장

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> case_num;

    int count;//지원자 숫자
    vector <int> pass;//최대 신입사원 수를 저장
    for(int j=0 ; j<case_num;j++){
        cin >> count;
        for(int i =0; i<count ;i++){
            cin >> score[i].first >> score[i].second;
        }//지원자의 성적을 입력받음
        
        sort(score,score + count);//정렬

        int result =1;//서류 1등은 무조건 선발
        int temp= score[0].second;//면접성적을 서류 성적의 ㄴ1등으로 초기화
        for(int i = 1; i< count ; i++){
            if(score[i].second<temp){
                result++;
                temp = score[i].second;
            }
        }
        pass.push_back(result);
    }
    for(int i = 0; i<pass.size();i++)
        cout<<pass[i]<<endl;
}
/*2023.01.17
<평균>
세준이는 점수를 조작해서 집에 가져가기로 함 
자기 점수 중에 최댓삽을 골랐다.
이 값을 M이라고 한다. 그리고 나서 모든 점수를 점수/M*100으로 고쳤다
예를 들어 세준이의 최고점이 70이고, 수학점수가 50이었으면 수학점수는 50/70*100
71.43이 된다. 세준이의 성적을 위의 방법대로 새로 계산했을 때, 새로운 평균을 구하는 프로그램 작성
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;//시험 본 과목의 개수
vector <int> score;//점수를 저장
vector <double> change_score;//바뀐 점수를 저장
int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> N;
    
    for(int i=0,a ; i<N ;i++){
        cin >> a;
        score.push_back(a);
    }
    sort(score.begin(),score.end());//정렬
    double sum=0;
    for(int i : score){
        double result= (double)i/score.back()*100;
        change_score.push_back(result);
        sum+=result;
    }//점수 바꾸기
    double average;
    average= sum/N;
    cout <<average;
}
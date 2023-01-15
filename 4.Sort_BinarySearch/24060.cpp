/*2023.01.15
알고리즘 수업 - 병합정렬1
N개의 서로 다른 양의 정수가 저장된 배열 A가 있다.
병합 정렬로 배열 A를 오름차순 정렬할 경우 배열 A에 K번째 저장되는 수를 구하자
*/
#include <iostream>
using namespace std;

int N,K;//N - A의 배열 크기, K - 저장횟수
int count_merge=0;

void merge(int *arr, int left, int mid, int right){
    int temp[right+2];//1부터 시작하는 temp 배열 선언
    int i=left, j=mid+1, t=1;
    while(i<=mid && j <= right){
        if(arr[i] <= arr[j]) temp[t++] = arr[i++];
        else temp[t++] = arr[j++];
    }
    while ( i <= mid) //왼쪽 배열 부분이 남은 경우
        temp[t++] = arr[i++];
    while (j <= right) //오른쪽 배열 부분이 남은 경우
        temp[t++] = arr[j++];
    i=left;//결과 저장을 위해
    t=1;//결과저장을 위해
    while(i <= right){
        arr[i++]=temp[t++];//결과를 저장
        if(++count_merge==K) cout << temp[t-1];//저장횟수와 같다면 출력
    }
}

void merge_sort(int *arr,int left, int right){
    if(left<right ){
        int mid = (left+right)/2;
        merge_sort(arr,left,mid);//전반부 정렬
        merge_sort(arr,mid+1,right);//후반부 정렬
        merge(arr, left, mid, right);//병합
    }
}



int main(){
    ios :: sync_with_stdio(false); cin.tie(0);

    cin >> N >> K;

    int A [N];//A배열 선언
    for(int i=0,a; i<N ;i++){
        cin >> a;
        A[i]=a;
    }

    merge_sort(A,0,N-1);
    if(count_merge<K) cout << -1;//저장횟수가 작으면 -1 출력
    return 0;
}
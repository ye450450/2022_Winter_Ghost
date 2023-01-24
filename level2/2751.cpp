/*2032.01.22
<수 정렬하기2>
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector <int> my_vector;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> N;

    while(N--){
        int temp;
        cin >> temp;
        my_vector.push_back(temp);
    }

    sort(my_vector.begin(), my_vector.end());//오름차순 정렬

    for(int i : my_vector)
        cout << i<<'\n';
    return 0;
}
/*merge sort*/
void merge_sort(int left, int right){
    if(left >= right){

    }
}
void merge(int []arr){
    //전반부와 후반부로 나누어서 정렬을 한다.====
    //정렬된 배열을 merge한다.
}

//merge sort : base에 올 때까지 분리하고, 정렬하면서 merge를 한다. 
//quick sort : 

//insertion sort : 들어갈 위치를 정해주면서 정렬한다.

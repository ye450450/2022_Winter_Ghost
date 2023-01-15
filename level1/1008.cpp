/*2023.01.15
A/B출력
*/
 #include <iostream>
 using namespace std;

double A,B; 
 int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> A >> B;
    double result =A/B;
    cout.precision(10);//소수점 10자리까지 표현
    cout << fixed;//소수점아래만 생각
    cout << result;
 }
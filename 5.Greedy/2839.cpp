//3kg, 5kg봉지가 있다.
#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int input,count;
    cin >> input;
    
    while(input>5){
        input-=5;
        count++;
    }

}
#include <iostream>
 
using namespace std;
 
int main() {
    int n, fat;
    cin >> n;
    
    if(n > 0 && n < 13){
        fat = 1;
        while(n > 0){
            fat = fat * n;
            n--;
        }
    }
    cout << fat << endl;
 
    return 0;
}

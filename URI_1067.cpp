#include <iostream>
 
using namespace std;
 
int main() {
    int x;
    cin >> x;
    
    if(x >= 1 && x <= 1000){
        for(int i = 1; i <= x; i++){
            if(i % 2 != 0)
                cout << i << endl;
        }
    }
    
    return 0;
}

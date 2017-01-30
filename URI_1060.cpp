#include <iostream>
 
using namespace std;
 
int main() {
    float a;
    int pos = 0;

    for(int i = 0; i < 6; i++){
        cin >> a;
        if(a >= 0)
            pos++;
    }
    cout << pos << " valores positivos" << endl;
 
    return 0;
}

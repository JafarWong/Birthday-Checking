#include <iostream>
#include "today.h"

using namespace std;

int main(){


    int banknotes [] {
        1, 3, 5, 10
    };

    int a, b , c ,d, n;
    int count = 0;

    cin >> a >> b >> c >> d >> n ;

    if (a+3*b+5*c+10*d < n ) {
        return 0;
    }
    else {
        for (int i = 0; i<=a; i++) {
            for (int j = 0; j<=b; j++) {
                for (int q = 0; q<=c; q++) {
                    for (int k = 0; k<=d; k++) {
                        if (i*1 + j*3 + q*5 + k*10 == n) {
                            count +=1;
                        }
                    }
                }
            }
        } 
    
    }
    if (count == 0 ) {
        cout << "no";
    }
    else {
        cout << count;
    }

    return 0;

}
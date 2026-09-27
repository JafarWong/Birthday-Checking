#include <iostream>
#include "today.h"

using namespace std;

int main () {
    int year, month, day;
    cout << "Please input the birth data as (yyyy mm dd)" << endl;
    cin >> year >> month >> day;

    if (year < 1900 ) {
        cout << "Year not in range!!" << endl;
        return 0;
    }

    bool isleap = (year % 4 ==0 && year % 100 != 0) || (year %400 ==0);

    int daysInMonth[] {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (isleap) {
        daysInMonth [2] = 29;
    }

    if (month < 1 || month >12 || day < 1 || day > daysInMonth[month]) {
        cout << "Invalid data!!" << endl;

    }

    int cyy = ThisYear();
    int cmm = ThisMonth();
    int cdd = ThisDay();

    bool isFuture = false;
    if (year > cyy) {
        isFuture = true;
    }
    else if (year == cyy && month > cmm) {
        isFuture = true;
    }
    else if (year == cyy && month == cmm && day > cdd) {
        isFuture = true;
    }

    if (isFuture) {
        cout << "You are not born yet!!" << endl;
        return 0;
    }

    if (year == cyy && month ==cmm && day == cdd) {
        cout << "Happy Birthday!!" << endl;
    }
    else {
        string suffix;

        if (day >=11 && day <= 13){
            suffix = "th";
        }
        else {
            switch (day%10) {
                case 1:
                    suffix = "st";
                    break;
                case 2: 
                    suffix = "nd";
                    break;
                case 3:
                    suffix = "rd";
                    break;
            default:
                suffix = "th";
                break;
            }
        }

        string monthNames[] = {
            "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
        };

        cout << "Your birthday was on " << day <<suffix << " " << monthNames[month] << " " << year << "." << endl;

    }

    int sum = 0;
    int temp;
    temp = year;

    while (temp>0) {
        sum +=temp%10; 
        temp/=10;
    }

    temp = month;
    while (temp >0) {
        sum += temp%10; 
        temp /= 10;
    }

    temp = day;
    while (temp >0) {
        sum += temp%10;
        temp /= 10;
    }
    
    
    while (sum >=10) {
        int nextSum = 0;
        temp = sum;
        while (temp > 0) {
            nextSum += temp%10;
            temp /= 10;

        }
        sum = nextSum;
    }

    cout << "Your lucky number is " << sum << "." << endl;
    return 0;
}
// https://www.urionlinejudge.com.br/judge/en/problems/view/1047

#include <iostream>

using namespace std;

int main() {

    int initialHour, initialMinute, finalHour, finalMinute, min, max, diff;

    cin >> initialHour >> initialMinute >> finalHour >> finalMinute;

    // Turning the initial time into minutes:
    min = (initialHour*60)+initialMinute;

    // Turning the final time into minutes:
    max = (finalHour*60)+finalMinute;

    // Calculating the difference between this interval.    
    // Notice that if 'max>min' we just return difference (in minutes).
    // Otherwise, we'll have a negative number indicating that the 'final time' is less than the 'initial time'.
    // As we're not working with 24h time, it means that it started one day and finished in the other.
    // So, we have to convert the absolute value of this difference (in minutes) as well.
    diff = (max>min) ? max-min : ((min-max)-(24*60))*(-1);

    if(diff!=0){

        cout << "O JOGO DUROU " << diff/60 << " HORA(S) E " << diff%60  << " MINUTO(S)" << endl;
    }
    // Notice that if the difference between 'final time' and 'initial time' is 0, it means that the game lasted for 24h0min.
    else{

        cout << "O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)" << endl;
    }

    return 0;
}
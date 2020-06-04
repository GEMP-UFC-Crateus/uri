// https://www.urionlinejudge.com.br/judge/en/problems/view/1557

// Note: This problem seems correct, but results in 'Presentation error' for some reason. Feel free to point the problem.

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// This function counts how many digits 'n' has:
int countDigits(int n){

    int count = 0;

    // Performing some arithmetic operations to extract each digit (from right to left):
    while(n>9){

        n/=10;
        count++;
    }

    return count+1;
}

int main(){

	// This solution doesn't use matrix, but a vector to simulate its traversing:
    vector<int> dim;

    bool finish = false;
    int N, v, i, j, k, max, spaces;;

    // Receiving a N value (until it's different of 0):
    while (!finish){

        cin >> N;

        if(N!=0) dim.push_back(N);
        else finish = true;
    }

    // This loop is use to generate each one of the squared matrices based on the previous input:
    for (v=0; v<dim.size(); v++){

        // The first row of the 'matrix' starts by 1, followed by powers of 2.
        // Then, the subsequent lines start by the respective number of the same column number.
        for (i = 1; i < pow(2, dim[v]); i *= 2){

            for (j = i; j < pow(2, dim[v]) * i; j *= 2){

				// Stores the max value that this 'matrix' will present:
                max = j;
            }
        }

        // Now that we have the max number, we can count how digits it has (to calculate how many spaces must be printed to respect the tabulation):
        spaces = countDigits(max);

        // Finally, we print the 'matrix' with tabulation:
        for (i = 1; i < pow(2, dim[v]); i *= 2){

            for (j = i; j < pow(2, dim[v]) * i; j *= 2){

            	// Notice that the amount of spaces to be printed is given by 'spaces-countDigits(j)':
                for(k=0; k<spaces-countDigits(j); k++) printf(" ");

                cout << j << " ";
            }

            cout << "\n";
        }

        cout << "\n";
    }

    return 0;
}
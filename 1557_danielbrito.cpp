// https://www.urionlinejudge.com.br/judge/en/problems/view/1557

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// This function counts how many digits 'n' has:
unsigned long long int countDigits(unsigned long long int n){

    unsigned long long int count = 0;

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

    unsigned long long int v, i, j, k, max, spaces;
    int n, c;

    // Receiving a 'n' value (until it's different of 0):
    while (cin >> n && n!=0){
		
		dim.push_back(n);
    }

    // This loop is use to generate each one of the squared matrices based on the previous input:
    for (v=0; v<dim.size(); v++){

        // Stores the max value that this 'matrix' will present:
        max = pow(2,(2*(dim[v]-1)));

        // Now that we have the max number, we can count how digits it has.
        // Then, we can calculate how many spaces must be printed to respect the tabulation.
        spaces = countDigits(max);

        // The first row of the 'matrix' starts by 1, followed by powers of 2.
        // Then, the subsequent lines start by the respective number of the same column number.
        for (i = 1; i < pow(2, dim[v]); i *= 2){

        	// Helps to control the printing of the space after each number:
        	c = 0;

            for (j = i; j < pow(2, dim[v]) * i; j *= 2){

            	// Notice that the amount of spaces to be printed is given by 'spaces-countDigits(j)':
                for(k=0; k<spaces-countDigits(j); k++) {

                	printf(" ");
                }

                // Checking if 'c' smaller than the last column.
                // Because if we print a space after the last number of the line, we'll get a 'Presentation Error':
                (c<(dim[v]-1)) ? cout << j << " " : cout << j;

                c++;
            }

            cout << "\n";
        }

        cout << "\n";
    }

    return 0;
}
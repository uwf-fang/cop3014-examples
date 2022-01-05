/**
 * Modulo operator in random number generation
 */


#include <iostream>
#include <cstdlib>
using namespace std;

int main() {

    char cont = 'y';
    int val;

    // goal even numbers between 2 and 100
    // possible value count (100 - 2) / 2 + 1 = 50
    // the interval is 2
    // the starting from 2
    int interval = 2;
    int start = 2;
    int end = 100;
    int count = (end - start) / interval + 1;

    // this loop will run at least once
    //  because of the initial value of cont variable
    while (cont == 'y' || cont == 'Y') {
        val = ((rand() % count) * interval + start);
        cout << "New random roll: " << val << endl;
        cout << "Do you want to continue? (y/n)\n";
        cin >> cont;
    }

   return 0;
}
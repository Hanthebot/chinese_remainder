#include <iostream>
#include <cassert>
#include <gmpxx.h>
using namespace std;

int main() {
    int n, flag;
    cout << "Enter the no. of pairs: " << endl;
    cin >> n;
    // initializes variables
    mpz_class *divisor = new mpz_class[n];
    mpz_class *remainder = new mpz_class[n];
    mpz_class lcm_num = 1, min_solution = 0, temp, x, solution_i;
    // receives input
    for (int i = 0; i < n; ++i) {
        cout << "Enter divisor " << i << ": " << endl;
        cin >> divisor[i];
        cout << "Enter remainder " << i << ": " << endl;
        cin >> remainder[i];
        // compute LCM alongside
        lcm_num *= divisor[i];
    }
    for (int i = 0; i < n; ++i) {
        // x := product of all divisor except current equation
        x = lcm_num / divisor[i];
        // find multiplicative inverse of x in mod divisor
        flag = mpz_invert(solution_i.get_mpz_t(), x.get_mpz_t(), divisor[i].get_mpz_t());
        assert(flag != 0 && "MMI doesn't exist");
        // add partial solution
        min_solution += remainder[i] * x * solution_i;
        if (min_solution >= lcm_num)
            min_solution %= lcm_num;
    }
    // prints output
    cout << "Solution: " << min_solution << " + " << lcm_num << "n" << endl;

    return 0;
}
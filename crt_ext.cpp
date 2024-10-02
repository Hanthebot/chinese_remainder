#include <iostream>
#include <gmpxx.h>
#include <cassert>
using namespace std;

int main() {
    int n, flag = 0;
    cout << "Enter the no. of pairs: " << endl;
    cin >> n;
    // initializes variables
    mpz_class *coefficient = new mpz_class[n];
    mpz_class *divisor = new mpz_class[n];
    mpz_class *remainder = new mpz_class[n];
    mpz_class lcm_num = 1, min_solution = 0, temp, x, solution_i;
    // receives input
    for (int i = 0; i < n; ++i) {
        cout << "Enter coefficient " << i << ": " << endl;
        cin >> coefficient[i];
        cout << "Enter divisor " << i << ": " << endl;
        cin >> divisor[i];
        cout << "Enter remainder " << i << ": " << endl;
        cin >> remainder[i];
        // compute LCM alongside
    }
    // preprocess: divide entire equation by GCD, or multiply multiplicative inverse
    for (int i = 0; i < n; ++i) {
        // divide by GCD
        mpz_gcd(temp.get_mpz_t(), coefficient[i].get_mpz_t(), divisor[i].get_mpz_t());
        if (temp != 1 && remainder[i] % temp == 0) {
            coefficient[i] /= temp;
            divisor[i] /= temp;
            remainder[i] /= temp;
        }
        if (coefficient[i] == 1) continue;
        // multiply multiplicative inverse
        flag = mpz_invert(temp.get_mpz_t(), coefficient[i].get_mpz_t(), divisor[i].get_mpz_t());
        if (flag == 0) continue; // MMI doesn't exist
        coefficient[i] = 1;
        remainder[i] *= temp;
        remainder[i] %= divisor[i];

    }
    for (int i = 0; i < n; ++i)
        lcm_num *= divisor[i];
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
#include <iostream>
#include <numeric>
#include <cmath>
#include <vector>
using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> nugs = nuggets(n);
    vector<int> p = primes(n);
    
    
}

vector<int> nuggets(int n) {
    vector<int> res;
    
    for (int i = 0; )
}

vector<int> primes(int n) {
    // Finds primes p1, p2, ..., pl
    vector<int> res;
    
    int i = 2;
    int curr_product = 1;
    while (curr_product < n) {
        if (is_prime(i)) {
            res.push_back(i);
            curr_product *= i;
            i += 1;
        }
    }
    return res;
}

bool is_prime(int n) {
    // Tests if a number is prime
    for (int i = 2; i < sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}


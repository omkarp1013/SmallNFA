#include <iostream>
#include <numeric>
#include <cmath>
#include <vector>
using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> p = primes(n);
    
    
}

int* nuggets(int n) {
    
}

vector<int> primes(int n) {
    // Finds primes p1, p2, ..., pl
    vector<int> res;
    
    while (n > 0) {
        for (int i = 2; i < sqrt(n); i++) {
            if (is_prime(i)) {
                res.push_back(i);
                n /= i;
            }
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


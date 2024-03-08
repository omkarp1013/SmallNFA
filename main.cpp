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
    int l = p.size();
    int s = max(nugs[0], nugs[1]) + nugs[2] + reduce(p.begin(), p.end());

    for (int i = 0; i < nugs.size(); i++) {
        cout << nugs[i];
    }

    cout << l;
    
    for (int i = 0; i < l; i++) {
        cout << p[i];
    }

    cout << s;
    
}

vector<int> nuggets(int n) {
    vector<int> res;
    int x = sqrt(n);
    int y = floor(sqrt(n));

    while (true) {
        if (gcd(x, y) == 1 && x * y - x - y < 4 * sqrt(n)) {
            res.push_back(x);
            res.push_back(y);
            res.push_back(n - x * y - x - y);
            break;
        } else {
            x -= 1;
            y += 1;
        }
    }
    return res;
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


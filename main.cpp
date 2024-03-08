#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
using namespace std;

vector<int> nuggets(int n);
vector<int> primes(int n);
bool is_prime(int n);
int gcd(int x, int y);

int main() {
    int n;
    cin >> n;

    vector<int> nugs = nuggets(n);
    vector<int> p = primes(n);
    int l = p.size();
    int s = max(nugs[0], nugs[1]) + nugs[2] + accumulate(p.begin(), p.end(), 0);

    for (int i = 0; i < nugs.size(); i++) {
        cout << nugs[i] << " ";
    }

    cout << l << " ";
    
    for (int i = 0; i < l; i++) {
        cout << p[i] << " ";
    }

    cout << s;
    return 0;
}

int gcd(int x, int y) {
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}


vector<int> nuggets(int n) {
    vector<int> res;
    for (int x = sqrt(n); x <= sqrt(n) + 4; ++x) {
        for (int y = x; y <= sqrt(n) + 4; ++y) {
            if (gcd(x, y) == 1 && (n - (x * y - x - y) <= 4 * sqrt(n))) {
                res.push_back(x);
                res.push_back(y);
                res.push_back(n - (x * y - x - y));
                return res;
            }
        }
    }
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
        }
        i += 1;
    }
    return res;
}

bool is_prime(int n) {
    // Tests if a number is prime
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
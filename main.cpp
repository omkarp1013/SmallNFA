#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
using namespace std;

#define ll long long

vector<ll> nuggets(int n);
vector<ll> primes(int n);
vector<ll> generate_primes(int n);
int gcd(int x, int y);

int main() {
    int n;
    cin >> n;

    vector<ll> nugs = nuggets(n);
    vector<ll> p = primes(n);
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

ll gcd(ll x, ll y) {
    while (y != 0) {
        ll temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}


vector<ll> nuggets(int n) {
    // Find nuggets x, y such that xy - x - y <= 4sqrt(n)
    vector<ll> res;
    int sqrtN = sqrt(n);
    for (ll x = sqrtN; x <= sqrtN + 20; ++x) {
        for (ll y = x; y <= sqrtN + 20; ++y) {
            if (gcd(x, y) == 1 && (n - (x * y - x - y) <= 4 * sqrtN)) {
                res.push_back(x);
                res.push_back(y);
                res.push_back(n - (x * y - x - y));
                return res;
            }
        }
    }
}

vector<ll> primes(int n) {
    // Finds primes p1, p2, ..., pl
    vector<ll> res;
    
    int i = 0;
    long long curr_product = 1;
    vector<ll> primes = generate_primes(n);
    while (curr_product < n) {
        curr_product *= primes[i];
        res.push_back(primes[i]);
        i += 1;
    }
    return res;
}

vector<ll> generate_primes(int n) {
    ll limit = sqrt(n);
    vector<bool> primes(limit + 1, true);
    vector<ll> res;

    for (ll p = 2; p <= limit; p++) {
        if (primes[p]) {
            res.push_back(p);
            for (ll i = p * p; i <= limit; i += p) {
                primes[i] = false;
            }
        }
    }

    return res;
}
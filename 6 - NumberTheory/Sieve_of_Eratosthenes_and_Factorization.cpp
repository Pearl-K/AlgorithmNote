#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int n = 1000000; // 최대 범위
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;

    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }
    // prime 벡터를 이용해 소수 여부 판별
    
    int N_cp = 100; // 분해할 숫자
    vector<int> N_factors;

    for (int now = 2; now * now <= N_cp; ++now) {
        if (prime[now]) {
            while (N_cp % now == 0) {
                N_factors.push_back(now);
                N_cp /= now;
            }
        }
    }

    if (N_cp != 1) {
        N_factors.push_back(N_cp);
    }

    // print result
    for (int factor : N_factors) {
        cout << factor << " ";
    }
    return 0;   
}

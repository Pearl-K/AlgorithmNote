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
    return 0;
}

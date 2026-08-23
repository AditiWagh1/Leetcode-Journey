class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        // Use vector<uint8_t> instead of vector<bool> to avoid bit-proxy overhead
        vector<uint8_t> isPrime(n, 1);
        int count = n / 2; // Assume all odd numbers >= 3 are prime initially

        for (int i = 3; 1LL * i * i < n; i += 2) {
            if (isPrime[i]) {
                // Step by 2*i to only mark odd multiples (e.g., 9, 15, 21...)
                for (int j = i * i; j < n; j += 2 * i) {
                    if (isPrime[j]) {
                        isPrime[j] = 0;
                        count--;
                    }
                }
            }
        }

        return count;
    }
};
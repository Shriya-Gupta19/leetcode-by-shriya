class Fancy {
public:
    const long long mod = 1e9 + 7;
    vector<long long> arr;
    long long mul = 1;
    long long add = 0;

    long long modInverse(long long x) {
        long long power = mod - 2;
        long long res = 1;
        while(power) {
            if(power & 1) res = (res * x) % mod;
            x = (x * x) % mod;
            power >>= 1;
        }
        return res;
    }

    Fancy() {}

    void append(int val) {
        long long x = ((val - add) % mod + mod) % mod;
        x = (x * modInverse(mul)) % mod;
        arr.push_back(x);
    }

    void addAll(int inc) {
        add = (add + inc) % mod;
    }

    void multAll(int m) {
        mul = (mul * m) % mod;
        add = (add * m) % mod;
    }

    int getIndex(int idx) {
        if(idx >= arr.size()) return -1;
        return (arr[idx] * mul + add) % mod;
    }
};
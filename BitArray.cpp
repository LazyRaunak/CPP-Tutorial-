#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    
    unsigned int n, s, p, q;
    cin >> n >> s >> p >> q;
    
    unsigned int ans = 0, a = s, ap = s;
    
    while (++ans < n) {
        
        a = (a * p + q) % 2147483648;
        if (a == s || a == ap) break;
        ap = a;
        
    } cout << ans;
}
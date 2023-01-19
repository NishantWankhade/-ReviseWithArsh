#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int two = 0, five = 0;
        while(n > 1){
            int a = n;
            while(a % 2 == 0){
                two++;
                a /= 2;
            }
            while(a % 5 == 0){
                five++;
                a /= 5;
            }
            n--;
        }
        return min(two,five);
    }
};
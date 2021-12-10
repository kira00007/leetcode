#include <bits/stdc++.h>
using namespace std;

//optimal solution is by using hash tables or something

class Solution {
public:
    int strStr(string haystack, string needle) {
        const int l1 = (int)haystack.size();
        const int l2 = (int)needle.size();
        for(int i = 0; i < l1-l2+1; i++) if(haystack.substr(i,l2) == needle) return i;
        return -1;
    }
};
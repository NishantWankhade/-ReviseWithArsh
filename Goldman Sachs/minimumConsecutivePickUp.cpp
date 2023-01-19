#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    class card{
        public:
            int count;
            int length;

            card(int _count = 0, int _len = 0) : count(_count),length(_len) {}
    };
    int minimumCardPickup(vector<int>& cards) {
        map<int,card>mp;
        int ans = -1;

        for(int i = 0; i < cards.size(); i++){
            int x = cards[i];
            if(mp[x].count == 0){
                mp[x].count++;
                mp[x].length = i;
            }
            else if(mp[x].count == 1){
                if(ans == -1){
                    ans = i - mp[x].length + 1;
                }
                else ans = min(ans,i - mp[x].length + 1);
                mp[x].count = 1;
                mp[x].length = i;
            }
        }

        return ans;
    }
};
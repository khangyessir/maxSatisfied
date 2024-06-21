#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int sum = 0;
        for(int i=0; i<n; ++i){
            if(grumpy[i] == 0){
                sum += customers[i];
            }
        }
        int maxSatisfaction = 0;
        int current = 0;
        for(int i=0; i<minutes; ++i){
            if(grumpy[i] == 1){
                current += customers[i];
            }
        }
        maxSatisfaction = current;
        for(int i=minutes; i<n; ++i){
            if(grumpy[i] == 1){
                current += customers[i];
            }
            if(grumpy[i-minutes] == 1){
                current -= customers[i-minutes];
            }
            maxSatisfaction = max(maxSatisfaction, current);
        }
        int ans = maxSatisfaction + sum;
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> customers = {1,0,1,2,1,1,7,5};
    vector<int> grumpy = {0,1,0,1,0,1,0,1};
    int minutes = 3;
    cout << sol.maxSatisfied(customers, grumpy, minutes) << endl;
    return 0;
}
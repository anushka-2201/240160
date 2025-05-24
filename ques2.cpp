#include <iostream>
#include <queue> 
#include <vector> 
#include <unordered_set>
#include <tuple>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;
int solve(vector<int> vect, int prev, int curr);
int main() {
    vector<int> vect = {2, 5, 3, 7, 11, 8, 10};
    int ans = solve(vect, -1, 0);
    cout<<ans;

}
int solve(vector<int> vect, int prev, int curr) {
    int n = vect.size();
    if(curr>=n) {
        return 0;
    }
    int take = 0;
    if(prev == -1 || vect[prev]<vect[curr]) {
        take = 1+solve(vect, curr, curr+1);
    }
    int skip = solve(vect, curr, curr+1);
    return max(skip, take);
}
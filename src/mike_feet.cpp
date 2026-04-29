#include "mike_feet.h"
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long> maxStrengthForAllSizes(const vector<long long>& heights) {
    int n = heights.size();
    
    vector<int> left(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    
    
    vector<int> right(n, n);
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    
    
    vector<long long> ans(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int len = right[i] - left[i] - 1;
        ans[len] = max(ans[len], heights[i]);
    }
    
    
    for (int i = n - 1; i >= 1; i--) {
        ans[i] = max(ans[i], ans[i + 1]);
    }
    
    return vector<long long>(ans.begin() + 1, ans.end());
}
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), count = 0, lastidx = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') count++;
            else count--;
            if (count == 0) ans = max(i - lastidx + 1, ans);
            if (count < 0) {
                count = 0;
                lastidx = i + 1;
            }
        }
        count = 0;
        lastidx = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')') count++;
            else count--;
            if (count == 0) ans = max(lastidx - i + 1, ans);
            if (count < 0) {
                count = 0;
                lastidx = i - 1;
            }
        }
        return ans;
    }
};
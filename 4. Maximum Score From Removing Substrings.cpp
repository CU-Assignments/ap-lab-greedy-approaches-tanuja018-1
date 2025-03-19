class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (x < y) swap(x, y), swap_chars(s);

        return removePairs(s, 'a', 'b', x) + removePairs(s, 'b', 'a', y);
    }

private:
    void swap_chars(string &s) {
        for (char &c : s) 
            if (c == 'a') c = 'b';
            else if (c == 'b') c = 'a';
    }

    int removePairs(string &s, char first, char second, int pointsValue) {
        stack<char> st;
        int points = 0;

        for (char c : s) {
            if (!st.empty() && st.top() == first && c == second) {
                st.pop();
                points += pointsValue;
            } else {
                st.push(c);
            }
        }
        s = "";
        while (!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());  

        return points;
    }
};

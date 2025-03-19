class Solution {
public:
  int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int low = 0, high = min(tasks.size(), workers.size());
        while (low < high) {
            int mid = (low + high + 1) / 2;
            if (canAssign(mid, tasks, workers, pills, strength)) low = mid;
            else high = mid - 1;
        }
        return low;
    }

private:
    bool canAssign(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        multiset<int> ms(workers.end() - k, workers.end());
        for (int i = k - 1; i >= 0; i--) {
            auto it = prev(ms.end());
            if (*it < tasks[i]) {
                if (!pills--) return false;
                it = ms.lower_bound(tasks[i] - strength);
                if (it == ms.end()) return false;
            }
            ms.erase(it);
        }
        return true;
    }
};

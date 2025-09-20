#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pair;
        for (int i = 0; i < position.size(); i++) {
            pair.push_back({position[i], speed[i]});
        }

        // Sort cars by position in descending order (closest to target first)
        sort(pair.rbegin(), pair.rend());

        vector<double> stack; // will store times to reach target
        for (auto& p : pair) {
            // calculate time to reach target
            stack.push_back((double)(target - p.first) / p.second);

            // merge fleets if current car catches up with previous car
            if (stack.size() >= 2 &&
                stack.back() <= stack[stack.size() - 2])
            {
                stack.pop_back(); // not a new fleet
            }
        }
        return stack.size(); // number of fleets
    }
};

int main() {
    Solution sol;

    // Example test case
    int target = 12;
    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};

    int result = sol.carFleet(target, position, speed);
    cout << "Number of car fleets: " << result << endl;

    return 0;
}
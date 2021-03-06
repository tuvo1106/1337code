#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

bool can_cross(vector<int> &stones)
{
    for (int i = 3; i < stones.size(); i++)
        if (stones[i] > 2 * stones[i - 1])
            return false;
    unordered_set<int> set;
    for (auto i : stones)
        set.insert(i);
    int last_stone = stones[stones.size() - 1];
    stack<int> positions;
    stack<int> jumps;
    positions.push(0);
    jumps.push(0);
    while (!(positions.empty()))
    {
        int curr_pos = positions.top();
        positions.pop();
        int curr_jump = jumps.top();
        jumps.pop();
        for (int i = curr_jump - 1; i <= curr_jump + 1; i++)
        {
            if (i <= 0)
                continue;
            if (curr_pos + i == last_stone)
                return true;
            if (set.find(curr_pos + i) != set.end())
            {
                positions.push(curr_pos + i);
                jumps.push(i);
            }
        }
    }
    return false;
}

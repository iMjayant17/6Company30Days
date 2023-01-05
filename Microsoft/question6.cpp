/*
Given an array rectangles where rectangles[i] = [xi, yi, ai, bi] represents an axis-aligned rectangle. The bottom-left point of the rectangle is (xi, yi) and the top-right point of it is (ai, bi).
Return true if all the rectangles together form an exact cover of a rectangular region.
Example 1:
Input: rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
Output: true
Explanation: All 5 rectangles together form an exact cover of a rectangular region.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
 
        map<pair<int, int>, int> count;
        for(vector<int> &rect : rectangles){
            count[{rect[0], rect[1]}]++;
            count[{rect[0], rect[3]}]--;
            count[{rect[2], rect[1]}]--;
            count[{rect[2], rect[3]}]++;
        }
        int corners = 0;
        for(auto &cnt : count){
            corners += abs(cnt.second);
        }
        return corners == 4;
    
    }
};
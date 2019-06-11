#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		vector<int> tmp;
		for (int i = 0; i < nums.size() - 2; i++) {
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			tmp.push_back(nums[i]);
			int left = i + 1, right = nums.size() - 1;
			while (left > i && right > left) {
				if (nums[i] + nums[left] + nums[right] == 0) {
					tmp.push_back(nums[left]);
					tmp.push_back(nums[right]);
					res.push_back(tmp);
					tmp.pop_back();
					tmp.pop_back();
					left++;
					right--;
				}
				else if (nums[i] + nums[left] + nums[right] > 0)
					right--;
				else
					left++;
			}
			tmp.pop_back();
		}
		return res;
	}
};
int main() {
	vector<int> v;
	int t;
	cin >> t;
	while (getchar() != '\n') {
		v.push_back(t);
		cin >> t;
	}
	v.push_back(t);
	Solution s;
	vector<vector<int>> res = s.threeSum(v);
	system("pause");
	return 0;
}
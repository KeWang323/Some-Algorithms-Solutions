//delete by subset
class Solution {
public:
	int SubsetSumRemoval(vector<int> input) {
		unordered_map<int, int> mapping;
		sort(input.begin(), input.end());
		for (int num : input) {
			mapping[num]++;
		}
		vector<vector<int>> subset;
		vector<int> res_sub;
		allsubset(input, subset, res_sub, 0);
		for (int i = 0; i < subset.size(); i++) {
			if (valid(subset[i], mapping)) {
				match(subset[i], mapping, input);
			}
		}
		int res = 0;
		for (auto i = mapping.begin(); i != mapping.end(); i++) {
			if (i->second == true) {
				res++;
			}
		}
		return res;
	}
private:
	void allsubset(const vector<int>& input, vector<vector<int>>& subset, vector<int>& res_sub, int index) {
		if (index == input.size()) {
			return;
		}
		for (int i = index; i < input.size(); i++) {
			res_sub.push_back(input[i]);
			subset.push_back(res_sub);
			allsubset(input, subset, res_sub, i + 1);
			res_sub.pop_back();
		}
	}
	bool valid(const vector<int>& res_sub, unordered_map<int, int>& mapping) {
		for (int num : res_sub) {
			if (mapping[num] == 0) {
				return false;
			}
		}
		return true;
	}
	void match(const vector<int>& res_sub, unordered_map<int, int>& mapping, const vector<int>& input) {
		int sum = 0;
		for (int num : res_sub) {
			sum += num;
		}
		for (int i = input.size() - 1; i >= 0 && input[i] >= sum; i--) {
			if (mapping[input[i]] > 0 && input[i] == sum) {
				if (res_sub[0] == sum) {
					if (mapping[sum] >= 2) {
						mapping[sum] -= 2;
					}
				}
				else {
					mapping[sum] -= 1;
					for (int num : res_sub) {
						mapping[num] -= 1;
					}
				}
				return;
			}
		}
	}
};
//delete by value
class Solution {
public:
	int SubsetSumRemoval(vector<int> input) {
		unordered_map<int, int> mapping;
		sort(input.begin(), input.end());
		for (int num : input) {
			mapping[num]++;
		}
		vector<vector<int>> subset;
		vector<int> res_sub;
		allsubset(input, subset, res_sub, 0);
		for (int i = input.size() - 1; i >= 0; i--) {
			if (mapping[input[i]] > 0) {
				match(subset, mapping, input[i]);
			}
		}
		int res = 0;
		for (auto i = mapping.begin(); i != mapping.end(); i++) {
			if (i->second == true) {
				res++;
			}
		}
		return res;
	}
private:
	void allsubset(const vector<int>& input, vector<vector<int>>& subset, vector<int>& res_sub, int index) {
		if (index == input.size()) {
			return;
		}
		for (int i = index; i < input.size(); i++) {
			res_sub.push_back(input[i]);
			subset.push_back(res_sub);
			allsubset(input, subset, res_sub, i + 1);
			res_sub.pop_back();
		}
	}
	bool valid(const vector<int>& res_sub, unordered_map<int, int>& mapping) {
		for (int num : res_sub) {
			if (mapping[num] == 0) {
				return false;
			}
		}
		return true;
	}
	void match(const vector<vector<int>>& subset, unordered_map<int, int>& mapping, const int& input) {
		for (int i = 0; i < subset.size(); i++) {
			if (valid(subset[i], mapping)) {
				int sum = 0;
				for (int num : subset[i]) {
					sum += num;
				}
				if (input == sum) {
					if (subset[i][0] == sum) {
						if (mapping[sum] >= 2) {
							mapping[sum] -= 2;
						}
					}
					else {
						mapping[sum] -= 1;
						for (int num : subset[i]) {
							mapping[num] -= 1;
						}
					}
					return;
				}
			}
		}
	}
};
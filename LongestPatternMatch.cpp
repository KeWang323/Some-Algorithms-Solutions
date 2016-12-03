class Solution {
public:
	string LongestPatternMatch(string pattern, string input) {
		if (pattern.empty() || input.empty()) {
			return "pattern not found";
		}
		int l = 0, r = 0;
		string inputcoded = code(input);
		int psize = pattern.size();
		for (int i = 0; i < psize; i++) {
			int s = i, f = i;
			while (f + psize <= input.size()) {
				if (match(inputcoded, f, pattern)) {
					f += psize;
					l = f - s > r - l ? s : l;
					r = f - s > r - l ? f : r;
				}
				else {
					f += psize;
					s = f;
				}
			}
		}
		return input.substr(l, r - l);
	}
private:
	string code(const string& input) {
		string res;
		for (char cha : input) {
			if (cha <= 'z' && cha >= 'a') {
				res.push_back('L');
			}
			else if (cha <= 'Z' && cha >= 'A') {
				res.push_back('U');
			}
			else if (isdigit(cha)) {
				res.push_back('D');
			}
			else {
				res.push_back(cha);
			}
		}
		return res;
	}
	bool match(const string& inputcoded, const int& f, const string& pattern) {
		for (int i = 0; i < pattern.size(); i++) {
			if (pattern[i] != inputcoded[f + i]) {
				return false;
			}
		}
		return true;
	}
};
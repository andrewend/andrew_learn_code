int findClosest(vector<string>& words, string word1, string word2)
{
	int idx1 = -1;
	int idx2 = -1;
	int ans = words.size() - 1;
	for (int i = 0; i < words.size(); i++) { 
		if (words[i] == word1) {
			idx1 = i;
		} else if (words[i] == word2) {
			idx2 = i;
		}
		if (idx1 > 0 && idx2 > 0) {
			ans = min(ans, abs(idx1 - idx2));
		}
	}
	return ans;
}
    

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;

    unordered_map<string, vector<string>> map;
    for (auto str : strs) {
        string strTmp(str);
        sort(str.begin(), str.end());
        map[str].push_back(strTmp);
    }

    for (auto mp : map) {
        res.push_back(mp.second);
    }

    return res;
}

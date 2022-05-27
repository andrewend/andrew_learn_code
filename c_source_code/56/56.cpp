#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>

using namespace std;

//示例 1：
//
//输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
//输出：[[1,6],[8,10],[15,18]]
//解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
//示例 2：
//
//输入：intervals = [[1,4],[4,5]]
//输出：[[1,5]]
//解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
//
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> res(intervals);
		vector<vector<int>> result;

		sort(res.begin(), res.end());
		int i = 0;
		for (; i < res.size() - 1; i++) {
			if (res[i][1] >= res[i+1][0]) {
				if (res[i][1] < res[i+1][1]) {
					res[i][1] = max(res[i][1], res[i+1][1]);
				} else {
					res[i+1][1] = max(res[i][1], res[i+1][1]);
				}

				res[i+1][0] = res[i][0];
			} else {
				result.emplace_back(res[i]);
			}
		}
		result.emplace_back(res[i]);
		return result;
	}
};

void print(vector<vector<int>>& res)
{
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			printf("%d\t", res[i][j]);
		}
		printf("\n");
	}
}

void test01()
{
	Solution solu;
	vector<vector<int>> intervals = { {1, 3}, {2, 6}, {8, 10}, {15, 18} };
	vector<vector<int>> res = solu.merge(intervals);
	vector<vector<int>> expectRes = { {1, 6}, {8, 10}, { 15, 18}};
	print(res);
	assert(res == expectRes);
}

void test02()
{
	Solution solu;
	vector<vector<int>> intervals = { {1, 4}, {4, 5} };
	vector<vector<int>> res = solu.merge(intervals);
	vector<vector<int>> expectRes = { {1, 5} };
	print(res);
	assert(res == expectRes);
}

void test03()
{
	Solution solu;
	vector<vector<int>> intervals = { {1, 4}, {0, 2}, {3, 5} };
	vector<vector<int>> res = solu.merge(intervals);
	print(res);
	vector<vector<int>> expectRes = { {0, 5} };

	assert(res == expectRes);
}
int main()
{
	test01();
	test02();
	test03();

	return 0;
}

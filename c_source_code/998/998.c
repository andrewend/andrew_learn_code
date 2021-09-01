#include <stdio.h>
#include <assert.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* insertIntoMaxTree(struct TreeNode* root, int val){
    if (!root) {
        struct TreeNode *B = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        B->val = val;
        B->left = NULL;
        B->right = NULL;
        return B;
    }

    if (val > root->val) {
        struct TreeNode *B = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        B->val = val;
        B->left = root;
        B->right = NULL;
        return B;
    }

    root->right = insertIntoMaxTree(root->right, val);
    return root;
}

#if 0
struct TreeNode* insertIntoMaxTree(struct TreeNode* root, int val)
{
	//struct TreeNode *res = (struct TreeNode*)malloc(
	return root;
}
#endif

struct TreeNode* creatTree(int* rootArray, int num, int idx)
{
	if (idx >= num) {
	    return 
	}
	struct TreeNode *res = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	

	return NULL;
}

struct TreeNode* creatTree(struct TreeNode* root, int* rootArray, int num, int idx)
{
	
	
}

int compareTree(struct TreeNode* left, struct TreeNode* right)
{
	return 1;
}

void test0()
{
    int rootArray[] = {4, 1, 3, NULL, NULL, 2};
    int rootSz = sizeof(rootArray) / sizeof(rootArray[0]);
    int resArray[] = {5, 4, NULL, 1, 3, NULL, NULL, 2};
    int resSz = sizeof(resArray) / sizeof(resArray[0]);

    int val = 5;
    
    struct TreeNode* root = creatTree(rootArray, rootSz, 0);
    struct TreeNode* result = creatTree(rootArray, resSz, 0);
    struct TreeNode* output = insertIntoMaxTree(root, val);
    int equal = compareTree(result, output);
    assert(equal == 1);
}


int main()
{
	test0();
}

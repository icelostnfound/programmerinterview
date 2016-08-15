#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeNode* ConstructCore(vector<int>::iterator startPreorder, vector<int>::iterator endPreorder,
								vector<int>::iterator startInorder, vector<int>::iterator endInorder)
{
	//在前序遍历中找到根节点的值
	int rootValue = *startPreorder;
	TreeNode* root = new TreeNode(rootValue);
	if (startPreorder==endPreorder)
	{
		if (startInorder == endInorder&&*startPreorder == *endPreorder)//只有根节点
			return root;
		else
			throw exception("Invalid input.");
	}
	//在中序遍历中找到根节点的值
	vector<int>::iterator rootinorder = startInorder;
	while (rootinorder<=endInorder&&*rootinorder!=rootValue)
	{
		rootinorder++;
	}
	if (rootinorder == endInorder&&*rootinorder != rootValue)
		throw exception("Invalid input.");
	int leftlength = rootinorder - startInorder;
	vector<int>::iterator leftPreorderEnd = startPreorder + leftlength;

	if (leftlength>0)
	{
		root->left = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootinorder - 1);
	}
	if (leftlength<(endPreorder-startPreorder))
	{
		root->right = ConstructCore(leftPreorderEnd + 1, endPreorder, rootinorder + 1, endInorder);
	}
	return root;
}

struct TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in)
{
	int length = pre.size();
	vector<int>::iterator itPre = pre.begin();
	vector<int>::iterator itIn = in.begin();
	if (pre.empty() || in.empty() || length <= 0)
		return NULL;
	return ConstructCore(itPre, itPre + length - 1, itIn, itIn + length - 1);
}


int main()
{
	int myarray[8] = { 1,2,3,7,3,5,6,8};
	int array[8] = { 4,7,2,1,5,3,8,6 };
	vector<int> pre(myarray, myarray + 8);
	vector<int>Int(array, array + 8);
	reConstructBinaryTree(pre, Int);
	return 0;
}

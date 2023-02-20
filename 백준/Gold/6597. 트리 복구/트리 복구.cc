#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#define MAX 1010

using namespace std;

string preorder, inorder;
int id;

void recursion(int s, int e){
	if (s > e) return;

	int mid = inorder.find(preorder[id]);
	id++;

	recursion(s, mid - 1);
	recursion(mid + 1, e);
	cout << inorder[mid];
}
int main(void) {
	while (true) {
		preorder.clear();
		inorder.clear();
		id = 0;
		cin >> preorder >> inorder;
		int len = preorder.length();
		if (len == 0) break;
        
		recursion(0, len - 1);
		cout << '\n';
	}
	
	return 0;
}
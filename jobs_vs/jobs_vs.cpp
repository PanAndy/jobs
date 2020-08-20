#include<iostream>
#include<vector>
#include<stack>

using namespace std;


bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
	stack<int> s;

	bool valide = true;
	int idx_push = 0;
	int idx_pop = 0;
	while (idx_push <= pushed.size())
	{
		while (!s.empty() && s.top() == popped[idx_pop])
		{
			s.pop();
			idx_pop++;
		}
		if (idx_push == popped.size()) {
			break;
		}
		s.push(pushed[idx_push++]);

	}
	if (s.empty())return true;
	else {
		return false;
	}
}

int main()
{
	vector<int> pushed = { 1,2,3,4,5 };
	vector<int> popped = { 4,3,5,1,2 };
	cout << validateStackSequences(pushed, popped);
	return 0;
}

#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<cstdio>

using namespace std;


int main()
{
	freopen("output.txt", "w", stdout);
	int m, n;
	cin >> m >> n;

	int** array = new int* [m];
	for (int i = 0; i < m; i++) {
		array[i] = new int[n];
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> array[i][j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++) {
			array[i][j]++;
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << array[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < m; i++) {
		delete[] array[i];
	}
	return 0;
}
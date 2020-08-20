#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct _Container_T {
	int array[5];
	int num;  // counter of valid number
}Container_T;

bool insertNumberToContainer(int value, Container_T* pCon)
{
	if (value != 1 && value != 2)return false;

	if (value == 1) {
		if (pCon->num < 5) {
			if (pCon->num == 0) {
				pCon->array[0] = value;
			}
			else {
				int i = 4;
				for (; i >= 0 && pCon->array[i] == 0; i--);
				pCon->array[i + 1] = value;
				int j = i;
				for (; j >= 0 && pCon->array[j] == 2; j--);
				if (j != i) {
					swap(pCon->array[i + 1], pCon->array[j + 1]);
				}
			}
			pCon->num++;
		}
		else {
			int flag = 0;
			if (pCon->array[0] == 1) {
				return true;
			}
			else {
				pCon->array[0] = 1;
			}
		}
	}
	else {
		if (pCon->num == 5) {
			if (pCon->array[0] == 2) {
				return true;
			}
			else {
				if (pCon->array[4] == 1) {
					pCon->array[4] = value;
				}
				else {
					int i = 0;
					for (; i < 5 && pCon->array[i] == 1; i++);
					pCon->array[i - 1] = value;
				}

			}
		}
		else {
			if (pCon->num == 0) {
				pCon->array[0] = value;
			}
			else {
				int i = 4;
				for (; i >= 0 && pCon->array[i] == 0; i--);
				pCon->array[i + 1] = value;
			}
			pCon->num++;
		}
	}

}


void print(Container_T* pCon) {
	if (pCon == NULL)return;
	for (int i = 0; i < 5; i++)
	{
		cout << pCon->array[i] << " ";
	}
	cout << endl;
}

int main()
{
	Container_T* pCon = new Container_T();
	for (int i = 0; i < 5; i++)pCon->array[i] = 0;
	print(pCon);

	insertNumberToContainer(1, pCon);
	print(pCon);

	insertNumberToContainer(2, pCon);
	print(pCon);

	insertNumberToContainer(1, pCon);
	print(pCon);

	insertNumberToContainer(1, pCon);
	print(pCon);

	insertNumberToContainer(1, pCon);
	print(pCon);

	insertNumberToContainer(2, pCon);
	print(pCon);

	return 0;
}
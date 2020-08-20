#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct point {
	int x, y;
	point(){}
	point(int x, int y) :x(x), y(y) {}
};

class box {
	point left_top;
	point right_bottom;

public:
	box(point x, point y) {
		left_top = x;
		right_bottom = y;
	}

	int area() {
		return (right_bottom.y - left_top.y) * (right_bottom.x - right_bottom.x);
	}

	int getWidth() {
		return min(right_bottom.y - left_top.y, right_bottom.x - right_bottom.x);
	}
	int getHeight() {
		return max(right_bottom.y - left_top.y, right_bottom.x - right_bottom.x);
	}

	vector<point> getCorner()
	{
		point left_bottom(left_top.x, right_bottom.y);
		point right_top(right_bottom.x, left_top.y);
		return {left_top, right_top, right_bottom, left_bottom};
	}

	bool isCollision(box& box2) {
		int x1 = left_top.x;
		int y1 = left_top.y;
		int x2 = right_bottom.x;
		int y2 = right_bottom.y;

		int x3 = box2.left_top.x;
		int y3 = box2.left_top.y;
		int x4 = box2.right_bottom.x;
		int y4 = box2.right_bottom.y;
		return (((x1 >= x3 && x1 < x4) || (x3 >= x1 && x3 <= x2)) && 
			((y1 >= y3 && y1 < y4) || (y3 >= y1 && y3 <= y2))) ? true : false;
	}
};

int main()
{
	return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


#define PI 3.141
#define CON_DEG 180 / PI /* convert statement to degrees = (statement) * 180 / pi */


typedef long double LD;

struct Point
{
	int x;
	int y;
	bool z = false;
	friend std::ostream &operator<<(std::ostream &, Point);
	friend bool operator==(const Point &_point1, const Point &_point2);
};

bool operator==(const Point &_point1, const Point &_point2)
{
	if (_point1.x == _point2.x && _point1.y == _point2.y)
	{
		return true;
	}
	return false;
}

std::ostream &operator<<(std::ostream &out, Point a)
{
	out << "corner = (" << a.x << "," << a.y << "," << a.z << ")\n";
	return out;
}

void jarvisInitCorner(std::vector<Point> &p)
{
	Point top{};
	int index{0};
	for (unsigned int i = 0; i <= p.size(); i++)
	{
		if (top.x < p[i].x && p[i].x < 1000)
		{
			index = i;
			top = p[i];
		}
	}
	if (index)
	{
		p[index].z = true;
		std::swap(p[0], p[index]);
	}
}

double pythagorean(const Point &a, const Point &b)
{
	double pyt = std::sqrt(std::pow((std::abs(a.x - b.x)), 2) +
						   std::pow((std::abs(a.y - b.y)), 2));
	return pyt;
}

LD arcCos(const LD a, const LD b, const LD c)
{
	LD angle = std::acos((b * b + c * c - a * a) / (2.0 * b * c));

	return angle * 57.3;
}

void jarvisCornerDetection(std::vector<Point> &p)
{
	LD x{0.0};
	int index{0};
	for (unsigned int i = 0; i < p.size(); i++)
	{
		if (p[i].z)
		{
			for (unsigned int j = 0; j < p.size(); j++)
			{
				if (!(p[j] == p[i]))
				{
					for (unsigned int k = 0; k < p.size(); k++)
					{
						if (!(p[i] == p[k]) && !(p[j] == p[k]))
						{

							if (x <= arcCos(pythagorean(p[j], p[k]),
											pythagorean(p[i], p[j]),
											pythagorean(p[i], p[k])))
							{
								x = arcCos(pythagorean(p[j], p[k]),
										   pythagorean(p[i], p[j]),
										   pythagorean(p[i], p[k]));
								index = k;
							}
						}
					}
				}
				x = 0;
				p[index].z = true;
			}
		}
	}
}



int main()
{

	std::vector<Point> points{
		{55, 320}, {200, 200}, {162, 420}, {226, 100}, {300, 50}, {153, 50}, {300, 300}, {349, 36}, {27, 413}};


			jarvisInitCorner(points);
			jarvisCornerDetection(points);

			std::cout << "-------------CORNERS-------------\n";
			for (auto i : points)
			{
				std::cout << i << "\n";
			}

	return 0;
}
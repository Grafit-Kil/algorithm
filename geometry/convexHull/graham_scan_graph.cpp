/*

compile : 
 g++ -lX11 -o jarvis_algorithm jarvis_algorithm.cpp 

*/


/*-----------------------------------------------------------------------------
Jarvis Algorihm => How to find the most inclusive convex in a set of points?

Step 1:
	Selecting a point to settle on this convex line.
	(max(y) point for this algorithm)

	example chart

	Y
	-------------------------------------------------------------
	|          point this(S point)--> *                         |
	|                *      *                                   |
	|                             *                             |
	|                                   *                       |
	|                   *                                       |
	|       *                                                   |
	|                             *                             |
	|                                          *                |
	|         *                  *                              |
	-------------------------------------------------------------X

Step 2:
	S point + selecting two respectively points and
	calculating the distances in the created triangle.
	> Please see pythagorean theorem

	example chart

	Y
	-------------------------------------------------------------
	|         point this(S point)-->  *                         |
	|                *      *                                   |
	|                             *                             |
	|                                   *                       |
	|              -->  *                                       |
	|       *                                                   |
	|                             *                             |
	|                                          *                |
	|         *             -->  *                              |
	-------------------------------------------------------------X

Step 3:
	The largest S angle is found for the triangles created
	The point(S) is stored in a vector.
	It is passed to the other point for the largest angle found and
	the operations are repeated for the new (S).

	Example Chart

	Y
	-------------------------------------------------------------
	|                old S point -->                            |
	|                *      *                                   |
	|                             *                             |
	|                                   *                       |
	|  New S point -->  *                                       |
	|       *                                                   |
	|                             *                             |
	|                                          *                |
	|         *                  *                              |
	-------------------------------------------------------------X

Step 4:
	Result =>
	The vector created is a set of convex points.

-----------------------------------------------------------------------------*/

#include <X11/Xlib.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <cmath>
#include <iomanip>
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

	return angle * CON_DEG;
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
				std::cout << p[index] << "\n";
				p[index].z = true;
			}
		}
	}
}

/* ----------------------- Draw --------------------- */
void drawBasePoints(Display *dis, Window &win, int scr, const std::vector<Point> &p)
{
	const char *msg = "-";
	for (unsigned int i = 0; i <= p.size(); i++)
	{
		// XDrawPoint(dis, win, DefaultGC(dis, scr), p[i].x, p[i].y);
		XDrawString(dis, win, DefaultGC(dis, scr), p[i].x, p[i].y, msg, strlen(msg));
	}
}

void drawBaseLines(Display *dis, Window &win, int scr, const std::vector<Point> &p)
{
	//int true_index{0};
	const char *msg = "+";
	for (unsigned int i = 0; i < p.size(); i++)
	{
		if (p[i].z)
		{
			// XDrawLine(dis, win, DefaultGC(dis, scr), p[true_index].x, p[true_index].y, p[i].x, p[i].y);
			XDrawString(dis, win, DefaultGC(dis, scr), p[i].x, p[i].y, msg, strlen(msg));
			//true_index = i;
		}
	}
}

int main()
{

	std::vector<Point> points{
		{55, 320}, {200, 200}, {162, 420},
		{226, 100}, {300, 50}, {153, 50},
		{300, 300}, {349, 36}, {27, 413}};

	Display *d;
	Window w;
	XEvent e;
	int s;

	d = XOpenDisplay(NULL);

	s = DefaultScreen(d);

	w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, 500, 500, 1,
							BlackPixel(d, s), WhitePixel(d, s));

	XSelectInput(d, w, ExposureMask | KeyPressMask);

	XMapWindow(d, w);
	std::vector<Point> convex_corner{};
	while (1)
	{
		XNextEvent(d, &e);
		if (e.type == Expose)
		{
			jarvisInitCorner(points);
			jarvisCornerDetection(points);

			std::cout << "-------------CORNERS-------------\n";
			for (auto i : points)
			{
				std::cout << i << "\n";
			}
		}

		if (e.type == KeyPress)
		{
			drawBasePoints(d, w, s, points);
			drawBaseLines(d, w, s, points);
		}

		if (e.xkey.keycode == 0x09)
		{
			break;
		}
	}

	XCloseDisplay(d);
}

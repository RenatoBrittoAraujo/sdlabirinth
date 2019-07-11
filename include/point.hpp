#ifndef POINT_HPP
#define POINT_HPP

class Point
{
public:

	Point();
	~Point();

	Point(float x, float y);

	float getX();
	float getY();
	void setX(float x);
	void setY(float y);

	float euclidianDistance(Point &other);

private:

	float _x, _y;

};

#endif
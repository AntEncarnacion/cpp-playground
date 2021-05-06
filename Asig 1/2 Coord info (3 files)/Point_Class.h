#pragma once
class Punto
{
private:
	int x1;
	int x2;
	int y1;
	int y2;

public:
	Punto();
	Punto(int, int, int, int);
	~Punto();
	void setX(int, int);
	void setY(int, int);

	int getX1() const;
	int getX2() const;
	int getY1() const;
	int getY2() const;
	double getDistance() const;
	void display() const;
};
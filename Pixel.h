// Written by Syed Hammad Ahmed
// OOP@DSU Fall 2015
// YOU MAY NOT MODIFY THIS FILE WITHOUT DISCUSSING WITH ME

#ifndef PIXEL_H
#define PIXEL_H

#include <string>
using namespace std;

class Pixel{
	private:
		int r;
		int g;
		int b;
	public:
		Pixel();  // sets default pixel to white
		int getR();
		int getG();
		int getB();
		void setR(int r);
		void setG(int g);
		void setB(int b);
		void setValues(int r, int g, int b);
};

#endif


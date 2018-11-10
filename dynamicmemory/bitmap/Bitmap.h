#pragma once

#ifndef __BITMAP_H__
#define __BITMAP_H__
/*
this is header for bitmap 

author: Hongbo Li		Jiang Li
date:	11/6/2018
*/



#include <iostream>
#include "color.h"
#include <string>



class Bitmap
{
public:
	Bitmap();
	Bitmap(int x, int y);
	~Bitmap();
	//draw shapes
	void point( Color a);
	void line(int w, int x, int y, int z, Color color);
	void horizLine(int x1, int x2, int y, Color a);
	void vertLine(int y1, int y2, int x, Color a);
	void drawRect(int x, int y, int w, int h, Color a);
	void ellipse(int xc, int yc, int a, int b, Color color);
	void roundRect(int w, int x, int y, int z,int a, const uint32_t color);
	void polygon(int w, int x, int y, int z, const uint32_t color);
	void bezier(int w, int x, int y, int z, int a, int b, int c, int d, const uint32_t color);
	void triangle(int w, int x, int y, int z, int a, int b, const uint32_t color);
	void gouraudTriangle(int w, int x, const uint32_t color1, int y, int z, const uint32_t color2, int a, int b, const uint32_t color3);
	// fill
	void fillEllipse(int w, int x, int y, int z, const uint32_t color);
	void fillRect(int w, int x, int y, int z, Color a);
	void fillPolygon(int w, int x, int y, int z, const uint32_t color);
	void fill(int w, int x, const uint32_t color);
	void fillTriangle(int w, int x, int y, int z, int a, int b, const uint32_t color);
	friend std::ostream &operator << (std::ostream & os, Bitmap& dt);
	//noob cout
	void noob(Color** Image_Martix);
	
private:
	int w, x, y, z, a, b, c;
	Color **Image_Martix;
};


#endif // !__BITMAP_H__

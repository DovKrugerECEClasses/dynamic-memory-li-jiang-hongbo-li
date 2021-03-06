// Bitmap.cpp : Defines the entry point for the console application.
/*
this is the progream for bitmap realization

author: Hongbo Li		Jiang Li
date:	11/6/2018
*/

#include <iostream>
#include "Bitmap.h"
#include "color.h"

extern int col = 0, raw = 0;


//bitmap class functions
Bitmap::Bitmap()
{
}

Bitmap::Bitmap(int x, int y)
{
	this->x = x;
	raw = x;
	this->y = y;
	col = y;
	Image_Martix = new Color *[y];
	
	for (int i = 0; i < y; i++)
	{
		Image_Martix[i] = new Color [x];
	}
}

Bitmap::~Bitmap()
{
	if (Image_Martix != NULL)
	{
		for (int i = 0; i < y; i++)
		{
			delete[] Image_Martix[i];
		}
		delete[]Image_Martix;
	}
}

#if 0 
void Bitmap::noob(Color** Image_Martix)
{
	for (int i = 0; i < 20; i++)
		if (Image_Martix[i][2].r)
		{
			std::cout << Image_Martix[i][2];
		}
	
}
#endif
std::ostream &operator << (std::ostream & os, Bitmap& dt)
{	
	for (int j = 0; j < col; j++)
	{
		for (int i = 0; i < raw; i++)
		{
			if (dt.Image_Martix[j][i].r == 255 && dt.Image_Martix[j][i].g == 0 && dt.Image_Martix[j][i].b == 0)
			{
				os << "R";
			}
			else if (dt.Image_Martix[j][i].g == 255 && dt.Image_Martix[j][i].r == 0 && dt.Image_Martix[j][i].b == 0)
			{
				os << "G";
			}
			else if (dt.Image_Martix[j][i].b == 255 && dt.Image_Martix[j][i].r == 0 && dt.Image_Martix[j][i].g == 0)
			{
				os << "B";
			}
			else if (dt.Image_Martix[j][i].g == 255 && dt.Image_Martix[j][i].r == 255 && dt.Image_Martix[j][i].b == 255)
			{
				os << "w";
			}
			else if (dt.Image_Martix[j][i].g == 0 && dt.Image_Martix[j][i].r == 0 && dt.Image_Martix[j][i].b ==0)
			{
				os << "L";
			}
			else
			{
				os << " ";
			}
		}
		os << "\n";
	}
	
	return os;
}

int main() {
	Bitmap b(30, 20); // 30 pixels across, 20 pixels high, each pixel RGBA
					  // top left pixel = (0,0)
	Color RED(255, 0, 0); // all red, no green, no blue (fully opaque)
	Color BLUE(0, 255, 0);
	Color GREEN(0, 0, 255);
	Color WHITE(255, 255, 255);
	Color BLACK(0, 0, 0);
 
	b.line(0, 0, 19, 19, RED);
	b.line(0, 5, 29, 10, BLUE); //Bresenham algorithm
								//https://en.wikipedia.org/wiki/Bresenham's_line_algorithm

								// https://en.wikipedia.org/wiki/Xiaolin_Wu%27s_line_algorithm
								//TODO: b.line(0,100, 100,50, BLUE); //Wu algorithm

	b.horizLine(0, 20,19, GREEN); // from x=0 to x=20 at y=19
	b.vertLine(5, 0, 19, GREEN); // from y = 0 to y=19 at x = 5
	b.fillRect(10, 10, 4, 3, BLACK); // x = 10, y =10 w=4, h=3
	b.drawRect(10, 10, 4, 3, WHITE); // x = 10, y =10 w=4, h=3

	b.ellipse(15, 0, 8, 5, RED);    // ellipse centered at (15,0) w= 8, h=5
	std::cout << b;
	system("pause");
	/*
	R
	R
	R
	R
	R
	BBB	
	BBBBB
	BBBBBB
	*/

}

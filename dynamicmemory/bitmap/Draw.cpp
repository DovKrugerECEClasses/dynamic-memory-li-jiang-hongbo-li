/*
this is the progream for drawing shape

author: Hongbo Li		Jiang Li 
date:	11/6/2018
*/

#include "Draw.h"
#include "color.h"

extern int col;
extern int raw;

void Bitmap::line(int x1, int y1, int x2, int y2, Color color) 
{
	
		int dx, dy;
		if (x1>x2) {
			dx = x1 - x2;
		}
		else {
			dx = x2 - x1;
		}
		if (y1>y2) {
			dy = y1 - y2;
		}
		else {
			dy = y2 - y1;
		}
		int count = 0;
		int j = y1;
		int xielv = dx / dy;
		for (int i = x1; i <= x2; i++) {
			if (count >= xielv) {
				j++;
				count = 0;
			}
			count++;
			Image_Martix[j][i] = color;
		}
	Image_Martix[5][5].r;
}

void Bitmap::horizLine(int x1, int x2, int y, Color a) {
	for (int i = x1; i <= x2; i++) {
		Image_Martix[y][i] = a;
	}
}

void Bitmap::point(Color a) {
	for(int i =0 ; i <raw ;i++)
		for (int j = 0; j < col; j++)
		{
			Image_Martix[j][i] = a;
		}


	
}

void Bitmap::vertLine(int x, int y1, int y2, Color a) {
	for (int i = y1; i <= y2; i++) {
		Image_Martix[i][x] = a;
	}
}
void Bitmap::drawRect(int x, int y, int w, int h, Color a)
{
	for (int i = 0; i<w; i++) {
		Image_Martix[x + i][y] = a;
		Image_Martix[x + i][y + h] = a;
	}
	for (int j = 0; j<=h; j++) {
		Image_Martix[x][y + j] = a;
		Image_Martix[x + w][y + j] = a;
	}
}
void Bitmap::ellipse(int xc, int yc, int a, int b, Color color)
{
	int sqa = a * a;
	int sqb = b * b;
	int d = sqb + sqa * (-b + 0.25);
	int x1 = 0;
	int x2 = 0;
	int y = b;
	//Image_Martix[yc + y][xc + x] = color;
	while (sqb * (x1 + 1) < sqa * (y - 0.5)) {
		if (d < 0) {
			d += sqb * (2 * x1 + 3);
		}
		else {
			d += (sqb * (2 * x1 + 3) + sqa * (-2 * y + 2));
			y--;
		}
		x1++;
		x2--;
		Image_Martix[yc + y][xc + x1] = color;
		Image_Martix[yc + y][xc + x2] = color;
	}
	d = (b * (x1 + 0.5)) * 2 + (a * (y - 1)) * 2 - (a * b) * 2;
	while (y > 0 || x2 > 0) {
		if (d < 0) {
			d += sqb * (2 * x1 + 2) + sqa * (-2 * y + 3);
			x1++;
			x2--;
		}
		else {
			d += sqa * (-2 * y + 3);
		}
		y--;
		Image_Martix[yc + y][xc + x1] = color;
		Image_Martix[yc + y][xc + x2] = color;
	}
}
void Bitmap::roundRect(int w, int x, int y, int z, int a, const uint32_t color)
{

}
void Bitmap::polygon(int w, int x, int y, int z, const uint32_t color)
{

}
void Bitmap::bezier(int w, int x, int y, int z, int a, int b, int c, int d, const uint32_t color)
{

}
void Bitmap::triangle(int w, int x, int y, int z, int a, int b, const uint32_t color)
{

}
void Bitmap::gouraudTriangle(int w, int x, const uint32_t color1, int y, int z, const uint32_t color2, int a, int b, const uint32_t color3)
{

}
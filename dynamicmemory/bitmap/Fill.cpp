/*
this is the progream for bitmap realization

author: Hongbo Li		Jiang Li
date:	11/6/2018
*/


#include "Fill.h"

void Bitmap::fill(int w, int x, const uint32_t color)
{

}
void Bitmap::fillEllipse(int w, int x, int y, int z, const uint32_t color)
{

}
void Bitmap::fillRect(int x, int y, int w, int h, Color a)
{
	for (int i = 0; i<w; i++) 
	{
		for (int j = 0; j<h; j++) 
		{
			Image_Martix[x + i][y + j] = a;
		}
	}
}

void Bitmap::fillPolygon(int w, int x, int y, int z, const uint32_t color)
{

}

void Bitmap::fillTriangle(int w, int x, int y, int z, int a, int b, const uint32_t color)
{

}
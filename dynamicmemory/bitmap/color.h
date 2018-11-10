#pragma once


#include <iostream>

class Color {
private:
	uint32_t rgba;
	
public:
	//variables
	
	uint32_t r;
	uint32_t g;
	uint32_t b;
	//function

	Color()
	{

	}
	Color(uint8_t r, uint8_t b, uint8_t g): r(r),g(g),b(b)
	{
		this->r = r;
		this->g = g;
		this->b = b;
	}
	
	Color(uint8_t r, uint8_t g, uint8_t b, uint8_t alpha)
	{

	}

};
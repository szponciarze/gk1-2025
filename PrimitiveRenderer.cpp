#include "PrimitiveRenderer.h"
#include<iostream>
#include<SDL.h>

//Rysuje pixel
void PrimitiveRenderer::putPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b) {
	if (!renderer)
		return;

	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	SDL_RenderDrawPoint(renderer, x, y);
}
//Rysuje linie algorytmem przyrostowym
void PrimitiveRenderer::incrementalAlgorithm(int x1, int y1, int x2, int y2, Uint8 r, Uint8 b, Uint8 g) {
	if (!renderer)
		return;
	int x;
	float dy, dx, m;

	

	dy = y2 - y1;
	dx = x2 - x1;

	//unikniecie dzielenia przez zero
	if (dx == 0 && dy == 0) {
		putPixel(x1, y1, r, g, b);
		return;
	}

	if (x1 > x2) {
		std::swap(x1, x2);
		std::swap(y1, y2);
		dx = x2 - x1;
		dy = y2 - y1;
	
	}


	m = dy / dx;


	// m <= 1
	if (std::fabs(m) <= 1.0f) {
		float y = static_cast<float>(y1);
		for (x = x1; x <= x2; ++x) {
			putPixel(x, static_cast<int>(std::round(y)), r, g, b);
			y += m;
		}
	
	}
	// m > 1
	else {
		if (y1 > y2) {
			std::swap(x1, x2);
			std::swap(y1, y2);
			dx = x2 - x1;
			dy = y2 - y1;
		}
		float invM = dx / dy;
		float x = static_cast<float>(x1);

		for (int y = y1; x <= y2; ++y) {
			putPixel(y, static_cast<int>(std::round(x)), r, g, b);
			x += invM;
		}

	}
	

}

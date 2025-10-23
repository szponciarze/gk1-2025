#include "PrimitiveRenderer.h"
#include<iostream>
#include<SDL.h>

//Rysuje pixel
void PrimitiveRenderer::putPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b) {
	if (!surface)
		return;
	if (x < 0 || y < 0 || x > surface->w || y >surface->h)
		return;

	Uint32* pixels = (Uint32*)surface->pixels;
	Uint32 color = SDL_MapRGB(surface->format, r, g, b);
	pixels[(y * surface->w) + x] = color;

}
//Rysuje linie algorytmem przyrostowym
void PrimitiveRenderer::incrementalAlgorithm(int x1, int y1, int x2, int y2, Uint8 r, Uint8 b, Uint8 g) {
	int x;
	float dy, dx, y, m;

	dy = y2 - y1;
	dx = x2 - x1;
	m = dy / dx;
	y = y1;

	for (x = x1; x <= x2; x++) {
		putPixel(x, (int)(y + 0.5), r, g, b);
		y += m;
	}

}

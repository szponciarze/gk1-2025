#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include "LineSegment.h"
#include <algorithm>
#include <iostream>
#include <SDL.h>
#include <vector>
#include <cmath> 

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
// Rysuje pusty prostok¹t
void PrimitiveRenderer::drawRect(int x, int y, int w, int h, Uint8 r, Uint8 g, Uint8 b) {
	if (!renderer) return;
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	SDL_Rect rect = { x, y, w, h };
	SDL_RenderDrawRect(renderer, &rect);
}

// Rysuje wype³niony prostok¹t
void PrimitiveRenderer::fillRect(int x, int y, int w, int h, Uint8 r, Uint8 g, Uint8 b) {
	if (!renderer) return;
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	SDL_Rect rect = { x, y, w, h };
	SDL_RenderFillRect(renderer, &rect);
}

// Rysuje pusty okr¹g (Bresenham)
void PrimitiveRenderer::drawCircle(int cx, int cy, int radius, Uint8 r, Uint8 g, Uint8 b) {
	if (!renderer) return;
	int x = radius;
	int y = 0;
	int decisionOver2 = 1 - x;

	while (y <= x) {
		putPixel(cx + x, cy + y, r, g, b);
		putPixel(cx + y, cy + x, r, g, b);
		putPixel(cx - x, cy + y, r, g, b);
		putPixel(cx - y, cy + x, r, g, b);
		putPixel(cx - x, cy - y, r, g, b);
		putPixel(cx - y, cy - x, r, g, b);
		putPixel(cx + x, cy - y, r, g, b);
		putPixel(cx + y, cy - x, r, g, b);
		y++;
		if (decisionOver2 <= 0) decisionOver2 += 2 * y + 1;
		else { x--; decisionOver2 += 2 * (y - x) + 1; }
	}
}

// Rysuje wype³niony okr¹g
void PrimitiveRenderer::fillCircle(int cx, int cy, int radius, Uint8 r, Uint8 g, Uint8 b) {
	if (!renderer) return;
	for (int y = -radius; y <= radius; y++) {
		for (int x = -radius; x <= radius; x++) {
			if (x * x + y * y <= radius * radius) {
				putPixel(cx + x, cy + y, r, g, b);
			}
		}
	}
}
//Rysuje pust¹ elipsê
void PrimitiveRenderer::drawEllipse(int cx, int cy, int Rx, int Ry, Uint8 r, Uint8 g, Uint8 b) {
	if (!renderer) return;

	for (float alpha = 0.0f; alpha < M_PI/2; alpha += 0.01f) {
		int x = static_cast<int>(Rx * cos(alpha));
		int y = static_cast<int>(Ry * sin(alpha));

		putPixel(cx + x, cy + y, r, g, b);
		putPixel(cx - x, cy + y, r, g, b);
		putPixel(cx + x, cy - y, r, g, b);
		putPixel(cx - x, cy - y, r, g, b);
	}
}
//Rysuje wype³nion¹ elipsê
void PrimitiveRenderer::fillEllipse(int cx, int cy, int Rx, int Ry, Uint8 r, Uint8 g, Uint8 b) {
	if (!renderer) return;

	for (float alpha = 0.0f; alpha < M_PI / 2; alpha += 0.01f) {
		int x = static_cast<int>(Rx * cos(alpha));
		int y = static_cast<int>(Ry * sin(alpha));

		for (int dx = 0; dx <= x; dx++) {
			putPixel(cx + dx, cy + y, r, g, b);
			putPixel(cx - dx, cy + y, r, g, b);
			putPixel(cx + dx, cy - y, r, g, b);
			putPixel(cx - dx, cy - y, r, g, b);

		}
	}
}
void PrimitiveRenderer::drawPolyline(const std::vector<Point2D>& points, Uint8 r, Uint8 g, Uint8 b, bool closed) {
	if (points.size() < 2) return;
	for (size_t i = 0; i < points.size() - 1; ++i) {

		incrementalAlgorithm(points[i].getX(), points[i].getY(),
			points[i + 1].getX(), points[i + 1].getY(),
			r, g, b);
	}
	if (closed) {
		incrementalAlgorithm(points.back().getX(), points.back().getY(),
			points.front().getX(), points.front().getY(),
			r, g, b);
	}
}

// Linie ³amane po odcinkach
void PrimitiveRenderer::drawPolyline(const std::vector<LineSegment>& segments, Uint8 r, Uint8 g, Uint8 b) {
	for (const auto& seg : segments) {
		incrementalAlgorithm(seg.getFirst().getX(), seg.getFirst().getY(),
			seg.getLast().getX(), seg.getLast().getY(),
			r, g, b);
	}
}
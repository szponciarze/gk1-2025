#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include "LineSegment.h"
#include <algorithm>
#include <iostream>
#include <SDL.h>
#include <vector>
#include <cmath> 
#include <stack>

//Rysuje pixel
void PrimitiveRenderer::putPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b) {
	if (!renderer)
		return;

	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	SDL_RenderDrawPoint(renderer, x, y);
}

bool PrimitiveRenderer::getPixel(int x, int y, Uint8& r, Uint8& g, Uint8& b)
{
	if (!renderer) return false;


	// poza ekran -> nie ruszaj
	int w, h;
	SDL_GetRendererOutputSize(renderer, &w, &h);
	if (x < 0 || y < 0 || x >= w || y >= h) return false;

	Uint32 pixel = 0;
	SDL_Rect rect = { x, y, 1, 1 };

	if (SDL_RenderReadPixels(renderer, &rect, SDL_PIXELFORMAT_RGBA8888, &pixel, sizeof(pixel)) != 0)
		return false;

	SDL_PixelFormat* fmt = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);
	SDL_GetRGB(pixel, fmt, &r, &g, &b);
	SDL_FreeFormat(fmt);

	return true;
}

//Rysuje linie algorytmem przyrostowym
void PrimitiveRenderer::incrementalAlgorithm(int x1, int y1, int x2, int y2,
	Uint8 r, Uint8 g, Uint8 b)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	
	//dlugosc odcinka
	int dx = x2 - x1;
	int dy = y2 - y1;

	float m;

	if (dx != 0) {
		m = (float)dy / (float)dx;
	}
	else { // pionowa linia
		if (y1 <= y2)
			for (int y = y1; y <= y2; ++y)
				SDL_RenderDrawPoint(renderer, x1, y);
		else
			for (int y = y2; y <= y1; ++y)
				SDL_RenderDrawPoint(renderer, x1, y);
		return;
	}

	// m<= 1 
	if (fabs(m) <= 1.0f) {

		if (x1 > x2) { 
			std::swap(x1, x2);
			std::swap(y1, y2); 
		}

		float y = (float)y1;
		for (int x = x1; x <= x2; x++) {

			SDL_RenderDrawPoint(renderer, x, (int)round(y));
			y += m; // m = dy/dx
		}
	}

	//  m > 1 
	else {

		if (y1 > y2) { 
			std::swap(y1, y2); 
			std::swap(x1, x2); 
		}

		float inv_m = (float)dx / (float)dy;

		float x = (float)x1;
		for (int y = y1; y <= y2; y++) {

			SDL_RenderDrawPoint(renderer, (int)round(x), y);

			//1/m = dx/dy
			x += inv_m;
		}
	}
}
// Rysuje pusty prostokat
void PrimitiveRenderer::drawRect(int x, int y, int w, int h, Uint8 r, Uint8 g, Uint8 b) {
	if (!renderer) return;
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	SDL_Rect rect = { x, y, w, h };
	SDL_RenderDrawRect(renderer, &rect);
}

// Rysuje wypelniony prostokat
void PrimitiveRenderer::fillRect(int x, int y, int w, int h, Uint8 r, Uint8 g, Uint8 b) {
	if (!renderer) return;
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	SDL_Rect rect = { x, y, w, h };
	SDL_RenderFillRect(renderer, &rect);
}

// Rysuje pusty okrag (Bresenham)
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

// Rysuje wypelniony okrag
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
//Rysuje pusta elipse
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
//Rysuje wypelniona elipse
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

// Linie lamane po odcinkach
void PrimitiveRenderer::drawPolyline(const std::vector<LineSegment>& segments, Uint8 r, Uint8 g, Uint8 b) {
	for (const auto& seg : segments) {
		incrementalAlgorithm(seg.getFirst().getX(), seg.getFirst().getY(),
			seg.getLast().getX(), seg.getLast().getY(),
			r, g, b);
	}
}

//Metoda pomocnicza, zwraca indeks pixelu 
static inline int pixelIndex(int x, int y, int width) {
	return y * width + x;
}


//Metoda wype³niaj¹ca floodFill
void PrimitiveRenderer::floodFill(SDL_Texture* targetTexture, int textureWidth, int textureHeight, int startX, int startY, Uint8 newR, Uint8 newG, Uint8 newB)
{
	if (!renderer || !targetTexture) return;
	if (startX < 0 || startY < 0 || startX >= textureWidth || startY >= textureHeight) return;

	
	SDL_Texture* oldTarget = SDL_GetRenderTarget(renderer);
	SDL_SetRenderTarget(renderer, targetTexture);

	//Bufor pixeli 
	std::vector<Uint32> pixels(textureWidth * textureHeight);
	if (SDL_RenderReadPixels(renderer, NULL, SDL_PIXELFORMAT_RGBA8888, pixels.data(), textureWidth * sizeof(Uint32)) != 0) {
		//Jezeli blad - przywroc stara texture i wyjdz
		SDL_SetRenderTarget(renderer, oldTarget);
		return;
	}

	//Przygotuj format do mapowania kolorów
	SDL_PixelFormat* fmt = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);
	if (!fmt) {
		SDL_SetRenderTarget(renderer, oldTarget);
		return;
	}

	//Pobranie koloru bazowego
	Uint32 idx = pixels[pixelIndex(startX, startY, textureWidth)];
	Uint8 baseR, baseG, baseB, baseA;
	SDL_GetRGBA(idx, fmt, &baseR, &baseG, &baseB, &baseA);

	//Jezeli kolor bazowy == kolor ktorym chcemy wypelnic - nie robimy nic
	if (baseR == newR && baseG == newG && baseB == newB) {
		SDL_FreeFormat(fmt);
		SDL_SetRenderTarget(renderer, oldTarget);
		return;
	}

	std::stack<std::pair<int, int>> st;
	st.push(std::make_pair(startX, startY));

	//Glowna petla floodFill
	while (!st.empty()) {
		auto p = st.top(); st.pop();
		int cx = p.first;
		int cy = p.second;

		if (cx < 0 || cy < 0 || cx >= textureWidth || cy >= textureHeight) continue;

		int i = pixelIndex(cx, cy, textureWidth);
		Uint32 cur = pixels[i];
		Uint8 r, g, b, a;
		SDL_GetRGBA(cur, fmt, &r, &g, &b, &a);

		if (r == baseR && g == baseG && b == baseB) {
			//Jezeli kolor pobranego pixelu==kolor bazowy, zmien kolor na nowy i zapisz
			Uint32 newPixel = SDL_MapRGBA(fmt, newR, newG, newB, 255);
			pixels[i] = newPixel;

			st.push(std::make_pair(cx + 1, cy));
			st.push(std::make_pair(cx - 1, cy));
			st.push(std::make_pair(cx, cy + 1));
			st.push(std::make_pair(cx, cy - 1));
		}
	}

	//Aktualizacja textury
	SDL_UpdateTexture(targetTexture, NULL, pixels.data(), textureWidth * sizeof(Uint32));

	SDL_FreeFormat(fmt);
	SDL_SetRenderTarget(renderer, oldTarget);
}

void PrimitiveRenderer::borderFill(SDL_Texture* targetTexture, int textureWidth, int textureHeight, int startX, int startY, Uint8 borderR, Uint8 borderG, Uint8 borderB, Uint8 fillR, Uint8 fillG, Uint8 fillB)
{
	if (!renderer || !targetTexture) return;
	if (startX < 0 || startY < 0 || startX >= textureWidth || startY >= textureHeight) return;

	SDL_Texture* oldTarget = SDL_GetRenderTarget(renderer);
	SDL_SetRenderTarget(renderer, targetTexture);

	std::vector<Uint32> pixels(textureWidth * textureHeight);
	if (SDL_RenderReadPixels(renderer, NULL, SDL_PIXELFORMAT_RGBA8888, pixels.data(), textureWidth * sizeof(Uint32)) != 0) {
		//Jezeli blad - przywroc stara texture i wyjdz
		SDL_SetRenderTarget(renderer, oldTarget);
		return;
	}

	SDL_PixelFormat* fmt = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);
	if (!fmt) { 
		//Jezeli blad - przywroc stara texture i wyjdz
		SDL_SetRenderTarget(renderer, oldTarget); 
		return; 
	}

	
	Uint32 borderPixel = SDL_MapRGBA(fmt, borderR, borderG, borderB, 255);
	Uint32 fillPixel = SDL_MapRGBA(fmt, fillR, fillG, fillB, 255);

	std::stack<std::pair<int, int>> st;
	st.push(std::make_pair(startX, startY));

	//Glowna petla borderFill
	while (!st.empty()) {
		auto p = st.top(); st.pop();
		int cx = p.first;
		int cy = p.second;

		if (cx < 0 || cy < 0 || cx >= textureWidth || cy >= textureHeight) continue;

		int i = pixelIndex(cx, cy, textureWidth);
		Uint32 cur = pixels[i];

		//Jezeli obecny piksel jest borderem albo juz wypelniony - pomijamy
		if (cur == borderPixel || cur == fillPixel) 
			continue;

		//Wypelniamy kolorem
		pixels[i] = fillPixel;

		st.push(std::make_pair(cx + 1, cy));
		st.push(std::make_pair(cx - 1, cy));
		st.push(std::make_pair(cx, cy + 1));
		st.push(std::make_pair(cx, cy - 1));
	}
	//Aktualizacja textury
	SDL_UpdateTexture(targetTexture, NULL, pixels.data(), textureWidth * sizeof(Uint32));
	SDL_FreeFormat(fmt);
	SDL_SetRenderTarget(renderer, oldTarget);
}
/**
* @file PrimitiveRenderer.h
* @brief Klasa odpowiedzialna za rysowanie prostych prymitywów oraz algorytmy wype³niania.
*/
#pragma once
#include<iostream>
#include<SDL.h>
#include<fstream>
#include<cmath>
#include <vector>


class Point2D;
class LineSegment;

/**
* @class primitiveRenderer
* @brief Renderer rysuj¹cy prymitywy.
*/
class PrimitiveRenderer {

private:
	/**
	* @brief Renderer SDL odpowiedzialny za rysowanie.
	*/
	SDL_Renderer* renderer;

public:
	/**
	* @brief Konstruktor klasy.
	* 
	* @param renderer WskaŸnik na renderer SDL.
	*/
	PrimitiveRenderer(SDL_Renderer* renderer) :renderer(renderer) {}

	/**
	* @param x Pozycja X piksela.
	* @param y Pozycja Y piksela.
	* @param r Kolor czerwony.
	* @param g Kolor zielony.
	* @param b Kolor niebieski.
	*/
	bool getPixel(int x, int y, Uint8& r, Uint8& g, Uint8& b);
	/**
	* @brief Rysuje pojedynczy piksel.
	* @param x Pozycja X piksela.
	* @param y Pozycja Y piksela.
	* @param r Kolor czerwony.
	* @param g Kolor zielony.
	* @param b Kolor niebieski.	
	*/
	void putPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b);
	/**
	* @brief Rysuje liniê algorytmem przyrostowym.
	* 
	* @param x1 Pozycja X punktu pocz¹tkowego.
    * @param y1 Pozycja Y punktu pocz¹tkowego.
    * @param x2 Pozycja X punktu koñcowego.
    * @param y2 Pozycja Y punktu koñcowego.
    * @param r Kolor czerwony.
    * @param g Kolor zielony.
    * @param b Kolor niebieski.
	*/
	void incrementalAlgorithm(int x1, int y1, int x2, int y2, Uint8 r, Uint8 g, Uint8 b);
	/**
	* @brief Rysuje prostok¹t.
	* @param x Pozycja X.
	* @param y Pozycja Y.
	* @param width Szerokoœæ prostok¹ta.
	* @param height Wysokoœæ prostok¹ta.
	* @param r Kolor czerwony.
    * @param g Kolor zielony.
    * @param b Kolor niebieski.
	*/
	void drawRect(int x, int y, int width, int height, Uint8 r, Uint8 g, Uint8 b);
	/**
	* @brief Rysuje wype³niony prostok¹t.
	* @param x Pozycja X.
	* @param y Pozycja Y.
	* @param width Szerokoœæ wype³nionego prostok¹ta.
	* @param height Wysokoœæ wype³nionego prostok¹ta.
	* @param r Kolor czerwony.
	* @param g Kolor zielony.
	* @param b Kolor niebieski.
	*/
	void fillRect(int x, int y, int width, int height, Uint8 r, Uint8 g, Uint8 b);
	/**
	* @brief Rysuje okr¹g.
	* @param cx Pozycja X œrodka okrêgu.
	* @param cy Pozycja Y œrodka okrêdu.
	* @param radius Przek¹tna okrêgu.
	* @param r Kolor czerwony.
	* @param g Kolor zielony.
	* @param b Kolor niebieski.
	*/
	void drawCircle(int cx, int cy, int radius, Uint8 r, Uint8 g, Uint8 b);
	/**
	* @brief Rysuje wype³niony okr¹g.
	* @param cx Pozycja X œrodka okrêgu.
	* @param cy Pozycja Y œrodka okrêdu.
	* @param radius Przek¹tna wype³nionego okrêgu.
	* @param r Kolor czerwony.
	* @param g Kolor zielony.
	* @param b Kolor niebieski.
	*/
	void fillCircle(int cx, int cy, int radius, Uint8 r, Uint8 g, Uint8 b);
	/**
	* @brief Rysuje elipsê.
	* @param cx Pozycja X œrodka elipsy.
	* @param cy Pozycja Y œrodka elipsy.
	* @param Rx Pó³ oœ w pozycji X.
	* @param Ry Pó³ oœ w pozycji Y.
	* @param r Kolor czerwony.
	* @param g Kolor zielony.
	* @param b Kolor niebieski.
	*/
	void drawEllipse(int cx, int cy, int Rx, int Ry, Uint8 r, Uint8 g, Uint8 b);
	/**
	* @brief Rysuje wype³nion¹ elipsê.
	* @param cx Pozycja X œrodka elipsy.
	* @param cy Pozycja Y œrodka elipsy.
	* @param Rx Pó³ oœ w pozycji X.
	* @param Ry Pó³ oœ w pozycji Y.
	* @param r Kolor czerwony.
	* @param g Kolor zielony.
	* @param b Kolor niebieski.
	*/
	void fillEllipse(int cx, int cy, int Rx, int Ry, Uint8 r, Uint8 g, Uint8 b);
	/**
	* @brief Rysuje linie ³amane po punktach.
	* 
	* @param points Punkty linii.
	* @param r Kolor czerwony.
	* @param g Kolor zielony.
	* @param b Kolor niebieski.
	* @param closed Czy zamkniêta (domyœlnie fa³sz).
	*/
	void drawPolyline(const std::vector<Point2D>& points, Uint8 r, Uint8 g, Uint8 b, bool closed = false);
	/**
	* @brief Rysuje linie ³amane po liniach.
	*
	* @param segments Linie.
	* @param r Kolor czerwony.
	* @param g Kolor zielony.
	* @param b Kolor niebieski.
	*/
	void drawPolyline(const std::vector<LineSegment>& segments, Uint8 r, Uint8 g, Uint8 b);
	/**
	* @brief Metoda wype³niania kolorem Flood Fill.
	*
	* @param targetTexture Tekstura na której wykonywane jest wype³nianie.
	* @param textureWidth Szerokoœæ.
	* @param textureHeight Wysokoœæ.
	* @param startX Punkt startowy X.
	* @param startY Punkt startowy Y.
	* @param newR Kolor czerwony.
	* @param newG Kolor zielony.
	* @param newB Kolor niebieski.
	*/
	void floodFill(SDL_Texture* targetTexture, int textureWidth, int textureHeight, int startX, int startY, Uint8 newR, Uint8 newG, Uint8 newB);
	/**
	* @brief Metoda wype³niania kolorem Border Fill.
	*
	* @param targetTexture Tekstura na której wykonywane jest wype³nianie.
	* @param textureWidth Szerokoœæ.
	* @param textureHeight Wysokoœæ.
	* @param startX Punkt startowy X.
	* @param startY Punkt startowy Y.
	* @param borderR Kolor czerwony granicy.
	* @param borderG Kolor zielony granicy.
	* @param borderB Kolor niebieski granicy.
	* @param fillR Kolor czerwony.
	* @param fillG Kolor zielony.
	* @param fillB Kolor niebieski.
	*/
	void borderFill(SDL_Texture* targetTexture, int textureWidth, int textureHeight, int startX, int startY,Uint8 borderR, Uint8 borderG, Uint8 borderB, Uint8 fillR, Uint8 fillG, Uint8 fillB);


};
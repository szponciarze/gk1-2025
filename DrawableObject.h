/**
 * @file DrawableObject.h
 * @brief Deklaracja klasy bazowej dla obiektów gry, które mo¿na rysowaæ na ekranie.
 */
#pragma once
#include "GameObject.h"
#include <SDL.H>
 /**
  * @class DrawableObject
  * @brief Bazowa klasa dla wszystkich obiektów gry obs³uguj¹cych rysowanie.
  */
class DrawableObject : public virtual GameObject {
public:
	/**
	 * @brief Konstruktor.
	 */
	DrawableObject();
	/**
	 * @brief Wirtualny destruktor klasy DrawableObject.
	 */
	virtual ~DrawableObject();
	/**
	* @brief Metoda rysuj¹ca obiekt na ekranie.
	*
	* @param renderer WskaŸnik na SDL_Renderer u¿ywany do renderowania obiektu.
	*/
	virtual void draw(SDL_Renderer* renderer);
};
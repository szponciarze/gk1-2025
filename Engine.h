/**
* @file Engine.h
* @brief G³ówna klasa odpowiedzialna za renderowanie,
* obs³ugê zdarzeñ oraz zarz¹dzanie obiektami.
*/
#pragma once
#include<iostream>
#include<SDL.h>
#include<fstream>
#include<vector>

class PrimitiveRenderer;
/**
* @class Engine
* @brief G³owna klasa silnika
* 
* Klasa odpowiada za tworzenie okna, rendererów, obs³ugê buforowania
* renderowanie obiektów, obs³ugê myszy i klawiatury. Zawiera
* g³ówn¹ pêtle gry.
*/
class Engine {
private:
	/**
	* @brief WskaŸnik na okno SDL.
	*/
	SDL_Window* window;
	/**
	* @brief Renderer SDL odpowiedzialny za rysowanie.
	*/
	SDL_Renderer* render;
	/**
	* @brief Wektor wykorzystywany do buforowania.
	*/
	std::vector<SDL_Texture*> buffers; 

	int currentBuffer = 0;
	int bufferCount = 2; // domyslnie podwojne buforowanie
	/**
	* @brief Tryb pe³noekranowy.
	*/
	bool Fullscreen;
	/**
	* @brief Flaga okreœlaj¹ca dzia³anie programu.
	*/
	bool isRunning;
	/**
	* @brief Szerokoœæ okna.
	*/
	int width;
	/**
	* @brief Wysokoœæ okna.
	*/
	int height;
	/**
	* @brief Flaga okreœlaj¹ca czy mysz jest aktywna.
	*/
	bool mouseOn;
	/**
	* @brief Flaga okreœlaj¹ca czy klawiatura jest aktywna.
	*/
	bool keyboardOn;
	/**
	* @brief Docelowa iloœæ klatek.
	*/
	int targetFPS;
	/**
	* @brief OpóŸnienie miêdzy klatkami.
	*/
	Uint32 frameDelay;
	/**
	* @brief Czas rozpoczêcia klatki.
	*/
	Uint32 frameStart;
	/**
	* @brief Czas klatki.
	*/
	Uint32 frameTime;
	/**
	* @brief Czas ostatniej klatki.
	*/
	Uint32 lastTime;
	/**
	* @brief Strumieñ do logowania b³êdów i komunikatów.
	*/
	std::ofstream logFile;
	/**
	* @brief Wybrany tryb rysowania kszta³tów.
	*/
	int shapeChoice;
	/**
	* @brief Wybrany tryb transformacji.
	*/
	int updateChoice;
	/**
	* @brief Wybrany tryb wypelnienia.
	*/
	int fillChoice;
	/**
	* @brief Flaga okreœlaj¹ca czy nale¿y u¿yæ wype³nienia borderFill.
	*/
	bool executeBorderFill = false;
	/**
	* @brief Flaga okreœlaj¹ca czy nale¿y u¿yæ wype³nienia floodFill.
	*/
	bool executeFloodFill = false;
	/**
	* @brief Pozycje startowe dla wype³nieñ:
	*        b_fillX, b_fillY – pocz¹tek wype³nienia border fill,
	*        f_fillX, f_fillY – pocz¹tek wype³nienia flood fill.
	*/
	int b_fillX, b_fillY, f_fillX, f_fillY;

public:
	/**
	* @brief Inicjalizuje ca³y silnik.
	* 
	* @param windowtitle Tytu³ okna.
	* @param x Pozycja X okna.
	* @param y Pozycja Y okna.
	* @param width Szerokoœæ okna.
	* @param height Wysokoœæ okna.
	* @param Fullscreen Tryb pe³noekranowy.
	* @param mouseOn Flaga do uruchamiania myszy.
	* @param keyboardOn Flaga do uruchamiania klawiatury.
	* @param targetFPS Docelowa liczba klatek.
	* @param bufferCounter Iloœæ buforów (domyœlnie 2).
	* 
	* @return true Jeœli wszystko siê powiod³o, false w przeciwnym wypadku.
	*/
	bool init(const std::string& windowtitle, int x, int y, int width, int height, bool Fullscreen, bool mouseOn, bool keyboardOn, int targetFPS, int bufferCount);
	/**
	* @brief G³ówna pêtla gry.
	*/
	void mainLoop();
	/**
	* @brief Czyszczenie ekranu do zadanego koloru.
	* 
	* @param r Kolor czerwony.
	* @param g Kolor zielony.
	* @param b Kolor niebieski.
	*/
	void clearScreen(Uint8 r, Uint8 g, Uint8 b);
	/**
	* @brief Logowanie b³êdów lub komunikatów do pliku.
	* 
	* @param message Tekst komunikatu.
	*/
	void logError(const std::string& message);
	/**
	* @brief Czyœci wszystkie zasoby.
	*/
	void clean();
	/**
	* @brief Rysuje jedn¹ klatkê.
	*/
	void renderFrame();

};


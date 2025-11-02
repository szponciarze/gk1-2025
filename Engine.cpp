#include "Engine.h"
#include"PrimitiveRenderer.h"
#include"Point2D.h"
#include"LineSegment.h"
#include<iostream>
#include<SDL.h>
#include<string>


//Inicjalizacja biblioteki graficznej
bool Engine::init(const std::string& windowtitle, int x, int y, int width, int height, bool Fullscreen, bool mouseOn, bool keyboardOn, int targetFPS, int bufferCount) {


	//zapisywanie bledow do pliku
	logFile.open("logFile.txt", std::ios::out | std::ios::app);
	if (!logFile) {
		std::cerr << "Nie mozna otworzyc pliku do zapisu bledow." << std::endl;
		return false;
	}


	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS) != 0) {
		logError("SDL Init error:" + std::string(SDL_GetError()));
		return false;
	}

	this->width = width;
	this->height = height;
	this->Fullscreen = Fullscreen;
	this->mouseOn = mouseOn;
	this->keyboardOn = keyboardOn;
	this->targetFPS = targetFPS;
	this->frameDelay = 1000 / targetFPS;
	this->bufferCount = (bufferCount < 2) ? 2 : 3; 
	this->currentBuffer = 0;

	Uint32 flags = Fullscreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN;
	window = SDL_CreateWindow(windowtitle.c_str(), x, y, width, height, flags);

	if (!window) {
		logError("SDL Window error:" + std::string(SDL_GetError()));
		return false;
	}

	//tworzenie rendereru
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!render) {
		logError("SDL Renderer error: " + std::string(SDL_GetError()));
		return false;
	}


	// tworzymy bufory (tekstury docelowe)
	for (int i = 0; i < this->bufferCount; ++i) {
		SDL_Texture* buffer = SDL_CreateTexture(render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);
		if (!buffer) {
			logError("Buffer number: " + std::to_string(i) + " error: " + SDL_GetError());
			return false;
		}
		buffers.push_back(buffer);
	}


	isRunning = true;
	return true;
}


//Glowna petla gry
void Engine::mainLoop() {
	SDL_Event e;

	while (isRunning) {
		frameStart = SDL_GetTicks();

		while (SDL_PollEvent(&e)) {	//Obsluga zdarzen
			if (e.type == SDL_QUIT)
				isRunning = false;

			if (keyboardOn && e.type == SDL_KEYDOWN) {
				std::cout << "Nacisnieto klawisz: " << SDL_GetKeyName(e.key.keysym.sym) << std::endl;
			}


			if (mouseOn && e.type == SDL_MOUSEBUTTONDOWN) {
				std::cout << "Nacisnieto klawisz myszy w: (" << e.button.x << "," << e.button.y << ")" << std::endl;
			}
		}

		renderFrame();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)	//Czasomierz
			SDL_Delay(frameDelay - frameTime);
	}

	clean();

}

//zapisywanie bledow do pliku
void Engine::logError(const std::string& message) {
	if (logFile.is_open()) {

		logFile << message << std::endl;

	}

	std::cerr << message << std::endl;


}

//czyszczenie ekranu
void Engine::clearScreen(Uint8 r, Uint8 g, Uint8 b) {
	SDL_SetRenderDrawColor(render, r, g, b, 255);
	SDL_RenderClear(render);
}

void Engine::renderFrame() {
	// ustawienie renderowania do aktualnego bufora
	SDL_SetRenderTarget(render, buffers[currentBuffer]);

	// czyszczenie bufora kolorem tla
	clearScreen(80, 80, 120);

	// rysowanie sceny
	PrimitiveRenderer renderer(render);
	Point2D point1(50, 150);
	Point2D point2(400, 500);
	LineSegment line(point1, point2);
	renderer.incrementalAlgorithm(100, 50, 400, 100, 255, 255, 255); // biala linia
	line.draw(renderer, 255, 0, 0);

	// Dodatkowe prymitywy do testow
	renderer.incrementalAlgorithm(50, 50, 200, 100, 255, 0, 0);
	renderer.incrementalAlgorithm(50, 100, 200, 50, 0, 255, 0);
	// Niebieski pusty prostokat
	renderer.drawRect(300, 100, 100, 50, 0, 0, 255);
	// Zolty pelny prostokat
	renderer.fillRect(300, 200, 100, 50, 255, 255, 0);
	// Fioletowe puste kolo
	renderer.drawCircle(600, 100, 50, 255, 0, 255);
	// Blekitne wypelnione kolo
	renderer.fillCircle(600, 200, 50, 0, 255, 255);
	// Zielona pusta elipsa
	renderer.drawEllipse(600, 300, 20, 40, 0, 255, 0);
	// Czerwona wypelniona elipsa
	renderer.fillEllipse(600, 400, 20, 40, 255, 0, 0);

	// --- LINIE LAMANE ---
	std::vector<Point2D> polylinePoints = {
		Point2D(50, 400),
		Point2D(150, 450),
		Point2D(250, 400),
		Point2D(350, 450)
	};
	renderer.drawPolyline(polylinePoints, 255, 128, 0, false); // otwarta
	renderer.drawPolyline(polylinePoints, 0, 255, 255, true);  // zamknięta


	renderer.drawRect(100, 300, 200, 100, 0, 0, 0);
	renderer.fillRect(450, 200, 150, 120, 255, 255, 0);


	renderer.borderFill(buffers[currentBuffer], width, height,150, 350, 0, 0, 0,255, 255, 255);


	//renderer.floodFill(buffers[currentBuffer], width, height,320, 230, 255, 255, 255);

	// przelaczenie na ekran
	SDL_SetRenderTarget(render, nullptr);
	SDL_RenderCopy(render, buffers[currentBuffer], nullptr, nullptr);
	SDL_RenderPresent(render);

	// przejscie do nastepnego bufora (2 lub 3)
	currentBuffer = (currentBuffer + 1) % bufferCount;
}


//zamkniecie gry
void Engine::clean() {
	for (auto& buf : buffers)
		SDL_DestroyTexture(buf);
	buffers.clear();

	if (render) 
		SDL_DestroyRenderer(render);

	if (window)
		SDL_DestroyWindow(window);

	SDL_Quit();

	if (logFile.is_open()) {
		logFile << "Silnik poprawnie zamknieto. \n" << std::endl;
		logFile.close();
	}

	std::cout << "Silnik zamkniety, zasoby zwolnione" << std::endl;
}



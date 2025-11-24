#include "Engine.h"
#include "PrimitiveRenderer.h"
#include "RectangleFilled.h"
#include "Circle.h"
#include "Point2D.h"
#include "LineSegment.h"
#include "GameObject.h"
#include "CircleFilled.h"
#include "DrawableObject.h"
#include "TransformableObject.h"
#include "UpdatableObject.h"
#include "Rectangle.h"
#include <vector>
#include <iostream>
#include <SDL.h>
#include <string>
#include "Ellipse.h"
#include "EllipseFilled.h"
#include "Polyline.h"
#include "Line.h"
#include "Player.h" 
#include "Bitmap.h" 


Player* player = new Player(200, 150, 64, 64); // Wymiary pasujace do sprite'ow
Rectangle* rect = new Rectangle(150, 100, 200, 150, 255, 0, 0);
RectangleFilled* rectfill = new RectangleFilled(150, 100, 200, 150, 255, 255, 255);
Circle* circle = new Circle(50, 50, 10, 255, 255, 255);
CircleFilled* circlefill = new CircleFilled(75, 75, 50, 125, 125, 125);
Ellipse* ellipse = new Ellipse(400, 300, 80, 30, 255, 255, 0);
EllipseFilled* ellipsefill = new EllipseFilled(600, 300, 40, 80, 0, 255, 255);
Polyline* polyline = new Polyline({ {100,100},{200,200},{300,120},{350,180} }, 255, 128, 0);
Line* line = new Line(100, 300, 500, 350, 255, 255, 0);

// BitmapHandler jest teraz uzywany przez BitmapObject i jego pochodne
BitmapHandler bitmapHandler;

std::vector<ShapeObject*> shapeObjects;
std::vector<UpdatableObject*> updatableObjects;


bool Engine::init(const std::string& windowtitle, int x, int y, int width, int height, bool Fullscreen, bool mouseOn, bool keyboardOn, int targetFPS, int bufferCount) {

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

    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!render) {
        logError("SDL Renderer error: " + std::string(SDL_GetError()));
        return false;
    }

    for (int i = 0; i < this->bufferCount; ++i) {
        SDL_Texture* buffer = SDL_CreateTexture(render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);
        if (!buffer) {
            logError("Buffer number: " + std::to_string(i) + " error: " + SDL_GetError());
            return false;
        }
        buffers.push_back(buffer);
    }

    //ANIMACJE
    // Ladowanie wszystkich 16 klatek animacji
    std::vector<std::string> directions = { "down", "up", "left", "right" };
    for (const auto& dir : directions) {
        for (int i = 0; i < 4; ++i) {
            std::string id = "hero_" + dir + "_" + std::to_string(i);
            std::string filePath = "sprites/" + id + ".bmp";
            if (!bitmapHandler.loadBitmap(render, id, filePath)) {
                logError("Nie udalo sie zaladowac bitmapy: " + filePath);
                
            }
        }
    }
    

    isRunning = true;
    this->lastTime = SDL_GetTicks();
    return true;
}

//Glowna petla gry
void Engine::mainLoop() {
    SDL_Event e;
    shapeObjects.push_back(rect);
    updatableObjects.push_back(rect);
    shapeObjects.push_back(rectfill);
    updatableObjects.push_back(rectfill);
    shapeObjects.push_back(circle);
    updatableObjects.push_back(circle);
    shapeObjects.push_back(circlefill);
    updatableObjects.push_back(circlefill);
    shapeObjects.push_back(ellipse);
    updatableObjects.push_back(ellipse);
    shapeObjects.push_back(ellipsefill);
    updatableObjects.push_back(ellipsefill);
    shapeObjects.push_back(polyline);
    updatableObjects.push_back(polyline);
    shapeObjects.push_back(line);
    updatableObjects.push_back(line);

    // Dodajemy gracza do obu wektorow, poniewaz jest zarowno rysowalny, jak i aktualizowalny
    shapeObjects.push_back(player);
    updatableObjects.push_back(player);

    while (isRunning) {
        frameStart = SDL_GetTicks();
        Uint32 currentTime = SDL_GetTicks();
        float dt = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;
        if (dt > 0.05f) {
            dt = 0.05f;
        }

        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)
                isRunning = false;

            if (keyboardOn && e.type == SDL_KEYDOWN) {
                // To można zostawic do debugowania, ale glowna obsluga klawiatury jest w Player
                 std::cout << "Nacisnieto klawisz: " << SDL_GetKeyName(e.key.keysym.sym) << std::endl;
            }

            if (mouseOn && e.type == SDL_MOUSEBUTTONDOWN) {
                std::cout << "Nacisnieto klawisz myszy w: (" << e.button.x << "," << e.button.y << ")" << std::endl;
            }
        }

        // Aktualizacja wszystkich obiektow z uwzglednieniem czasu klatki
        for (auto& obj : updatableObjects) {
            obj->update(dt);
        }

        renderFrame();

        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
            SDL_Delay(frameDelay - frameTime);
    }
    clean();
}

void Engine::logError(const std::string& message) {
    if (logFile.is_open()) {
        logFile << message << std::endl;
    }
    std::cerr << message << std::endl;
}

void Engine::clearScreen(Uint8 r, Uint8 g, Uint8 b) {
    SDL_SetRenderDrawColor(render, r, g, b, 255);
    SDL_RenderClear(render);
}

void Engine::renderFrame() {
    SDL_SetRenderTarget(render, buffers[currentBuffer]);

    clearScreen(80, 80, 120);


    // Rysowanie wszystkich obiektow
    for (auto obj : shapeObjects) {
        obj->draw(render); // Player zostanie narysowany w tej petli
    }

    SDL_SetRenderTarget(render, nullptr);
    SDL_RenderCopy(render, buffers[currentBuffer], nullptr, nullptr);
    SDL_RenderPresent(render);

    currentBuffer = (currentBuffer + 1) % bufferCount;
}

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

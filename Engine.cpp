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
ShapeObject* selectedShape = nullptr;
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
    /*
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
    shapeObjects.push_back(player);
    updatableObjects.push_back(player);
    */

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

            //if (!shapeObjects.empty()) {
            //    selectedShape = shapeObjects.back(); 
           // }

            if (keyboardOn && e.type == SDL_KEYDOWN) {
                 std::cout << "Nacisnieto klawisz: " << SDL_GetKeyName(e.key.keysym.sym) << std::endl;
            }
            //WYBOR KSZTALTU//
            if (keyboardOn && e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_1) {
                std::cout << "Wybrano opcje rysowania prostokatu! Nacisnij w dowolne miejsce na ekranie" << std::endl;
                shapeChoice = 1;
            }
            if (keyboardOn && e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_2) {
                std::cout << "Wybrano opcje rysowania kola! Nacisnij w dowolne miejsce na ekranie" << std::endl;
                shapeChoice = 2;
            }
            if (keyboardOn && e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_3) {
                std::cout << "Wybrano opcje rysowania elipsy! Nacisnij w dowolne miejsce na ekranie" << std::endl;
                shapeChoice = 3;
            }
            if (keyboardOn && e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_4) {
                std::cout << "Wybrano opcje rysowania wypelnionego kola! Nacisnij w dowolne miejsce na ekranie" << std::endl;
                shapeChoice = 4;
            }
            if (keyboardOn && e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_5) {
                std::cout << "Wybrano opcje rysowania wypelnionej elipsy! Nacisnij w dowolne miejsce na ekranie" << std::endl;
                shapeChoice = 5;
            }
            if (keyboardOn && e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_6) {
                std::cout << "Wybrano opcje rysowania wypelnionego prostokata! Nacisnij w dowolne miejsce na ekranie" << std::endl;
                shapeChoice = 6;
            }
            if (keyboardOn && e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_7) {
                std::cout << "Wybrano opcje rysowania linii! Nacisnij w dowolne miejsce na ekranie" << std::endl;
                shapeChoice = 7;
            }
            if (keyboardOn && e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_8) {
                std::cout << "Wybrano opcje rysowania polyline! Nacisnij w dowolne miejsce na ekranie" << std::endl;
                shapeChoice = 8;
            }
            if (keyboardOn && e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_0) {
                std::cout << "Tryb rysowania wylaczony!" << std::endl;
                shapeChoice = 0;
            }
            //KONIEC WYBORU KSZTALTU
            //WYBOR TRANSFORMACJI
            if (keyboardOn && e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_t) {
                shapeChoice = 0;
                std::cout << "Tryb translacji!" << std::endl;
                updateChoice = 1;
            }

            if (keyboardOn && e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_r) {
                shapeChoice = 0;
                std::cout << "Tryb rotacji!" << std::endl;
                updateChoice = 2;
            }

            if (keyboardOn && e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_y) {
                shapeChoice = 0;
                std::cout << "Tryb skalowania!" << std::endl;
                updateChoice = 3;
            }

            if (keyboardOn && e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_e) {
                shapeChoice = 0;
                std::cout << "Tryb czuwania!" << std::endl;
                updateChoice = 0;
            }

            if (keyboardOn && e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_p) {
                std::cout << "Tryb wyboru obiektu! Kliknij w obiekt myszą\n";
                shapeChoice = 99; 
            }
            //KONIEC WYBORU TRANSFORMACJI
            //WYBIERANIE OBIEKTU DO TRANSFORMACJI
            if (mouseOn && e.type == SDL_MOUSEBUTTONDOWN && shapeChoice==99) {
                int mx = e.button.x;
                int my = e.button.y;

                if (!shapeObjects.empty()) {
                    for (int i = shapeObjects.size() - 1; i >= 0; i--) {
                        std::cout << "Obiekt " << i << ": x=" << shapeObjects[i]->getX()<< ", y=" << shapeObjects[i]->getY() << std::endl;
                        if (shapeObjects[i]->containsPoint(mx, my)) {
                            selectedShape = shapeObjects[i];
                            std::cout << "Wybrano obiekt!\n";
                            shapeChoice = 0;
                            break;
                        }
                    }
                }
            }
            //KONIEC WYBORU OBIEKTU DO TRANSFORMACJI


            
            if (mouseOn && e.type == SDL_MOUSEBUTTONDOWN) {
                std::cout << "Nacisnieto klawisz myszy w: (" << e.button.x << "," << e.button.y << ")" << std::endl;
                //SWITCH DO RYSOWANIA KSZTALTOW
                switch (shapeChoice) {
                case 0: {
                    break;
                }
                case 1: {
                    Rectangle* rectangle2 = new Rectangle(e.button.x, e.button.y, 200, 150, 0, 0, 0);
                    shapeObjects.push_back(rectangle2);
                    updatableObjects.push_back(rectangle2);
                    break;
                }
                case 2: {
                    Circle* circle2 = new Circle(e.button.x, e.button.y, 10, 0, 0, 0);
                    shapeObjects.push_back(circle2);
                    updatableObjects.push_back(circle2);
                    break;
                }
                case 3: {
                    Ellipse* ellipse2 = new Ellipse(e.button.x, e.button.y, 20, 30, 0, 0, 0);
                    shapeObjects.push_back(ellipse2);
                    updatableObjects.push_back(ellipse2);
                    break;
                }
                case 4: {
                    CircleFilled* circlefill2 = new CircleFilled(e.button.x, e.button.y, 50, 125, 125, 125);
                    shapeObjects.push_back(circlefill2);
                    updatableObjects.push_back(circlefill2);
                    break;
                }
                case 5: {
                    EllipseFilled* ellipsefill2 = new EllipseFilled(e.button.x, e.button.y, 40, 80, 0, 255, 255);
                    shapeObjects.push_back(ellipsefill2);
                    updatableObjects.push_back(ellipsefill2);
                    break;
                }
                case 6: {
                    RectangleFilled* rectanglefill2 = new RectangleFilled(e.button.x, e.button.y, 200, 150, 255, 255, 255);
                    shapeObjects.push_back(rectanglefill2);
                    updatableObjects.push_back(rectanglefill2);
                    break;
                }
                case 7: {
                    Line* line2 = new Line(e.button.x, e.button.y, e.button.x + 100, e.button.y, 255, 0, 0);
                    shapeObjects.push_back(line2);
                    updatableObjects.push_back(line2);
                    break;
                }
                case 8: {
                    std::vector<SDL_FPoint> pos = {
                    {static_cast<float>(e.button.x), static_cast<float>(e.button.y)},
                    {static_cast<float>(e.button.x + 50), static_cast<float>(e.button.y + 30)},
                    {static_cast<float>(e.button.x + 100), static_cast<float>(e.button.y)}
                    };
                    Polyline* polyline2 = new Polyline(pos, 0, 255, 0);                    
                    shapeObjects.push_back(polyline2);
                    updatableObjects.push_back(polyline2);
                    break;
                }
                default: 
                    break;
                }
                //KONIEC
               }

            if (mouseOn&& e.type == SDL_MOUSEMOTION && selectedShape != nullptr && updateChoice != 0) {
                int dx = e.motion.xrel;
                int dy = e.motion.yrel;

                switch (updateChoice) {
                case 1: {
                    selectedShape->translate(dx, dy);
                    break;
                }
                case 2: {
                    selectedShape->rotate(dx);
                    break;
                }
                case 3: {
                    selectedShape->scale(1.0f + dx * 0.01f, 1.0f + dy * 0.01f);
                    break;
                }
                case 0: 
                    break;
                default:
                    break;
                }
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

    for (auto obj : shapeObjects)
        delete obj;
    shapeObjects.clear();
    updatableObjects.clear();

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


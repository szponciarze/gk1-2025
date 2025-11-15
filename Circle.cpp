#pragma once
#include "Circle.h"
#include"PrimitiveRenderer.h"
#include <SDL.h>


    Circle::Circle(float cx, float cy, float radius, Uint8 r, Uint8 g, Uint8 b)//konstruktor
        : cx(cx), cy(cy), radius(radius), r(r), g(g), b(b) {
    }

    void Circle::translate(float dx, float dy){//przesuniecie kola
        cx+=dx;
        cy+=dy;
    }

    void Circle::rotate(float angle){
        //obrot kola nic nie wnosi
    }

    void Circle::scale(float sx, float sy) {//skalowanie kola
        radius*=(sx+sy)/2.0f;
    }

    void Circle::draw(SDL_Renderer* renderer) {//glowna metoda - rysowanie kola(algorytm Bresenhama)
        if (!renderer) return;
        int x=radius;
        int y=0;
        int decisionOver2=1-x;

        while (y<=x) {
            //rysowanie 8 symetrycznych punktow
            SDL_SetRenderDrawColor(renderer,r,g,b,255);
            SDL_RenderDrawPoint(renderer,cx+x,cy+y);
            SDL_RenderDrawPoint(renderer,cx+y,cy+x);
            SDL_RenderDrawPoint(renderer,cx-x,cy+y);
            SDL_RenderDrawPoint(renderer,cx-y,cy+x);
            SDL_RenderDrawPoint(renderer,cx-x,cy-y);
            SDL_RenderDrawPoint(renderer,cx-y,cy-x);
            SDL_RenderDrawPoint(renderer,cx+x,cy-y);
            SDL_RenderDrawPoint(renderer,cx+y,cy-x);

            y++;
            if (decisionOver2<=0)
                decisionOver2 += 2*y+1;
            else {
                x--;
                decisionOver2 += 2*(y-x)+1;
            }
        }
    }

    void Circle::update(float dt) {
        //przesuwanie kola w dol
        translate(0,50.0f*dt);
    }

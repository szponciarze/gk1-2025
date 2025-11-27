#pragma once
#include "Circle.h"
#include"PrimitiveRenderer.h"
#include <SDL.h>


    Circle::Circle(float x, float y, float radius, Uint8 r, Uint8 g, Uint8 b)
        : ShapeObject(x, y, 0, 0), radius(radius), r(r), g(g), b(b) {
    }

    void Circle::translate(float dx, float dy){//przesuniecie kola
        m_x+=dx;
        m_y+=dy;
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
            SDL_RenderDrawPoint(renderer,m_x+x,m_y+y);
            SDL_RenderDrawPoint(renderer,m_x+y,m_y+x);
            SDL_RenderDrawPoint(renderer,m_x-x,m_y+y);
            SDL_RenderDrawPoint(renderer,m_x-y,m_y+x);
            SDL_RenderDrawPoint(renderer,m_x-x,m_y-y);
            SDL_RenderDrawPoint(renderer,m_x-y,m_y-x);
            SDL_RenderDrawPoint(renderer,m_x+x,m_y-y);
            SDL_RenderDrawPoint(renderer,m_x+y,m_y-x);

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
       // translate(0,50.0f*dt);
    }
    bool Circle::containsPoint(float px, float py) {
        float dx = px - m_x;
        float dy = py - m_y;
        return dx * dx + dy * dy <= radius * radius;
    }

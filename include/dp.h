#ifndef DP_H
#define DP_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cmath>
#include <sstream>
#define ll long long

const ll width = 800, height = 600, upper = 20;
const float PI = 3.14159, G = 9.81, cl1 = 200, cl2 = 200, cm1 = 4, cm2 = 4, ca1 = 60 *PI/180, ca2 = 90 *PI/180;

class Pendul {
public:
    float len, mass, angle, vel = 0, acc = 0, x, y;
    //length [m]
    //mass [g]
    //angle [deg]
    //vel [m/s]
    //acc [m/ss]
    Pendul(float l, float m, float a);
};

class Pend : public sf::Sprite {
    sf::RenderTexture textr;
    sf::CircleShape pends[2];
    sf::Vertex va[3];
    sf::VertexArray trail;
    sf::VertexBuffer vb;
    sf::Font fnt;
    Pendul p1, p2;
    float time = 0.1;
    bool show = true, log = false;
public:
    Pend(Pendul p1, Pendul p2);
    void update();
    void render();
    void chshow();
    void chlog();
};

#endif
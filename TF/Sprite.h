#pragma once
using namespace std;
using namespace System;
using namespace System::Drawing;
#include <math.h>
class Sprite {
public:
	Sprite();
	~Sprite();
	int getX() { return x; }
	int getY() { return y; }
	void setDX(int _dx) { dx = _dx; }
	void setDY(int _dy) { dy = _dy; }
	int getDX() { return dx; }
	int getDY() { return dy; }
	int getVidas() { return contvidas; }
	Rectangle getRectangle();
	Rectangle getSigRectangle();
protected:
	int x, y, dx, dy;
	int ancho, alto;
	int  indiceX, indiceY;
	int contvidas;
	float escala;
};

Sprite::Sprite() {}
Sprite::~Sprite() {}
Rectangle Sprite::getRectangle() { return Rectangle(x, y, ancho * escala, alto * escala); }
Rectangle Sprite::getSigRectangle() { return Rectangle(x + dx, y + dy, ancho * escala, alto * escala); }
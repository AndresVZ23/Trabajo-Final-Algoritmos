#pragma once
using namespace std;
using namespace System;
using namespace System::Drawing;
#include <math.h>
class Sprite2 {
public:
	Sprite2();
	~Sprite2();
	void drawRectangle2(Graphics^ g);
	int getX2() { return x2; }
	int getY2() { return y2; }
	void setDX2(int _dx2) { dx2 = _dx2; }
	void setDY2(int _dy2) { dy2 = _dy2; }
	int getDX2() { return dx2; }
	int getDY2() { return dy2; }
	int getVidas2() { return contvidas2; }
	Rectangle getRectangle2();
	Rectangle getSigRectangle2();
protected:
	int x2, y2, dx2, dy2;
	int ancho2, alto2;
	int  indiceX2, indiceY2;
	int contvidas2;
	float escala2;
};

Sprite2::Sprite2() {}
Sprite2::~Sprite2() {}
void Sprite2::drawRectangle2(Graphics^ g) {
	g->DrawRectangle(gcnew Pen(Color::Blue, 5), x2, y2, int(ancho2 * escala2), int(alto2 * escala2));
}
Rectangle Sprite2::getRectangle2() { return Rectangle(x2, y2, ancho2 * escala2, alto2 * escala2); }
Rectangle Sprite2::getSigRectangle2() { return Rectangle(x2 + dx2, y2 + dy2, ancho2 * escala2, alto2 * escala2); }
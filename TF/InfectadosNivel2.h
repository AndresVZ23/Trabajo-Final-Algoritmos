#pragma once
#include"Sprite2.h"
class InfectadoNivel2 :public Sprite2 {
public:
	InfectadoNivel2(Graphics^ g);
	~InfectadoNivel2();
	void dibujar2(Graphics^ g);
	void mover2();
	void dejardemover2();
	void moverinverso(Graphics^ g);
	void perseguir2(int ex2, int ey2);
	void setdir2(int dx2, int dy2);
	bool moviminetoInvalido2(Graphics^ g);
	bool puedemover2;
private:
};

InfectadoNivel2::InfectadoNivel2(Graphics^ g) {
	Random r;
	Bitmap^ img2 = gcnew Bitmap("Infectado.png");
	alto2 = img2->Height / 4;
	ancho2 = img2->Width / 3;
	y2 = r.Next((int)g->VisibleClipBounds.Height - alto2);
	x2 = (int)g->VisibleClipBounds.Width - ancho2;
	dy2 = dx2 = 4;
	indiceY2 = indiceX2 = 0;
	escala2 = 0.9;
	delete img2;
}

InfectadoNivel2::~InfectadoNivel2() {}
void InfectadoNivel2::dibujar2(Graphics^ g) {
	if (dx2 < 0) {
		indiceY2 = 1;
	}
	else if (dx2 > 0) {
		indiceY2 = 2;
	}
	else if (dy2 > 0) {
		indiceY2 = 0;
	}
	else if (dy2 < 0) {
		indiceY2 = 3;
	}
	Bitmap^ img2 = gcnew Bitmap("Infectado.png");
	Rectangle molde2 = Rectangle(indiceX2 * ancho2, indiceY2 * alto2, ancho2, alto2);
	g->DrawImage(img2, getRectangle2(), molde2, GraphicsUnit::Pixel);
	indiceX2++;
	if (indiceX2 == 3)
		indiceX2 = 0;
	delete img2;
}
void InfectadoNivel2::mover2() {
	x2 += dx2;
	y2 += dy2;
}
void InfectadoNivel2::dejardemover2() {
	puedemover2 = false;
}
void InfectadoNivel2::moverinverso(Graphics^ g) {
	dy2 *= -1;
	dx2 *= -1;

	y2 += dy2;
	x2 += dx2;
}
void InfectadoNivel2::perseguir2(int ex2, int ey2) {
	if (puedemover2) {
		if (int(x2) < ex2) { dx2 = 5; }
		else if (int(x2) > ex2) { dx2 = -5; }
		else dx2 = 0;

		if (int(y2) < ey2) { dy2 = 5; }
		else if (int(y2) > ey2) { dy2 = -5; }
		else dy2 = 0;
	}
	else {
		dx2 = dy2 = 0;
	}
}
void InfectadoNivel2::setdir2(int dx2, int dy2) {
	this->dx2 = dx2;
	this->dy2 = dy2;
}

bool InfectadoNivel2::moviminetoInvalido2(Graphics^ g) {
	if (x2 + dx2 + ancho2 > g->VisibleClipBounds.Width)return true;
	return false;
}
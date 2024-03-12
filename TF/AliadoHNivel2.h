#pragma once
#include"Sprite2.h"
class AliadoHNivel2 :public Sprite2 {
public:
	AliadoHNivel2(Graphics^ g);
	~AliadoHNivel2();
	void dibujar2(Graphics^ g);
	void mover2(Graphics^ g);
	void moverinverso2(Graphics^ g);
	bool moviminetoInvalido2(Graphics^ g);
private:
};

AliadoHNivel2::AliadoHNivel2(Graphics^ g) {
	Bitmap^ img2 = gcnew Bitmap("AliadoH.png");
	alto2 = img2->Height / 4;
	ancho2 = img2->Width / 3;
	x2 = (int)g->VisibleClipBounds.Width - ancho2;
	y2 = (int)g->VisibleClipBounds.Height / 2;
	dy2 = dx2 = 10;
	indiceY2 = indiceX2 = 0;
	escala2 = 0.9;
	delete img2;
}

AliadoHNivel2::~AliadoHNivel2() {}
void AliadoHNivel2::dibujar2(Graphics^ g) {
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
	Bitmap^ img2 = gcnew Bitmap("AliadoH.png");
	Rectangle molde2 = Rectangle(indiceX2 * ancho2, indiceY2 * alto2, ancho2, alto2);
	g->DrawImage(img2, getRectangle2(), molde2, GraphicsUnit::Pixel);
	indiceX2++;
	if (indiceX2 == 3)
		indiceX2 = 0;
	delete img2;
}
void AliadoHNivel2::mover2(Graphics^ g) {
	indiceY2 = 0;
	indiceX2 = 0;
	if (y2 + dy2<0 || y2 + dy2 + alto2 > g->VisibleClipBounds.Height)dy2 *= -1;
	if (x2 + dx2<0 || x2 + dx2 + ancho2 > g->VisibleClipBounds.Width)dx2 *= -1;
	y2 += dy2;
	x2 += dx2;
}
void AliadoHNivel2::moverinverso2(Graphics^ g) {
	dy2 *= -1;
	dx2 *= -1;

	y2 += dy2;
	x2 += dx2;
}
bool AliadoHNivel2::moviminetoInvalido2(Graphics^ g) {
	if (y2 + dy2 + alto2 > g->VisibleClipBounds.Height)return true;
	return false;
}
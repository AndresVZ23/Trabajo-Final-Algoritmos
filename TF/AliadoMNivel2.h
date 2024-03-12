#pragma once
#include"Sprite2.h"
class AliadoMNivel2 :public Sprite2 {
public:
	AliadoMNivel2(Graphics^ g);
	~AliadoMNivel2();
	void dibujar2(Graphics^ g);
	void mover2(Graphics^ g);
	void moverinverso2(Graphics^ g);
	bool moviminetoInvalido2(Graphics^ g);
private:
};

AliadoMNivel2::AliadoMNivel2(Graphics^ g) {
	Random r;
	Bitmap^ img2 = gcnew Bitmap("AliadoM.png");
	alto2 = img2->Height / 4;
	ancho2 = img2->Width / 3;
	x2 = r.Next((int)g->VisibleClipBounds.Width - ancho2);
	y2 = (int)g->VisibleClipBounds.Height / 2;
	dy2 = dx2 = 3;
	indiceY2 = indiceX2 = 0;
	escala2 = 0.9;
	delete img2;
}

AliadoMNivel2::~AliadoMNivel2() {}
void AliadoMNivel2::dibujar2(Graphics^ g) {
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
	Bitmap^ img2 = gcnew Bitmap("AliadoM.png");
	Rectangle molde2 = Rectangle(indiceX2 * ancho2, indiceY2 * alto2, ancho2, alto2);
	g->DrawImage(img2, getRectangle2(), molde2, GraphicsUnit::Pixel);
	indiceX2++;
	if (indiceX2 == 3)
		indiceX2 = 0;
	delete img2;
}
void AliadoMNivel2::mover2(Graphics^ g) {
	indiceY2 = 0;
	indiceX2 = 0;
	if (y2 + dy2<0 || y2 + dy2 + alto2 > g->VisibleClipBounds.Height)dy2 *= -1;
	if (x2 + dx2<0 || x2 + dx2 + ancho2 > g->VisibleClipBounds.Width)dx2 *= -1;
	y2 += dy2;
	x2 += dx2;
}
void AliadoMNivel2::moverinverso2(Graphics^ g) {
	dy2 *= -1;
	dx2 *= -1;

	y2 += dy2;
	x2 += dx2;
}
bool AliadoMNivel2::moviminetoInvalido2(Graphics^ g) {
	if (y2 + dy2 + alto2 > g->VisibleClipBounds.Height)return true;
	return false;
}
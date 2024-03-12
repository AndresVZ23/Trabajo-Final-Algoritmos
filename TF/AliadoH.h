#pragma once
#include"Sprite.h"
class AliadoH :public Sprite {
public:
	AliadoH(Graphics^ g);
	~AliadoH();
	void dibujar(Graphics^ g);
	void mover(Graphics^ g);
	void moverinverso(Graphics^ g);
	bool moviminetoInvalido(Graphics^ g);
private:
};

AliadoH::AliadoH(Graphics^ g) {
	Bitmap^ img = gcnew Bitmap("AliadoH.png");
	alto = img->Height / 4;
	ancho = img->Width / 3;
	x = (int)g->VisibleClipBounds.Width - ancho;
	y = (int)g->VisibleClipBounds.Height / 2;
	dy = dx = 10;
	indiceY = indiceX = 0;
	escala = 0.75;
	delete img;
}

AliadoH::~AliadoH() {}
void AliadoH::dibujar(Graphics^ g) {
	if (dx < 0) {
		indiceY = 1;
	}
	else if (dx > 0) {
		indiceY = 2;
	}
	else if (dy > 0) {
		indiceY = 0;
	}
	else if (dy < 0) {
		indiceY = 3;
	}
	Bitmap^ img = gcnew Bitmap("AliadoH.png");
	Rectangle molde = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
	g->DrawImage(img, getRectangle(), molde, GraphicsUnit::Pixel);
	indiceX++;
	if (indiceX == 3)
		indiceX = 0;
	delete img;
}
void AliadoH::mover(Graphics^ g) {
	indiceY = 0;
	indiceX = 0;
	if (y + dy<0 || y + dy + alto > g->VisibleClipBounds.Height)dy *= -1;
	if (x + dx<0 || x + dx + ancho > g->VisibleClipBounds.Width)dx *= -1;
	y += dy;
	x += dx;
}
void AliadoH::moverinverso(Graphics^ g) {
	dy *= -1;
	dx *= -1;

	y += dy;
	x += dx;
}
bool AliadoH::moviminetoInvalido(Graphics^ g) {
	if (y + dy + alto > g->VisibleClipBounds.Height)return true;
	return false;
}
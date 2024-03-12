#pragma once
#include"Sprite.h"
class AliadoM :public Sprite {
public:
	AliadoM(Graphics^ g);
	~AliadoM();
	void dibujar(Graphics^ g);
	void mover(Graphics^ g);
	void moverinverso(Graphics^ g);
	bool moviminetoInvalido(Graphics^ g);
private:
};

AliadoM::AliadoM(Graphics^ g) {
	Random j;
	Bitmap^ img = gcnew Bitmap("AliadoM.png");
	alto = img->Height / 4;
	ancho = img->Width / 3;
	x = j.Next((int)g->VisibleClipBounds.Width - ancho);
	y = (int)g->VisibleClipBounds.Height / 2;
	dy = dx = 3;
	indiceY = indiceX = 0;
	escala = 0.75;
	delete img;
}

AliadoM::~AliadoM() {}
void AliadoM::dibujar(Graphics^ g) {
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
	Bitmap^ img = gcnew Bitmap("AliadoM.png");
	Rectangle molde = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
	g->DrawImage(img, getRectangle(), molde, GraphicsUnit::Pixel);
	indiceX++;
	if (indiceX == 3)
		indiceX = 0;
	delete img;
}
void AliadoM::mover(Graphics^ g) {
	indiceY = 0;
	indiceX = 0;
	if (y + dy<0 || y + dy + alto > g->VisibleClipBounds.Height)dy *= -1;
	if (x + dx<0 || x + dx + ancho > g->VisibleClipBounds.Width)dx *= -1;
	y += dy;
	x += dx;
}
void AliadoM::moverinverso(Graphics^ g) {
	dy *= -1;
	dx *= -1;

	y += dy;
	x += dx;
}
bool AliadoM::moviminetoInvalido(Graphics^ g) {
	if (y + dy + alto > g->VisibleClipBounds.Height)return true;
	return false;
}
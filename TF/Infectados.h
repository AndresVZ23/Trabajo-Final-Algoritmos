#pragma once
#include"Sprite.h"
class Infectado :public Sprite {
public:
	Infectado(Graphics^ g);
	~Infectado();
	void dibujar(Graphics^ g);
	void mover();
	void dejardemover();
	void moverinverso(Graphics^ g);
	void perseguir(int ex, int ey);
	void setdir(int dx, int dy);
	bool moviminetoInvalido(Graphics^ g);
	bool puedemover;
private:
};

Infectado::Infectado(Graphics^ g) {
	Random r;
	Bitmap^ img = gcnew Bitmap("Infectado.png");
	alto = img->Height / 4;
	ancho = img->Width / 3;
	y = r.Next((int)g->VisibleClipBounds.Height - alto);
	x = (int)g->VisibleClipBounds.Width - ancho;
	dy = dx = 4;
	indiceY = indiceX = 0;
	escala = 0.75;
	delete img;
}

Infectado::~Infectado() {}
void Infectado::dibujar(Graphics^ g) {
	Bitmap^ img = gcnew Bitmap("Infectado.png");
	Rectangle molde = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
	g->DrawImage(img, getRectangle(), molde, GraphicsUnit::Pixel);
	indiceX++;
	if (indiceX == 3)
		indiceX = 0;
	delete img;
}
void Infectado::mover() {
	x += dx;
	y += dy;
}
void Infectado::dejardemover() {
	puedemover = false;
}
void Infectado::moverinverso(Graphics^ g) {
	dy *= -1;
	dx *= -1;

	y += dy;
	x += dx;
}
void Infectado::perseguir(int ex, int ey) {
	if (puedemover) {
		int distanciax = ex - int(x);
		int distanciay = ey - int(y);
		if (distanciax || distanciay)
			if (abs(distanciax) > abs(distanciay)) {
				dy = 0;
				dx = (distanciax / abs(distanciax)) * 4;
				if (dx > 0) {
					indiceY = 2;
				}
				else if (dx < 0) {
					indiceY = 1;
				}
			}
			else {
				dx = 0;
				dy = (distanciay / abs(distanciay)) * 4;
				if (this->dy < 0) {
					indiceY = 3;
				}
				if (this->dy > 0) {
					indiceY = 0;
				}
			}
	}
	else {
		dx = dy = 0;
	}
}
void Infectado::setdir(int dx, int dy) {
	this->dx = dx;
	this->dy = dy;
}

bool Infectado::moviminetoInvalido(Graphics^ g) {
	if (x + dx + ancho > g->VisibleClipBounds.Width)return true;
	return false;
}
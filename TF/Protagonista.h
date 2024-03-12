#pragma once
#include "Sprite.h"
#include "Vacuna.h"
#include <vector>
enum acciones { izquierda, derecha, arriba, abajo, ninguna };
using namespace std;
class Protagonista : public Sprite {
	acciones accion;
public:
	Protagonista();
	~Protagonista();
	void setAccion(acciones _accion);
	void dibujar(Graphics^ g);
	void desplazar(Graphics^ g);
	void mover(Graphics^ g);
	void disparo();
	vector<Vacuna*>* getArrVacunas();
	int getX();
	int getY();
private:
	vector<Vacuna*>* arrVacunas;
	char tecla;
};

Protagonista::Protagonista() {
	Random j;
	Bitmap^ img = gcnew Bitmap("Protagonista.png");
	arrVacunas = new vector<Vacuna*>();
	contvidas = 3;
	x = y = j.Next(10, 40);
	alto = img->Height / 4;
	ancho = img->Width / 3;
	dx = dy = 0;
	indiceY = indiceX = 0;
	escala = 0.75;
	accion = ninguna;
	delete img;
}
Protagonista::~Protagonista() {}
void Protagonista::setAccion(acciones _accion) { accion = _accion; }

void Protagonista::dibujar(Graphics^ g) {
	Bitmap^ img = gcnew Bitmap("Protagonista.png");
	Rectangle molde = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
	g->DrawImage(img, getRectangle(), molde, GraphicsUnit::Pixel);
	delete img;
}

void Protagonista::desplazar(Graphics^ g) {
	switch (accion)
	{
	case arriba:
		indiceY = 3;
		if (indiceX >= 0 && indiceX < 2) ++indiceX;
		else indiceX = 0;
		break;
	case izquierda:
		indiceY = 1;
		if (indiceX >= 0 && indiceX < 2) ++indiceX;
		else indiceX = 0;
		break;
	case abajo:
		indiceY = 0;
		if (indiceX >= 0 && indiceX < 2) ++indiceX;
		else indiceX = 0;
		break;
	case derecha:
		indiceY = 2;
		if (indiceX >= 0 && indiceX < 2) ++indiceX;
		else indiceX = 0;
		break;
	case ninguna:
		dx = 0;
		dy = 0;
	}

	if (x + dx < 0 || x + dx + ancho > g->VisibleClipBounds.Width)
		dx = -dx;
	if (y + dy < 0 || y + dy + alto > g->VisibleClipBounds.Height)
		dy = -dy;

	x += dx;
	y += dy;
}

void Protagonista::mover(Graphics^ g) {
	desplazar(g);
	dibujar(g);
}
void Protagonista::disparo() {
	int pdx = 0, pdy = 0;

	if (dx > 0 && dy == 0) { pdy = 0; pdx = 16; };
	if (dx < 0 && dy == 0) { pdy = 0; pdx = -16; };
	if (dx == 0 && dy > 0) { pdx = 0; pdy = 16; };
	if (dx == 0 && dy < 0) { pdx = 0; pdy = -16; };
	if (dx == 0 && dy == 0) {
		if (indiceY == 3) {
			pdx = 0; pdy = -16;
		}
		else if (indiceY == 2) {
			pdx = 16; pdy = 0;
		}
		else if (indiceY == 1) {
			pdx = -16; pdy = 0;
		}
		else if (indiceY == 0) {
			pdx = 0; pdy = 16;
		}
	};

	arrVacunas->push_back(new Vacuna(x + (ancho * escala) / 2, y + (alto * escala) / 2, pdx, pdy));
}
vector<Vacuna*>* Protagonista::getArrVacunas() { return arrVacunas; }
int Protagonista::getX() { return x; }
int Protagonista::getY() { return y; }
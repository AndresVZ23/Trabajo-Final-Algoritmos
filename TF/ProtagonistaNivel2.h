#pragma once
#include "Sprite2.h"
#include "VacunaNivel2.h"
#include <vector>
enum acciones2 { izquierda2, derecha2, arriba2, abajo2, ninguna2 };
using namespace std;
class ProtagonistaNivel2 : public Sprite2 {
	acciones2 accion2;
public:
	ProtagonistaNivel2();
	~ProtagonistaNivel2();
	void setAccion2(acciones2 _accion2);
	void dibujar2(Graphics^ g);
	void desplazar2(Graphics^ g);
	void mover2(Graphics^ g);
	void disparo2();
	vector<VacunaNivel2*>* getArrVacunaNivel2();
	int getX2();
	int getY2();
private:
	vector<VacunaNivel2*>* arrVacunaNivel2;
	char tecla2;
};

ProtagonistaNivel2::ProtagonistaNivel2() {
	Random r;
	Bitmap^ img2 = gcnew Bitmap("Protagonista.png");
	arrVacunaNivel2 = new vector<VacunaNivel2*>();
	contvidas2 = 3;
	x2 = y2 = r.Next(10, 40);
	alto2 = img2->Height / 4;
	ancho2 = img2->Width / 3;
	dx2 = dy2 = 0;
	indiceY2 = indiceX2 = 0;
	escala2 = 0.9;
	accion2 = ninguna2;
	delete img2;
}
ProtagonistaNivel2::~ProtagonistaNivel2() {}
void ProtagonistaNivel2::setAccion2(acciones2 _accion2) { accion2 = _accion2; }

void ProtagonistaNivel2::dibujar2(Graphics^ g) {
	Bitmap^ img2 = gcnew Bitmap("Protagonista.png");
	Rectangle molde2 = Rectangle(indiceX2 * ancho2, indiceY2 * alto2, ancho2, alto2);
	g->DrawImage(img2, getRectangle2(), molde2, GraphicsUnit::Pixel);
	delete img2;
}

void ProtagonistaNivel2::desplazar2(Graphics^ g) {
	switch (accion2)
	{
	case arriba2:
		indiceY2 = 3;
		if (indiceX2 >= 0 && indiceX2 < 2) ++indiceX2;
		else indiceX2 = 0;
		break;
	case izquierda2:
		indiceY2 = 1;
		if (indiceX2 >= 0 && indiceX2 < 2) ++indiceX2;
		else indiceX2 = 0;
		break;
	case abajo2:
		indiceY2 = 0;
		if (indiceX2 >= 0 && indiceX2 < 2) ++indiceX2;
		else indiceX2 = 0;
		break;
	case derecha2:
		indiceY2 = 2;
		if (indiceX2 >= 0 && indiceX2 < 2) ++indiceX2;
		else indiceX2 = 0;
		break;
	case ninguna2:
		dx2 = 0;
		dy2 = 0;
	}

	if (x2 + dx2 < 0 || x2 + dx2 + ancho2 > g->VisibleClipBounds.Width)
		dx2 = -dx2;
	if (y2 + dy2 < 0 || y2 + dy2 + alto2 > g->VisibleClipBounds.Height)
		dy2 = -dy2;

	x2 += dx2;
	y2 += dy2;
}

void ProtagonistaNivel2::mover2(Graphics^ g) {
	desplazar2(g);
	dibujar2(g);
}
void ProtagonistaNivel2::disparo2() {
	int pdx2 = 0, pdy2 = 0;

	if (dx2 > 0 && dy2 == 0) { pdy2 = 0; pdx2 = 16; };
	if (dx2 < 0 && dy2 == 0) { pdy2 = 0; pdx2 = -16; };
	if (dx2 == 0 && dy2 > 0) { pdx2 = 0; pdy2 = 16; };
	if (dx2 == 0 && dy2 < 0) { pdx2 = 0; pdy2 = -16; };
	if (dx2 == 0 && dy2 == 0) {
		if (indiceY2 == 3) {
			pdx2 = 0; pdy2 = -16;
		}
		else if (indiceY2 == 2) {
			pdx2 = 16; pdy2 = 0;
		}
		else if (indiceY2 == 1) {
			pdx2 = -16; pdy2 = 0;
		}
		else if (indiceY2 == 0) {
			pdx2 = 0; pdy2 = 16;
		}
	};

	arrVacunaNivel2->push_back(new VacunaNivel2(x2 + (ancho2 * escala2) / 2, y2 + (alto2 * escala2) / 2, pdx2, pdy2));
}
vector<VacunaNivel2*>* ProtagonistaNivel2::getArrVacunaNivel2() { return arrVacunaNivel2; }
int ProtagonistaNivel2::getX2() { return x2; }
int ProtagonistaNivel2::getY2() { return y2; }
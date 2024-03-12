#pragma once
#include"Sprite2.h"
class Paciente0 :public Sprite2 {
public:
	Paciente0(Graphics^ g);
	~Paciente0();
	void dibujar2(Graphics^ g);
	void mover2();
	void perseguir2(int ex2, int ey2);
	void setdir2(int dx2, int dy2);
	bool moviminetoInvalido2(Graphics^ g);
private:
};

Paciente0::Paciente0(Graphics^ g) {
	Random r;
	Bitmap^ img2 = gcnew Bitmap("PrimerPortadorDelVirus.png");
	alto2 = img2->Height / 4;
	ancho2 = img2->Width / 3;
	y2 = ((int)g->VisibleClipBounds.Height - alto2) / 2;
	x2 = (int)g->VisibleClipBounds.Width - ancho2;
	dy2 = dx2 = 2;
	indiceY2 = indiceX2 = 0;
	escala2 = 0.9;
	delete img2;
}

Paciente0::~Paciente0() {}
void Paciente0::dibujar2(Graphics^ g) {
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
	Bitmap^ img2 = gcnew Bitmap("PrimerPortadorDelVirus.png");
	Rectangle molde2 = Rectangle(indiceX2 * ancho2, indiceY2 * alto2, ancho2, alto2);
	g->DrawImage(img2, getRectangle2(), molde2, GraphicsUnit::Pixel);
	indiceX2++;
	if (indiceX2 == 3)
		indiceX2 = 0;
	delete img2;
}
void Paciente0::mover2() {
	x2 += dx2;
	y2 += dy2;
}
void Paciente0::perseguir2(int ex2, int ey2) {
	int distanciax2 = ex2 - int(x2);
	int distanciay2 = ey2 - int(y2);
	if (distanciax2 || distanciay2)
		if (abs(distanciax2) > abs(distanciay2)) {
			dy2 = 0;
			dx2 = (distanciax2 / abs(distanciax2)) * 4;
		}
		else {
			dx2 = 0;
			dy2 = (distanciay2 / abs(distanciay2)) * 4;
		}
}
void Paciente0::setdir2(int dx2, int dy2) {
	this->dx2 = dx2;
	this->dy2 = dy2;
}

bool Paciente0::moviminetoInvalido2(Graphics^ g) {
	if (x2 + dx2 + ancho2 > g->VisibleClipBounds.Width)return true;
	return false;
}
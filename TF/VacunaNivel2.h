#pragma once
#include "Sprite2.h"
class VacunaNivel2 :public Sprite2 {
public:
	VacunaNivel2(int px2, int py2, int dx2, int dy2);
	~VacunaNivel2();
	void dibujar2(Graphics^ g);
	void mover2();
	bool movimientoInvalido2(Graphics^ g);
private:

};

VacunaNivel2::VacunaNivel2(int px2, int py2, int pdx2, int pdy2)
{
	Bitmap^ img2 = gcnew Bitmap("Vacuna.png");
	x2 = px2;
	y2 = py2;
	dx2 = pdx2;
	dy2 = pdy2;
	ancho2 = img2->Width;
	alto2 = img2->Height;
	escala2 = 0.04;
	delete img2;
}

VacunaNivel2::~VacunaNivel2() {}
void VacunaNivel2::dibujar2(Graphics^ g) {
	Bitmap^ img2 = gcnew Bitmap("Vacuna.png");
	g->DrawImage(img2, getRectangle2(), Rectangle(0, 0, ancho2, alto2), GraphicsUnit::Pixel);
	delete img2;
}
void VacunaNivel2::mover2() {
	x2 += dx2;
	y2 += dy2;
}
bool VacunaNivel2::movimientoInvalido2(Graphics^ g) {
	if (y2 + dy2 < 0 || y2 + dy2 + alto2 * escala2 > g->VisibleClipBounds.Height || x2 + dx2 + ancho2 * escala2 > g->VisibleClipBounds.Width || x2 + dx2 < 0)
		return true;
	else
		return false;
}
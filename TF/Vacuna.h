#pragma once
#include "Sprite.h"
class Vacuna :public Sprite {
public:
	Vacuna(int px, int py, int dx, int dy);
	~Vacuna();
	void dibujar(Graphics^ g);
	void mover();
	bool movimientoInvalido(Graphics^ g);
private:

};

Vacuna::Vacuna(int px, int py, int pdx, int pdy)
{
	Bitmap^ img = gcnew Bitmap("Vacuna.png");
	x = px;
	y = py;
	dx = pdx;
	dy = pdy;
	ancho = img->Width;
	alto = img->Height;
	escala = 0.035;
	delete img;
}

Vacuna::~Vacuna() {}
void Vacuna::dibujar(Graphics^ g) {
	Bitmap^ img = gcnew Bitmap("Vacuna.png");
	g->DrawImage(img, getRectangle(), Rectangle(0, 0, ancho, alto), GraphicsUnit::Pixel);
	delete img;
}
void Vacuna::mover() {
	x += dx;
	y += dy;
}
bool Vacuna::movimientoInvalido(Graphics^ g) {
	if (y + dy < 0 || y + dy + alto * escala > g->VisibleClipBounds.Height || x + dx + ancho * escala > g->VisibleClipBounds.Width || x + dx < 0)
		return true;
	else
		return false;
}
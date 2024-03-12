#pragma once
#include"ProtagonistaNivel2.h"
#include"InfectadosNivel2.h"
#include"AliadoMNivel2.h"
#include"AliadoHNivel2.h"
#include"Paciente0.h"
#include <time.h>
#include <iostream>
using namespace System::Windows::Forms;

struct Rectangulo2
{
	int x2, y2, ancho2, alto2;
	Rectangulo2(int px2, int py2, int pancho2, int palto2)
	{
		x2 = px2;
		y2 = py2;
		ancho2 = pancho2;
		alto2 = palto2;
	}
	Rectangle getRectangle() { return Rectangle(x2, y2, ancho2, alto2); }
};

using namespace std;
class ControladoraNivel2 {
public:
	ControladoraNivel2(Graphics^ g);
	~ControladoraNivel2();
	void dibujarTodo2(Graphics^ g);
	void atenderEventoJugador2(bool accion_presion, Keys tecla);
	void moverJugadorNivel2(Graphics^ g);
	void disparoJugador2();
	void dibujarAliadoM2(Graphics^ g);
	void dibujarAliadoH2(Graphics^ g);
	void moverTodo2(Graphics^ g);
	void colision2(Graphics^ g);
	void generarInfectados2(Graphics^ g);
	ProtagonistaNivel2* getJugador2() { return jugadorNivel2; }
	int getVidas2();
	int getVacunasUsadas2();
	int getInfectadosGenerados2();
	int getInfectadosCurados2();
	int getVidasPaciente0();
private:
	int contVacunasUsadas2;
	int contInfectadosGenerados2;
	int contInfectadosCurados2;
	int contVidas2;
	int contVidasPaciente0;
	vector<Rectangulo2> arrRectangulos2;
	ProtagonistaNivel2* jugadorNivel2;
	Paciente0* enemigoPrincipal;
	vector<InfectadoNivel2*> arrInfectadosNivel2;
	vector<AliadoMNivel2*> arrAliadoMNivel2;
	vector<AliadoHNivel2*> arrAliadoHNivel2;
	clock_t cronometro2;
	bool generar2;
};

ControladoraNivel2::ControladoraNivel2(Graphics^ g) {
	srand(time(NULL));
	jugadorNivel2 = new ProtagonistaNivel2();
	enemigoPrincipal = new Paciente0(g);
	//for que me sive para agregar 1 Infectado
	for (int i = 0; i < 1; i++) {
		arrInfectadosNivel2.push_back(new InfectadoNivel2(g));
	}
	contVidas2 = 4;
	contVidasPaciente0 = 8;
	contVacunasUsadas2 = 0;
	contInfectadosGenerados2 = 1;
	contInfectadosCurados2 = 0;
}
ControladoraNivel2::~ControladoraNivel2() {}

void ControladoraNivel2::dibujarTodo2(Graphics^ g) {
	//dibujar jugadorNivel2
	jugadorNivel2->dibujar2(g);
	//dibujar Paciente 0
	enemigoPrincipal->dibujar2(g);
	//dibujar Vacunas
	for (int i = 0; i < jugadorNivel2->getArrVacunaNivel2()->size(); i++)
	{
		jugadorNivel2->getArrVacunaNivel2()->at(i)->dibujar2(g);
	}
	//dibujar Infectados
	for (int i = 0; i < arrInfectadosNivel2.size(); i++)
	{
		arrInfectadosNivel2.at(i)->dibujar2(g);
	}
	//dibujar AliadoM
	for (int i = 0; i < arrAliadoMNivel2.size(); i++)
	{
		arrAliadoMNivel2.at(i)->dibujar2(g);
	}
	//dibujar AliadoH
	for (int i = 0; i < arrAliadoHNivel2.size(); i++)
	{
		arrAliadoHNivel2.at(i)->dibujar2(g);
	}
}
void ControladoraNivel2::moverTodo2(Graphics^ g)
{
	//mover Vacunas
	for (int i = 0; i < jugadorNivel2->getArrVacunaNivel2()->size(); i++)
	{
		jugadorNivel2->getArrVacunaNivel2()->at(i)->mover2();
	}
	//mover Infectados
	for (int i = 0; i < arrInfectadosNivel2.size(); i++)
	{
		arrInfectadosNivel2.at(i)->perseguir2(jugadorNivel2->getX2(), jugadorNivel2->getY2());
		arrInfectadosNivel2.at(i)->mover2();
	}
	//mover AliadoM
	for (int i = 0; i < arrAliadoMNivel2.size(); i++)
	{
		arrAliadoMNivel2.at(i)->mover2(g);
	}
	//mover AliadoM
	for (int i = 0; i < arrAliadoHNivel2.size(); i++)
	{
		arrAliadoHNivel2.at(i)->mover2(g);
	}
	//mover Paciente0
	enemigoPrincipal->perseguir2(jugadorNivel2->getX2(), jugadorNivel2->getY2());
	enemigoPrincipal->mover2();
}
void ControladoraNivel2::atenderEventoJugador2(bool accion_presion, Keys tecla) {
	int vel2 = 4;
	if (accion_presion) {
		switch (tecla) {
		case Keys::Left:
			jugadorNivel2->setAccion2(izquierda2);
			jugadorNivel2->setDX2(-vel2);
			break;

		case Keys::Right:
			jugadorNivel2->setAccion2(derecha2);
			jugadorNivel2->setDX2(vel2);
			break;

		case Keys::Up:
			jugadorNivel2->setAccion2(arriba2);
			jugadorNivel2->setDY2(-vel2);
			break;

		case Keys::Down:
			jugadorNivel2->setAccion2(abajo2);
			jugadorNivel2->setDY2(vel2);
			break;
		}
	}
	else {
		jugadorNivel2->setAccion2(ninguna2);
		jugadorNivel2->setDX2(0);
		jugadorNivel2->setDY2(0);
	}
}
void ControladoraNivel2::moverJugadorNivel2(Graphics^ g)
{
	//Obstaculos
	Rectangle ob = Rectangle(39, 191, 7, 121);
	Rectangle ob2 = Rectangle(49, 191, 139, 27);
	Rectangle ob3 = Rectangle(228, 191, 101, 26);
	Rectangle ob4 = Rectangle(331, 191, 7, 123);
	Rectangle ob5 = Rectangle(49, 290, 280, 24);
	Rectangle ob6 = Rectangle(112, 542, 115, 62);
	Rectangle ob7 = Rectangle(228, 453, 76, 100);
	Rectangle ob8 = Rectangle(495, 23, 269, 132);
	Rectangle ob9 = Rectangle(534, 155, 77, 34);
	Rectangle ob10 = Rectangle(419, 354, 7, 163);
	Rectangle ob11 = Rectangle(425, 409, 71, 111);
	Rectangle ob12 = Rectangle(495, 415, 7, 131);

	//colision del jugador con los obstaculos

	if (jugadorNivel2->getSigRectangle2().IntersectsWith(ob))
	{
		jugadorNivel2->dibujar2(g);
	}
	else if (jugadorNivel2->getSigRectangle2().IntersectsWith(ob2)) {
		jugadorNivel2->dibujar2(g);
	}
	else if (jugadorNivel2->getSigRectangle2().IntersectsWith(ob3)) {
		jugadorNivel2->dibujar2(g);
	}
	else if (jugadorNivel2->getSigRectangle2().IntersectsWith(ob4)) {
		jugadorNivel2->dibujar2(g);
	}
	else if (jugadorNivel2->getSigRectangle2().IntersectsWith(ob5)) {
		jugadorNivel2->dibujar2(g);
	}
	else if (jugadorNivel2->getSigRectangle2().IntersectsWith(ob6)) {
		jugadorNivel2->dibujar2(g);
	}
	else if (jugadorNivel2->getSigRectangle2().IntersectsWith(ob7)) {
		jugadorNivel2->dibujar2(g);
	}
	else if (jugadorNivel2->getSigRectangle2().IntersectsWith(ob8)) {
		jugadorNivel2->dibujar2(g);
	}
	else if (jugadorNivel2->getSigRectangle2().IntersectsWith(ob9)) {
		jugadorNivel2->dibujar2(g);
	}
	else if (jugadorNivel2->getSigRectangle2().IntersectsWith(ob10)) {
		jugadorNivel2->dibujar2(g);
	}
	else if (jugadorNivel2->getSigRectangle2().IntersectsWith(ob11)) {
		jugadorNivel2->dibujar2(g);
	}
	else if (jugadorNivel2->getSigRectangle2().IntersectsWith(ob12)) {
		jugadorNivel2->dibujar2(g);
	}
	else {
		jugadorNivel2->mover2(g);
	}

	//colision de la vacuna con un obstaculo
	for (int i = 0; i < jugadorNivel2->getArrVacunaNivel2()->size(); i++) {
		if (jugadorNivel2->getArrVacunaNivel2()->at(i)->getRectangle2().IntersectsWith(ob))
		{
			//eliminar de mi arreglo a una Vacuna
			jugadorNivel2->getArrVacunaNivel2()->erase(jugadorNivel2->getArrVacunaNivel2()->begin() + i);
			i--;
			break;
		}
		else if (jugadorNivel2->getArrVacunaNivel2()->at(i)->getRectangle2().IntersectsWith(ob2))
		{
			jugadorNivel2->getArrVacunaNivel2()->erase(jugadorNivel2->getArrVacunaNivel2()->begin() + i);
			i--;
			break;
		}
		else if (jugadorNivel2->getArrVacunaNivel2()->at(i)->getRectangle2().IntersectsWith(ob3))
		{
			jugadorNivel2->getArrVacunaNivel2()->erase(jugadorNivel2->getArrVacunaNivel2()->begin() + i);
			i--;
			break;
		}
		else if (jugadorNivel2->getArrVacunaNivel2()->at(i)->getRectangle2().IntersectsWith(ob4))
		{
			jugadorNivel2->getArrVacunaNivel2()->erase(jugadorNivel2->getArrVacunaNivel2()->begin() + i);
			i--;
			break;
		}
		else if (jugadorNivel2->getArrVacunaNivel2()->at(i)->getRectangle2().IntersectsWith(ob5))
		{
			jugadorNivel2->getArrVacunaNivel2()->erase(jugadorNivel2->getArrVacunaNivel2()->begin() + i);
			i--;
			break;
		}
		else if (jugadorNivel2->getArrVacunaNivel2()->at(i)->getRectangle2().IntersectsWith(ob6))
		{
			jugadorNivel2->getArrVacunaNivel2()->erase(jugadorNivel2->getArrVacunaNivel2()->begin() + i);
			i--;
			break;
		}
		else if (jugadorNivel2->getArrVacunaNivel2()->at(i)->getRectangle2().IntersectsWith(ob7))
		{
			jugadorNivel2->getArrVacunaNivel2()->erase(jugadorNivel2->getArrVacunaNivel2()->begin() + i);
			i--;
			break;
		}
		else if (jugadorNivel2->getArrVacunaNivel2()->at(i)->getRectangle2().IntersectsWith(ob8))
		{
			jugadorNivel2->getArrVacunaNivel2()->erase(jugadorNivel2->getArrVacunaNivel2()->begin() + i);
			i--;
			break;
		}
		else if (jugadorNivel2->getArrVacunaNivel2()->at(i)->getRectangle2().IntersectsWith(ob9))
		{
			jugadorNivel2->getArrVacunaNivel2()->erase(jugadorNivel2->getArrVacunaNivel2()->begin() + i);
			i--;
			break;
		}
		else if (jugadorNivel2->getArrVacunaNivel2()->at(i)->getRectangle2().IntersectsWith(ob10))
		{
			jugadorNivel2->getArrVacunaNivel2()->erase(jugadorNivel2->getArrVacunaNivel2()->begin() + i);
			i--;
			break;
		}
		else if (jugadorNivel2->getArrVacunaNivel2()->at(i)->getRectangle2().IntersectsWith(ob11))
		{
			jugadorNivel2->getArrVacunaNivel2()->erase(jugadorNivel2->getArrVacunaNivel2()->begin() + i);
			i--;
			break;
		}
		else if (jugadorNivel2->getArrVacunaNivel2()->at(i)->getRectangle2().IntersectsWith(ob12))
		{
			jugadorNivel2->getArrVacunaNivel2()->erase(jugadorNivel2->getArrVacunaNivel2()->begin() + i);
			i--;
			break;
		}
	}

	//colision AliadoMNivel2 con obstaculo
	for (int i = 0; i < arrAliadoMNivel2.size(); i++) {
		if (arrAliadoMNivel2.at(i)->getRectangle2().IntersectsWith(ob))
		{
			arrAliadoMNivel2.at(i)->moverinverso2(g);
			i--;
			break;
		}
		else if (arrAliadoMNivel2.at(i)->getRectangle2().IntersectsWith(ob2))
		{
			arrAliadoMNivel2.at(i)->moverinverso2(g);
			i--;
			break;
		}
		else if (arrAliadoMNivel2.at(i)->getRectangle2().IntersectsWith(ob3))
		{
			arrAliadoMNivel2.at(i)->moverinverso2(g);
			i--;
			break;
		}
		else if (arrAliadoMNivel2.at(i)->getRectangle2().IntersectsWith(ob4))
		{
			arrAliadoMNivel2.at(i)->moverinverso2(g);
			i--;
			break;
		}
		else if (arrAliadoMNivel2.at(i)->getRectangle2().IntersectsWith(ob5))
		{
			arrAliadoMNivel2.at(i)->moverinverso2(g);
			i--;
			break;
		}
		else if (arrAliadoMNivel2.at(i)->getRectangle2().IntersectsWith(ob6))
		{
			arrAliadoMNivel2.at(i)->moverinverso2(g);
			i--;
			break;
		}
		else if (arrAliadoMNivel2.at(i)->getRectangle2().IntersectsWith(ob7))
		{
			arrAliadoMNivel2.at(i)->moverinverso2(g);
			i--;
			break;
		}
		else if (arrAliadoMNivel2.at(i)->getRectangle2().IntersectsWith(ob8))
		{
			arrAliadoMNivel2.at(i)->moverinverso2(g);
			i--;
			break;
		}
		else if (arrAliadoMNivel2.at(i)->getRectangle2().IntersectsWith(ob9))
		{
			arrAliadoMNivel2.at(i)->moverinverso2(g);
			i--;
			break;
		}
		else if (arrAliadoMNivel2.at(i)->getRectangle2().IntersectsWith(ob10))
		{
			arrAliadoMNivel2.at(i)->moverinverso2(g);
			i--;
			break;
		}
		else if (arrAliadoMNivel2.at(i)->getRectangle2().IntersectsWith(ob11))
		{
			arrAliadoMNivel2.at(i)->moverinverso2(g);
			i--;
			break;
		}
		else if (arrAliadoMNivel2.at(i)->getRectangle2().IntersectsWith(ob12))
		{
			arrAliadoMNivel2.at(i)->moverinverso2(g);
			i--;
			break;
		}
	}

	//colision AliadoHNivel2 con obstaculo
	for (int i = 0; i < arrAliadoHNivel2.size(); i++) {
		if (arrAliadoHNivel2.at(i)->getRectangle2().IntersectsWith(ob))
		{
			arrAliadoHNivel2.at(i)->moverinverso2(g);
			i--;
			break;
		}
		else if (arrAliadoHNivel2.at(i)->getRectangle2().IntersectsWith(ob2))
		{
			arrAliadoHNivel2.at(i)->moverinverso2(g);
			i--;
			break;
		}
		else if (arrAliadoHNivel2.at(i)->getRectangle2().IntersectsWith(ob3))
		{
			arrAliadoHNivel2.at(i)->moverinverso2(g);
			i--;
			break;
		}
		else if (arrAliadoHNivel2.at(i)->getRectangle2().IntersectsWith(ob4))
		{
			arrAliadoHNivel2.at(i)->moverinverso2(g);
			i--;
			break;
		}
		else if (arrAliadoHNivel2.at(i)->getRectangle2().IntersectsWith(ob5))
		{
			arrAliadoHNivel2.at(i)->moverinverso2(g);
			i--;
			break;
		}
		else if (arrAliadoHNivel2.at(i)->getRectangle2().IntersectsWith(ob6))
		{
			arrAliadoHNivel2.at(i)->moverinverso2(g);
			i--;
			break;
		}
		else if (arrAliadoHNivel2.at(i)->getRectangle2().IntersectsWith(ob7))
		{
			arrAliadoHNivel2.at(i)->moverinverso2(g);
			i--;
			break;
		}
		else if (arrAliadoHNivel2.at(i)->getRectangle2().IntersectsWith(ob8))
		{
			arrAliadoHNivel2.at(i)->moverinverso2(g);
			i--;
			break;
		}
		else if (arrAliadoHNivel2.at(i)->getRectangle2().IntersectsWith(ob9))
		{
			arrAliadoHNivel2.at(i)->moverinverso2(g);
			i--;
			break;
		}
		else if (arrAliadoHNivel2.at(i)->getRectangle2().IntersectsWith(ob10))
		{
			arrAliadoHNivel2.at(i)->moverinverso2(g);
			i--;
			break;
		}
		else if (arrAliadoHNivel2.at(i)->getRectangle2().IntersectsWith(ob11))
		{
			arrAliadoHNivel2.at(i)->moverinverso2(g);
			i--;
			break;
		}
		else if (arrAliadoHNivel2.at(i)->getRectangle2().IntersectsWith(ob12))
		{
			arrAliadoHNivel2.at(i)->moverinverso2(g);
			i--;
			break;
		}
	}

	//colision Infectados con obstaculo
	for (int i = 0; i < arrInfectadosNivel2.size(); i++) {
		if (arrInfectadosNivel2.at(i)->getRectangle2().IntersectsWith(ob)) {
			arrInfectadosNivel2.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrInfectadosNivel2.at(i)->getRectangle2().IntersectsWith(ob2)) {
			arrInfectadosNivel2.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrInfectadosNivel2.at(i)->getRectangle2().IntersectsWith(ob3)) {
			arrInfectadosNivel2.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrInfectadosNivel2.at(i)->getRectangle2().IntersectsWith(ob4)) {
			arrInfectadosNivel2.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrInfectadosNivel2.at(i)->getRectangle2().IntersectsWith(ob5)) {
			arrInfectadosNivel2.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrInfectadosNivel2.at(i)->getRectangle2().IntersectsWith(ob6)) {
			arrInfectadosNivel2.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrInfectadosNivel2.at(i)->getRectangle2().IntersectsWith(ob7)) {
			arrInfectadosNivel2.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrInfectadosNivel2.at(i)->getRectangle2().IntersectsWith(ob8)) {
			arrInfectadosNivel2.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrInfectadosNivel2.at(i)->getRectangle2().IntersectsWith(ob9)) {
			arrInfectadosNivel2.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrInfectadosNivel2.at(i)->getRectangle2().IntersectsWith(ob10)) {
			arrInfectadosNivel2.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrInfectadosNivel2.at(i)->getRectangle2().IntersectsWith(ob11)) {
			arrInfectadosNivel2.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrInfectadosNivel2.at(i)->getRectangle2().IntersectsWith(ob12)) {
			arrInfectadosNivel2.at(i)->moverinverso(g);
			i--;
			break;
		}
	}
}

void ControladoraNivel2::colision2(Graphics^ g)
{
	//colision de la Vacuna con parte superior del formulario
	for (int i = 0; i < jugadorNivel2->getArrVacunaNivel2()->size(); i++)
	{
		if (jugadorNivel2->getArrVacunaNivel2()->at(i)->movimientoInvalido2(g))
		{
			//eliminar de mi arreglo a una Vacuna
			jugadorNivel2->getArrVacunaNivel2()->erase(jugadorNivel2->getArrVacunaNivel2()->begin() + i);
			i--;
			break;
		}
	}

	//colision de la Vacuna con un Infectado
	for (int i = 0; i < jugadorNivel2->getArrVacunaNivel2()->size(); i++)
	{
		for (int j = 0; j < arrInfectadosNivel2.size(); j++)
		{
			if (jugadorNivel2->getArrVacunaNivel2()->at(i)->getRectangle2().IntersectsWith(arrInfectadosNivel2[j]->getRectangle2()))
			{
				//eliminar de mi arreglo a una Vacuna
				jugadorNivel2->getArrVacunaNivel2()->erase(jugadorNivel2->getArrVacunaNivel2()->begin() + i);
				//eliminar a un Infectado de mi arreglo
				arrInfectadosNivel2.erase(arrInfectadosNivel2.begin() + j);
				contInfectadosCurados2++;
				i--;
				j--;
				break;
			}
		}
	}

	//colision con parte inferior del formulario
	for (int i = 0; i < arrInfectadosNivel2.size(); i++)
		if (arrInfectadosNivel2.at(i)->moviminetoInvalido2(g))
		{
			arrInfectadosNivel2.erase(arrInfectadosNivel2.begin() + i);
			i--;
			break;
		}

	//colision jugadorNivel2 con Infectados
	for (int i = 0; i < arrInfectadosNivel2.size(); i++) {
		if (arrInfectadosNivel2.at(i)->getRectangle2().IntersectsWith(jugadorNivel2->getRectangle2()))
		{
			jugadorNivel2 = new ProtagonistaNivel2();
			contVidas2--;
			i--;
			break;
		}
	}
	//colision jugadorNivel2 con AliadoM
	for (int i = 0; i < arrAliadoMNivel2.size(); i++) {
		if (arrAliadoMNivel2.at(i)->getRectangle2().IntersectsWith(jugadorNivel2->getRectangle2()))
		{
			arrAliadoMNivel2.erase(arrAliadoMNivel2.begin() + i);
			contVidas2++;
			i--;
			break;
		}
	}
	//colision enemigo principal con AliadoM
	for (int i = 0; i < arrAliadoMNivel2.size(); i++) {
		if (arrAliadoMNivel2.at(i)->getRectangle2().IntersectsWith(enemigoPrincipal->getRectangle2()))
		{
			arrAliadoMNivel2.erase(arrAliadoMNivel2.begin() + i);
			i--;
			break;
		}
	}
	//colision enemigo principal con AliadoH
	for (int i = 0; i < arrAliadoHNivel2.size(); i++) {
		if (arrAliadoHNivel2.at(i)->getRectangle2().IntersectsWith(enemigoPrincipal->getRectangle2()))
		{
			arrAliadoHNivel2.erase(arrAliadoHNivel2.begin() + i);
			i--;
			break;
		}
	}
	//colision jugadorNivel2 con AliadoH
	for (int i = 0; i < arrAliadoHNivel2.size(); i++) {
		if (arrAliadoHNivel2.at(i)->getRectangle2().IntersectsWith(jugadorNivel2->getRectangle2()))
		{
			arrAliadoHNivel2.erase(arrAliadoHNivel2.begin() + i);
			contVidas2 += 4;
			i--;
			break;
		}
	}
	//colision jugadorNivel2 con Paciente0
	if (jugadorNivel2->getRectangle2().IntersectsWith(enemigoPrincipal->getRectangle2())) {
		jugadorNivel2 = new ProtagonistaNivel2();
		contVidas2 -= 2;
	}
	//colision de la vacuna con el Paciente0
	for (int i = 0; i < jugadorNivel2->getArrVacunaNivel2()->size(); i++)
	{
		if (jugadorNivel2->getArrVacunaNivel2()->at(i)->getRectangle2().IntersectsWith(enemigoPrincipal->getRectangle2()))
		{
			//eliminar de mi arreglo a una Vacuna
			jugadorNivel2->getArrVacunaNivel2()->erase(jugadorNivel2->getArrVacunaNivel2()->begin() + i);
			//eliminar a un Infectado de mi arreglo
			enemigoPrincipal = new Paciente0(g);
			contVidasPaciente0--;
			i--;
			break;
		}
	}
}
void ControladoraNivel2::generarInfectados2(Graphics^ g)
{
	if (generar2) { cronometro2 = clock(); generar2 = false; }
	if ((clock() - cronometro2) / CLOCKS_PER_SEC == 2) {
		contInfectadosGenerados2++;
		arrInfectadosNivel2.push_back(new InfectadoNivel2(g));
		generar2 = true;
	}
}
void ControladoraNivel2::disparoJugador2()
{
	contVacunasUsadas2++;
	jugadorNivel2->disparo2();
}
void ControladoraNivel2::dibujarAliadoM2(Graphics^ g) {
	arrAliadoMNivel2.push_back(new AliadoMNivel2(g));
}
void ControladoraNivel2::dibujarAliadoH2(Graphics^ g) {
	arrAliadoHNivel2.push_back(new AliadoHNivel2(g));
}
int ControladoraNivel2::getVidas2() { return contVidas2; }
int ControladoraNivel2::getVidasPaciente0() { return contVidasPaciente0; }
int ControladoraNivel2::getVacunasUsadas2() { return contVacunasUsadas2; }
int ControladoraNivel2::getInfectadosGenerados2() { return contInfectadosGenerados2; }
int ControladoraNivel2::getInfectadosCurados2() { return contInfectadosCurados2; };
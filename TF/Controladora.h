#pragma once
#include"Protagonista.h"
#include"Infectados.h"
#include"AliadoM.h"
#include"AliadoH.h"
#include <time.h>
#include <iostream>
using namespace System::Windows::Forms;
using namespace std;

struct Rectangulo
{
	int x, y, ancho, alto;
	Rectangulo(int px, int py, int pancho, int palto)
	{
		x = px;
		y = py;
		ancho = pancho;
		alto = palto;
	}
	Rectangle getRectangle() { return Rectangle(x, y, ancho, alto); }
};

class Controladora {
public:
	Controladora(Graphics^ g);
	~Controladora();
	void dibujarTodo(Graphics^ g);
	void atenderEventoJugador(bool accion_presion, Keys tecla);
	void moverJugador(Graphics^ g);
	void disparoJugador();
	void dibujarAliadoM(Graphics^ g);
	void dibujarAliadoH(Graphics^ g);
	void moverTodo(Graphics^ g);
	void colision(Graphics^ g);
	void generarInfectados(Graphics^ g);
	Protagonista* getJugador() { return jugador; }
	int getVidas();
	int getVacunasUsadas();
	int getInfectadosGenerados();
	int getInfectadosCurados();
private:
	int contVacunasUsadas;
	int contInfectadosGenerados;
	int contInfectadosCurados;
	int contVidas;
	vector<Rectangulo> arrRectangulos;
	Protagonista* jugador;
	vector<Infectado*> arrInfectados;
	vector<AliadoM*> arrAliadoM;
	vector<AliadoH*> arrAliadoH;
	clock_t cronometro;
	bool generar;
};

Controladora::Controladora(Graphics^ g) {
	srand(time(NULL));
	jugador = new Protagonista();
	//for que me sive para agregar 1 Infectado
	for (int i = 0; i < 1; i++) {
		arrInfectados.push_back(new Infectado(g));
	}
	contVidas = 3;
	contVacunasUsadas = 0;
	contInfectadosGenerados = 1;
	contInfectadosCurados = 0;
}
Controladora::~Controladora() {}

void Controladora::dibujarTodo(Graphics^ g) {
	//dibujar jugador
	jugador->dibujar(g);
	//dibujar Vacunas
	for (int i = 0; i < jugador->getArrVacunas()->size(); i++)
	{
		jugador->getArrVacunas()->at(i)->dibujar(g);
	}
	//dibujar Infectados
	for (int i = 0; i < arrInfectados.size(); i++)
	{
		arrInfectados.at(i)->dibujar(g);
	}
	//dibujar AliadoM
	for (int i = 0; i < arrAliadoM.size(); i++)
	{
		arrAliadoM.at(i)->dibujar(g);
	}
	//dibujar AliadoH
	for (int i = 0; i < arrAliadoH.size(); i++)
	{
		arrAliadoH.at(i)->dibujar(g);
	}
}
void Controladora::moverTodo(Graphics^ g)
{
	//mover Vacunas
	for (int i = 0; i < jugador->getArrVacunas()->size(); i++)
	{
		jugador->getArrVacunas()->at(i)->mover();
	}
	//mover Infectados
	for (int i = 0; i < arrInfectados.size(); i++)
	{
		arrInfectados.at(i)->perseguir(jugador->getX(), jugador->getY());
		arrInfectados.at(i)->mover();
	}
	//mover AliadoM
	for (int i = 0; i < arrAliadoM.size(); i++)
	{
		arrAliadoM.at(i)->mover(g);
	}
	//mover AliadoM
	for (int i = 0; i < arrAliadoH.size(); i++)
	{
		arrAliadoH.at(i)->mover(g);
	}
}
void Controladora::atenderEventoJugador(bool accion_presion, Keys tecla) {
	int vel = 4;
	if (accion_presion) {
		switch (tecla) {
		case Keys::Left:
			jugador->setAccion(izquierda);
			jugador->setDX(-vel);
			break;

		case Keys::Right:
			jugador->setAccion(derecha);
			jugador->setDX(vel);
			break;

		case Keys::Up:
			jugador->setAccion(arriba);
			jugador->setDY(-vel);
			break;

		case Keys::Down:
			jugador->setAccion(abajo);
			jugador->setDY(vel);
			break;
		}
	}
	else {
		jugador->setAccion(ninguna);
		jugador->setDX(0);
		jugador->setDY(0);
	}
}
void Controladora::moverJugador(Graphics^ g) {

	//Obstaculos
	Rectangle obs = Rectangle(677, 90, 121, 67);
	Rectangle obs2 = Rectangle(654, 141, 23, 23);
	Rectangle obs3 = Rectangle(730, 157, 40, 10);
	Rectangle obs4 = Rectangle(697, 245, 80, 56);
	Rectangle obs5 = Rectangle(492, 129, 101, 51);
	Rectangle obs6 = Rectangle(490, 235, 80, 50);
	Rectangle obs7 = Rectangle(570, 229, 290, 12);
	Rectangle obs8 = Rectangle(594, 186, 267, 10);
	Rectangle obs9 = Rectangle(510, 285, 63, 10);
	Rectangle obs10 = Rectangle(493, 347, 102, 60);
	Rectangle obs11 = Rectangle(472, 460, 387, 10);
	Rectangle obs12 = Rectangle(140, 460, 85, 10);
	Rectangle obs13 = Rectangle(345, 460, 65, 10);
	Rectangle obs14 = Rectangle(338, 392, 10, 78);
	Rectangle obs15 = Rectangle(225, 392, 10, 78);
	Rectangle obs16 = Rectangle(225, 392, 113, 10);
	Rectangle obs17 = Rectangle(185, 245, 202, 12);
	Rectangle obs18 = Rectangle(185, 92, 22, 12);
	Rectangle obs19 = Rectangle(185, 92, 9, 155);
	Rectangle obs20 = Rectangle(380, 92, 9, 155);
	Rectangle obs21 = Rectangle(365, 92, 22, 12);

	//colision del jugador con los obstaculos

	if (jugador->getSigRectangle().IntersectsWith(obs))
	{
		jugador->dibujar(g);
	}
	else if (jugador->getSigRectangle().IntersectsWith(obs2)) {
		jugador->dibujar(g);
	}
	else if (jugador->getSigRectangle().IntersectsWith(obs3)) {
		jugador->dibujar(g);
	}
	else if (jugador->getSigRectangle().IntersectsWith(obs4)) {
		jugador->dibujar(g);
	}
	else if (jugador->getSigRectangle().IntersectsWith(obs5)) {
		jugador->dibujar(g);
	}
	else if (jugador->getSigRectangle().IntersectsWith(obs6)) {
		jugador->dibujar(g);
	}
	else if (jugador->getSigRectangle().IntersectsWith(obs7)) {
		jugador->dibujar(g);
	}
	else if (jugador->getSigRectangle().IntersectsWith(obs8)) {
		jugador->dibujar(g);
	}
	else if (jugador->getSigRectangle().IntersectsWith(obs9)) {
		jugador->dibujar(g);
	}
	else if (jugador->getSigRectangle().IntersectsWith(obs10)) {
		jugador->dibujar(g);
	}
	else if (jugador->getSigRectangle().IntersectsWith(obs11)) {
		jugador->dibujar(g);
	}
	else if (jugador->getSigRectangle().IntersectsWith(obs12)) {
		jugador->dibujar(g);
	}
	else if (jugador->getSigRectangle().IntersectsWith(obs13)) {
		jugador->dibujar(g);
	}
	else if (jugador->getSigRectangle().IntersectsWith(obs14)) {
		jugador->dibujar(g);
	}
	else if (jugador->getSigRectangle().IntersectsWith(obs15)) {
		jugador->dibujar(g);
	}
	else if (jugador->getSigRectangle().IntersectsWith(obs16)) {
		jugador->dibujar(g);
	}
	else if (jugador->getSigRectangle().IntersectsWith(obs17)) {
		jugador->dibujar(g);
	}
	else if (jugador->getSigRectangle().IntersectsWith(obs18)) {
		jugador->dibujar(g);
	}
	else if (jugador->getSigRectangle().IntersectsWith(obs19)) {
		jugador->dibujar(g);
	}
	else if (jugador->getSigRectangle().IntersectsWith(obs20)) {
		jugador->dibujar(g);
	}
	else if (jugador->getSigRectangle().IntersectsWith(obs21)) {
		jugador->dibujar(g);
	}
	else
	{
		jugador->mover(g);
	}

	//colision de la vacuna con un obstaculo
	for (int i = 0; i < jugador->getArrVacunas()->size(); i++) {
		if (jugador->getArrVacunas()->at(i)->getRectangle().IntersectsWith(obs))
		{
			//eliminar de mi arreglo a una Vacuna
			jugador->getArrVacunas()->erase(jugador->getArrVacunas()->begin() + i);
			i--;
			break;
		}
		else if (jugador->getArrVacunas()->at(i)->getRectangle().IntersectsWith(obs2))
		{
			jugador->getArrVacunas()->erase(jugador->getArrVacunas()->begin() + i);
			i--;
			break;
		}
		else if (jugador->getArrVacunas()->at(i)->getRectangle().IntersectsWith(obs3))
		{
			jugador->getArrVacunas()->erase(jugador->getArrVacunas()->begin() + i);
			i--;
			break;
		}
		else if (jugador->getArrVacunas()->at(i)->getRectangle().IntersectsWith(obs4))
		{
			jugador->getArrVacunas()->erase(jugador->getArrVacunas()->begin() + i);
			i--;
			break;
		}
		else if (jugador->getArrVacunas()->at(i)->getRectangle().IntersectsWith(obs5))
		{
			jugador->getArrVacunas()->erase(jugador->getArrVacunas()->begin() + i);
			i--;
			break;
		}
		else if (jugador->getArrVacunas()->at(i)->getRectangle().IntersectsWith(obs6))
		{
			jugador->getArrVacunas()->erase(jugador->getArrVacunas()->begin() + i);
			i--;
			break;
		}
		else if (jugador->getArrVacunas()->at(i)->getRectangle().IntersectsWith(obs7))
		{
			jugador->getArrVacunas()->erase(jugador->getArrVacunas()->begin() + i);
			i--;
			break;
		}
		else if (jugador->getArrVacunas()->at(i)->getRectangle().IntersectsWith(obs8))
		{
			jugador->getArrVacunas()->erase(jugador->getArrVacunas()->begin() + i);
			i--;
			break;
		}
		else if (jugador->getArrVacunas()->at(i)->getRectangle().IntersectsWith(obs9))
		{
			jugador->getArrVacunas()->erase(jugador->getArrVacunas()->begin() + i);
			i--;
			break;
		}
		else if (jugador->getArrVacunas()->at(i)->getRectangle().IntersectsWith(obs10))
		{
			jugador->getArrVacunas()->erase(jugador->getArrVacunas()->begin() + i);
			i--;
			break;
		}
		else if (jugador->getArrVacunas()->at(i)->getRectangle().IntersectsWith(obs11))
		{
			jugador->getArrVacunas()->erase(jugador->getArrVacunas()->begin() + i);
			i--;
			break;
		}
		else if (jugador->getArrVacunas()->at(i)->getRectangle().IntersectsWith(obs12))
		{
			jugador->getArrVacunas()->erase(jugador->getArrVacunas()->begin() + i);
			i--;
			break;
		}
		else if (jugador->getArrVacunas()->at(i)->getRectangle().IntersectsWith(obs13))
		{
			jugador->getArrVacunas()->erase(jugador->getArrVacunas()->begin() + i);
			i--;
			break;
		}
		else if (jugador->getArrVacunas()->at(i)->getRectangle().IntersectsWith(obs14))
		{
			jugador->getArrVacunas()->erase(jugador->getArrVacunas()->begin() + i);
			i--;
			break;
		}
		else if (jugador->getArrVacunas()->at(i)->getRectangle().IntersectsWith(obs15))
		{
			jugador->getArrVacunas()->erase(jugador->getArrVacunas()->begin() + i);
			i--;
			break;
		}
		else if (jugador->getArrVacunas()->at(i)->getRectangle().IntersectsWith(obs16))
		{
			jugador->getArrVacunas()->erase(jugador->getArrVacunas()->begin() + i);
			i--;
			break;
		}
		else if (jugador->getArrVacunas()->at(i)->getRectangle().IntersectsWith(obs17))
		{
			jugador->getArrVacunas()->erase(jugador->getArrVacunas()->begin() + i);
			i--;
			break;
		}
		else if (jugador->getArrVacunas()->at(i)->getRectangle().IntersectsWith(obs18))
		{
			jugador->getArrVacunas()->erase(jugador->getArrVacunas()->begin() + i);
			i--;
			break;
		}
		else if (jugador->getArrVacunas()->at(i)->getRectangle().IntersectsWith(obs19))
		{
			jugador->getArrVacunas()->erase(jugador->getArrVacunas()->begin() + i);
			i--;
			break;
		}
		else if (jugador->getArrVacunas()->at(i)->getRectangle().IntersectsWith(obs20))
		{
			jugador->getArrVacunas()->erase(jugador->getArrVacunas()->begin() + i);
			i--;
			break;
		}
		else if (jugador->getArrVacunas()->at(i)->getRectangle().IntersectsWith(obs21))
		{
			jugador->getArrVacunas()->erase(jugador->getArrVacunas()->begin() + i);
			i--;
			break;
		}
	}

	//colision AliadoM con obstaculo
	for (int i = 0; i < arrAliadoM.size(); i++) {
		if (arrAliadoM.at(i)->getRectangle().IntersectsWith(obs))
		{
			arrAliadoM.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoM.at(i)->getRectangle().IntersectsWith(obs2))
		{
			arrAliadoM.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoM.at(i)->getRectangle().IntersectsWith(obs3))
		{
			arrAliadoM.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoM.at(i)->getRectangle().IntersectsWith(obs4))
		{
			arrAliadoM.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoM.at(i)->getRectangle().IntersectsWith(obs5))
		{
			arrAliadoM.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoM.at(i)->getRectangle().IntersectsWith(obs6))
		{
			arrAliadoM.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoM.at(i)->getRectangle().IntersectsWith(obs7))
		{
			arrAliadoM.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoM.at(i)->getRectangle().IntersectsWith(obs8))
		{
			arrAliadoM.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoM.at(i)->getRectangle().IntersectsWith(obs9))
		{
			arrAliadoM.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoM.at(i)->getRectangle().IntersectsWith(obs10))
		{
			arrAliadoM.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoM.at(i)->getRectangle().IntersectsWith(obs11))
		{
			arrAliadoM.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoM.at(i)->getRectangle().IntersectsWith(obs12))
		{
			arrAliadoM.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoM.at(i)->getRectangle().IntersectsWith(obs13))
		{
			arrAliadoM.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoM.at(i)->getRectangle().IntersectsWith(obs14))
		{
			arrAliadoM.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoM.at(i)->getRectangle().IntersectsWith(obs15))
		{
			arrAliadoM.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoM.at(i)->getRectangle().IntersectsWith(obs16))
		{
			arrAliadoM.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoM.at(i)->getRectangle().IntersectsWith(obs17))
		{
			arrAliadoM.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoM.at(i)->getRectangle().IntersectsWith(obs18))
		{
			arrAliadoM.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoM.at(i)->getRectangle().IntersectsWith(obs19))
		{
			arrAliadoM.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoM.at(i)->getRectangle().IntersectsWith(obs20))
		{
			arrAliadoM.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoM.at(i)->getRectangle().IntersectsWith(obs21))
		{
			arrAliadoM.at(i)->moverinverso(g);
			i--;
			break;
		}
	}

	//colision AliadoH con obstaculo
	for (int i = 0; i < arrAliadoH.size(); i++) {
		if (arrAliadoH.at(i)->getRectangle().IntersectsWith(obs))
		{
			arrAliadoH.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoH.at(i)->getRectangle().IntersectsWith(obs2))
		{
			arrAliadoH.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoH.at(i)->getRectangle().IntersectsWith(obs3))
		{
			arrAliadoH.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoH.at(i)->getRectangle().IntersectsWith(obs4))
		{
			arrAliadoH.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoH.at(i)->getRectangle().IntersectsWith(obs5))
		{
			arrAliadoH.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoH.at(i)->getRectangle().IntersectsWith(obs6))
		{
			arrAliadoH.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoH.at(i)->getRectangle().IntersectsWith(obs7))
		{
			arrAliadoH.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoH.at(i)->getRectangle().IntersectsWith(obs8))
		{
			arrAliadoH.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoH.at(i)->getRectangle().IntersectsWith(obs9))
		{
			arrAliadoH.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoH.at(i)->getRectangle().IntersectsWith(obs10))
		{
			arrAliadoH.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoH.at(i)->getRectangle().IntersectsWith(obs11))
		{
			arrAliadoH.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoH.at(i)->getRectangle().IntersectsWith(obs12))
		{
			arrAliadoH.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoH.at(i)->getRectangle().IntersectsWith(obs13))
		{
			arrAliadoH.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoH.at(i)->getRectangle().IntersectsWith(obs14))
		{
			arrAliadoH.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoH.at(i)->getRectangle().IntersectsWith(obs15))
		{
			arrAliadoH.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoH.at(i)->getRectangle().IntersectsWith(obs16))
		{
			arrAliadoH.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoH.at(i)->getRectangle().IntersectsWith(obs17))
		{
			arrAliadoH.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoH.at(i)->getRectangle().IntersectsWith(obs18))
		{
			arrAliadoH.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoH.at(i)->getRectangle().IntersectsWith(obs19))
		{
			arrAliadoH.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoH.at(i)->getRectangle().IntersectsWith(obs20))
		{
			arrAliadoH.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrAliadoH.at(i)->getRectangle().IntersectsWith(obs21))
		{
			arrAliadoH.at(i)->moverinverso(g);
			i--;
			break;
		}
	}

	//colision Infectados con obstaculo
	for (int i = 0; i < arrInfectados.size(); i++) {
		if (arrInfectados.at(i)->getRectangle().IntersectsWith(obs)) {
			arrInfectados.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrInfectados.at(i)->getRectangle().IntersectsWith(obs2)) {
			arrInfectados.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrInfectados.at(i)->getRectangle().IntersectsWith(obs3)) {
			arrInfectados.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrInfectados.at(i)->getRectangle().IntersectsWith(obs4)) {
			arrInfectados.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrInfectados.at(i)->getRectangle().IntersectsWith(obs5)) {
			arrInfectados.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrInfectados.at(i)->getRectangle().IntersectsWith(obs6)) {
			arrInfectados.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrInfectados.at(i)->getRectangle().IntersectsWith(obs7)) {
			arrInfectados.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrInfectados.at(i)->getRectangle().IntersectsWith(obs8)) {
			arrInfectados.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrInfectados.at(i)->getRectangle().IntersectsWith(obs9)) {
			arrInfectados.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrInfectados.at(i)->getRectangle().IntersectsWith(obs10)) {
			arrInfectados.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrInfectados.at(i)->getRectangle().IntersectsWith(obs11)) {
			arrInfectados.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrInfectados.at(i)->getRectangle().IntersectsWith(obs12)) {
			arrInfectados.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrInfectados.at(i)->getRectangle().IntersectsWith(obs13)) {
			arrInfectados.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrInfectados.at(i)->getRectangle().IntersectsWith(obs14)) {
			arrInfectados.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrInfectados.at(i)->getRectangle().IntersectsWith(obs15)) {
			arrInfectados.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrInfectados.at(i)->getRectangle().IntersectsWith(obs16)) {
			arrInfectados.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrInfectados.at(i)->getRectangle().IntersectsWith(obs17)) {
			arrInfectados.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrInfectados.at(i)->getRectangle().IntersectsWith(obs18)) {
			arrInfectados.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrInfectados.at(i)->getRectangle().IntersectsWith(obs19)) {
			arrInfectados.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrInfectados.at(i)->getRectangle().IntersectsWith(obs20)) {
			arrInfectados.at(i)->moverinverso(g);
			i--;
			break;
		}
		else if (arrInfectados.at(i)->getRectangle().IntersectsWith(obs21)) {
			arrInfectados.at(i)->moverinverso(g);
			i--;
			break;
		}
	}
}

void Controladora::colision(Graphics^ g)
{
	//colision de la Vacuna con parte superior del formulario
	for (int i = 0; i < jugador->getArrVacunas()->size(); i++)
	{
		if (jugador->getArrVacunas()->at(i)->movimientoInvalido(g))
		{
			//eliminar de mi arreglo a una Vacuna
			jugador->getArrVacunas()->erase(jugador->getArrVacunas()->begin() + i);
			i--;
			break;
		}
	}

	//colision de la Vacuna con un Infectado
	for (int i = 0; i < jugador->getArrVacunas()->size(); i++)
	{
		for (int j = 0; j < arrInfectados.size(); j++)
		{
			if (jugador->getArrVacunas()->at(i)->getRectangle().IntersectsWith(arrInfectados[j]->getRectangle()))
			{
				//eliminar de mi arreglo a una Vacuna
				jugador->getArrVacunas()->erase(jugador->getArrVacunas()->begin() + i);
				//eliminar a un Infectado de mi arreglo
				arrInfectados.erase(arrInfectados.begin() + j);
				contInfectadosCurados++;
				i--;
				j--;
				break;
			}
		}
	}

	//colision con parte inferior del formulario
	for (int i = 0; i < arrInfectados.size(); i++)
		if (arrInfectados.at(i)->moviminetoInvalido(g))
		{
			arrInfectados.erase(arrInfectados.begin() + i);
			i--;
			break;
		}

	//colision jugador con Infectados
	for (int i = 0; i < arrInfectados.size(); i++) {
		if (arrInfectados.at(i)->getRectangle().IntersectsWith(jugador->getRectangle()))
		{
			jugador = new Protagonista();
			contVidas--;
			i--;
			break;
		}
	}

	//colision jugador con AliadoM
	for (int i = 0; i < arrAliadoM.size(); i++) {
		if (arrAliadoM.at(i)->getRectangle().IntersectsWith(jugador->getRectangle()))
		{
			arrAliadoM.erase(arrAliadoM.begin() + i);
			contVidas++;
			i--;
			break;
		}
	}
	//colision jugador con AliadoH
	for (int i = 0; i < arrAliadoH.size(); i++) {
		if (arrAliadoH.at(i)->getRectangle().IntersectsWith(jugador->getRectangle()))
		{
			arrAliadoH.erase(arrAliadoH.begin() + i);
			contVidas += 4;
			i--;
			break;
		}
	}
}
void Controladora::generarInfectados(Graphics^ g)
{
	if (generar) { cronometro = clock(); generar = false; }
	if ((clock() - cronometro) / CLOCKS_PER_SEC == 5) {
		contInfectadosGenerados++;
		arrInfectados.push_back(new Infectado(g));
		generar = true;
	}
}
void Controladora::disparoJugador()
{
	contVacunasUsadas++;
	jugador->disparo();
}
void Controladora::dibujarAliadoM(Graphics^ g) {
	arrAliadoM.push_back(new AliadoM(g));
}
void Controladora::dibujarAliadoH(Graphics^ g) {
	arrAliadoH.push_back(new AliadoH(g));
}
int Controladora::getVidas() { return contVidas; }
int Controladora::getVacunasUsadas() { return contVacunasUsadas; }
int Controladora::getInfectadosGenerados() { return contInfectadosGenerados; }
int Controladora::getInfectadosCurados() { return contInfectadosCurados; };
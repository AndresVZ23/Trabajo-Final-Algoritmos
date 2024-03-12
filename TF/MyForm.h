#pragma once
#include "Controladora.h"
namespace TF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::Timer^ timer1;
	private:
		Graphics^ g;
		BufferedGraphics^ buffi;
		Bitmap^ imgFondo;
		Controladora* oControladora;
		bool juegoTerminado;
	public:
		MyForm(void)
		{
			InitializeComponent();
			g = this->CreateGraphics();
			buffi = BufferedGraphicsManager::Current->Allocate(g, this->ClientRectangle);
			oControladora = new Controladora(buffi->Graphics);
			imgFondo = gcnew Bitmap("Fondo.jpg");
			juegoTerminado = false;
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se están usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			delete buffi;
			delete g;
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 605);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp_1);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {


		buffi->Graphics->DrawImage(imgFondo, Rectangle(0, 0, g->VisibleClipBounds.Width, g->VisibleClipBounds.Height));
		oControladora->dibujarTodo(buffi->Graphics);
		oControladora->moverTodo(buffi->Graphics);
		oControladora->colision(buffi->Graphics);
		oControladora->generarInfectados(buffi->Graphics);
		oControladora->moverJugador(buffi->Graphics);

		////Con esto logramos verificar la posicion correcta de los obstaculos
		//Rectangle obs = Rectangle(677, 90, 121, 67);
		//Rectangle obs2 = Rectangle(654, 141, 23, 23);
		//Rectangle obs3 = Rectangle(730, 157, 40, 10);
		//Rectangle obs4 = Rectangle(697, 245, 80, 56);
		//Rectangle obs5 = Rectangle(492, 129, 101, 51);
		//Rectangle obs6 = Rectangle(490, 235, 80, 50);
		//Rectangle obs7 = Rectangle(570, 229, 290, 12);
		//Rectangle obs8 = Rectangle(594, 186, 267, 10);
		//Rectangle obs9 = Rectangle(510, 285, 63, 10);
		//Rectangle obs10 = Rectangle(493, 347, 102, 60);
		//Rectangle obs11 = Rectangle(472, 460, 387, 10);
		//Rectangle obs12 = Rectangle(140, 460, 85, 10);
		//Rectangle obs13 = Rectangle(345, 460, 65, 10);
		//Rectangle obs14 = Rectangle(338, 392, 10, 78);
		//Rectangle obs15 = Rectangle(225, 392, 10, 78);
		//Rectangle obs16 = Rectangle(225, 392, 113, 10);
		//Rectangle obs17 = Rectangle(185, 245, 202, 12);
		//Rectangle obs18 = Rectangle(185, 92, 22, 12);
		//Rectangle obs19 = Rectangle(185, 92, 9, 155);
		//Rectangle obs20 = Rectangle(380, 92, 9, 155);
		//Rectangle obs21 = Rectangle(365, 92, 22, 12);
		//Pen^ lapiz = gcnew  Pen(Color::Blue, 3.0);
		//buffi->Graphics->DrawRectangle(lapiz, obs);
		//buffi->Graphics->DrawRectangle(lapiz, obs2);
		//buffi->Graphics->DrawRectangle(lapiz, obs3);
		//buffi->Graphics->DrawRectangle(lapiz, obs4);
		//buffi->Graphics->DrawRectangle(lapiz, obs5);
		//buffi->Graphics->DrawRectangle(lapiz, obs6);
		//buffi->Graphics->DrawRectangle(lapiz, obs7);
		//buffi->Graphics->DrawRectangle(lapiz, obs8);
		//buffi->Graphics->DrawRectangle(lapiz, obs9);
		//buffi->Graphics->DrawRectangle(lapiz, obs10);
		//buffi->Graphics->DrawRectangle(lapiz, obs11);
		//buffi->Graphics->DrawRectangle(lapiz, obs12);
		//buffi->Graphics->DrawRectangle(lapiz, obs13);
		//buffi->Graphics->DrawRectangle(lapiz, obs14);
		//buffi->Graphics->DrawRectangle(lapiz, obs15);
		//buffi->Graphics->DrawRectangle(lapiz, obs16);
		//buffi->Graphics->DrawRectangle(lapiz, obs17);
		//buffi->Graphics->DrawRectangle(lapiz, obs18);
		//buffi->Graphics->DrawRectangle(lapiz, obs19);
		//buffi->Graphics->DrawRectangle(lapiz, obs20);
		//buffi->Graphics->DrawRectangle(lapiz, obs21);

		buffi->Render(g);

		if (oControladora->getInfectadosCurados() >= 15) {
			timer1->Enabled = false;
			MessageBox::Show("Felicitaciones, ganaste el primer nivel !!! :)" + "\n" + "Si deseas un mayor reto, intenta el nivel 2" + "\n\n\n" + "Estadísticas:" + "\n\n" + "Cantidad de vacunas usadas : " + Convert::ToString(oControladora->getVacunasUsadas()) + "\n" + "Cantidad de infectados generados : " + Convert::ToString(oControladora->getInfectadosGenerados()) + "\n" + "Cantidad de infectados curados : " + Convert::ToString(oControladora->getInfectadosCurados()) + "\n" + "Vidas restantes: " + Convert::ToString(oControladora->getVidas()));
			this->Close();
		}
		if (oControladora->getVidas() <= 0) {
			timer1->Enabled = false;
			MessageBox::Show("Fallaste, no lograste completar el primer nivel :(" + "\n" + "Ahora regresarás al menú principal" + "\n\n\n" + "Estadísticas:" + "\n\n" + "Cantidad de vacunas usadas : " + Convert::ToString(oControladora->getVacunasUsadas()) + "\n" + "Cantidad de infectados generados : " + Convert::ToString(oControladora->getInfectadosGenerados()) + "\n" + "Cantidad de infectados curados : " + Convert::ToString(oControladora->getInfectadosCurados()) + "\n" + "Vidas restantes: " + Convert::ToString(oControladora->getVidas()));
			this->Close();
		}
		if (juegoTerminado) {
			timer1->Enabled = false;
			MessageBox::Show("Acabas de cerrar el juego, volverás al menú principal" + "\n\n\n" + "Estadísticas:" + "\n\n" + "Cantidad de vacunas usadas : " + Convert::ToString(oControladora->getVacunasUsadas()) + "\n" + "Cantidad de infectados generados : " + Convert::ToString(oControladora->getInfectadosGenerados()) + "\n" + "Cantidad de infectados curados : " + Convert::ToString(oControladora->getInfectadosCurados()) + "\n" + "Vidas restantes: " + Convert::ToString(oControladora->getVidas()));
			this->Close();
		}
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		oControladora->atenderEventoJugador(true, e->KeyCode);
		switch (e->KeyCode)
		{
		case Keys::Space: oControladora->disparoJugador(); break;
		case Keys::M: oControladora->dibujarAliadoM(buffi->Graphics); break;
		case Keys::H: oControladora->dibujarAliadoH(buffi->Graphics); break;
		case Keys::Escape: juegoTerminado = true;;
		}
	}
	private: System::Void MyForm_KeyUp_1(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		oControladora->atenderEventoJugador(false, e->KeyCode);
	}
	};
}
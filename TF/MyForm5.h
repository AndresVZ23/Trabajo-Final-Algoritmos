#pragma once
#include "ControladoraNivel2.h"
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
	public ref class MyForm5 : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::Timer^ timer1;
	private:
		Graphics^ g;
		BufferedGraphics^ buffi;
		Bitmap^ imgFondoNivel2;
		ControladoraNivel2* oControladora;
		bool juegoTerminado;
	public:
		MyForm5(void)
		{
			InitializeComponent();
			g = this->CreateGraphics();
			buffi = BufferedGraphicsManager::Current->Allocate(g, this->ClientRectangle);
			oControladora = new ControladoraNivel2(buffi->Graphics);
			imgFondoNivel2 = gcnew Bitmap("FondoNivel2.jpeg");
			juegoTerminado = false;
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se están usando.
		/// </summary>
		~MyForm5()
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
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm5::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(984, 605);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm5::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm5::MyForm_KeyUp_1);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {


		buffi->Graphics->DrawImage(imgFondoNivel2, Rectangle(0, 0, g->VisibleClipBounds.Width, g->VisibleClipBounds.Height));
		oControladora->dibujarTodo2(buffi->Graphics);
		oControladora->moverTodo2(buffi->Graphics);
		oControladora->colision2(buffi->Graphics);
		oControladora->generarInfectados2(buffi->Graphics);
		oControladora->moverJugadorNivel2(buffi->Graphics);

		/*Rectangle ob = Rectangle(39, 191, 7, 121);
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
		Pen^ lapiz = gcnew  Pen(Color::Red, 3.0);
		buffi->Graphics->DrawRectangle(lapiz, ob);
		buffi->Graphics->DrawRectangle(lapiz, ob2);
		buffi->Graphics->DrawRectangle(lapiz, ob3);
		buffi->Graphics->DrawRectangle(lapiz, ob4);
		buffi->Graphics->DrawRectangle(lapiz, ob5);
		buffi->Graphics->DrawRectangle(lapiz, ob6);
		buffi->Graphics->DrawRectangle(lapiz, ob7);
		buffi->Graphics->DrawRectangle(lapiz, ob8);
		buffi->Graphics->DrawRectangle(lapiz, ob9);
		buffi->Graphics->DrawRectangle(lapiz, ob10);
		buffi->Graphics->DrawRectangle(lapiz, ob11);
		buffi->Graphics->DrawRectangle(lapiz, ob12);*/

		buffi->Render(g);

		if (oControladora->getVidasPaciente0() <= 0) {
			timer1->Enabled = false;
			MessageBox::Show("Felicidades!!!!! :)" + "\n" + "Ayudaste a capturar al portador del virus, y a los infectados a curarse : )" + "\n" + "Ahora regresarás al menú principal" + "\n\n\n" + "Estadísticas:" + "\n\n" + "Cantidad de vacunas usadas : " + Convert::ToString(oControladora->getVacunasUsadas2()) + "\n" + "Cantidad de infectados generados : " + Convert::ToString(oControladora->getInfectadosGenerados2()) + "\n" + "Cantidad de infectados curados : " + Convert::ToString(oControladora->getInfectadosCurados2()) + "\n" + "Vidas restantes : " + Convert::ToString(oControladora->getVidas2()));
			this->Close();
		}
		if (oControladora->getVidas2() <= 0) {
			timer1->Enabled = false;
			MessageBox::Show("Nooo, fallaste :(" + "\n" + "Los pobladores no lograron recuperarse del virus :((( " + "\n" + "Ahora regresarás al menú principal, pero si deseas puedes volver a intentarlo" + "\n\n\n" + "Estadísticas:" + "\n\n" + "Cantidad de vacunas usadas : " + Convert::ToString(oControladora->getVacunasUsadas2()) + "\n" + "Cantidad de infectados generados : " + Convert::ToString(oControladora->getInfectadosGenerados2()) + "\n" + "Cantidad de infectados curados : " + Convert::ToString(oControladora->getInfectadosCurados2()) + "\n" + "Vidas restantes: " + Convert::ToString(oControladora->getVidas2()));
			this->Close();
		}
		if (juegoTerminado) {
			timer1->Enabled = false;
			MessageBox::Show("Acabas de cerrar el juego, volverás al menú principal" + "\n\n\n" + "Estadísticas:" + "\n\n" + "Cantidad de vacunas usadas : " + Convert::ToString(oControladora->getVacunasUsadas2()) + "\n" + "Cantidad de infectados generados : " + Convert::ToString(oControladora->getInfectadosGenerados2()) + "\n" + "Cantidad de infectados curados : " + Convert::ToString(oControladora->getInfectadosCurados2()) + "\n" + "Vidas restantes: " + Convert::ToString(oControladora->getVidas2()));
			this->Close();
		}
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		oControladora->atenderEventoJugador2(true, e->KeyCode);
		switch (e->KeyCode)
		{
		case Keys::Space: oControladora->disparoJugador2(); break;
		case Keys::M: oControladora->dibujarAliadoM2(buffi->Graphics); break;
		case Keys::H: oControladora->dibujarAliadoH2(buffi->Graphics); break;
		case Keys::Escape: juegoTerminado = true;;
		}
	}
	private: System::Void MyForm_KeyUp_1(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		oControladora->atenderEventoJugador2(false, e->KeyCode);
	}
	};
}

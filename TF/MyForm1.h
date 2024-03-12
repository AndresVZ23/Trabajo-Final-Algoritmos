#pragma once
#include "MyForm.h"
#include "MyForm2.h"
#include "MyForm3.h"
#include "MyForm4.h"
#include "MyForm5.h"
namespace TF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	private:
		Graphics^ g;
		BufferedGraphics^ buffi;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtNombre;

	private: System::Windows::Forms::Button^ btn_Nombre;
	private: System::Windows::Forms::Label^ lblMensaje;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnCreditos;

	private: System::Windows::Forms::Button^ btnInstrucciones;

	private: System::Windows::Forms::Button^ btnHistoria;

		   Bitmap^ imgFondoInicial;
	public:
		MyForm1(void)
		{
			InitializeComponent();
			imgFondoInicial = gcnew Bitmap("FondoInicial.png");
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_Nivel1;
	protected:
	private: System::Windows::Forms::Button^ btn_Nivel2;
	private: System::Windows::Forms::Button^ btn_Salir;

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm1::typeid));
			this->btn_Nivel1 = (gcnew System::Windows::Forms::Button());
			this->btn_Nivel2 = (gcnew System::Windows::Forms::Button());
			this->btn_Salir = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->btn_Nombre = (gcnew System::Windows::Forms::Button());
			this->lblMensaje = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnCreditos = (gcnew System::Windows::Forms::Button());
			this->btnInstrucciones = (gcnew System::Windows::Forms::Button());
			this->btnHistoria = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btn_Nivel1
			// 
			this->btn_Nivel1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->btn_Nivel1->Enabled = false;
			this->btn_Nivel1->Font = (gcnew System::Drawing::Font(L"Segoe Script", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_Nivel1->Location = System::Drawing::Point(188, 410);
			this->btn_Nivel1->Name = L"btn_Nivel1";
			this->btn_Nivel1->Size = System::Drawing::Size(110, 45);
			this->btn_Nivel1->TabIndex = 0;
			this->btn_Nivel1->Text = L"Nivel 1";
			this->btn_Nivel1->UseVisualStyleBackColor = false;
			this->btn_Nivel1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// btn_Nivel2
			// 
			this->btn_Nivel2->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->btn_Nivel2->Enabled = false;
			this->btn_Nivel2->Font = (gcnew System::Drawing::Font(L"Segoe Script", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_Nivel2->Location = System::Drawing::Point(692, 410);
			this->btn_Nivel2->Name = L"btn_Nivel2";
			this->btn_Nivel2->Size = System::Drawing::Size(110, 45);
			this->btn_Nivel2->TabIndex = 1;
			this->btn_Nivel2->Text = L"Nivel 2";
			this->btn_Nivel2->UseVisualStyleBackColor = false;
			this->btn_Nivel2->Click += gcnew System::EventHandler(this, &MyForm1::btn_Nivel2_Click);
			// 
			// btn_Salir
			// 
			this->btn_Salir->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->btn_Salir->Font = (gcnew System::Drawing::Font(L"Segoe Script", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_Salir->Location = System::Drawing::Point(400, 480);
			this->btn_Salir->Name = L"btn_Salir";
			this->btn_Salir->Size = System::Drawing::Size(200, 60);
			this->btn_Salir->TabIndex = 2;
			this->btn_Salir->Text = L"Salir";
			this->btn_Salir->UseVisualStyleBackColor = false;
			this->btn_Salir->Click += gcnew System::EventHandler(this, &MyForm1::btn_Salir_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe Script", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(129, 166);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(103, 27);
			this->label1->TabIndex = 3;
			this->label1->Text = L"NOMBRE: ";
			// 
			// txtNombre
			// 
			this->txtNombre->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->txtNombre->Font = (gcnew System::Drawing::Font(L"Segoe Script", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtNombre->ForeColor = System::Drawing::Color::White;
			this->txtNombre->Location = System::Drawing::Point(248, 166);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(511, 27);
			this->txtNombre->TabIndex = 4;
			// 
			// btn_Nombre
			// 
			this->btn_Nombre->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btn_Nombre->ForeColor = System::Drawing::Color::Chartreuse;
			this->btn_Nombre->Location = System::Drawing::Point(802, 163);
			this->btn_Nombre->Name = L"btn_Nombre";
			this->btn_Nombre->Size = System::Drawing::Size(54, 29);
			this->btn_Nombre->TabIndex = 5;
			this->btn_Nombre->Text = L"Ingresar";
			this->btn_Nombre->UseVisualStyleBackColor = false;
			this->btn_Nombre->Click += gcnew System::EventHandler(this, &MyForm1::btn_Nombre_Click);
			// 
			// lblMensaje
			// 
			this->lblMensaje->AutoSize = true;
			this->lblMensaje->BackColor = System::Drawing::Color::Transparent;
			this->lblMensaje->Font = (gcnew System::Drawing::Font(L"Segoe Print", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblMensaje->ForeColor = System::Drawing::SystemColors::ControlText;
			this->lblMensaje->Location = System::Drawing::Point(138, 216);
			this->lblMensaje->Name = L"lblMensaje";
			this->lblMensaje->Size = System::Drawing::Size(0, 23);
			this->lblMensaje->TabIndex = 6;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe Print", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::HotTrack;
			this->label2->Location = System::Drawing::Point(390, 60);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(226, 86);
			this->label2->TabIndex = 7;
			this->label2->Text = L"TRABAJO FINAL\r\n         SW24";
			// 
			// btnCreditos
			// 
			this->btnCreditos->BackColor = System::Drawing::Color::IndianRed;
			this->btnCreditos->Enabled = false;
			this->btnCreditos->Font = (gcnew System::Drawing::Font(L"Segoe Script", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCreditos->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnCreditos->Location = System::Drawing::Point(134, 263);
			this->btnCreditos->Name = L"btnCreditos";
			this->btnCreditos->Size = System::Drawing::Size(125, 46);
			this->btnCreditos->TabIndex = 8;
			this->btnCreditos->Text = L"Créditos";
			this->btnCreditos->UseVisualStyleBackColor = false;
			this->btnCreditos->Click += gcnew System::EventHandler(this, &MyForm1::btnCreditos_Click);
			// 
			// btnInstrucciones
			// 
			this->btnInstrucciones->BackColor = System::Drawing::Color::IndianRed;
			this->btnInstrucciones->Enabled = false;
			this->btnInstrucciones->Font = (gcnew System::Drawing::Font(L"Segoe Script", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnInstrucciones->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnInstrucciones->Location = System::Drawing::Point(420, 330);
			this->btnInstrucciones->Name = L"btnInstrucciones";
			this->btnInstrucciones->Size = System::Drawing::Size(161, 46);
			this->btnInstrucciones->TabIndex = 9;
			this->btnInstrucciones->Text = L"Instrucciones";
			this->btnInstrucciones->UseVisualStyleBackColor = false;
			this->btnInstrucciones->Click += gcnew System::EventHandler(this, &MyForm1::btnInstrucciones_Click);
			// 
			// btnHistoria
			// 
			this->btnHistoria->BackColor = System::Drawing::Color::IndianRed;
			this->btnHistoria->Enabled = false;
			this->btnHistoria->Font = (gcnew System::Drawing::Font(L"Segoe Script", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnHistoria->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnHistoria->Location = System::Drawing::Point(731, 263);
			this->btnHistoria->Name = L"btnHistoria";
			this->btnHistoria->Size = System::Drawing::Size(125, 46);
			this->btnHistoria->TabIndex = 10;
			this->btnHistoria->Text = L"Historia";
			this->btnHistoria->UseVisualStyleBackColor = false;
			this->btnHistoria->Click += gcnew System::EventHandler(this, &MyForm1::btnHistoria_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(984, 605);
			this->Controls->Add(this->btnHistoria);
			this->Controls->Add(this->btnInstrucciones);
			this->Controls->Add(this->btnCreditos);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lblMensaje);
			this->Controls->Add(this->btn_Nombre);
			this->Controls->Add(this->txtNombre);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btn_Salir);
			this->Controls->Add(this->btn_Nivel2);
			this->Controls->Add(this->btn_Nivel1);
			this->Name = L"MyForm1";
			this->Text = L"MyForm1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Form^ Nivel1 = gcnew MyForm();
		Nivel1->ShowDialog();
		delete Nivel1;
		btn_Nivel2->Enabled = true;
	}
	private: System::Void btn_Salir_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btn_Nombre_Click(System::Object^ sender, System::EventArgs^ e) {
		lblMensaje->Text = "Bienvenido " + txtNombre->Text + ", seleccione una de las siguientes opciones: ";
		btnCreditos->Enabled = true;
		btnHistoria->Enabled = true;
		btnInstrucciones->Enabled = true;
		btn_Nivel1->Enabled = true;
	}
	private: System::Void btnHistoria_Click(System::Object^ sender, System::EventArgs^ e) {
		Form^ Historia = gcnew MyForm2();
		Historia->ShowDialog();
		delete Historia;
	}
	private: System::Void btnCreditos_Click(System::Object^ sender, System::EventArgs^ e) {
		Form^ Creditos = gcnew MyForm3();
		Creditos->ShowDialog();
		delete Creditos;
	}
	private: System::Void btnInstrucciones_Click(System::Object^ sender, System::EventArgs^ e) {
		Form^ Instrucciones = gcnew MyForm4();
		Instrucciones->ShowDialog();
		delete Instrucciones;
	}
	private: System::Void btn_Nivel2_Click(System::Object^ sender, System::EventArgs^ e) {
		Form^ Nivel2 = gcnew MyForm5();
		Nivel2->ShowDialog();
		delete Nivel2;
	}
	};
}
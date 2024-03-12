#pragma once

namespace TF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm4
	/// </summary>
	public ref class MyForm4 : public System::Windows::Forms::Form
	{
	private:
		Graphics^ g;
		BufferedGraphics^ buffi;
	private: System::Windows::Forms::Label^ lblInstrucciones;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnGanar;
	private: System::Windows::Forms::Button^ btnPerder;

		   Bitmap^ imgFondo4;
	public:
		MyForm4(void)
		{
			InitializeComponent();
			imgFondo4 = gcnew Bitmap("Fondo2.jpg");
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm4()
		{
			if (components)
			{
				delete components;
			}
		}

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm4::typeid));
			this->lblInstrucciones = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnGanar = (gcnew System::Windows::Forms::Button());
			this->btnPerder = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblInstrucciones
			// 
			this->lblInstrucciones->AutoSize = true;
			this->lblInstrucciones->BackColor = System::Drawing::Color::Transparent;
			this->lblInstrucciones->Font = (gcnew System::Drawing::Font(L"Segoe Print", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblInstrucciones->ForeColor = System::Drawing::Color::SeaGreen;
			this->lblInstrucciones->Location = System::Drawing::Point(220, 25);
			this->lblInstrucciones->Name = L"lblInstrucciones";
			this->lblInstrucciones->Size = System::Drawing::Size(298, 57);
			this->lblInstrucciones->TabIndex = 0;
			this->lblInstrucciones->Text = L"INSTRUCCIONES";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::SeaGreen;
			this->button1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->button1->Location = System::Drawing::Point(297, 347);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(117, 28);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Regresar";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm4::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe Print", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Blue;
			this->label1->Location = System::Drawing::Point(170, 97);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(214, 207);
			this->label1->TabIndex = 2;
			this->label1->Text = L"MOVER: Teclas Direccionales\r\n\r\nDISPARAR: Barra Espaciadora\r\n\r\nGenerar AliadoH: Te"
				L"cla \"H\"\r\n\r\nGenerar AliadoM: Tecla \"M\"\r\n\r\nTerminar el juego: Tecla ESC";
			// 
			// btnGanar
			// 
			this->btnGanar->BackColor = System::Drawing::Color::Gold;
			this->btnGanar->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnGanar->ForeColor = System::Drawing::SystemColors::InfoText;
			this->btnGanar->Location = System::Drawing::Point(456, 157);
			this->btnGanar->Name = L"btnGanar";
			this->btnGanar->Size = System::Drawing::Size(93, 52);
			this->btnGanar->TabIndex = 3;
			this->btnGanar->Text = L"¿Cómo se\r\ngana\?";
			this->btnGanar->UseVisualStyleBackColor = false;
			this->btnGanar->Click += gcnew System::EventHandler(this, &MyForm4::btnGanar_Click);
			// 
			// btnPerder
			// 
			this->btnPerder->BackColor = System::Drawing::Color::DarkRed;
			this->btnPerder->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnPerder->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->btnPerder->Location = System::Drawing::Point(456, 252);
			this->btnPerder->Name = L"btnPerder";
			this->btnPerder->Size = System::Drawing::Size(93, 52);
			this->btnPerder->TabIndex = 4;
			this->btnPerder->Text = L"¿Cómo se\r\npierde\?";
			this->btnPerder->UseVisualStyleBackColor = false;
			this->btnPerder->Click += gcnew System::EventHandler(this, &MyForm4::btnPerder_Click);
			// 
			// MyForm4
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(724, 453);
			this->Controls->Add(this->btnPerder);
			this->Controls->Add(this->btnGanar);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->lblInstrucciones);
			this->Name = L"MyForm4";
			this->Text = L"MyForm4";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btnGanar_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("NIVEL 1" + "\n" + "Logrando curar a 15 infectados" + "\n\n" + "NIVEL 2" + "\n" + "Logrando derrotar al portador del virus");
	}
	private: System::Void btnPerder_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("NIVEL 1 y 2" + "\n" + "Al perder todas las vidas (3 en el primer nivel y 4 en el segundo nivel)");
	}
	};
}
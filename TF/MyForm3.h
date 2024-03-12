#pragma once
namespace TF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm3
	/// </summary>
	public ref class MyForm3 : public System::Windows::Forms::Form
	{
	private:
		Graphics^ g;
		BufferedGraphics^ buffi;
	private: System::Windows::Forms::Label^ lblCreditos;
	private: System::Windows::Forms::Label^ lbl_creditos;
	private: System::Windows::Forms::Button^ btn_regresarcreditos;

		   Bitmap^ imgFondo3;
	public:
		MyForm3(void)
		{
			InitializeComponent();
			imgFondo3 = gcnew Bitmap("Fondo2.jpg");
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm3()
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm3::typeid));
			this->lblCreditos = (gcnew System::Windows::Forms::Label());
			this->lbl_creditos = (gcnew System::Windows::Forms::Label());
			this->btn_regresarcreditos = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblCreditos
			// 
			this->lblCreditos->AutoSize = true;
			this->lblCreditos->BackColor = System::Drawing::Color::Transparent;
			this->lblCreditos->Font = (gcnew System::Drawing::Font(L"Segoe Print", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCreditos->ForeColor = System::Drawing::Color::RoyalBlue;
			this->lblCreditos->Location = System::Drawing::Point(280, 50);
			this->lblCreditos->Name = L"lblCreditos";
			this->lblCreditos->Size = System::Drawing::Size(194, 57);
			this->lblCreditos->TabIndex = 0;
			this->lblCreditos->Text = L"CRÉDITOS";
			// 
			// lbl_creditos
			// 
			this->lbl_creditos->AutoSize = true;
			this->lbl_creditos->BackColor = System::Drawing::Color::Transparent;
			this->lbl_creditos->Font = (gcnew System::Drawing::Font(L"Segoe Print", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_creditos->ForeColor = System::Drawing::Color::DarkGreen;
			this->lbl_creditos->Location = System::Drawing::Point(136, 160);
			this->lbl_creditos->Name = L"lbl_creditos";
			this->lbl_creditos->Size = System::Drawing::Size(457, 78);
			this->lbl_creditos->TabIndex = 1;
			this->lbl_creditos->Text = L"Abel Andrés Valle Zuta                  -      U202210297\r\nKevin Fabricio Grados "
				L"Farfán           -      U202218419\r\nMarcelo Sebastian Ramirez Ramirez  -      U2"
				L"02210582";
			// 
			// btn_regresarcreditos
			// 
			this->btn_regresarcreditos->BackColor = System::Drawing::Color::RoyalBlue;
			this->btn_regresarcreditos->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->btn_regresarcreditos->Location = System::Drawing::Point(290, 300);
			this->btn_regresarcreditos->Name = L"btn_regresarcreditos";
			this->btn_regresarcreditos->Size = System::Drawing::Size(136, 29);
			this->btn_regresarcreditos->TabIndex = 2;
			this->btn_regresarcreditos->Text = L"Regresar";
			this->btn_regresarcreditos->UseVisualStyleBackColor = false;
			this->btn_regresarcreditos->Click += gcnew System::EventHandler(this, &MyForm3::btn_regresarcreditos_Click);
			// 
			// MyForm3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(724, 453);
			this->Controls->Add(this->btn_regresarcreditos);
			this->Controls->Add(this->lbl_creditos);
			this->Controls->Add(this->lblCreditos);
			this->Name = L"MyForm3";
			this->Text = L"MyForm3";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_regresarcreditos_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}

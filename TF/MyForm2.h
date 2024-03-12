#pragma once
namespace TF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm2
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	private:
		Graphics^ g;
		BufferedGraphics^ buffi;
	private: System::Windows::Forms::Label^ lblHistoria;

	private: System::Windows::Forms::Label^ lbl_Historia;
	private: System::Windows::Forms::Button^ btnHistoria_Regresar;


		   Bitmap^ imgFondo2;
	public:
		MyForm2(void)
		{
			InitializeComponent();
			imgFondo2 = gcnew Bitmap("Fondo2.jpg");
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm2()
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm2::typeid));
			this->lblHistoria = (gcnew System::Windows::Forms::Label());
			this->lbl_Historia = (gcnew System::Windows::Forms::Label());
			this->btnHistoria_Regresar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lblHistoria
			// 
			this->lblHistoria->AutoSize = true;
			this->lblHistoria->BackColor = System::Drawing::Color::Transparent;
			this->lblHistoria->Font = (gcnew System::Drawing::Font(L"Segoe Print", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblHistoria->ForeColor = System::Drawing::Color::Firebrick;
			this->lblHistoria->Location = System::Drawing::Point(280, 20);
			this->lblHistoria->Name = L"lblHistoria";
			this->lblHistoria->Size = System::Drawing::Size(186, 57);
			this->lblHistoria->TabIndex = 0;
			this->lblHistoria->Text = L"HISTORIA";
			// 
			// lbl_Historia
			// 
			this->lbl_Historia->AutoSize = true;
			this->lbl_Historia->BackColor = System::Drawing::Color::Transparent;
			this->lbl_Historia->Font = (gcnew System::Drawing::Font(L"Segoe Print", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Historia->ForeColor = System::Drawing::Color::Purple;
			this->lbl_Historia->Location = System::Drawing::Point(109, 104);
			this->lbl_Historia->Name = L"lbl_Historia";
			this->lbl_Historia->Size = System::Drawing::Size(518, 231);
			this->lbl_Historia->TabIndex = 1;
			this->lbl_Historia->Text = resources->GetString(L"lbl_Historia.Text");
			// 
			// btnHistoria_Regresar
			// 
			this->btnHistoria_Regresar->BackColor = System::Drawing::Color::DarkRed;
			this->btnHistoria_Regresar->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->btnHistoria_Regresar->Location = System::Drawing::Point(307, 347);
			this->btnHistoria_Regresar->Name = L"btnHistoria_Regresar";
			this->btnHistoria_Regresar->Size = System::Drawing::Size(119, 25);
			this->btnHistoria_Regresar->TabIndex = 2;
			this->btnHistoria_Regresar->Text = L"Regresar";
			this->btnHistoria_Regresar->UseVisualStyleBackColor = false;
			this->btnHistoria_Regresar->Click += gcnew System::EventHandler(this, &MyForm2::button1_Click);
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(724, 453);
			this->Controls->Add(this->btnHistoria_Regresar);
			this->Controls->Add(this->lbl_Historia);
			this->Controls->Add(this->lblHistoria);
			this->Name = L"MyForm2";
			this->Text = L"MyForm2";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
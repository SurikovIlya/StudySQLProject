#pragma once
#include "SQLStudy.h"

namespace StudySQLProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textName;
	private: System::Windows::Forms::Button^ btnInsertName;
	private: System::Windows::Forms::ComboBox^ cmbNames;
	private: System::Windows::Forms::Button^ btnFillNames;
	private: System::Windows::Forms::Button^ btnDelete;
	private: System::Windows::Forms::TextBox^ textUpdateName;
	private: System::Windows::Forms::Button^ btnUpdateName;




	protected:


	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textName = (gcnew System::Windows::Forms::TextBox());
			this->btnInsertName = (gcnew System::Windows::Forms::Button());
			this->cmbNames = (gcnew System::Windows::Forms::ComboBox());
			this->btnFillNames = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->textUpdateName = (gcnew System::Windows::Forms::TextBox());
			this->btnUpdateName = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textName
			// 
			this->textName->Location = System::Drawing::Point(12, 21);
			this->textName->Name = L"textName";
			this->textName->Size = System::Drawing::Size(331, 20);
			this->textName->TabIndex = 0;
			this->textName->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// btnInsertName
			// 
			this->btnInsertName->Location = System::Drawing::Point(12, 57);
			this->btnInsertName->Name = L"btnInsertName";
			this->btnInsertName->Size = System::Drawing::Size(331, 23);
			this->btnInsertName->TabIndex = 1;
			this->btnInsertName->Text = L"InsertName";
			this->btnInsertName->UseVisualStyleBackColor = true;
			this->btnInsertName->Click += gcnew System::EventHandler(this, &MyForm::btnInsertName_Click);
			// 
			// cmbNames
			// 
			this->cmbNames->FormattingEnabled = true;
			this->cmbNames->Location = System::Drawing::Point(12, 137);
			this->cmbNames->Name = L"cmbNames";
			this->cmbNames->Size = System::Drawing::Size(331, 21);
			this->cmbNames->TabIndex = 2;
			// 
			// btnFillNames
			// 
			this->btnFillNames->Location = System::Drawing::Point(12, 174);
			this->btnFillNames->Name = L"btnFillNames";
			this->btnFillNames->Size = System::Drawing::Size(154, 23);
			this->btnFillNames->TabIndex = 3;
			this->btnFillNames->Text = L"FillNames";
			this->btnFillNames->UseVisualStyleBackColor = true;
			this->btnFillNames->Click += gcnew System::EventHandler(this, &MyForm::btnFillNames_Click);
			// 
			// btnDelete
			// 
			this->btnDelete->Location = System::Drawing::Point(189, 174);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(154, 23);
			this->btnDelete->TabIndex = 4;
			this->btnDelete->Text = L"Delete";
			this->btnDelete->UseVisualStyleBackColor = true;
			this->btnDelete->Click += gcnew System::EventHandler(this, &MyForm::btnDelete_Click);
			// 
			// textUpdateName
			// 
			this->textUpdateName->Location = System::Drawing::Point(12, 247);
			this->textUpdateName->Name = L"textUpdateName";
			this->textUpdateName->Size = System::Drawing::Size(331, 20);
			this->textUpdateName->TabIndex = 5;
			this->textUpdateName->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged_1);
			// 
			// btnUpdateName
			// 
			this->btnUpdateName->Location = System::Drawing::Point(12, 284);
			this->btnUpdateName->Name = L"btnUpdateName";
			this->btnUpdateName->Size = System::Drawing::Size(331, 23);
			this->btnUpdateName->TabIndex = 6;
			this->btnUpdateName->Text = L"UpdateName";
			this->btnUpdateName->UseVisualStyleBackColor = true;
			this->btnUpdateName->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(359, 329);
			this->Controls->Add(this->btnUpdateName);
			this->Controls->Add(this->textUpdateName);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->btnFillNames);
			this->Controls->Add(this->cmbNames);
			this->Controls->Add(this->btnInsertName);
			this->Controls->Add(this->textName);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) 
	{

	}

	private: System::Void btnInsertName_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		SQLStudy SqlStudy;
		Names^ n = gcnew Names();

		n->Name = textName->Text;

		SqlStudy.Insert(n);
	}

	private: System::Void btnFillNames_Click(System::Object^ sender, System::EventArgs^ e)
	{
		SQLStudy SqlStudy;

		cmbNames->DataSource = SqlStudy.FillComboBox();
	}

	private: System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		SQLStudy SqlStudy;
		Names^ n = gcnew Names();

		String^ strokaFromCmb;

		strokaFromCmb = Convert::ToString(cmbNames->SelectedItem);

		array<String^, 1>^ parts = strokaFromCmb->Split(gcnew array<Char, 1>{'-'}, System::StringSplitOptions::RemoveEmptyEntries);

		n->ID = Convert::ToInt32(parts[0]);
		n->Name = parts[1];

		SqlStudy.Delete(n);
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		SQLStudy SqlStudy;

		if (textUpdateName->Text == "")
			MessageBox::Show("Поле для ввода новго имени не может ыбть пустым!");
		else
		{
			Names^ nOld = gcnew Names();

			String^ strokaFromCmb;

			strokaFromCmb = Convert::ToString(cmbNames->SelectedItem);

			array<String^, 1>^ parts = strokaFromCmb->Split(gcnew array<Char, 1>{'-'}, System::StringSplitOptions::RemoveEmptyEntries);

			nOld->ID = Convert::ToInt32(parts[0]);
			nOld->Name = parts[1];

			Names^ nNew = gcnew Names();

			nNew->Name = textUpdateName->Text;

			SqlStudy.Update(nOld, nNew);
		}
	}

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void textBox1_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
	}
};
}

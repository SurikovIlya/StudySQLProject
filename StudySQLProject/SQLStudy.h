#pragma once
#include "Names.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace Data;
using namespace Data::SqlClient;

ref class SQLStudy
{
public:
	SqlConnection^ conn;
	SqlConnectionStringBuilder^ connStrBuilder;

	void ConnectToDB()
	{
		// Data Source=DESKTOP-41M3H1B\SQLEXPRESS;Initial Catalog=SQLStudyDB;Integrated Security=True
		connStrBuilder = gcnew SqlConnectionStringBuilder();
		connStrBuilder->DataSource = "DESKTOP-41M3H1B\\SQLEXPRESS";
		connStrBuilder->InitialCatalog = "SQLStudyDB";
		connStrBuilder->IntegratedSecurity = true;

		conn = gcnew SqlConnection(Convert::ToString(connStrBuilder));
	}

	// Insert
	void Insert(Names^ n)
	{
		try
		{
			// Подключаемся к БД.
			ConnectToDB();

			String^ cmdText = "INSERT INTO dbo.SQLStudyDB_1(Name) VALUES(@NameVstavka)";
			SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);

			// Устанавливаем параметр, который примем из "MyForm".
			cmd->Parameters->AddWithValue("@NameVstavka", n->Name);
			conn->Open();
			cmd->ExecuteNonQuery();
		}
		finally
		{
			if (conn != nullptr)
			{
				conn->Close();
			}
		}
	}

	// FillComboBox
	ListBox::ObjectCollection^ FillComboBox()
	{
		try
		{
			// Подключаемся к БД.
			ConnectToDB();

			// Создаем список
			ListBox^ ListWithNames = gcnew ListBox();
			Names^ n = gcnew Names();

			String^ cmdText = "SELECT * FROM dbo.SQLStudyDB_1";
			SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);

			conn->Open();

			SqlDataReader^ reader = cmd->ExecuteReader();

			// Цикл по строкам таблицы dbo.SQLStudyDB_1
			while (reader->Read())
			{
				n->ID = Convert::ToInt32(reader["ID"]->ToString());
				n->Name = (reader["Name"]->ToString());

				// Заполняем список в нужном формате
				ListWithNames->Items->Add(String::Format("{0}-{1}", n->ID, n->Name));
			}

			return ListWithNames->Items;
		}
		finally
		{
			if (conn != nullptr)
			{
				conn->Close();
			}
		}
	}

	// Delete
	void Delete(Names^ n)
	{
		try
		{
			// Подключаемся к БД.
			ConnectToDB();

			String^ cmdText = "DELETE FROM dbo.SQLStudyDB_1 WHERE ID = @ID";
			SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);
			cmd->Parameters->AddWithValue("@ID", n->id);

			conn->Open();

			cmd->ExecuteNonQuery();
		}
		finally
		{
			if (conn != nullptr)
			{
				conn->Close();
			}
		}
	}

	// Update
	void Update(Names^ nOld, Names^ nNew)
	{
		try
		{
			// Подключаемся к БД.
			ConnectToDB();

			String^ cmdText = "UPDATE dbo.SQLStudyDB_1 SET Name = @Name WHERE ID = @ID";
			SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);

			// Устанавливаем параметр, который примем из "MyForm".
			cmd->Parameters->AddWithValue("@Name", nNew->Name);
			cmd->Parameters->AddWithValue("@ID", nOld->ID);
			
			conn->Open();
			cmd->ExecuteNonQuery();
		}
		finally
		{
			if (conn != nullptr)
			{
				conn->Close();
			}
		}
	}
};


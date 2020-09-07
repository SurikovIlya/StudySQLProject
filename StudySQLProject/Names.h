#pragma once
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace Data;
using namespace Data::SqlClient;

ref class Names
{
public:
	static int id;
	static String^ name;

	static property int ID
	{
		int get()
		{
			return id;
		}

		void set(int value)
		{
			id = value;
		}
	}

	static property String^ Name
	{
		String^ get()
		{
			return name;
		}

		void set(String^ value)
		{
			name = value;
		}
	}
};


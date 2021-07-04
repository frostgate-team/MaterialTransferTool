#pragma once

#include "core.h"
#include <msclr\marshal_cppstd.h>

TextureMap material;

namespace MaterialTransferTool {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ToolWindow
	/// </summary>
	public ref class ToolWindow : public System::Windows::Forms::Form
	{
	public:
		ToolWindow(void)
		{
			
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ToolWindow()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fIleToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ newToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ quitToolStripMenuItem;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;


	private: System::Windows::Forms::GroupBox^ groupBox3;

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::CheckBox^ checkBox3;




	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::Label^ label10;


	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ToolWindow::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fIleToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->quitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fIleToolStripMenuItem1 });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(747, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fIleToolStripMenuItem1
			// 
			this->fIleToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->newToolStripMenuItem,
					this->aboutToolStripMenuItem, this->quitToolStripMenuItem
			});
			this->fIleToolStripMenuItem1->Name = L"fIleToolStripMenuItem1";
			this->fIleToolStripMenuItem1->Size = System::Drawing::Size(37, 20);
			this->fIleToolStripMenuItem1->Text = L"FIle";
			// 
			// newToolStripMenuItem
			// 
			this->newToolStripMenuItem->Name = L"newToolStripMenuItem";
			this->newToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->newToolStripMenuItem->Text = L"Open";
			this->newToolStripMenuItem->Click += gcnew System::EventHandler(this, &ToolWindow::newToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			// 
			// quitToolStripMenuItem
			// 
			this->quitToolStripMenuItem->Name = L"quitToolStripMenuItem";
			this->quitToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->quitToolStripMenuItem->Text = L"Quit";
			this->quitToolStripMenuItem->Click += gcnew System::EventHandler(this, &ToolWindow::quitToolStripMenuItem_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Silver;
			this->pictureBox1->Location = System::Drawing::Point(6, 19);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(344, 329);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(6, 364);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(344, 23);
			this->progressBar1->TabIndex = 3;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox8);
			this->groupBox1->Controls->Add(this->label10);
			this->groupBox1->Controls->Add(this->checkBox1);
			this->groupBox1->Controls->Add(this->checkBox3);
			this->groupBox1->Location = System::Drawing::Point(12, 284);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(346, 101);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Parameters";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &ToolWindow::groupBox1_Enter);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(6, 43);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(136, 17);
			this->checkBox1->TabIndex = 3;
			this->checkBox1->Text = L"Not to do specular map";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(6, 19);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(109, 17);
			this->checkBox3->TabIndex = 2;
			this->checkBox3->Text = L"Don\'t write log file";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Controls->Add(this->pictureBox1);
			this->groupBox2->Controls->Add(this->progressBar1);
			this->groupBox2->Location = System::Drawing::Point(379, 37);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(356, 402);
			this->groupBox2->TabIndex = 5;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Image";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Black;
			this->label7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(17, 53);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(43, 13);
			this->label7->TabIndex = 5;
			this->label7->Text = L"Physics";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Black;
			this->label9->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(17, 27);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(57, 13);
			this->label9->TabIndex = 4;
			this->label9->Text = L"Resolution";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label8);
			this->groupBox3->Controls->Add(this->textBox7);
			this->groupBox3->Controls->Add(this->label6);
			this->groupBox3->Controls->Add(this->label5);
			this->groupBox3->Controls->Add(this->label4);
			this->groupBox3->Controls->Add(this->label3);
			this->groupBox3->Controls->Add(this->label2);
			this->groupBox3->Controls->Add(this->textBox6);
			this->groupBox3->Controls->Add(this->textBox5);
			this->groupBox3->Controls->Add(this->textBox4);
			this->groupBox3->Controls->Add(this->textBox3);
			this->groupBox3->Controls->Add(this->textBox2);
			this->groupBox3->Controls->Add(this->label1);
			this->groupBox3->Controls->Add(this->textBox1);
			this->groupBox3->Location = System::Drawing::Point(13, 37);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(345, 241);
			this->groupBox3->TabIndex = 6;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Map info";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(6, 211);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(29, 13);
			this->label8->TabIndex = 15;
			this->label8->Text = L"Path";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(67, 204);
			this->textBox7->Name = L"textBox7";
			this->textBox7->ReadOnly = true;
			this->textBox7->Size = System::Drawing::Size(272, 20);
			this->textBox7->TabIndex = 14;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 160);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(59, 13);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Illumination";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 133);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(34, 13);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Alpha";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 106);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(38, 13);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Height";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 79);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(49, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Specular";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 53);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(40, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Normal";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(67, 153);
			this->textBox6->Name = L"textBox6";
			this->textBox6->ReadOnly = true;
			this->textBox6->Size = System::Drawing::Size(272, 20);
			this->textBox6->TabIndex = 8;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(67, 126);
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->Size = System::Drawing::Size(272, 20);
			this->textBox5->TabIndex = 7;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(67, 99);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(272, 20);
			this->textBox4->TabIndex = 6;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(67, 72);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(272, 20);
			this->textBox3->TabIndex = 5;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(67, 46);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(272, 20);
			this->textBox2->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(40, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Diffuse";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::Control;
			this->textBox1->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->textBox1->Location = System::Drawing::Point(67, 20);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(272, 20);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 401);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ToolWindow::button1_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(6, 67);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(79, 13);
			this->label10->TabIndex = 4;
			this->label10->Text = L"Material List file";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(89, 64);
			this->textBox8->Name = L"textBox8";
			this->textBox8->ReadOnly = true;
			this->textBox8->Size = System::Drawing::Size(251, 20);
			this->textBox8->TabIndex = 15;
			// 
			// ToolWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(747, 450);
			this->ControlBox = false;
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(763, 489);
			this->MinimumSize = System::Drawing::Size(763, 489);
			this->Name = L"ToolWindow";
			this->Text = L"MaterialTransferTool";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		string getFilePath(string mat_filepath, string mat_type)
		{
			for (size_t i = mat_filepath.length() - 1; i != 0; i--)
			{
				if (mat_filepath[i] == '\\')
					return mat_filepath + mat_type;
				mat_filepath.pop_back();
			}
			return mat_filepath + mat_type;
		}

		string SysToStd(System::String^ sysString)
		{
			return msclr::interop::marshal_as<std::string>(sysString);
		}

		System::String^ StdToSys(std::string stdStr)
		{
			return msclr::interop::marshal_as<System::String^>(stdStr);
		}

		void writeLog()
		{
			std::ofstream logfile;
			std::string namae = SysToStd(textBox7->Text);
			std::smatch match;

			regex_search(namae, match, regex("\\w+$"));
			namae = match.str();

			logfile.open(namae+"log");
			logfile << "<log>\n";
			logfile << "\t<info>\n";
			logfile << "\tmaterial name is: " << namae + "mat\n";
			logfile << "\tTexture has been upscaled to " << SysToStd(label9->Text) << std::endl;
			logfile << "\t</info>\n";
			logfile << "\t<textures>\n";
			if (textBox1->Text != "NONE" || textBox1->Text != "")
				logfile << "\t" << SysToStd(textBox1->Text) << std::endl;
			if (textBox2->Text != "NONE" || textBox2->Text != "")
				logfile << "\t" << SysToStd(textBox2->Text) << std::endl;
			if (textBox3->Text != "NONE" || textBox3->Text != "")
				logfile << "\t" << SysToStd(textBox3->Text) << std::endl;
			if (textBox4->Text != "NONE" || textBox4->Text != "")
				logfile << "\t" << SysToStd(textBox4->Text) << std::endl;
			if (textBox5->Text != "NONE" || textBox5->Text != "")
				logfile << "\t" << SysToStd(textBox5->Text) << std::endl;
			if (textBox6->Text != "NONE" || textBox6->Text != "")
				logfile << "\t" << SysToStd(textBox6->Text) << std::endl;
			logfile << "\t</textures>\n";
			logfile << "</log>";
			logfile.close();
		}
#pragma endregion
	private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
	}


private: System::Void newToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	try
	{
		delete pictureBox1->Image;
		pictureBox1->Image = nullptr;
		MatReader materialReader;
		std::remove(material.getHashPath().c_str());
		OpenFileDialog^ ofd = gcnew OpenFileDialog();
		ofd->Filter = "HPL Materials(*.mat)|*.mat";
		if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			String^ filename = gcnew String(ofd->FileName);
			materialReader.ReadAllLines(msclr::interop::marshal_as<std::string>(filename));
			progressBar1->Value = 10;
			textBox1->Text = StdToSys(materialReader.getDiffuseLocation());
			progressBar1->Value = 20;
			textBox2->Text = StdToSys(materialReader.getNMapLocation());
			progressBar1->Value = 30;
			textBox3->Text = StdToSys(materialReader.getSpecularLocation());
			progressBar1->Value = 40;
			textBox4->Text = StdToSys(materialReader.getHeightLocation());
			progressBar1->Value = 50;
			textBox5->Text = StdToSys(materialReader.getAlphaLocation());
			progressBar1->Value = 60;
			textBox6->Text = StdToSys(materialReader.getIlluminationLocation());
			textBox7->Text = filename;
			progressBar1->Value = 70;
			material.createHiddenLinkImage(getFilePath(SysToStd(filename), materialReader.getDiffuseLocation()));
			progressBar1->Value = 80;
			pictureBox1->Image = pictureBox1->Image->FromFile(StdToSys(material.getHashPath()));
			progressBar1->Value = 90;
			label7->Text = StdToSys(materialReader.getPhysMaterial());
			label9->Text = StdToSys(material.getImageRes());
			progressBar1->Value = 100;
			progressBar1->Text = "Ready";
		}
	}
	catch (const std::exception& ex)
	{
		//String^ exception = msclr::interop::marshal_as<String^>(ex.what());
		MessageBox::Show(StdToSys(ex.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
private: System::Void quitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	delete pictureBox1->Image;
	pictureBox1->Image = nullptr;
	std::remove(material.getHashPath().c_str());
	Application::ExitThread();
}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	string label = msclr::interop::marshal_as<std::string>(label7->Text);
	smatch match;

	if (textBox1->Text != "NONE" && textBox1->Text != "") { 
		material.TextureUpscale(getFilePath(SysToStd(textBox7->Text), SysToStd(textBox1->Text))); progressBar1->Value = 10; }
	if (textBox2->Text != "NONE" && textBox2->Text != "") {
		material.TextureUpscale(getFilePath(SysToStd(textBox7->Text), SysToStd(textBox2->Text))); progressBar1->Value = 20; }
	if (textBox5->Text != "NONE" && textBox5->Text != "") {
		material.TextureUpscale(getFilePath(SysToStd(textBox7->Text), SysToStd(textBox5->Text))); progressBar1->Value = 25; }
	if (textBox6->Text != "NONE" && textBox6->Text != "") {
		material.TextureUpscale(getFilePath(SysToStd(textBox7->Text), SysToStd(textBox6->Text))); progressBar1->Value = 30; }


	if (!checkBox1->Checked)
	{
		if (regex_search(label, match, regex("Rock")) || regex_search(label, match, regex("rock")))
		{
			material.MakeSpecularFromDiffuse(getFilePath(SysToStd(textBox7->Text), SysToStd(textBox1->Text)), ROCK);
			progressBar1->Value = 100;
		}
		else if (regex_search(label, match, regex("Wood")) || regex_search(label, match, regex("wood")))
		{
			material.MakeSpecularFromDiffuse(getFilePath(SysToStd(textBox7->Text), SysToStd(textBox1->Text)), WOOD);
			progressBar1->Value = 100;
		}
		else if (regex_search(label, match, regex("Organic")) || regex_search(label, match, regex("organic")))
		{
			material.MakeSpecularFromDiffuse(getFilePath(SysToStd(textBox7->Text), SysToStd(textBox1->Text)), ORGANIC);
			progressBar1->Value = 100;
		}
		else if (regex_search(label, match, regex("Metal")) || regex_search(label, match, regex("metal")))
		{
			material.MakeSpecularFromDiffuse(getFilePath(SysToStd(textBox7->Text), SysToStd(textBox1->Text)), ROCK);
			progressBar1->Value = 100;
		}
		else
		{
			material.MakeSpecularFromDiffuse(getFilePath(SysToStd(textBox7->Text), SysToStd(textBox1->Text)), DEFAULT);
			progressBar1->Value = 100;
		}
	}
	else
	{
		if (textBox3->Text != "NONE" || textBox3->Text != "") {
			material.TextureUpscale(getFilePath(SysToStd(textBox7->Text), SysToStd(textBox3->Text)));
		}
		progressBar1->Value = 100;
		writeLog();
	}
}
};
}

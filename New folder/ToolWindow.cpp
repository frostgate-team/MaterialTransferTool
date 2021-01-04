#include "ToolWindow.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	MaterialTransferTool::ToolWindow form;
	Application::Run(% form);
}
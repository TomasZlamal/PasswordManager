#include "../include/App.hpp"
#include "../include/frame.hpp"
wxIMPLEMENT_APP(App);
bool App::OnInit()
{

	MyFrame* frame = new MyFrame(wxT("Password manager"), hasPassword());
	frame->SetBackgroundColour(wxColour(*wxWHITE));
	frame->Center();
	frame->SetClientSize(700, 400);

	frame->Show(true);
		
	return true;
}

bool App::hasPassword()
{
	return true;
}

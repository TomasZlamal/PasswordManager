#include "../include/frame.hpp"

MyFrame::MyFrame(const wxString& title, bool hasPassword)
  : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, { 700, 400 }, wxCAPTION | wxCLOSE_BOX | wxCLIP_CHILDREN)
{
  currentText = "";

  // input
  wxPanel* inputPanel = new wxPanel(this);
  this->inputPanel = inputPanel;
  wxButton* button = new wxButton(inputPanel, wxID_ANY, "Submit", wxPoint(300, 200), wxSize(70, 40));
  wxStaticText* text = new wxStaticText(inputPanel, wxID_ANY, "Input your encryption key", wxPoint(270, 140));
  wxTextCtrl* input = new wxTextCtrl(inputPanel, wxID_ANY, "", wxPoint(280, 170), wxSize(100, 20), wxTE_PASSWORD);
  button->Bind(wxEVT_BUTTON, &MyFrame::OnButtonClicked, this);
  input->Bind(wxEVT_TEXT, &MyFrame::OnTextChanged, this);
  // home
  
  /*wxPanel* homePanel = new wxPanel(this);
  wxStaticText* homeText = new wxStaticText(homePanel, wxID_ANY, "This is the home page", wxPoint(270, 140));
  this->homePanel = homePanel;

  homePanel->Hide();*/

  CreateStatusBar();
  if (!hasPassword) {
    state = appStatus::home;
  }
  else {
    state = appStatus::login;
  }
  refresh();
}
void MyFrame::refresh() {
  switch (state) {
    case appStatus::login: {
      wxLogStatus("Show");
      inputPanel->Show();
    } break;
    case appStatus::home: {
      wxPanel* homePanel = new wxPanel(this);
      wxStaticText* homeText = new wxStaticText(homePanel, wxID_ANY, "This is the home page", wxPoint(270, 140));
      this->homePanel = homePanel;
    } break;
  }
}
void MyFrame::OnButtonClicked(wxCommandEvent& evt) {
  wxLogStatus("Key inputted");
  password = currentText;
  state = appStatus::home;
  inputPanel->Hide();
  refresh();
}
void MyFrame::OnTextChanged(wxCommandEvent& evt) {
  currentText = evt.GetString();
  
}
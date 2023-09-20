#include "../include/frame.hpp"

MyFrame::MyFrame(const wxString& title, bool hasPassword)
  : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, { 700, 400 }, wxCAPTION | wxCLOSE_BOX | wxCLIP_CHILDREN)
{
  currentText = "";

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
  if (this->currentPanel) {
    this->currentPanel->Destroy();
  }
  switch (state) {
    case appStatus::login: {
      wxPanel* inputPanel = new wxPanel(this);
      this->currentPanel = inputPanel;
      wxButton* button = new wxButton(inputPanel, wxID_ANY, "Submit", wxPoint(300, 200), wxSize(70, 40));
      wxStaticText* text = new wxStaticText(inputPanel, wxID_ANY, "Input your encryption key", wxPoint(270, 140));
      wxTextCtrl* input = new wxTextCtrl(inputPanel, wxID_ANY, "", wxPoint(280, 170), wxSize(100, 20), wxTE_PASSWORD);
      button->Bind(wxEVT_BUTTON, &MyFrame::OnSubmit, this);
      input->Bind(wxEVT_TEXT, &MyFrame::OnTextChanged, this);
    } break;
    case appStatus::home: {
      wxPanel* homePanel = new wxPanel(this);
      wxStaticText* homeText = new wxStaticText(homePanel, wxID_ANY, "This is the home page", wxPoint(270, 140));
      this->currentPanel = homePanel;
      wxButton* button = new wxButton(homePanel, wxID_ANY, "Input another key", wxPoint(0, 0), wxSize(140, 25));
      homePanel->Bind(wxEVT_BUTTON, &MyFrame::OnLoginButtonClicked, this);
    } break;
  }
  this->Layout();
}
void MyFrame::OnSubmit(wxCommandEvent& evt) {
  password = currentText;
  state = appStatus::home;
  this->Layout();
  refresh();
}
void MyFrame::OnTextChanged(wxCommandEvent& evt) {
  currentText = evt.GetString();
}

void MyFrame::OnLoginButtonClicked(wxCommandEvent& evt)
{
  state = appStatus::login;
  this->Layout();
  refresh();
}

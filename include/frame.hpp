#pragma once
// Declare our main frame class
#include <wx/wx.h>
#include "meta/macros.h"
enum class appStatus {
  login,
  home,
  info
};
class MyFrame : public wxFrame
{
public:
  MyFrame(const wxString& title);
private:
  appStatus state;
  wxPanel* currentPanel;
  wxString password;
  wxString currentText;
  wxStaticText* remainingText;
  wxTextCtrl* inputText;
  bool keyIsShown;

  void OnSubmit(wxCommandEvent& evt);
  void OnTextChanged(wxCommandEvent& evt);
  void OnLoginButtonClicked(wxCommandEvent& evt);
  void OnMore(wxCommandEvent& evt);
  void OnBack(wxCommandEvent& evt);
  void OnShow(wxCommandEvent& evt);

  void Refresh();
};
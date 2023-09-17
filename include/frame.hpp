#pragma once
// Declare our main frame class
#include <wx/wx.h>
enum class appStatus {
  login,
  home
};
class MyFrame : public wxFrame
{
public:
  MyFrame(const wxString& title, bool hasPassword);
  void refresh();
private:
  appStatus state;
  wxPanel* inputPanel;
  wxPanel* homePanel;
  wxString password;
  wxString currentText;
  void OnButtonClicked(wxCommandEvent& evt);
  void OnTextChanged(wxCommandEvent& evt);
};
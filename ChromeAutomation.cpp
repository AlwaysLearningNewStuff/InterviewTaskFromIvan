#include "ChromeAutomation.h"

UI_Automation::ChromeAutomation::ChromeAutomation()
{
	hr = UI_Automation.CoCreateInstance(CLSID_CUIAutomation);
	if (FAILED(hr) || !UI_Automation)
		throw _com_error(hr);

	//URL's id is 0xC354, or use UIA_EditControlTypeId for 1st edit box
	hr = UI_Automation->CreatePropertyCondition(UIA_ControlTypePropertyId,
		CComVariant(0xC354), &condition);

	if (FAILED(hr) || !UI_Automation)
		throw _com_error(hr);
}

void UI_Automation::ChromeAutomation::GetURL()
{
	HWND chrome_window = NULL;

	while (true)
	{
		chrome_window = FindWindowEx(0, chrome_window, L"Chrome_WidgetWin_1", NULL);
		if (!chrome_window)
			break;

		if (!IsWindowVisible(chrome_window))
			continue;

		stopwatch.Start();

		CComPtr<IUIAutomationElement> root;
		hr = UI_Automation->ElementFromHandle(chrome_window, &root);
		if (FAILED(hr) || !root)
			throw _com_error(hr);

		CComPtr<IUIAutomationElement> address_bar_textbox;
		hr = root->FindFirst(TreeScope_Descendants, condition, &address_bar_textbox);
		if (FAILED(hr) || !address_bar_textbox)
			continue;

		CComVariant active_url;
		hr = address_bar_textbox->GetCurrentPropertyValue(UIA_ValueValuePropertyId, &active_url);
		if (FAILED(hr))
			throw _com_error(hr);

		stopwatch.Stop();

		std::wcout << active_url.bstrVal << L" ["
			<< stopwatch.ElapsedTime() << L"] miliseconds" << std::endl;

		break;
	}
}



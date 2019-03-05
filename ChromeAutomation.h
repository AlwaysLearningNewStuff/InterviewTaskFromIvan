#pragma once
#include <Windows.h>		//   FindWindowEx and other WinAPIs
#include "ComHelpers.h"
#include "Utilities.h"
#include <UIAutomation.h>	//   to "grab" Chrome's Address Bar
#include <iostream>			//   wcout

namespace UI_Automation
{
	class ChromeAutomation
	{
		HRESULT hr;
		ComHelpers::COM_init c;
		CComQIPtr<IUIAutomation> UI_Automation;
		CComPtr<IUIAutomationCondition> condition;
		Clocks::StopWatch stopwatch;

	public:

		ChromeAutomation();
		void GetURL();
	};
}
#define UNICODE
#include "ChromeAutomation.h"
#include <thread>			//   for cross-platform sleep function

int main()
{
	try
	{
		UI_Automation::ChromeAutomation chrome;
		const int wait_period = 4;

		while(true)
		{
			chrome.GetURL();

			std::this_thread::sleep_for(std::chrono::seconds(wait_period));
		}
	}
	catch (_com_error &e)
	{
		std::wcout << "COM exception in main: \n" << e.ErrorMessage() << std::endl;
	}

	return 0;
}
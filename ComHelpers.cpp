#include "ComHelpers.h"

ComHelpers::COM_init::COM_init()
{
	m_hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);

	if (FAILED(m_hr))
		throw _com_error(m_hr);
}

ComHelpers::COM_init::~COM_init()
{
	::CoUninitialize();
}

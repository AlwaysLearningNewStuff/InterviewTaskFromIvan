#pragma once
#include <AtlBase.h>		
#include <AtlCom.h>			
#include <comdef.h>			//   _com_error

namespace ComHelpers
{
	class COM_init
	{
		HRESULT m_hr;
	public:
		COM_init();

		// no copying/moving is awailable
		COM_init(const COM_init &) = delete;
		COM_init(COM_init &&) = delete;
		COM_init& operator=(const COM_init &) = delete;
		COM_init& operator=(COM_init &&) = delete;

		~COM_init();
	};
}
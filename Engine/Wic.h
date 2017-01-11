#pragma once

#include <wincodec.h>
#include <wrl.h>
#pragma comment(lib, "windowscodec.lib")

class Wic
{
public:
	Wic();
	~Wic();

	IWICImagingFactory2 *GetFactory()const;
private:
	Microsoft::WRL::ComPtr<IWICImagingFactory2> m_pFactory;
};


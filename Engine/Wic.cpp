#include "Wic.h"

Wic::Wic()
{
	HRESULT hr = S_OK;
	hr = CoCreateInstance(
		CLSID_WICImagingFactory2,
		nullptr,
		CLSCTX_INPROC_SERVER,
		IID_PPV_ARGS( &m_pFactory )
	);
	if( FAILED( hr ) ) throw( hr );
}

Wic::~Wic()
{}

IWICImagingFactory2 * Wic::GetFactory() const
{
	return m_pFactory.Get();
}

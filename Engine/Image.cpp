#include "Image.h"
#include "Colors.h"
#include <iomanip>

Image::Image( const std::wstring &Filename, const Wic &crWic )

{
	Microsoft::WRL::ComPtr<IWICBitmapDecoder> pDecoder;
	Microsoft::WRL::ComPtr<IWICBitmapFrameDecode> pFrame;
	Microsoft::WRL::ComPtr<IWICFormatConverter> pConverter;

	GUID container_type;
	std::wstring ext = Filename.substr( Filename.size() - 3, 3 );

	if( ext == L"png" )container_type = GUID_ContainerFormatPng;
	else if( ext == L"bmp" )container_type = GUID_ContainerFormatBmp;
	else if( ext == L"jpg" || ext == L"jpeg" )container_type = GUID_ContainerFormatJpeg;
	else throw( STG_E_UNKNOWN );

	IWICImagingFactory2 *pFactory = crWic.GetFactory();
	HRESULT hr = pFactory->CreateDecoder(
		container_type, nullptr, &pDecoder
	);
	if( FAILED( hr ) ) throw( hr );

	hr = pDecoder->GetFrame( 0, &pFrame );
	if( FAILED( hr ) ) throw( hr );

	WICRect wr{};
	pFrame->GetSize( &m_width, &m_height );
	m_pBits = std::make_unique<unsigned char[]>( m_width * m_height * sizeof( unsigned int ) );
	const unsigned stride = m_width * sizeof( unsigned );
	const unsigned buff_size = stride * m_height;

	hr = pConverter->Initialize(
		pFrame.Get(), GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone,
		nullptr, 1., WICBitmapPaletteTypeCustom 
	);
	if( FAILED( hr ) ) throw( hr );

	hr = pConverter->CopyPixels( &wr, stride, buff_size, m_pBits.get() );
	if( FAILED( hr ) ) throw( hr );
}

unsigned char * Image::GetBits() const
{
	return m_pBits.get();
}

unsigned int Image::GetWidth() const
{
	return m_width;
}

unsigned int Image::GetHeight() const
{
	return m_height;
}

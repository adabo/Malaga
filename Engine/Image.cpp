#include "Image.h"
#include "Colors.h"
#include "Vector.h"
#include <iomanip>

Image::Image( const std::wstring &Filename )
{
	using Microsoft::WRL::ComPtr;
	Wic wic;
	ComPtr<IWICBitmapDecoder> pDecoder;
	ComPtr<IWICBitmapFrameDecode> pFrame;
	ComPtr<IWICFormatConverter> pConverter;

	// Get the factory
	IWICImagingFactory2 *pFactory = wic.GetFactory();

	// Create a Decoder from file
	HRESULT hr = pFactory->CreateDecoderFromFilename( Filename.c_str(), nullptr, GENERIC_READ, WICDecodeMetadataCacheOnDemand, &pDecoder );
	if( FAILED( hr ) ) throw( hr );

	// Get the first and only frame
	hr = pDecoder->GetFrame( 0, &pFrame );
	if( FAILED( hr ) ) throw( hr );
		
	pFrame->GetSize( &m_width, &m_height );
	m_pBits = std::make_unique<unsigned char[]>( m_width * m_height * sizeof( unsigned int ) );
	const unsigned stride = m_width * sizeof( unsigned );
	const unsigned buff_size = stride * m_height;

	// Create a format converter to make sure it's 32 bpp
	hr = pFactory->CreateFormatConverter( &pConverter );
	if( FAILED( hr ) ) throw( hr );

	// Initialize the converter using the frame
	hr = pConverter->Initialize(
		pFrame.Get(), GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone,
		nullptr, 1., WICBitmapPaletteTypeCustom 
	);
	if( FAILED( hr ) ) throw( hr );

	// Copy the pixel data to this Image class so we can release the Wic objects
	WICRect wr{};
	wr.Width = m_width;
	wr.Height = m_height;
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

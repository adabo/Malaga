#pragma once

#include <string>
#include <memory>
#include "Wic.h"

class Image
{
public:
	Image( const std::wstring &Filename);

	unsigned char *GetBits()const;
	unsigned int GetWidth()const;
	unsigned int GetHeight()const;
protected:
	std::unique_ptr<unsigned char[]> m_pBits = nullptr;
	unsigned m_width = 0u, m_height = 0u;
};
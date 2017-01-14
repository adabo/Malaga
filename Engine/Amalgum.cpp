#include "Amalgum.h"


Amalgum::Amalgum( Keyboard & Kbd )
	:
	m_player( Kbd, *this )
{}

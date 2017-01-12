#include "Amalgum.h"



Amalgum::Amalgum()
{}


Amalgum::~Amalgum()
{}

Amalgum::Amalgum( Keyboard & Kbd )
	:
	m_player( Kbd, *this )
{}

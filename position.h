#ifndef		_POSITION_
#define		_POSITION_

#include "findef.h"

#define		LONG		0
#define		SHORT		1
#define		EQUITY		2
#define		DEBT		3

Position create_position(void);
void delete_position(Position val);
Position increase_position();


#endif // !_POSITION_

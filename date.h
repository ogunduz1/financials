#ifndef		_DATE_
#define		_DATE_

typedef unsigned int date_t;

#define		DAY_OFFSET					0
#define		MONTH_OFFSET				5
#define		YEAR_OFFSET					9
#define		SET_DAY(V, X)				V = (X << DAY_OFFSET) | V
#define		SET_MONTH(V, X)				V = (X << MONTH_OFFSET) | V
#define		SET_YEAR(V, X)				V = (X << YEAR_OFFSET) | V
#define		SET_DATE(V, D, M, Y)		((SET_YEAR(V, Y),SET_MONTH(V, M)),SET_DAY(V, D))
#define		DAY_MASK					0x1F
#define		MONTH_MASK					0x1E0
#define		YEAR_MASK					0xFFE00	
#define		GET_DAY(V)					(V & DAY_MASK) >> DAY_OFFSET			
#define		GET_MONTH(V)				(V & MONTH_MASK) >> MONTH_OFFSET
#define		GET_YEAR(V)					(V & YEAR_MASK) >> YEAR_OFFSET


#endif // !_DATE_


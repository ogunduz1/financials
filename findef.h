#ifndef		_FINDEF_
#define		_FINDEF_
#include <stddef.h>

/* symbolic constants */
#define		ANNUAL_RANGE	5
#define		QTR_RANGE		5
#define		FIN_BS			0x1
#define		FIN_IS			0x2
#define		FIN_CF			0x4
#define		FIN_ANN			0x8
#define		FIN_QTR			0x10

#define		FIN_TTM			0
#define		FIN_LAST		1
#define		FIN_PREV		2
#define		FIN_SECOND		3
#define		FIN_OLDEST		4

#define		QUARTER			91
#define		ANNUAL			QUARTER * 4

#define		UNKNOWN			INT_MAX

/* only definitions */
typedef int unit_t;
typedef void *BalanceSheet;
typedef void *IncomeStatement;
typedef void *CashFlow;
typedef void *Stock;
typedef void *Position;

/* global variables */
extern size_t g_stock_size;
extern size_t g_balance_sheet_size;
extern size_t g_cash_flow_size;
extern size_t g_income_statement_size;


#endif // !_FINDEF_

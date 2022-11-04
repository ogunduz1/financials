#ifndef		_STOCK_
#define		_STOCK_

#include <limits.h>
#include <stddef.h>
#include <stdio.h>


/* types */
#include "findef.h"
#include "date.h"


/* XMacros */
#define		XCURRENCIES	\
X(USD)					\
X(TRY)					\

#define		XMARKETS	\
X(BIST)					\
X(NYSE)					\
X(NASDAQ)				\

#define		XSECTORS	\
X(ENERGY)				\
X(MATERIALS)			\
X(INDUSTRIALS)			\
X(HEALTH_CARE)			\
X(IT)					\
X(REAL_ESTATE)			\
X(CONSUMER_STAPLES)		\
X(UTILITIES)			\
X(CONSUMER_DISCRETIONARY)\
X(COMMUNICATION_SERVICES)\
X(FINANCIALS)			\

#define		XINDUSTRIES	\
X(DEFENCE)				\
X(BANKS)				\
//...

/* Symbolic Constants */


#define		X(a)	a,
typedef enum _Currency { XCURRENCIES }Currency;
#undef		X

#define		X(a)	a,
typedef enum _Market { XMARKETS }Market;
#undef		X

#define		X(a)	a,
typedef enum _Sector { XSECTORS }Sector;
#undef		X

#define		X(a)	a,
typedef enum _Industry { XINDUSTRIES }Industry;
#undef		X

/* global variables */
extern size_t g_stock_size;
extern size_t g_balance_sheet_size;
extern size_t g_income_statement_size;
extern size_t g_cash_flow_size;

/* function prototypes */
/* constructors */
Stock create_stock(void);
BalanceSheet create_balance_sheet(void);
IncomeStatement create_income_statement(void);
CashFlow create_cash_flow(void);
/* desturctors */
void delete_stock(Stock handle);
void delete_balance_sheet(BalanceSheet handle);
void delete_income_statement(IncomeStatement handle);
void delete_cash_flow(CashFlow handle);
/* mutators */
char *stock_set_company_name(Stock handle, char *name);
char *stock_set_country(Stock handle, char *name);
int stock_set_market(Stock handle, Market m);
int stock_set_currency(Stock handle, Currency c);
int stock_set_sector(Stock handle, Sector s);
int stock_set_industry(Stock handle, Industry i);
int stock_set_foundation(Stock handle, int year);
int stock_set_price(Stock handle, unit_t price);
void *stock_set_financial(Stock handle, void *report, int report_type, int duration, int date);

/* accessors */
void *stock_get_financial(const Stock handle, int report_type, int duration, int date);
char *stock_get_company_name(const Stock handle, char *dest);
char *stock_get_country(const Stock handle, char *dest);
char *stock_get_market(const Stock handle, char *dest);
char *stock_get_currency(const Stock handle, char *dest);
char *stock_get_sector(const Stock handle, char *dest);
char *stock_get_industry(const Stock handle, char *dest);
int stock_get_foundation(const Stock handle);
unit_t stock_get_price(const Stock handle);
char *balance_sheet_get_currency(const BalanceSheet handle);
char *income_statement_get_currency(const IncomeStatement handle);
char *cash_flow_get_currency(const CashFlow handle);
/* ratios and indicators */
unit_t working_capital(const BalanceSheet handle);
double current_ratio(const BalanceSheet handle);
double quick_ratio(const BalanceSheet handle); //acid_test
double dept_to_assets_ratio(const BalanceSheet handle);
double equity_ratio(const BalanceSheet handle);
double dept_to_equity_ratio(const BalanceSheet handle);
double day_sales_outstanding(const IncomeStatement handle);
unit_t book_value(const BalanceSheet handle);
unit_t ebit(const IncomeStatement handle);
unit_t ebitda(const IncomeStatement handle);
unit_t gross_profit(const IncomeStatement handle);
unit_t operating_income(const IncomeStatement handle);
unit_t total_income(const IncomeStatement handle);
/* input output */
int fin_get_data(const char *url, FILE *dest); //get data from web?
int stock_get_data(const char *url, Stock dest);
int fin_read_data(FILE* src, void *mem);
void fin_print_data(FILE *out);
void fin_send_email(FILE *src);


#endif // !_STOCK_


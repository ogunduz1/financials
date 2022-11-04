#define _CRT_SECURE_NO_WARNINGS

#include "stock.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define		NAMESIZE		100
#define		WORDSIZE		32

struct _BalanceSheet {
	Currency mcurrency;
	date_t	mdate;
	struct {
		unit_t cash_and_equivalents;
		unit_t receivables;
		unit_t inventory;
		unit_t prepaids;
		unit_t others;
	}current_assets;

	struct {
		unit_t ppe;
		unit_t intangibles;
		unit_t others;
	}non_current_assets;

	struct {
		unit_t others;

	}current_liabilities;

	struct {
		unit_t others;

	}non_current_liabilities;

	struct {
		unit_t capital_stock;
		unit_t interest;
		unit_t others;
	}equity;
	int flag;
};

struct _IncomeStatement {
	Currency mcurrency;
	date_t mdate;
	int duration;
	unit_t revenue;
	unit_t cost_of_revenue;
	struct {
		unit_t selling_general;
		unit_t research_development;
	} operating_expenses;
	unit_t total_operating_expenses;
	unit_t taxes;
	unit_t depreciations;
	unit_t interest_expenses;
	unit_t other_incomes;
};

struct _CashFlow {
	Currency mcurrency;
	date_t mdate;
	int duration;
	unit_t operating;
	unit_t investing;
	unit_t financing;
	unit_t changes;
};

struct _Stock {
	char company[NAMESIZE];
	char country[WORDSIZE];
	Market mmarket;
	Currency mcurrency;
	Sector	msector;
	Industry mindustry;
	int foundation_year;
	unit_t mprice;
	struct _BalanceSheet *annual_balance_sheets;
	struct _BalanceSheet *quarterly_balance_sheets;
	struct _IncomeStatement *annual_income_statements;
	struct _IncomeStatement *quarterly_income_statements;
	struct _CashFlow *annual_cash_flows;
	struct _CashFlow *quarterly_cash_flows;
};

size_t g_balance_sheet_size = sizeof(struct _BalanceSheet);
size_t g_income_statement_size = sizeof(struct _IncomeStatement);
size_t g_cash_flow_size = sizeof(struct _CashFlow);
size_t g_stock_size = sizeof(struct _Stock);

#define		X(a)	#a,
static const char* pcurrency[] = { XCURRENCIES };
#undef		X

#define		X(a)	#a,
static const char* pmarket[] = { XMARKETS };
#undef		X

#define		X(a)	#a,
static const char* psector[] = { XSECTORS };
#undef		X

#define		X(a)	#a,
static const char* pindustry[] = { XINDUSTRIES };
#undef		X

/* static functions */
static void exit_err(const char *str) {
	fprintf(stderr, str);
	exit(EXIT_FAILURE);
}
static void *access_financial(struct _Stock *h, int report_type, int duration, size_t *size /*out*/) {
	void *p = NULL;

	switch (report_type) {

	case FIN_BS:
		*size = sizeof(struct _BalanceSheet);

		if (duration = FIN_ANN)
			p = h->annual_balance_sheets;
		if (duration = FIN_QTR)
			p = h->quarterly_balance_sheets;

		break;

	case FIN_IS:
		*size = sizeof(struct _IncomeStatement);

		if (duration = FIN_ANN)
			p = h->annual_income_statements;

		if (duration = FIN_QTR)
			p = h->quarterly_income_statements;

		break;

	case FIN_CF:
		*size = sizeof(struct _CashFlow);

		if (duration = FIN_ANN)
			p = h->annual_cash_flows;

		if (duration = FIN_QTR)
			p = h->quarterly_cash_flows;

		break;

	default:
		break;
	}

	return p;
}

BalanceSheet create_balance_sheet(void) {
	struct _BalanceSheet* p;

	if ((p = (struct _BalanceSheet*)calloc(1, sizeof(struct _BalanceSheet))) == NULL)
		exit_err("calloc error");

	return (BalanceSheet)p;
}

IncomeStatement create_income_statement(void) {
	struct _IncomeStatement* p;

	if ((p = (struct _IncomeStatement*)calloc(1, sizeof(struct _IncomeStatement))) == NULL)
		exit_err("calloc error");

	return (IncomeStatement)p;
}

CashFlow create_cash_flow(void) {
	struct _CashFlow* p;

	if ((p = (struct _CashFlow*)calloc(1, sizeof(struct _CashFlow))) == NULL)
		exit_err("calloc error");

	return (CashFlow)p;
}

Stock create_stock(void) {
	struct _Stock *p;
	
	if ((p = (struct _Stock*)calloc(1, sizeof(struct _Stock))) == NULL)
		exit_err("calloc error");

	if ((p->annual_balance_sheets = calloc(ANNUAL_RANGE, g_balance_sheet_size)) == NULL)
		exit_err("calloc error");

	if ((p->quarterly_balance_sheets = calloc(QTR_RANGE, g_balance_sheet_size)) == NULL)
		exit_err("calloc error");

	if ((p->annual_income_statements = calloc(ANNUAL_RANGE, g_income_statement_size)) == NULL)
		exit_err("calloc error");

	if ((p->quarterly_income_statements = calloc(QTR_RANGE, g_income_statement_size)) == NULL)
		exit_err("calloc error");
	
	if ((p->annual_cash_flows = calloc(ANNUAL_RANGE, g_cash_flow_size)) == NULL)
		exit_err("calloc error");

	if ((p->quarterly_cash_flows = calloc(QTR_RANGE, g_cash_flow_size)) == NULL)
		exit_err("calloc error");
	
	return (Stock)p; 
}

char *stock_set_company_name(Stock handle, const char *name) {
	
	return strcpy(((struct _Stock *)handle)->company, name);
}

char *stock_set_country(Stock handle, const char *name) {
	return strcpy(((struct _Stock *)handle)->country, name);
}

int stock_set_market(Stock handle, Market m) {
	return ((struct _Stock *)handle)->mmarket = m;
}

int stock_set_currency(Stock handle, Currency c) {
	return ((struct _Stock *)handle)->mcurrency = c;

}

int stock_set_sector(Stock handle, Sector s) {
	return ((struct _Stock *)handle)->msector = s;
}

int stock_set_industry(Stock handle, Industry i) {
	return ((struct _Stock *)handle)->mindustry = i;
}

int stock_set_foundation(Stock handle, int year) {
	return ((struct _Stock *)handle)->foundation_year = year;
}

int stock_set_price(Stock handle, unit_t price) {
	return ((struct _Stock *)handle)->mprice = price;

}

void *stock_set_financial(Stock handle, const void *report, int report_type, int duration, int date) {
	struct _Stock *h = (struct _Stock *)handle;
	size_t size = 0;
	void *p = NULL;

	p = access_financial(h, report_type, duration, &size);

	if (p == NULL)
		return p;

	if (memcpy(p, report, size) == NULL)
		exit_err("memcpy error\n");
	
	return p;
}


void delete_stock(Stock val) {
	struct _Stock *p = (struct _Stock*)val;
	
	free(p->annual_balance_sheets);
	free(p->quarterly_balance_sheets);
	free(p->annual_income_statements);
	free(p->quarterly_income_statements);
	free(p->annual_cash_flows);
	free(p->quarterly_cash_flows);
	free(p);
}

void delete_balance_sheet(BalanceSheet val) {
	free(val);
}

void delete_income_statement(IncomeStatement val) {
	free(val);
}

void delete_cash_flow(CashFlow val) {
	free(val);
}

void* get_financial(Stock handle, int report_type, int duration, int date) {
	struct _Stock *h = (struct _Stock *)handle;
	size_t size = 0;
	void *p = NULL;

	p = access_financial(h, report_type, duration, &size);
	

	return ((char *)p + size);
}



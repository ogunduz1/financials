#include <stdio.h>
#include "findef.h"
#include "date.h"
#include "stock.h"

int main(void) {
	Stock s1 = create_stock();
	BalanceSheet b1 = create_balance_sheet();
	IncomeStatement i1 = create_income_statement();
	CashFlow c1 = create_cash_flow();
	printf("test\n");
	delete_stock(s1);
	delete_balance_sheet(b1);
	delete_income_statement(i1);
	delete_cash_flow(c1);
	printf("%d\n", square(5));
	return 0;
}

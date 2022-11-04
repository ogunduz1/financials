#ifndef		_FINIO_
#define		_FINIO_

#include <stddef.h>
#include "findef.h"


/* function prototypes */

void fin_get_data(void); //get data from web?
void fin_print_data(FILE *out);
void fin_read_data(FILE *in); //read to static member
void fin_send_email(void);
void fin_record(void);



#endif // !_FINIO_

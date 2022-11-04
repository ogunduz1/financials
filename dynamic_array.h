#ifndef		_DARRAY_
#define		_DARRAY_

#include <stddef.h>
#include <stdio.h>

typedef struct _Darray {
	void *obj;
	size_t size;
	size_t capacity;
}*Darray;

Darray create_dynamic_array(size_t size);
void delete_dynamic_array(Darray handle);
Darray add_item(Darray handle, const void *item);
Darray remove_item(Darray handle, size_t idx);
size_t 



#endif // !_DARRAY_

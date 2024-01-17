#include "libtui_buffering_errs.h"
#include <stdlib.h>

const char *libtui_buffering_error_str(enum LIBTUI_BUFFERING_ERR err)
{
	const char *err_str = NULL;

	if (err >= BUFFERING_ERROR_COUNT)
		goto done;

	err_str = LIBTUI_BUFFERING_ERR_STRS[err];

done:
	return err_str;
}

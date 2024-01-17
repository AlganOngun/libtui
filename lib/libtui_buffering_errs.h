#ifndef LIBTUI_BUFFERING_ERRS
#define LIBTUI_BUFFERING_ERRS

/*
 * Error Codes For Buffering Module
 */
#include <sys/cdefs.h>
enum LIBTUI_BUFFERING_ERR {
	// No Error
	BUFFERING_ERROR_OK = 0,
	// Either x or y is bigger than the respective buffer dimension.
	BUFFERING_ERROR_INVALID_DIMENSION,
	// Tried to use malloc but failed
	BUFFERING_ERROR_MALLOC_FAILED,
	// The buf* passed in as an argument is NULL
	BUFFERING_ERROR_NULL_BUF,
	// The buf->buf is NULL. the const char* buf inside libtui_buffer->buf is NULL
	BUFFERING_ERROR_NULL_BUF_BUFFER,

	// Total number of errors
	BUFFERING_ERROR_COUNT,
};

#endif

#include "libtui_keyboard.h"

#include <stdio.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <sys/types.h>
#include <unistd.h>

bool libtui_keyboard_is_kb_hit(void)
{
	static bool initialized = false;

	if (!initialized) {
		struct termios term;
		tcgetattr(STDIN_FILENO, &term);
		term.c_lflag &= ~(ICANON | ECHO);
		tcsetattr(STDIN_FILENO, TCSANOW, &term);
		setbuf(stdin, NULL);
		initialized = true;
	}

	int bytesWaiting;
	ioctl(STDIN_FILENO, FIONREAD, &bytesWaiting);
	return bytesWaiting;
}

enum LIBTUI_KEYCODE libtui_keyboard_get_key(void)
{
	struct termios oldattr, newattr;
	char ch;
	tcgetattr(STDIN_FILENO, &oldattr);
	newattr = oldattr;
	newattr.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
	return ch;
}

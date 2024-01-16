#ifndef LIBTUI_TERM_CONTROL_H
#define LIBTUI_TERM_CONTROL_H

// Hides the cursor of the terminal.
// Make sure to call libtui_enable_cursor() before exiting your program.
// Uses: printf("\e[?25l"); underhood.
void libtui_hide_cursor(void);

// Shows the cursor of the terminal.
// Uses: printf("\e[?25h"); underhood.
void libtui_show_cursor(void);

// Truly clears the console independent from all the buffer stuff.
// Uses: system("clear");
// Only reasonable use case for this function is calling it in the beginning of your program to
// clear everthing that has been written to terminal thus, giving your program a completely empty
// space to draw to.
void libtui_true_clear(void);

#endif

#ifndef LIBTUI_TERM_CONTROL_H
#define LIBTUI_TERM_CONTROL_H

/*! \defgroup libtui_term_control Term Control
 * All the things about the term_control module
 *   \{
 */

/*! \file libtui_term_control.h
 *  \brief The group of functions that provide a nice interface for the client to work with terminal settings. Handles all the platform dependent dirty stuff and makes it easy for user to work with. */

/*! \fn void libtui_hide_cursor(void).
*   \brief Hides the cursor of the terminal.
*
* Make sure to call libtui_enable_cursor() before exiting your program.
*/
void libtui_hide_cursor(void);

/*! \fn void libtui_show_cursor(void).
*   \brief Shows the cursor of the terminal.
*/
void libtui_show_cursor(void);

/*! \fn void libtui_true_clear(void).
*   \brief Truly clears the console independent from all the buffer stuff.
*          Uses: system("clear");
*
* Only reasonable use case for this function is calling it in the beginning of your program to
* clear everthing that has been written to terminal thus, giving your program a completely empty space to draw to.
*/
void libtui_true_clear(void);

/*! \example simple.c
 * This is an example demonstrating libtui_draw, libtui_renderer, libtui_keyboard and libtui_term_control modules with an example of how to handle errors properly.
 */

//! \}

#endif

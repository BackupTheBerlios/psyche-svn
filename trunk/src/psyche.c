#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "psyche.h"
#include "utils.h"
#include "workspace.h"
#include "windows.h"
#include "events.h"
 

int main(int argc, char *argv[])
{
	PSY_WSPACE *wspace;
	
	initscr();
	nocbreak();
	keypad(stdscr, t);
	start_color();
	mousemask(ALL_MOUSE_EVENTS, NULL);
	/* todo: colors from configuration file */
	if(has_colors()) {
		refresh();
		init_pair(COLOR_PAIR(0), COLOR_BLUE, COLOR_BLUE);
		bkgd(32 | COLOR_PAIR(0));
	}
	
	wspace = workspace_create("workspace");
	window_create("prova", "ciao", 20, 20, 10, 10, wspace->head);

	while(1) {
		event_get();
		update_panels();
		refresh();
		
	}
	
	endCDK();
	endwin();
	
	return EXIT_SUCCESS;
}


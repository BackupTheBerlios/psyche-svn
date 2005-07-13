#include "psyche.h"
#include "events.h"

void event_get(void) 
{
	MEVENT *event;
	int c;
	
	c = getch(); /* wgetch(wcurrent) */
	switch(c) {
		case KEY_MOUSE:
			if(getmouse(event) == OK) {
	
			}
			//printw("mouse");
	}
}

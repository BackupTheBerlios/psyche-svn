#include "psyche.h"
#include "utils.h"
#include "windows.h"

PSY_WIN*
window_create(const char *ctitle, const char *title, int sizey, int sizex, 
	      int posy, int posx, PSY_WIN *head)
{
	PSY_WIN *new, *last;

	assert(ctitle && title);
	
	new = (PSY_WIN *)xmalloc(sizeof(PSY_WIN));

	new->ctitle = strdup(ctitle);
	new->screen = initCDKScreen(new->wbody);
	new->wshad = newwin(sizey, sizex, posy+1, posx+1);
	new->wbody = newwin(sizey, sizex, posy, posx);
	new->pshad = new_panel(new->wshad);
	new->pbody = new_panel(new->wbody);

	/* setup default properties */
	wbkgd(new->wbody, 32 | COLOR_PAIR(7));
	box(new->wbody, 0, 0);
	window_title(new, title);
	window_has_shad(new, t);
	window_has_close(new, t);
	window_has_min(new, t);
	window_has_opt(new, t);
	window_is_res(new, t);
	window_is_mov(new, t);
	window_showbar(new, t);

        /* insert in windows list */
     
	if(head == NULL)
		head = new;
	else {
		last = head;
		while(last->next!=NULL) 
			last = last->next;
		last->next = new;
	}

	return new;
}

void
window_has_shad(PSY_WIN *win, bool has_shad)
{
	assert(win);
	
	win->has_shad = has_shad;
	
	if(win->has_shad == f)
		hide_panel(win->pshad);
	else {
		show_panel(win->pshad);	
		top_panel(win->pbody);
	}
}

void
window_showbar(PSY_WIN *win, bool has_tbar)
{
	assert(win);

	win->has_tbar = has_tbar;
	
	if(win->has_tbar == f) { /* hide bar */
		mvwhline(win->wbody, 0, 1, 0, getmaxx(win->wbody)-2);
		mvwaddch(win->wbody, 0, 0, '+');
		mvwaddch(win->wbody, 0, getmaxx(win->wbody)-1, '+');
	} else { /* show bar */
		wattron(win->wbody, COLOR_PAIR(29) | A_BOLD);
		mvwhline(win->wbody, 0, 0, 32, getmaxx(win->wbody));
		if(win->has_close == t)
			mvwprintw(win->wbody, 0, 0, "[x]");

		if(win->has_opt == t)
			mvwprintw(win->wbody, 0, win->has_close*3, "[o]");

		if(win->has_min == t)
			mvwprintw(win->wbody, 0, 
				  3 * (win->has_close + win->has_opt), "[_]");

		mvwprintw(win->wbody, 0, 3 * (win->has_close + win->has_opt + 
			  win->has_min) + 1, "%s - %s", win->ctitle, win->title);
		wattroff(win->wbody, COLOR_PAIR(29) | A_BOLD);
	}
}

void
window_title(PSY_WIN *win, const char *title)
{
	assert(win && title);
	
	free(win->title);
	win->title=strdup(title);
	window_showbar(win, win->has_tbar);
}

void
window_has_close(PSY_WIN *win, bool has_close)
{
	assert(win);
	
	win->has_close = has_close;
	window_showbar(win, win->has_tbar);	
}

void
window_has_min(PSY_WIN *win, bool has_min)
{
	assert(win);
	
	win->has_min = has_min;
	window_showbar(win, win->has_tbar);
}

void
window_has_opt(PSY_WIN *win, bool has_opt)
{
	assert(win);
	
	win->has_opt = has_opt;
	window_showbar(win, win->has_tbar);
}

void
window_is_res(PSY_WIN *win, bool is_res)
{
	assert(win);
	
	win->is_res = is_res;
	
	if(win->is_res == t) {  /* show resize button */
		wattron(win->wbody, COLOR_PAIR(29) | A_BOLD);
		mvwprintw(win->wbody, getmaxy(win->wbody)-1, 
			  getmaxx(win->wbody)-2, "<>");
		wattroff(win->wbody, COLOR_PAIR(29) | A_BOLD);
	} else {  /* hide resize button */
		wattron(win->wbody, COLOR_PAIR(7));
		mvwprintw(win->wbody, getmaxy(win->wbody)-1, 
			  getmaxx(win->wbody)-2, "-+");
		wattroff(win->wbody, COLOR_PAIR(7));
	}
}

void
window_is_mov(PSY_WIN *win, bool is_mov)
{
	assert(win);
	
	win->is_mov = is_mov;
}

void 
window_del(PSY_WIN *win)
{
	del_panel(win->pbody);
	del_panel(win->pshad);
 	delwin(win->wbody); 
	delwin(win->wshad); 
	destroyCDKScreen(win->screen);
	free(win);
}

void
window_free(PSY_WIN *win, PSY_WIN *head)
{
	PSY_WIN *tmp;
	
	assert(win);
	
	for(tmp = head; tmp->next != win; tmp->next);
	tmp->next = win->next;

	window_del(win);
}


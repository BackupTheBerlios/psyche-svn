#ifndef WINDOWS_H
#define WINDOWS_H

typedef struct winnode {
	/* class title and title */
	char *ctitle;
	char *title;
	/* curses and cdk */
	WINDOW *wbody;
	WINDOW *wshad;
	PANEL *pbody;
	PANEL *pshad;
	CDKSCREEN *screen;
	/* properties */
	bool has_shad;
	bool has_tbar;
	bool has_close;
	bool has_min;
	bool has_opt;
	bool is_res;
	bool is_mov;
	/* list */
	struct winnode *next;
} PSY_WIN;

/* init a window */
PSY_WIN *window_create(const char *ctitle, const char *title, int sizey,
		       int sizex, int posy, int posx, PSY_WIN *head);
/* window properties */
void window_has_shad(PSY_WIN *win, bool has_shad);
void window_showbar(PSY_WIN *win, bool has_tbar);
void window_has_close(PSY_WIN *win, bool has_close);
void window_has_min(PSY_WIN *win, bool has_min);
void window_has_opt(PSY_WIN *win, bool has_opt);
void window_is_res(PSY_WIN *win, bool is_res);
void window_is_mov(PSY_WIN *win, bool is_mov);
/* edit title */
void window_title(PSY_WIN *win, const char *title);
/* destroy a window */
void window_del(PSY_WIN *win);
void window_free(PSY_WIN *win, PSY_WIN *head);

#endif /* WINDOWS_H */

#include "../include/corewar.h"

void		init_colors(void)
{
	initscr();
	noecho();
	start_color();
	init_pair(1, 3, 0); //Yellow, 11 bkgd
	init_pair(2, 2, 0); // Green, 10 bkgd
	init_pair(3, 4, 0); // Blue 12, 4
	init_pair(4, 9, 0); // Red, 9 bkgd 1
	init_pair(11, 0, 11); // 
	init_pair(12, 0, 10); // 
	init_pair(13, 0, 12); // 
	init_pair(14, 0, 1); // 

	//init_pair(4, 6, 0); // CYAN
	init_pair(10, 8, 0); //Bright Black ("Gray")
	curs_set(0);
	timeout(0);
	wresize(stdscr, 74, 192); //set screen size
	//resizeterm(100, 200);
}

void		print_elem(UC elem, int pair)
{
	attron(COLOR_PAIR(pair));
	printw("%0.2x", elem);
	attroff(COLOR_PAIR(pair));
	printw(" ");
}

int 		check_carri(t_carriage *carriage, int pos)
{
	t_carriage *temp;

	temp = carriage;
	while (temp)
	{
		if (temp->position == pos)
			return (temp->player_id);
		temp = temp->next;
	}
	return (0);
}

void		print_map(t_carriage *carriage, int delay)
{
	int j = 0;
	int i = 0;
	int car_id;

	printw("delay = %d\n", delay);
	while (j < MEM_SIZE)
	{
		if ((car_id = check_carri(carriage, j)))
			print_elem(g_map[j++].cell, car_id + 10); //g_map[j++].color + 10
		print_elem(g_map[j].cell, g_map[j].color);
		j++;
	}
}

void	npause(void)
{
	while (1)
		if (getch() == ' ')
			return ;
}


void	visualization(t_carriage *carriage)
{

	init_colors();
	int delay = 100000;
	int ch = getch();

	while (1)
	{
		ch = getch();

		if (ch == 'q')
			delay += 1000;
		if (ch == 'w')
			delay -= 1000;
		if (ch == ' ')
			npause();

		/* ПРОСТО ТЕСТ ДВИЖЕНИЯ КАРЕТКИ, МОЖНО УБРАТЬ */
		t_carriage *tmp = carriage;
		while (tmp)
		{
			tmp->position += 1;
			if (tmp->position == MEM_SIZE)
				tmp->position = 0;
			tmp = tmp->next;
		}
		/**********************************************/

		erase();

		print_map(carriage, delay);
		//box(stdscr, 0, 0);
		mvaddstr(0,0,"");
		wrefresh(stdscr);
		refresh();
		usleep(delay);
		ch = 0;
	}
	endwin();
}






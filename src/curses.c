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

void		print_map(t_carriage *carriage, int delay, int cycles)
{
	int j = 0;
	int i = 0;
	int car_id;

	printw("Cycles/second : %d\n", cycles);
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


void		check_key(int *cycles)
{
	int ch;

	ch = getch();
	if (ch == 'q')
		*cycles = ((*cycles + 100) > 1000) ? 1000 : *cycles + 100;
	if (ch == 'w')
		*cycles = ((*cycles + 10) > 1000) ? 1000 : *cycles + 10;
	if (ch == 'e')
		*cycles = ((*cycles + 1) > 1000) ? 1000 : *cycles + 1;
	if (ch == 'y')
		*cycles = ((*cycles - 100) < 1) ? 1 : *cycles - 100;
	if (ch == 't')
		*cycles = ((*cycles - 10) < 1) ? 1 : *cycles - 10;;
	if (ch == 'r')
		*cycles = ((*cycles - 1) < 1) ? 1 : *cycles - 1;
	if (ch == ' ')
		npause();
}

void	visualization(t_carriage *carriage)
{

	init_colors();
	int delay = 1000000;
	int cycles = 10;

	while (1)
	{
		check_key(&cycles);	

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

		print_map(carriage, delay, cycles);
		//box(stdscr, 0, 0);
		//mvaddstr(0,0,"");
		wrefresh(stdscr);
		refresh();
		usleep(delay / cycles);
		
	}
	endwin();
}






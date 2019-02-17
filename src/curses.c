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
	//wresize(stdscr, 74, 192); //set screen size
	//resizeterm(100, 200);
}

void		print_elem(UC elem, int pair, WINDOW *w, int x, int y)
{
	wattron(w, COLOR_PAIR(pair));
	mvwprintw(w, y, x, "%0.2x", elem);
	wattroff(w, COLOR_PAIR(pair));
	//wprintw(w, " ");
}

int 		check_carriage(t_carriage *carriage, int pos)
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

void		print_map(t_carriage *carriage, int delay, int cycles, WINDOW *w)
{
	int i = 0;
	int car_id;
	int x = 2;
	int y = 1;

	while (i < MEM_SIZE)
	{
		if ((car_id = check_carriage(carriage, i)))
			print_elem(g_map[i].cell, car_id + 10, w, x, y); //g_map[i++].color + 10
		else
			print_elem(g_map[i].cell, g_map[i].color, w, x ,y);
		i++;
		x += 3;
		if (x >= 192)
		{
			x = 2;
			y += 1;
		}
		if (y > 64)
		{
			x = 2;
			y = 1;
		}
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
	WINDOW *w;
	WINDOW *info;

	w = newwin(66, 195, 0, 0); 
	info = newwin(66, 50, 0, 194); 
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
		
		werase(w);
		werase(info);

		print_map(carriage, delay, cycles, w);

		mvwprintw(info, 1, 3, "Cycles/second : %d\n", cycles);
		mvwprintw(info, 3, 3, "'q' : +100\n");
		mvwprintw(info, 4, 3, "'w' : +10\n");
		mvwprintw(info, 5, 3, "'e' : +1\n");
		mvwprintw(info, 7, 3, "'r' : -1\n");
		mvwprintw(info, 8, 3, "'t' : -10\n");
		mvwprintw(info, 9, 3, "'y' : -100\n");

		wattron(w, COLOR_PAIR(10));
		wattron(info, COLOR_PAIR(10));
		box(w, 0, 0);
		box(info, 0, 0);
		wattroff(w, COLOR_PAIR(10));
		wattroff(info, COLOR_PAIR(10));

		wrefresh(w);
		wrefresh(info);
		usleep(delay / cycles);
		
	}
	delwin(w);
	delwin(info);
	endwin();
}






#include "../include/corewar.h"

void		init_colors(void)
{
	initscr();
	noecho();
	curs_set(0);
	timeout(0);
	start_color();
	init_pair(1, 3, 0); //Yellow, 11 bkgd
	init_pair(2, 2, 0); // Green, 10 bkgd
	init_pair(3, 4, 0); // Blue 12, 4
	init_pair(4, 9, 0); // Red, 9 bkgd 1
	init_pair(11, 0, 11); // carriage 1
	init_pair(12, 0, 10); // carriage 2
	init_pair(13, 0, 12); // carriage 3 
	init_pair(14, 0, 1); // carriage 4
	init_pair(21, 15, 3); // live 1
	init_pair(22, 15, 2); // live 2
	init_pair(23, 15, 4); // live 3
	init_pair(24, 15, 9); // live 4

	//init_pair(30, 6, 0); // CYAN
	init_pair(10, 8, 0); //Bright Black ("Gray")
}

void		print_elem(UC elem, int pair, int x, int y)
{
	wattron(g_base->w, COLOR_PAIR(pair));
	mvwprintw(g_base->w, y, x, "%0.2x", elem);
	wattroff(g_base->w, COLOR_PAIR(pair));
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

void		print_map(t_carriage *carriage)
{
	int car_id;
	int x = 2;
	int y = 1;
	int i = 0;

	while (i < MEM_SIZE)
	{
		if ((car_id = check_carriage(carriage, i)))
			print_elem(g_base->map[i].cell, car_id + 10, x, y);
		else if (g_base->map[i].cell == 1)
			print_elem(g_base->map[i].cell, g_base->map[i].color + 20, x, y);
		else
			print_elem(g_base->map[i].cell, g_base->map[i].color, x, y);
		i++;
		x += 3;
		y = (x >= 192) ? y + 1 : y;
		x = (x >= 192) ? 2 : x;
		y = (y > 64) ? 1 : y;
	}
}

void	npause(void)
{
	g_base->running = 0;

	Mix_PauseMusic();
	while (1)
	{
		werase(g_base->info);
		wattron(g_base->info, COLOR_PAIR(4));
		wattron(g_base->info, A_BLINK);
		mvwprintw(g_base->info, 1, 3, "STOPED\n");
		if (g_base->music_init == 1)
			mvwprintw(g_base->info, 1, 30, "MUSIC: Stoped\n");
		wattroff(g_base->info, COLOR_PAIR(4));
		wattroff(g_base->info, A_BLINK);
		if (g_base->music_init == 0)
			mvwprintw(g_base->info, 1, 30, "MUSIC: OFF\n");
		print_info_table();
		wrefresh(g_base->info);
		if (check_key(getch(), 0) == ' ')
		{
			Mix_ResumeMusic();
			g_base->running = 1;
			return ;
		}
	}
}


int		check_key(int ch, int check)
{
	int cycles;

	cycles = g_base->cycles;
	if (ch == 'q')
		g_base->cycles = ((cycles + 100) > 1000) ? 1000 : cycles + 100;
	if (ch == 'w')
		g_base->cycles = ((cycles + 10) > 1000) ? 1000 : cycles + 10;
	if (ch == 'e')
		g_base->cycles = ((cycles + 1) > 1000) ? 1000 : cycles + 1;
	if (ch == 'y')
		g_base->cycles = ((cycles - 100) < 1) ? 1 : cycles - 100;
	if (ch == 't')
		g_base->cycles = ((cycles - 10) < 1) ? 1 : cycles - 10;;
	if (ch == 'r')
		g_base->cycles = ((cycles - 1) < 1) ? 1 : cycles - 1;
	if (ch == 'd')
		g_base->cycles = 10;
	if (check && ch == ' ')
		npause();
	if (!g_base->music_init && ch == 'm')
		sdl_mixer_init();
	return ch;
}

void		sdl_mixer_init(void)
{
	g_base->music = NULL;
	g_base->music_init = 1;
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
		g_base->music_init = 0;
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
		g_base->music_init = 0;
	g_base->music = Mix_LoadMUS(MUS_PATH);
	if (g_base->music == NULL)
		g_base->music_init = 0;
	if (Mix_PlayMusic(g_base->music, -1) == -1)
		g_base->music_init = 0;
}

void	visualization_init(void)
{
	init_colors();
	Mix_PlayingMusic();
	g_base->w = newwin(66, 195, 0, 0);
	g_base->info = newwin(66, 50, 0, 194);
	g_base->delay = 1000000;
	g_base->cycles = 10;
	g_base->running = 1;
}

void	print_bots(void)
{
	int i;

	i = 0;
	while (i < g_base->bots)
	{
		wattron(g_base->info, COLOR_PAIR(i + 1));
		mvwprintw(g_base->info, 5 + (i * 6), 3, "Champ : %s\n", g_base->bot[i].bot_name);
		wattroff(g_base->info, COLOR_PAIR(i + 1));
		mvwprintw(g_base->info, 5 + (i * 6) + 1, 5, "Lives\t\t%d\n", 0);
		mvwprintw(g_base->info, 5 + (i * 6) + 2, 5, "Something else\t%d\n", 0);
		i++;
	}
}

void	print_duck(void)
{
	mvwprintw(g_base->info, 62, 1, "      _\n");
	mvwprintw(g_base->info, 63, 1, "  .__(.)< (MAY THE FORCE BE WHITH YOU)\n");
	mvwprintw(g_base->info, 64, 1, "  \\___)   \n");
}

void	print_run(void)
{
	if (g_base->running)
	{
		wattron(g_base->info, COLOR_PAIR(2));
		mvwprintw(g_base->info, 1, 3, "RUNING\n");
		if (g_base->music_init == 1)
			mvwprintw(g_base->info, 1, 30, "MUSIC: Play\n");
		wattroff(g_base->info, COLOR_PAIR(2));
		if (g_base->music_init == 0)
			mvwprintw(g_base->info, 1, 30, "MUSIC: OFF\n");
	}
}

void	print_info(void)
{
	int n;

	n = 5 + (g_base->bots * 6) + 2;
	print_run();
	mvwprintw(g_base->info, 3, 3, "Cycles/second : %d\n", g_base->cycles);
	mvwprintw(g_base->info, 58, 3, "Q : +100\tW : +10\t\tE : +1\n");
	mvwprintw(g_base->info, 59, 3, "R : -1\tT : -10\t\tY : -100\n");

	mvwprintw(g_base->info, n, 3, "CYCLE_TO_DIE\t\t%d\n", CYCLE_TO_DIE);
	mvwprintw(g_base->info, n + 2, 3, "CYCLE_DELTA\t\t%d\n", CYCLE_DELTA);
	mvwprintw(g_base->info, n + 4, 3, "NBR_LIVE\t\t%d\n", NBR_LIVE);
	mvwprintw(g_base->info, n + 6, 3, "MAX_CHECKS\t\t%d\n", MAX_CHECKS);

}

void	print_info_table(void)
{
	print_info();
	print_bots();
	print_duck();
	wattron(g_base->w, COLOR_PAIR(10));
	wattron(g_base->info, COLOR_PAIR(10));
	box(g_base->w, 0, 0);
	box(g_base->info, 0, 0);
	mvwhline(g_base->info, 5 + (g_base->bots * 6), 1, ACS_HLINE, 48);
	wattroff(g_base->w, COLOR_PAIR(10));
	wattroff(g_base->info, COLOR_PAIR(10));
}

void	visualization(t_carriage *carriage)
{
	
	check_key(getch(), 1);
	
	werase(g_base->w);
	werase(g_base->info);

	print_map(carriage);
	print_info_table();
	
	wrefresh(g_base->w);
	wrefresh(g_base->info);
	usleep(g_base->delay / g_base->cycles);
		
}






#ifndef MAIN_FRAME_H
#define MAIN_FRAME_H

typedef struct{
	int wall;
	int root;
	int path;
	int cline;
}block;

class mazeframe
{
private:
	int width;
	int mode;
	block** field;
	int escape_step;
public:
	mazeframe();
	mazeframe(int argc, char** argv);
	~mazeframe();
	void ckeckfield();
	void solution_check();
	void set_block(block** field);
	block** get_block();
	void path_solve();
	int get_escape_step();
	void wall_clear();
	void root_clear();
	void path_clear();
	void cline_clear();
	void solve_clear();
	void field_clear();
	//void reroll();
};
/*
class maze_solver : public mazeframe {
private:
	mazeframe* mazedata;
	int escape_step;
public:
	maze_solver(int argc, char** argv);
	void solution_check();
	int get_escape_step();
};
*/
class play_maze : public mazeframe{
private:

public:
	play_maze(int argc, char** argv);
};

#endif
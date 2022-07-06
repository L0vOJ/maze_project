#ifndef MAIN_FRAME_H
#define MAIN_FRAME_H

typedef struct{
	int x;
	int y;
	int wall;
	int root;
	int path;
	int cline;
}block;

class mazeframe
{
private:
	
protected:
	int width;
	int mode;
	block** field;
public:
	mazeframe();
	mazeframe(int argc, char** argv);
	~mazeframe();
	void ckeckfield();
};

class maze_solver : public mazeframe {
private:
	//mazeframe* mazedata;
	int escape_step;
public:
	maze_solver(int argc, char** argv);
	void solution_check();
	int get_escape_step();
};

class play_maze : public mazeframe{
private:

public:
	play_maze(int argc, char** argv);
};

#endif
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

class pathfinding : public mazeframe {
private:

public:
	pathfinding(int argc, char** argv);
	void solution_check();
};

#endif
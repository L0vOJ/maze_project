#ifndef MAZEFRAME_H
#define MAZEFRAME_H

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
	int width;
	int mode;
	block** field;
public:
	mazeframe();
	mazeframe(char** argv);
	~mazeframe();
	void ckeckfield();
};
#endif
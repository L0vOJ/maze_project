#ifndef MAIN_FRAME_H
#define MAIN_FRAME_H

#include <vector>	

typedef struct{
	int wall;
	int root;
	int path;
	int cline;
}block;

typedef struct{
	int year;
	int month;
	int day;
	int hour;
	int min;
	int sec;
}tlog;

class mazeframe
{
private:
	block** field;
	int escape_step;
	tlog t;
protected:
	int width;
	int mode;
public:
	mazeframe();
	mazeframe(int argc, char** argv);
	~mazeframe();

	void path_solve();

	void checkfield();
	void path_check();
	void path_check_num();

	void set_block(block** field);
	
	block** get_block();
	int get_width();
	int get_escape_step();
	//tm* get_timelog();
	void show_timelog();

	void wall_clear();
	void root_clear();
	void path_clear();
	void cline_clear();
	void solve_clear();
	void field_clear();
	void regen();
};

class play_maze : public mazeframe{		//상속하면 미로 자체 생성 가능해질 것
private:
	mazeframe* maze;
	block** field;
public:
	play_maze();
	play_maze(int argc, char** argv);
	play_maze(mazeframe& classA);
	void origin_check();
	void game_init();
	void step(int decision);
	~play_maze();
};
/*
class data_manage{	//로그 관리 시스템으로 만들 예정 //stl vector 걍 써도 되지만 이번엔 조잡해도 내가 직접 만들어본다
private:
	mazeframe* chunk;
public:
	data_manage();

	void push();
	void pull_back();
	void pull_point();
	void show_data();

	//void get_data();
	//void set_data();
};
*/
class command{	// real time amulate 모듈 // 파일 관리 모듈은 하위로 둔다 { : public data_manage }
private:
	int* keybind;
	//mazeframe* dm;
	//data_manage* dm;
	std::vector<mazeframe*> dm;
public:
	command();
	void run();
	void navigate(int input);
	int keybinding(char key);
	//void setKeyBind();
	void log_show();
};



#endif
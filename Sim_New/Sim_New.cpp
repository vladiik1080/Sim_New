#include <iostream>
#include <vector>
#include <math.h>
#include <random>
#include <time.h>

using namespace std;

enum Obj_move
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	STAND
};

enum Obj_alive
{
	START,
	EAT,
	DEATH
};

enum Obj_color
{
	WHITE,
	GREEN,
	YELLOW,
	RED,
	BLUE,
	BLACK
};

class Obj
{
public:
	Obj(Obj_alive alive, Obj_move move, Obj_color color)
		:x_alive(alive), x_move(move), x_color(color)
	{}
	Obj()
	{}
	void Set_obj(Obj_alive alive, Obj_move move, Obj_color color)
	{
		x_alive = alive;
		x_move = move;
		x_color = color;
	}
	void Set_obj_alive(Obj_alive alive)
	{
		x_alive = alive;
	}
	void Set_obj_move(Obj_move move)
	{
		x_move = move;
	}
	void Set_obj_color(Obj_color color)
	{
		x_color = color;
	}
	void Get_obj(Obj obj)
	{
		cout << obj.x_alive << " " << obj.x_move << " " << obj.x_color << endl;
	}
	void Get_alive()
	{
		cout << x_alive << endl;
	}
	Obj Get_def_obj()
	{
		Obj* obj = new Obj;
		obj->Set_obj(START,STAND,WHITE);

		return *obj;
	}
	int set_alive()
	{
		int alive_v;

		srand(time(NULL));

		alive_v = rand() % 2;
		if (alive_v == 0)
			return 0;
		if (alive_v == 1)
			return 1;
	}
	int set_move()
	{
		srand(time(NULL));

		int move_v = rand() % 5;
		if (move_v == 0)
			return LEFT;
		if (move_v == 1)
			return RIGHT;
		if (move_v == 2)
			return UP;
		if (move_v == 3)
			return DOWN;
		if (move_v == 4)
			return STAND;
	}
	
private:
	Obj_alive x_alive;
	Obj_move x_move;
	Obj_color x_color;
};

class Map:public Obj
{
public:
	vector <Obj> map;
	Map(int size_x,int size_y,vector <Obj> map)
		:x_size_x(size_x),x_size_y(size_y),map(map)
	{}
	void Init_map()
	{
		for (int i = 0; i < x_size_x * x_size_y; i++)
		{
			map.push_back(Get_def_obj());
		}
	}
	void Get_Map()
	{
		for (int i = 0; i < map.size(); i++)
		{
			Get_obj(map[i]);
		}
	}
	void Step_Map()
	{
		for (int i = 0; i < map.size(); i++)
		{
			int alive = set_alive();
			if (alive == 0)
				map[i].Set_obj_alive(EAT);
			else
				map[i].Set_obj_alive(DEATH);
			Get_obj(map[i]);
			//map[i].Set_obj_move(set_move());
		}
	}
private:
	int x_size_x;
	int x_size_y;
};

int main()
{
	srand(time(NULL));

	vector <Obj> map;

	Obj obj;
	Map map_map(3,3,map);
	map_map.Init_map();
	map_map.Get_Map();
	map_map.Step_Map();
	//map.Get_Map();
	

	return 0;
}

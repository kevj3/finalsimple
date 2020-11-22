#include "ofMain.h"

class Character
{
public:
	Character() {
		int x;
		int y;
		int dx;
		int dy;

		int width;
		int height;
		int health;
	}

	int x = 500;
	int y = 500;

	int dx = 0;
	int dy = 0;


	int width = 100;
	int height = 130;
	int health = 1000;

	void create(ofImage img);
	void Move();

	void MoveUp();
	void MoveRight();
	void MoveLeft();
	void MoveDown();
	void MoveUpRight();
	void MoveUpLeft();
	void MoveDownLeft();
	void MoveDownRight();
	void Stop();
};
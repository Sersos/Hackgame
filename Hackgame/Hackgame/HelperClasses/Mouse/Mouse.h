#ifndef MOUSE_H
#define MOUSE_H

class Mouse
{
public:
	Mouse();

	int GetMousePositionX();
	int GetMousePositionY();

	void Update();

private:
	int m_x;
	int m_y;
};

#endif
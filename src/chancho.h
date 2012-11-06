#include <gl\glut.h>

class Chancho{
private:
	float x;
	float y;
	float z;
	bool muerto;
public:
	Chancho();
	~Chancho();
	void dibujar( void );
	float getX();
	float getY();
	float getZ();
	void setX(float xx);
	void setY(float yy);
	void setZ(float zz);
	void setPosition(float x, float y, float z);
	void morrir();
};

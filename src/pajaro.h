#include <gl\glut.h>

class Pajaro{
private:
	float x;
	float y;
	float z;
public:
	Pajaro();
	~Pajaro();
	void dibujar( void );
	float getX();
	float getY();
	float getZ();
	void setX(float xx);
	void setY(float yy);
	void setZ(float zz);
	void setPosition(float xx, float yy, float zz);
};

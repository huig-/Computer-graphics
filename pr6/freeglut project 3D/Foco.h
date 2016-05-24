
#ifndef Foco_H_
#define Foco_H_

class Foco{
    public:
	Foco(GLfloat pos[3], GLfloat dir[3]);
	void setPos(GLfloat pos[3]);
	void setDir(GLfloat dir[3]);
    private:
	GLfloat pos[3];
	GLfloat dir[3];
};
#endif

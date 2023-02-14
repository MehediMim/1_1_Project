# include "iGraphics.h"

int x = 300, y = 300, r = 20;

bool MusicOn=true;
void iDraw() {
	iClear();
	iSetColor(20, 200, 200);
	iFilledCircle(x, y, r);
}
void iMouseMove(int mx, int my) {
}

void iMouse(int button, int state, int mx, int my) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
	}
}

void iKeyboard(unsigned char key) {
	if (key == 'q') {
		exit(0);
	}
}

void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}
}


int main() {
    if(MusicOn){
        PlaySound("Sound/Congratulations_sound.wav",NULL,SND_LOOP);
    }
	iInitialize(400, 400, "demo");
	return 0;
}

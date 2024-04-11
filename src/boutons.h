#ifndef BOUTONS_H
#define BOUTONS_H
#include <donnees_borne.h>
#include "Timer.h"
#include "Voyants.h"

typedef enum{
	CHARGE = 0,
	STP

}button;

typedef enum{
        TIMEOUT = 0,
        SUCCESS

}status;
class Boutons{
	entrees *io;
	int shmid;
	Timer timer;
	Voyants voyant;
	public:
	Boutons();
	int get_bouton(button but);
        status attente_boutons(int temps);
        void reset_bouton_stop();
};

#endif

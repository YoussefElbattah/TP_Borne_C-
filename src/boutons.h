#ifndef BOUTONS_H
#define BOUTONS_H
#include <donnees_borne.h>
#include "Timer.h"
#include "Voyants.h"

/**
* \enum button
* \brief Boutons de la borne (CHARGE & STOP).
*
* button est un enum qui prend en charge deux constants CHARGE et STP qui sont respectivement le bouton (charge et stop)
* 
*/


typedef enum{
	CHARGE = 0, /*!< Bouton charge */
	STP			/*!< Bouton stop */

}button;

/**
* \enum status
* \brief le status du bouton charge soit SUCCESS ou TIMEOUT (CHARGE & STOP).
* 
* status est une série qui prend en charge deux constants SUCCESS et TIMEOUT qui sont respectivement le bouton charge est en success ou timeout
* 
*/

typedef enum{
        TIMEOUT = 0, 	/*!< Bouton charge n'est pas appuié avant le temps défini */
        SUCCESS			/*!< Bouton charge est appuié avec success avant le temps défini */

}status;

/*! \class Boutons
* \brief classe representant les Boutons de la borne
*
* la classe Boutons qui gére les Boutons de la borne de charge
*/
class Boutons{
	entrees *io;
	int shmid;
	Timer timer;
	public:
	Boutons();
	int get_bouton(button but);
	status attente_boutons(int temps);
};

#endif

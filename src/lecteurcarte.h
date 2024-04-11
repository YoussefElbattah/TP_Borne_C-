#ifndef LECTEURCARTE_H
#define LECTEURCARTE_H
#include <lcarte.h>
#include "Base_client.h"
#include "Voyants.h"
#include "boutons.h"

/*! \class LecteurCarte
* \brief classe representant la lecture de la carte du client
*
* la classe LecteurCarte qui gére la lecture de la carte du client
*/

class LecteurCarte
{
	int numero;
        int carte;
        int current_num;
  public : 
        int lire_carte();
	LecteurCarte();
        int get_num();
};

#endif // LECTEURCARTE_H

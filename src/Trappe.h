#ifndef TRAPPE_H
#define TRAPPE_H

#include "donnees_borne.h"
#include "Voyants.h"

/*! \class Voyants
* \brief classe representant les voyants de la borne
*
* la classe Charge qui gére les voyants de la borne de charge
*/
class Trappe{
    int trappe_status;
    entrees *io;
    Voyants voyant;
public:
    Trappe();
    void Close();
    void Open();
};

#endif // TRAPPE_H

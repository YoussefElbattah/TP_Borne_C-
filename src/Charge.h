#ifndef CHARGE_H
#define CHARGE_H
#include "donnees_borne.h"


/*! \class Charge
* \brief classe representant les élements de charge de la borne de charge
*
* la classe Charge qui gére l'interface charge de la borne
*/

class Charge{
    int tension;
    entrees *io;
public:
    Charge();
    int get_tension();
    void set_pwm(pwm PWM);
    pwm get_pwm();
    void close_AC();
    void open_AC();
};

#endif // CHARGE_H

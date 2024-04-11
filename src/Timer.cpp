/**
* \file Timer.cpp
* \brief Definition des methodes de la classe Timer
* \authors ELBATTAH et SAPIN-CAPEL
* \date 11 avril 2024
*
* Definition des methodes de la classe Timer qui gére le timer 
*
*/

#include <iostream>
#include "Timer.h"
#include <memoire_borne.h>

/**
 * @brief méthode qui permet d'initialiser le timer
 * 
 */
void Timer::initialiser(){
	io = acces_memoire(&shmid);
	/* associe la zone de memoire partageeau pointeur */
	if (io==NULL) std::cout<<"Erreur pas de mem sh"<<std::endl;
	depart_timer=io->timer_sec;
}
/**
 * @brief méthode qui renvoie la valeur du temps passé après l'initialisation
 * 
 * @return int 
 */
int Timer::get_value(){
	end_timer = io->timer_sec;
	return (end_timer - depart_timer);

}

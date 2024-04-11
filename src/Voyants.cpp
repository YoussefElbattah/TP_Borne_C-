/**
* \file Voyants.cpp
* \brief Definition des methodes de la classe Voyants
* \authors ELBATTAH et SAPIN-CAPEL
* \date 11 avril 2024
*
* Definition des methodes de la classe Voyants qui gére les Voyants de la borne de charge
*
*/

#include <iostream>
#include "Voyants.h"
#include <unistd.h>
int shmid;

/**
 * @brief Construct a new Voyants:: Voyants object
 * 
 */
Voyants::Voyants(){
	io = acces_memoire(&shmid);
	/* associe la zone de memoire partageeau pointeur */
        if (io==NULL) std::cout<<"Erreur pas de mem sh"<<std::endl;
}
/**
 * @brief méthode qui permet de changer la couleur du voyant charge
 * 
 * @param couleur 
 */
void Voyants::set_voyant_charge(led couleur){
	io->led_charge = couleur;
}
/**
 * @brief méthode qui permet de changer la couleur du voyant disponible
 * 
 * @param couleur 
 */
void Voyants::set_voyant_dispo(led couleur){
	io->led_dispo = couleur;
}
/**
 * @brief méthode qui permet de changer la couleur du voyant prise
 * 
 * @param couleur 
 */
void Voyants::set_voyant_prise(led couleur){
	io->led_prise = couleur;
}
/**
 * @brief méthode qui permet de changer la couleur du voyant defaut
 * 
 * @param couleur 
 */
void Voyants::set_voyant_defaut(led couleur){
	io->led_defaut = couleur;
}
/**
 * @brief méthode qui permet de changer la couleur du voyant trappe
 * 
 * @param couleur 
 */
void Voyants::set_voyant_trappe(led couleur){
	io->led_trappe = couleur;
}

/**
 * @brief méthode qui permet de clignoter le voyant charge
 * 
 * @param couleur 
 */
void Voyants::blink_charge(led couleur){
	timer.initialiser();
	while(timer.get_value() < 8){
		io->led_charge = couleur;
		sleep(1);
		io->led_charge = OFF;
		sleep(1);
	}
}

/**
 * @brief méthode qui permet de clignoter le voyant defaut
 * 
 * @param couleur 
 */

void Voyants::blink_defaut(led couleur){

	timer.initialiser();
	while(timer.get_value() < 8){
		io->led_charge = couleur;
		sleep(1);
		io->led_charge = OFF;
		sleep(1);
	}
}

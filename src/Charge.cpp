/**
* \file Charge.cpp
* \brief Definition des methodes de la classe Charge
* \authors ELBATTAH et SAPIN-CAPEL
* \date 11 avril 2024
*
* Definition des methodes de la classe Charge qui gére l'interface charge de la borne
*
*/

#include "Charge.h"
#include <memoire_borne.h>
#include <iostream>

/**
 * @brief Construct a new Charge:: Charge object
 * 
 */
Charge::Charge(){
    io = acces_memoire(&shmid);
    /* associe la zone de memoire partageeau pointeur */
    if (io==NULL) std::cout<<"Erreur pas de mem sh"<<std::endl;
}

/**
 * @brief méthode qui renvoie la tension de la borne
 * 
 * @return int : tension
 */
int Charge::get_tension(){
    return(io->gene_u);
}

/**
 * @brief méthode qui change la valeur de PWM
 * 
 * @param PWM 
 */
void Charge::set_pwm(pwm PWM){
    io->gene_pwm = PWM;
}

/**
 * @brief méthode qui renvoie la valeur du PWM de la borne
 * 
 * @return pwm 
 */
pwm Charge::get_pwm(){
    return io->gene_pwm;
}

/**
 * @brief méthode qui permet d'ouvrir le contacteur AC
 * 
 */
void Charge::open_AC(){
    io->contacteur_AC = 0;
}

/**
 * @brief méthode qui permet de fermer le contacteur AC
 * 
 */
void Charge::close_AC(){
    io->contacteur_AC = 1;
}


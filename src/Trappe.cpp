/**
* \file Trappe.cpp
* \brief Definition des methodes de la classe Trappe
* \authors ELBATTAH et SAPIN-CAPEL
* \date 11 avril 2024
*
* Definition des methodes de la classe Trappe qui gére la trappe 
*
*/

#include "Trappe.h"
#include <iostream>

/**
 * @brief Construct a new Trappe:: Trappe object
 * 
 */
Trappe::Trappe(){
    trappe_status = 0;
    io = acces_memoire(&shmid);
    /* associe la zone de memoire partageeau pointeur */
    if (io==NULL) std::cout<<"Erreur pas de mem sh"<<std::endl;
}

/**
 * @brief méthode qui permet d'ouvrir la trappe 
 * 
 */
void Trappe::Open(){
    voyant.set_voyant_trappe(VERT);
}

/**
 * @brief méthode qui permet de fermer la trappe 
 * 
 */
void Trappe::Close(){
    voyant.set_voyant_trappe(ROUGE);
}

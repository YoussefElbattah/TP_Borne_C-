/**
* \file Base_client.cpp
* \brief Definition des methodes de la classe Base_client
* \authors ELBATTAH et SAPIN-CAPEL
* \date 11 avril 2024
*
* Definition des methodes de la classe Base_client où les clients sont enregistrés
*
*/

#include "Base_client.h"
#include <iostream>
#include <fstream>

using namespace std;

/**
 * @brief méthode pour l'authentification d'un client
 * 
 * @param numero_carte du client authentifié 
 * @return int : Succes ou Echec
 */
int Base_client::authentifier(int numero_carte){
	for(int i = 0; i < Numero_carte.size() ; i++){
		if(numero_carte == Numero_carte[i]){
			return 1;
		}
	}
	return 0;
}

/**
 * @brief Construct a new Base_client::Base_client object
 * 
 */
Base_client::Base_client(){
	fstream MyReadFile;
	MyReadFile.open("Base_client.txt",ios::in);
	
	if(!MyReadFile){
		std::cout<< "le fichier n'existe pas " << endl;
	}else{
		while(!MyReadFile.eof()){
		MyReadFile >> buff_client;
                Numero_carte.push_back(buff_client);
		}
		MyReadFile.close();
	}
}

#pragma once
#include <string>			// Needed to process error messages
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <XML\rapidxml_utils.hpp>
#include <XML\rapidxml_iterators.hpp>
#include <XML\rapidxml_print.hpp>
#include <XML\rapidxml_utils.hpp>

//#define RESOURCE_PATH "../../res/"
//#define RESOURCE_FILE(filename) (RESOURCE_PATH + (filename)).c_str()

void testXml(const std::string &filename, std::string diff) {
	rapidxml::file<> xmlFile(filename.c_str());//carrega el fitxer xml amb la ruta especifcada
	rapidxml::xml_document<>doc;// crea un document que contindrà el DOM tree per l'XML
	doc.parse<0>(xmlFile.data());//parseja tot el contingut del fitxer carregat
								 //la funcio data() retorna una cadena de caracters amb tot el que te larxiu
	rapidxml::xml_node<> *pRoot = doc.first_node("difficultMode");

	std::cout << "Nmbre de la raiz: " << doc.first_node()->name() << "\n";//aqui tindria que imprimir:difficultMode
																		  //rapidxml::xml_node<> *pRoot = doc.first_node();//el rootelement es el prmier element del arxiu xml que sera el primer node: difficultMode
	for (rapidxml::xml_node<> *pNode = pRoot->first_node("MODE")->next_sibling(); pNode; pNode = pNode->next_sibling()) {
		rapidxml::xml_attribute<> *pAttr = pNode->first_attribute();
		std::cout << pAttr->name() << "-" << pAttr->value() << "\n";

	}
	rapidxml::xml_node<> *pNode = pRoot->first_node("MODE");
	rapidxml::xml_node<> *pNode1 = pNode->first_node("time");
	std::cout << pNode1->value() << std::endl;
	std::string a;
	a = pNode1->value();
	int temps = atoi(a.c_str());
	std::cout << "temps: " << temps << std::endl;

	int b = temps + 1;
	std::cout << b << std::endl;

	std::cout << "AAAAAAAAAAAAAAAAAAAAAAAAA\n" << std::endl;
	std::string tmp, vI, aI, iI;//temps, velocitat, aliments, increment
	std::string columns, rows;

	int time; int speedI; int foodI; int evolveI;
	int numColumns; int numRows;

	for (rapidxml::xml_node<> *pNode = pRoot->first_node("MODE"); pNode; pNode = pNode->next_sibling()) {
		rapidxml::xml_attribute<> *pAttr = pNode->first_attribute();
		std::string atr;
		atr = pAttr->value();


		//easy stats
		if (atr == "facil" && diff == "1") {
			rapidxml::xml_node<> *pColumns = pNode->first_node("numCol");//agafo lstring de columnes i el guardo com un int
			columns = pColumns->value();
			numColumns = atoi(rows.c_str());

			rapidxml::xml_node<> *pRows = pNode->first_node("numRow");
			rows = pRows->value();
			numRows = atoi(rows.c_str());

			rapidxml::xml_node<> *pTemps = pNode->first_node("time");
			tmp = pTemps->value();
			time = atoi(tmp.c_str());

			rapidxml::xml_node<> *pVel = pNode->first_node("vInicial");
			vI = pVel->value();
			speedI = atoi(vI.c_str());

			rapidxml::xml_node<> *pAl = pNode->first_node("alimentsIncials");
			aI = pAl->value();
			foodI = atoi(aI.c_str());

			rapidxml::xml_node<> *pInc = pNode->first_node("incrementAliments");
			iI = pInc->value();
			evolveI = atoi(iI.c_str());
			std::cout  << numRows << "FUNCIONA" << std::endl;

			break;
		}

		/*//medium stats
		if (atr == "medio" && diff == "2") {
			rapidxml::xml_node<> *pColumns1 = pNode->first_node("numCol");//agafo lstring de columnes i el guardo com un int
			columns = pColumns1->value();
			numColumns = atoi(rows.c_str());

			rapidxml::xml_node<> *pRows1 = pNode->first_node("numRow");
			rows = pRows1->value();
			numRows = atoi(rows.c_str());

			rapidxml::xml_node<> *pTemps1 = pNode->first_node("time");
			tmp = pTemps1->value();
			time = atoi(tmp.c_str());

			rapidxml::xml_node<> *pVel1 = pNode->first_node("vInicial");
			vI = pVel1->value();
			speedI = atoi(vI.c_str());

			rapidxml::xml_node<> *pAl1 = pNode->first_node("alimentsIncials");
			aI = pAl1->value();
			foodI = atoi(aI.c_str());

			rapidxml::xml_node<> *pInc1 = pNode->first_node("incrementAliments");
			iI = pInc1->value();
			evolveI = atoi(iI.c_str());
			std::cout << time << "\n" << numRows << "FUNCIONA" << std::endl;
		}
		 //hard stats
		 if (atr == "dificil" && diff == "3") {
		 rapidxml::xml_node<> *pColumns = pNode->first_node("numCol");//agafo lstring de columnes i el guardo com un int
		 columns = pColumns->value();
		 numColumns = atoi(rows.c_str());

		 rapidxml::xml_node<> *pRows = pNode->first_node("numRow");
		 rows = pRows->value();
		 numRows = atoi(rows.c_str());

		 rapidxml::xml_node<> *pTemps = pNode->first_node("time");
		 tmp = pTemps->value();
		 time = atoi(tmp.c_str());

		 rapidxml::xml_node<> *pVel = pNode->first_node("vInicial");
		 vI = pVel->value();
		 speedI = atoi(vI.c_str());

		 rapidxml::xml_node<> *pAl = pNode->first_node("alimentsIncials");
		 aI = pAl->value();
		 foodI = atoi(aI.c_str());

		 rapidxml::xml_node<> *pInc = pNode->first_node("incrementAliments");
		 iI = pInc->value();
		 evolveI = atoi(iI.c_str());
		 std::cout << time << "\n" << numRows << std::endl;
		 }*/

		else {
			std::cout << "INTRODUCE A VALID DIFFICULTY" << std::endl;
		}
	}


}





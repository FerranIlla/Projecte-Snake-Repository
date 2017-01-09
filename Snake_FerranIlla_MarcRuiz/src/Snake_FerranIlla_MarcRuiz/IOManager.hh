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

int timeXML, speedXML, foodXML, incrementXML, numColumnsXML, numRowsXML;

void readDifficultyXml(int diff) {
	rapidxml::file<> xmlFile("../../res/test.xml");//carrega el fitxer xml amb la ruta especifcada
	rapidxml::xml_document<>doc;// crea un document que contindrà el DOM tree per l'XML
	doc.parse<0>(xmlFile.data());//parseja tot el contingut del fitxer carregat
								 //la funcio data() retorna una cadena de caracters amb tot el que te larxiu
	rapidxml::xml_node<> *pRoot = doc.first_node("difficultMode");

	std::string tmp, vI, aI, iI;//temps, velocitat, aliments, increment
	std::string columns, rows;



	for (rapidxml::xml_node<> *pNode = pRoot->first_node("MODE"); pNode; pNode = pNode->next_sibling()) {
		rapidxml::xml_attribute<> *pAttr = pNode->first_attribute("difficult");
		std::string atr;
		atr = pAttr->value();
		if (atr == "facil" && diff == 0) { //easy difficulty
			rapidxml::xml_node<> *pColumns = pNode->first_node("numCol");//agafo lstring de columnes i el guardo com un int
			columns = pColumns->value();
			numColumnsXML = atoi(columns.c_str());
			//std::cout << "nombre de columnes: " << numColumnsXML << std::endl;

			rapidxml::xml_node<> *pRows = pNode->first_node("numRow");
			rows = pRows->value();
			numRowsXML = atoi(rows.c_str());
			//std::cout << "nombre de fileres: " << numRowsXML << std::endl;

			rapidxml::xml_node<> *pTemps = pNode->first_node("time");
			tmp = pTemps->value();
			timeXML = atoi(tmp.c_str());
			//std::cout << "timer: " << timeXML << std::endl;

			rapidxml::xml_node<> *pVel = pNode->first_node("vInicial");
			vI = pVel->value();
			speedXML = atoi(vI.c_str());
			//std::cout << "speed of the snake: " << speedXML << std::endl;

			rapidxml::xml_node<> *pAl = pNode->first_node("alimentsInicials");
			aI = pAl->value();
			foodXML = atoi(aI.c_str());
			//std::cout << "number of food: " << foodXML << std::endl;

			rapidxml::xml_node<> *pInc = pNode->first_node("incrementAliments");
			iI = pInc->value();
			incrementXML = atoi(iI.c_str());
			//std::cout << "increment: " << incrementXML << std::endl;
			break;
		}
		else if (atr == "medio" && diff == 1) { //normal difficulty
			rapidxml::xml_node<> *pColumns1 = pNode->first_node("numCol");//agafo lstring de columnes i el guardo com un int
			columns = pColumns1->value();
			numColumnsXML = atoi(columns.c_str());
			//std::cout << "nombre de columnes: " << numColumnsXML << std::endl;

			rapidxml::xml_node<> *pRows = pNode->first_node("numRow");
			rows = pRows->value();
			numRowsXML = atoi(rows.c_str());
			//std::cout << "el nombre de files son: " << numRowsXML << std::endl;

			rapidxml::xml_node<> *pTemps1 = pNode->first_node("time");
			tmp = pTemps1->value();
			timeXML = atoi(tmp.c_str());
			//std::cout << "el temps son: " << timeXML << " segons" << std::endl;
	
			rapidxml::xml_node<> *pVel1 = pNode->first_node("vInicial");
			vI = pVel1->value();
			speedXML = atoi(vI.c_str());
			//std::cout << "la velocitat inicial es: " << vI << std::endl;

			rapidxml::xml_node<> *pAl1 = pNode->first_node("alimentsInicials");
			aI = pAl1->value();
			foodXML = atoi(aI.c_str());
			//std::cout << "els aliments que hi hauran: " << foodXML << std::endl;

			rapidxml::xml_node<> *pInc1 = pNode->first_node("incrementAliments");
			iI = pInc1->value();
			incrementXML = atoi(iI.c_str());
			//std::cout << "increment de aliments es: " << incrementXML << std::endl;
			break;

		}

		//hard stats
		if (atr == "dificil" && diff == 2) { //hard difficulty
			rapidxml::xml_node<> *pColumns = pNode->first_node("numCol");//agafo lstring de columnes i el guardo com un int
			columns = pColumns->value();
			numColumnsXML = atoi(columns.c_str());
			//std::cout << "nombre de columnes: " << numColumnsXML << std::endl;

			rapidxml::xml_node<> *pRows = pNode->first_node("numRow");
			rows = pRows->value();
			numRowsXML = atoi(rows.c_str());
			//std::cout << "el nombre de files son: " << numRowsXML << std::endl;

			rapidxml::xml_node<> *pTemps = pNode->first_node("time");
			tmp = pTemps->value();
			timeXML = atoi(tmp.c_str());
			//std::cout << "el temps son: " << timeXML << " segons" << std::endl;

			rapidxml::xml_node<> *pVel = pNode->first_node("vInicial");
			vI = pVel->value();
			speedXML = atoi(vI.c_str());
			//std::cout << "la velocitat inicial es: " << vI << std::endl;

			rapidxml::xml_node<> *pAl = pNode->first_node("alimentsInicials");
			aI = pAl->value();
			foodXML = atoi(aI.c_str());
			//std::cout << "els aliments que hi hauran: " << foodXML << std::endl;

			rapidxml::xml_node<> *pInc = pNode->first_node("incrementAliments");
			iI = pInc->value();
			incrementXML = atoi(iI.c_str());
			//std::cout << "increment de aliments es: " << incrementXML << std::endl;

			break;
		}
	}

}


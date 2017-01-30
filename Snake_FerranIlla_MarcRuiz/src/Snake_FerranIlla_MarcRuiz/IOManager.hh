#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include<algorithm>
#include <XML\rapidxml_utils.hpp>
#include <XML\rapidxml_iterators.hpp>
#include <XML\rapidxml_print.hpp>
#include <XML\rapidxml_utils.hpp>

int timeXML, speedXML, foodXML, incrementXML, wallXML;

void readDifficultyXml(int diff) {
	rapidxml::file<> xmlFile("../../res/test.xml"); //carrega el fitxer xml amb la ruta especifcada
	rapidxml::xml_document<>doc; // crea un document que contindrà el DOM tree per l'XML
	doc.parse<0>(xmlFile.data()); //parseja tot el contingut del fitxer carregat
								 //la funcio data() retorna una cadena de caracters amb tot el que te larxiu
	rapidxml::xml_node<> *pRoot = doc.first_node("difficultMode");

	std::string tmp, vI, aI, iI, wall; //temps, velocitat, aliments, increment, midaParets


	for (rapidxml::xml_node<> *pNode = pRoot->first_node("MODE"); pNode; pNode = pNode->next_sibling()) {
		rapidxml::xml_attribute<> *pAttr = pNode->first_attribute("difficult");
		std::string atr;
		atr = pAttr->value();
		if (atr == "facil" && diff == 0) { //easy difficulty
			rapidxml::xml_node<> *pWall = pNode->first_node("wallSize"); //agafo lstring de columnes i el guardo com un int
			wall = pWall->value();
			wallXML = atoi(wall.c_str());
			
			rapidxml::xml_node<> *pTemps = pNode->first_node("time");
			tmp = pTemps->value();
			timeXML = atoi(tmp.c_str());

			rapidxml::xml_node<> *pVel = pNode->first_node("vInicial");
			vI = pVel->value();
			speedXML = atoi(vI.c_str());

			rapidxml::xml_node<> *pAl = pNode->first_node("alimentsInicials");
			aI = pAl->value();
			foodXML = atoi(aI.c_str());

			rapidxml::xml_node<> *pInc = pNode->first_node("incrementAliments");
			iI = pInc->value();
			incrementXML = atoi(iI.c_str());
			break;
		}
		else if (atr == "medio" && diff == 1) { //normal difficulty
			rapidxml::xml_node<> *pWall = pNode->first_node("wallSize"); //agafo lstring de columnes i el guardo com un int
			wall = pWall->value();
			wallXML = atoi(wall.c_str());

			rapidxml::xml_node<> *pTemps1 = pNode->first_node("time");
			tmp = pTemps1->value();
			timeXML = atoi(tmp.c_str());
	
			rapidxml::xml_node<> *pVel1 = pNode->first_node("vInicial");
			vI = pVel1->value();
			speedXML = atoi(vI.c_str());

			rapidxml::xml_node<> *pAl1 = pNode->first_node("alimentsInicials");
			aI = pAl1->value();
			foodXML = atoi(aI.c_str());

			rapidxml::xml_node<> *pInc1 = pNode->first_node("incrementAliments");
			iI = pInc1->value();
			incrementXML = atoi(iI.c_str());
			break;

		}

		if (atr == "dificil" && diff == 2) { //hard difficulty
			rapidxml::xml_node<> *pWall = pNode->first_node("wallSize"); //agafo lstring de columnes i el guardo com un int
			wall = pWall->value();
			wallXML = atoi(wall.c_str());

			rapidxml::xml_node<> *pTemps = pNode->first_node("time");
			tmp = pTemps->value();
			timeXML = atoi(tmp.c_str());

			rapidxml::xml_node<> *pVel = pNode->first_node("vInicial");
			vI = pVel->value();
			speedXML = atoi(vI.c_str());

			rapidxml::xml_node<> *pAl = pNode->first_node("alimentsInicials");
			aI = pAl->value();
			foodXML = atoi(aI.c_str());

			rapidxml::xml_node<> *pInc = pNode->first_node("incrementAliments");
			iI = pInc->value();
			incrementXML = atoi(iI.c_str());
			break;
		}
	}

}

struct Persona {
	string nombre;
	int score;
	bool operator <(Persona aux) {
		return (score < aux.score);
	};
};

void writeRanking(vector<Persona> playerData) {
	ofstream updatefile("../../res/ranking.bin", ios::out | ios::binary);
	for (int i = 0; i < playerData.size(); i++) {
		updatefile.write(playerData[i].nombre.c_str(), playerData[i].nombre.size()); // Write string to binary file
		updatefile.write("\0", sizeof(char)); // Add null end string for easier reading
		updatefile.write(reinterpret_cast<char*>(&playerData[i].score), sizeof(playerData[i].score)); // Write int to binary file
	}
	updatefile.close();
}

vector<Persona> readRanking() {//s'imprimeix per consola
	vector<Persona> ranking;
	ranking.resize(10);
	ifstream loadfile("../../res/ranking.bin", ios::in | ios::binary);
	for (int i = 0; i < ranking.size(); i++) {
		getline(loadfile, ranking[i].nombre, '\0'); // Get player name (only if null ternimated in binary)
		loadfile.read(reinterpret_cast<char*>(&ranking[i].score), sizeof(ranking[i].score)); // Read int bytes

	}
	loadfile.close();
	return ranking;
}

vector<Persona> updateRanking(vector<Persona> r, Persona playerData) {
	
	r.push_back(playerData);
	sort(r.rbegin(), r.rend());
	r.pop_back();

	return r;
}

void printRanking(vector<Persona> r) {
	cout << "----------RANKING----------" << endl;
	for (int i = 0; i < r.size(); i++) {
		cout << "Player: { " << r[i].nombre << ", " << r[i].score << " }" << endl; //Show the ranking 
	}
}
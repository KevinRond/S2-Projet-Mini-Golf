// Mini-Golf.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Ball.h"
#include "Hole.h"
#include "Terrain.h"
#include "Interraction.h"
#include "Mur.h"
#include "Coup.h"
#include "GameManager.h"
#include "Manette.h"

using namespace std;


int main()
{
	//GameManager gm(20, 25);
	//gm.Run();
	//Terrain *terrain1 = new Terrain;
	//terrain1->OpenTerrain("Terrain2.txt");
	//terrain1->Display();
	/*Interraction* inter = new Interraction;
	Ball* ball1 = new Ball;
	Mur* mur1 = new Mur(0, 20, 20, 20);
	ball1->Set_direction(270);
	ball1->Set_Vx(5);
	inter->BalleMur(ball1, mur1);*/
	//Coup coup1(30, 100);
	//terrain1->CoupDonne(coup1);
	//terrain1->CoupDonne(coup1);
	Manette manette;
	manette.demande(2, 9);
	string com = "COM7";
	manette.setup(com);
	std::thread comm(&Manette::communication, &manette);

/*----------------------------- Tests Manette + coup -----------------------------*/
	Terrain* terrain = new Terrain;
	terrain->OpenTerrain("Terrain3.txt");
	terrain->Display();
	Coup coup;
	while (!manette.getButton1())
	{
		coup.setDirection(manette.getJoyX()-2);
		cout << coup.getDirection() << endl;
		Sleep(100);
	}
	manette.demande(3, 9);
	for (int i = 0; i < 5; i++)
	{
		if (manette.getAmplitude() > coup.getAmplitude())
			coup.setAmplitude(manette.getAmplitude());
		cout << coup.getAmplitude() << endl;
		Sleep(1000);
	}
	coup.initcoup();
	terrain->CoupDonne(coup);
	manette.setState(true);
	manette.setState(false);
	manette.communication();
	manette.demande(2, 9);
	while (!manette.getButton1())
	{
		coup.setDirection(manette.getJoyX() - 2);
		cout << coup.getDirection() << endl;
		Sleep(100);
	}
	


	
	
	manette.demande(2, 9); //Choisir direction



/*----------------------------- Tests Lecture Manette -----------------------------*/
	for (int i; i < 1000; i++) {
		if (manette.getCas() == 1) {
			cout << "Valeur Joystick: " << manette.getJoyY() << endl;
			if (manette.getButton1() == true)
				cout << "Bouton 1" << endl;
			if (manette.getButton2() == true)
				cout << "Bouton 2" << endl;
			if (manette.getButton3() == true)
				cout << "Bouton 3" << endl;
			if (manette.getButton4() == true)
				cout << "Bouton 4" << endl;
		}
		if (manette.getCas() == 2) {
			cout << "Valeur Joystick: " << manette.getJoyX() << endl;
			if (manette.getButton1() == true)
				cout << "Bouton 1" << endl;
			if (manette.getButton2() == true)
				cout << "Bouton 2" << endl;
			if (manette.getButton3() == true)
				cout << "Bouton 3" << endl;
			if (manette.getButton4() == true)
				cout << "Bouton 4" << endl;
		}
		if (manette.getCas() == 3)
			cout << manette.getAmplitude() << endl;

		Sleep(100);
	}
/*------------------------------------------------------------------------*/
	manette.setState(false);

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

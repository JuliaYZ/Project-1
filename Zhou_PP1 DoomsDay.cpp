#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//function prototypes
void instructions();
void storyline();
void map();
void PassTime(int time = 5);

int main()
{
	int HP = 200;
	int SP = 30;
	int CE = 30;
	int kill = 0; 
	int zombies = 15;
	int zombieHP = 90;
	int zombieCE = 50;
	int Bread = 30;
	int Gun = 100;
	int Water = 20;
	int SaucepanLid = 30;
	int Bandage = 50;
	int Medicine = 100;
	int Injection = 150;
	
	instructions();
	storyline();
	
	int choice;
	
	do
	{
		cout << "HP: " << HP << endl;
		cout << "SP: " << SP << endl;
		cout << "CE: " << CE << endl;
		map();
		
		cout << "\nWhere do you want to go: ";
		cin >> choice;
		
		SP -= 10;
		
		switch(choice)
		{
			case 0:
				cout << "\nGood-bye! See you next time.\n";
				break;
			case 1:
				cout << "\nSecurity Office\n";
				cout << "There are 4 zombies in the room.\n";
				if (CE <= zombieCE)
				{
					HP -= 4.0 * zombieCE;
				}
				
				kill += 4.0;
				
				if (HP <= 0 || SP <= 0)
				{
					choice = 0;
					cout << "Sorry, you are dead.\n";
				}
				else if (kill == zombies)
				{
					choice = 0;
					cout << "You kill all " << zombies << " zombies!\n";
				}
				else
				{
					CE += Gun;
					cout << "You are alive!\n";
					cout << "You found a gun, your CE increased.\n" << endl;
				}
				break;
			case 2:
				cout << "\nStorehouse\n";
				if (CE <= zombieCE)
				{
					HP -= 3.0 * zombieCE;	
				}
				
				kill += 3.0;
				
				if (HP <= 0 || SP <= 0)
				{
					choice = 0;
					cout << "Sorry, you are dead.\n";
				}
				else if (kill == zombies)
				{
					choice = 0;
					cout << "You kill all " << zombies << " zombies!\n";
				}
				else
				{
					HP += Bandage;
					cout << "You are alive!\n";
					cout << "You found a bandage, your HP increased.\n" << endl;
				}
				break;
			case 3:
				cout << "\nPharmacy\n";
				if (CE <= zombieCE)
				{
					HP -= 2.0 * zombieCE;
				}
				
				kill += 2.0;
				
				if (HP <= 0 || SP <= 0)
				{
					choice = 0;
					cout << "Sorry, you are dead.\n";
				}
				else if (kill == zombies)
				{
					choice = 0;
					cout << "You kill all " << zombies << " zombies!\n";
				}
				else
				{
					HP += Medicine;
					cout << "You are alive!\n";
					cout << "You found medicine, your HP increased.\n" << endl;
				}
				break;
			case 4:
				cout << "\nCafeteria\n";
				if (CE <= zombieCE)
				{
					HP -= 2.0 * zombieCE;
				}
				
				kill += 2.0;
				
				if (HP <= 0 || SP <= 0)
				{
					choice = 0;
					cout << "Sorry, you are dead.\n";
				}
				else if (kill == zombies)
				{
					choice = 0;
					cout << "You kill all " << zombies << " zombies!\n";
				}
				else
				{
					SP += Bread;
					SP += Water;
					CE += SaucepanLid;
					cout << "You are alive!\n";
					cout << "You found some bread and water, your SP increased.\n";
					cout << "You also found a lid, your CE increased.\n" << endl;
				}

				break;
			case 5:
				cout << "\nRestroom\n";
				if (CE <= zombieCE)
				{
					HP -= zombieCE;
				}
				
				kill += 1.0;
				
				if (HP <= 0 || SP <= 0)
				{
					choice = 0;
					cout << "Sorry, you are dead.\n";
				}
				else if (kill == zombies)
				{
					choice = 0;
					cout << "You kill all " << zombies << " zombies!\n";
				}
				else
				{
					cout << "You are alive!\n";
					cout << "There are nothing in the restroom.\n" << endl;
				}
				break;
			case 6:
				cout << "\nLaboratory\n";
				if (CE <= zombieCE)
				{
					HP -= 3.0 * zombieCE;
				}
				
				kill += 3.0;
				
				if (HP <= 0 || SP <= 0)
				{
					choice = 0;
					cout << "Sorry, you are dead.\n";
				}
				else if (kill == zombies)
				{
					choice = 0;
					cout << "You kill all " << zombies << " zombies!\n";
				}
				else
				{
					HP += Injection;
					cout << "You are alive!\n";
					cout << "You found injection, your HP increased.\n" << endl;
				}
				break;
			default:
				cout << "\nSorry, but " << choice << "isn't a valid choice.\n";
		}
	}while (choice != 0);
	
	cout << "Thank you for playing!" << endl;
	
	return 0;
}

void instructions()
{
	cout << "\t\t\tWelcome to DoomsDay" << endl;
	cout << "Players need to choose their own destination and search for supplies to" << endl
		 <<	"ensure their HP(Health Point) and SP (Strength Value). They also need to" << endl
		 << "search for weapons to have higher CE(Combat Effectiveness) and defeat all" << endl
		 << "zombies in the hospital to win the game." << endl;
	cout << "\nThe player will see their information everytime before select a room.\n" << endl;
}

void storyline()
{
	cout << "Preface:" << endl;
	cout << "In 3529, global zombies broke out. You and your parents are separated in " << endl 
	     << "fugitive. You need to find food while avoiding zombies, but unfortunately, " << endl
		 << "you roll down the hillside. Branches have cut you in many places, and you " << endl
		 << "have to find the medicine. Fortunately, there is a clinic in a small town " << endl
		 << "not far away." << endl;
	
	//Found flashlight and map in the Administration
	cout << "You pick a ramdom wooden stick in the forest and walk into the hospital." << endl
		 << "It's quiet. You can't see anything, but you found a flashlight on the floor." << endl
		 << "When you turn on thr flashligh, a zombie suddenly strikes at you and You are " << endl
		 << "scared and hit it with the large wooden stick, and it falls to the ground. " << endl
		 << "You're so lucky that this zombie seems to have just awakened not long. You look" << endl
		 << "around in the Administration. You found a map of the hospital on the wall.\n" << endl;
}

void map()
{
	cout << "_________________________/  ______________/  _________________________________" << endl
		 << "|                |                                  |                        |" << endl
		 << "|    Security    |          Administration          |      Storehouse        |" << endl
		 << "|     Office     |                                  |         (2)            |" << endl
		 << "|      (1)       |             Quit(0)              |                        |" << endl
		 << "|____________   _|                                  |____________________   _|" << endl
		 << "|              /                                                           / |" << endl
		 << "|                                                                            |" << endl
		 << "|____________________/  _________/  _______/  ___________________________/  _|" << endl
		 << "|              |                         |          |                        |" << endl
		 << "|   Pharmacy   |        Cafeteria        | Restroom |       Laboratory       |" << endl
		 << "|     (3)      |           (4)           |    (5)   |          (6)           |" << endl
		 << "|______________|                         |__________|________________________|" << endl
		 << "|                                                                            |" << endl
		 << "|                                                                            |" << endl
		 << "|                                                                            |" << endl
		 << "|____________________________________________________________________________|" << endl;
}

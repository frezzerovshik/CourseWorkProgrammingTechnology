//
//  Games.cpp
//  CourseWorkProgrammingTechnology
//
//  Created by Артем Шарапов on 11.03.2020.
//  Copyright © 2020 Hooba-booba. All rights reserved.
//

#include "Games.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include "MyException.h"

#define TIME_FOR_SLEEP 15000000 //в микросекундах
#define NUM_OF_LINES 7

using namespace std;

void Games:: notifyObservers(Notify newNotify) {
    for (int i = 0 ; i < listOfObservers.size(); ++i) {
        if (newNotify.country == listOfObservers[i]->choosenCountry &&
            newNotify.sport == listOfObservers[i]->choosenSport) {
            listOfObservers[i]->observerObject->update(&newNotify);
        }
    }
}

void Games:: registerObserver(Shell *newObserver) {
    listOfObservers.push_back(newObserver);
}

void Games:: unsubObserver(Country countryKey , Sports sportsKey , Observer* user) {
    bool isFound = true;
    for (int i = 0; i < listOfObservers.size() ; ++i) {
        if (
            listOfObservers[i]->choosenCountry == countryKey &&
            listOfObservers[i]->choosenSport == sportsKey    &&
            listOfObservers[i]->observerObject == user
            ) {
            
            listOfObservers.erase(listOfObservers.begin()+i);
            isFound = false;
            break;
            
        }
    }//for
    if (isFound) {
        cout << "Пользователь не найден" << endl;
    }
}

void Games:: competitions () {
	bool flag = true;
	char userAnswer {};
	while (flag) {
		biatlon();
		skeleton();
		skies();
		figureSkiing();
		cout << "Продолжать наблюдать за соревнованиями? 1 - Да 2 - Нет" << endl;
		cin >> userAnswer;
		if (userAnswer == '1')
			usleep(TIME_FOR_SLEEP);
		else
			flag = false;
	}//while
}

void Games:: biatlon() {
	vector<Sportsman> validCompetitors;
	Sportsman temp;
	for (vector<Sportsman>::iterator it = competitors.begin(); it <= competitors.end(); it++) {
		if ((*it).kindOfSports == Sports::Biatlon) 
			validCompetitors.push_back(*it);
	}
	for (int i = 0 ; i < validCompetitors.size() - 1 ; ++i) {
		for (int j = 0; j < validCompetitors.size() - i - 1; ++j) {
			if (validCompetitors[j].agility > validCompetitors[j + 1].agility &&
				validCompetitors[j].stamina > validCompetitors[j+1].stamina) {
				
				temp = validCompetitors[j];
				validCompetitors[j] = validCompetitors[j + 1];
				validCompetitors[j + 1] = temp;
			}
		}
	}
	Notify firstPlace, secondPlace, thirdPlace;
	firstPlace.country = validCompetitors[0].whereFrom; firstPlace.place = "1"; firstPlace.sport = Sports::Biatlon; firstPlace.name = validCompetitors[0].name;
	secondPlace.country = validCompetitors[1].whereFrom; secondPlace.place = "2"; secondPlace.sport = Sports::Biatlon; secondPlace.name = validCompetitors[1].name;
	thirdPlace.country = validCompetitors[2].whereFrom; thirdPlace.place = "3"; thirdPlace.sport = Sports::Biatlon; thirdPlace.name = validCompetitors[2].name;
	
	notifyObservers(firstPlace);
	notifyObservers(secondPlace);
	notifyObservers(thirdPlace);
}



void Games::skeleton() {
	vector<Sportsman> validCompetitors;
	Sportsman temp;
	for (vector<Sportsman>::iterator it = competitors.begin(); it <= competitors.end(); it++) {
		if ((*it).kindOfSports == Sports::Skeleton)
			validCompetitors.push_back(*it);
	}
	for (int i = 0; i < validCompetitors.size() - 1; ++i) {
		for (int j = 0; j < validCompetitors.size() - i - 1; ++j) {
			if (validCompetitors[j].agility > validCompetitors[j + 1].agility) {
				temp = validCompetitors[j];
				validCompetitors[j] = validCompetitors[j + 1];
				validCompetitors[j + 1] = temp;
			}
		}
	}
	Notify firstPlace, secondPlace, thirdPlace;
	firstPlace.country = validCompetitors[0].whereFrom; firstPlace.place = "1"; firstPlace.sport = Sports::Skeleton; firstPlace.name = validCompetitors[0].name;
	secondPlace.country = validCompetitors[1].whereFrom; secondPlace.place = "2"; secondPlace.sport = Sports::Skeleton; secondPlace.name = validCompetitors[1].name;
	thirdPlace.country = validCompetitors[2].whereFrom; thirdPlace.place = "3"; thirdPlace.sport = Sports::Skeleton; thirdPlace.name = validCompetitors[2].name;

	notifyObservers(firstPlace);
	notifyObservers(secondPlace);
	notifyObservers(thirdPlace);
}

void Games::skies() {
	vector<Sportsman> validCompetitors;
	Sportsman temp;
	for (vector<Sportsman>::iterator it = competitors.begin(); it <= competitors.end(); it++) {
		if ((*it).kindOfSports == Sports::Skies)
			validCompetitors.push_back(*it);
	}
	for (int i = 0; i < validCompetitors.size() - 1; ++i) {
		for (int j = 0; j < validCompetitors.size() - i - 1; ++j) {
			if ((validCompetitors[j].stamina > validCompetitors[j + 1].stamina)&&(validCompetitors[j].strenght > validCompetitors[j + 1].strenght)) {
				temp = validCompetitors[j];
				validCompetitors[j] = validCompetitors[j + 1];
				validCompetitors[j + 1] = temp;
			}
		}
	}
	Notify firstPlace, secondPlace, thirdPlace;
	firstPlace.country = validCompetitors[0].whereFrom; firstPlace.place = "1"; firstPlace.sport = Sports::Skies; firstPlace.name = validCompetitors[0].name;
	secondPlace.country = validCompetitors[1].whereFrom; secondPlace.place = "2"; secondPlace.sport = Sports::Skies; secondPlace.name = validCompetitors[1].name;
	thirdPlace.country = validCompetitors[2].whereFrom; thirdPlace.place = "3"; thirdPlace.sport = Sports::Skies; thirdPlace.name = validCompetitors[2].name;

	notifyObservers(firstPlace);
	notifyObservers(secondPlace);
	notifyObservers(thirdPlace);
}

void Games::figureSkiing() {
	vector<Sportsman> validCompetitors;
	Sportsman temp;
	for (vector<Sportsman>::iterator it = competitors.begin(); it <= competitors.end(); it++) {
		if ((*it).kindOfSports == Sports::FigureSkiing)
			validCompetitors.push_back(*it);
	}
	for (int i = 0; i < validCompetitors.size() - 1; ++i) {
		for (int j = 0; j < validCompetitors.size() - i - 1; ++j) {
			if ((validCompetitors[j].stamina > validCompetitors[j + 1].stamina) && (validCompetitors[j].agility > validCompetitors[j + 1].agility)) {
				temp = validCompetitors[j];
				validCompetitors[j] = validCompetitors[j + 1];
				validCompetitors[j + 1] = temp;
			}
		}
	}
	Notify firstPlace, secondPlace, thirdPlace;
	firstPlace.country = validCompetitors[0].whereFrom; firstPlace.place = "1"; firstPlace.sport = Sports::FigureSkiing; firstPlace.name = validCompetitors[0].name;
	secondPlace.country = validCompetitors[1].whereFrom; secondPlace.place = "2"; secondPlace.sport = Sports::FigureSkiing; secondPlace.name = validCompetitors[1].name;
	thirdPlace.country = validCompetitors[2].whereFrom; thirdPlace.place = "3"; thirdPlace.sport = Sports::FigureSkiing; thirdPlace.name = validCompetitors[2].name;

	notifyObservers(firstPlace);
	notifyObservers(secondPlace);
	notifyObservers(thirdPlace);
}

Games:: Games() {
	ifstream input("/Users/frez2zerovshik/Documents/Универ/Третий курс/6 семестр/CourseWorkProgrammingTechnology/CourseWorkProgrammingTechnology/Sportsman.txt");
	string config;
	Sportsman bubbleGuy;
	string kindOfSports;
	string country;
    MyException exception;
	getline(input, config);
	int numberOfSportsmans = atoi(config.c_str());

	if (!input.is_open()) {
		cout << "Ошибка - невозможно прочитать файл" << endl;
		return;
	}
    if (numberOfSportsmans == 0) {
        throw exception.emptyFile();
    }
    for (int i = 0;i < numberOfSportsmans;++i) {
        if(!input.eof()) {
            getline(input, bubbleGuy.agility);
            getline(input, kindOfSports);
            getline(input, bubbleGuy.luck);
            getline(input, bubbleGuy.name);
            getline(input, bubbleGuy.stamina);
            getline(input, bubbleGuy.strenght);
            getline(input, country);

            if (kindOfSports == "Biatlon") {
                bubbleGuy.kindOfSports = Sports::Biatlon;
            }
            else {
                if (kindOfSports == "Skeleton") {
                    bubbleGuy.kindOfSports = Sports::Skeleton;
                }
                else {
                    if (kindOfSports == "Skies") {
                        bubbleGuy.kindOfSports = Sports::Skies;
                    }
                    else {
                        if (kindOfSports == "FigureSkiing") {
                            bubbleGuy.kindOfSports = Sports::FigureSkiing;
                        }
                    }
                }
            }

            if (country == "Russia") {
                bubbleGuy.whereFrom = Country::Russia;
            }
            else {
                if (country == "Canada") {
                    bubbleGuy.whereFrom = Country::Canada;
                }
                else {
                    if (country == "France") {
                        bubbleGuy.whereFrom = Country::France;
                    }
                    else {
                        if (country == "Finland") {
                            bubbleGuy.whereFrom = Country::Finland;
                        }
                        else {
                            if (country == "Japan") {
                                bubbleGuy.whereFrom = Country::Japan;
                            }
                        }
                    }
                }
            }
            competitors.push_back(bubbleGuy);
        }
	} //for
	input.close();
    cout << "Число соревнующихся: " << competitors.size() << endl;
    cout << "Считанная из файла конфигурация: " << config << endl;
}
Games:: ~Games() {
    // Пустая реализация
}

void Games::freeList() {
    listOfObservers.clear();
}

void Games::remind() {
    cout << "Вы следите за: " << endl;
    for (int i = 0; i < listOfObservers.size(); ++i) {
        switch (listOfObservers[i]->choosenCountry) {
            case Country::Russia:
                cout << "Россия ";
                break;
            case Country::Canada:
                cout << "Канада ";
                break;
            case Country::Finland:
                cout << "Финляндия";
                break;
            case Country::Japan:
                cout << "Япония ";
                break;
            case Country::France:
                cout << "Франция";
                break;
            default:
                MyException exception;
                throw exception.wrongCountry();
                break;
        }
        
        switch (listOfObservers[i]->choosenSport) {
            case Sports::Biatlon:
                cout << "Биатлон" << endl;
                break;
            case Sports::Skeleton:
                cout << "Скелетон" << endl;
                break;
            case Sports::Skies:
                cout << "Конькобежный спорт" << endl;
                break;
            case Sports::FigureSkiing:
                cout << "Фигурное катание" << endl;
                break;
            default:
                MyException exception;
                throw exception.wrongSports();
                break;
        }
        
    }
}

unsigned long Games::numberOfObservers() {
    return listOfObservers.size();
}

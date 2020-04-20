//
//  User.cpp
//  CourseWorkProgrammingTechnology
//
//  Created by Артем Шарапов on 11.03.2020.
//  Copyright © 2020 Hooba-booba. All rights reserved.
//

#include "User.hpp"
#include "Types.h"
#include <string>
#include <iostream>
#include "MyException.h"

using namespace std;

User::~User() {
	//Пустая реализация
}

User :: User() {
    // Пустая реализация
}

User :: User(Subject* followingSubject, std::string username) {
    char ask {};
    this->username = username;
    while (true) {
        makeBubble(followingSubject);
        cout << "Повторить действие? 1 - Да 2 - Нет" << endl;
        cin >> ask;
        if (ask == '2')
            break;
    }
}

void User::makeBubble(Subject* followingSubject) {
     char choosenCountry{};
     char choosenSport{};
     Shell* bubble = new Shell();
     
     cout << "Выберите, за какую страну болеть" << endl << "1 - Россия" << endl << "2 - Канада" << endl << "3 - Япония" << endl << "4 - Финляндия" << endl << "5 - Франция" << endl;
     cin >> choosenCountry;
     
     switch (choosenCountry) {
         case '1':
             bubble->choosenCountry = Country::Russia;
             break;
         case '2':
             bubble->choosenCountry = Country::Canada;
             break;
         case '3':
             bubble->choosenCountry = Country::Japan;
             break;
         case '4':
             bubble->choosenCountry = Country::Finland;
             break;
         case '5':
             bubble->choosenCountry = Country::France;
             break;
         default:
             break;
     }
    
     cout << "Выберите вид спорта, за которым хотите наблюдать" << endl << "1 - биатлон" << endl << "2 - Скелетон" << endl << "3 - конькобежный спорт" << endl << "4 - фигурное катание" << endl;
     cin >> choosenSport;
     
     switch (choosenSport) {
         case '1':
             bubble->choosenSport = Sports::Biatlon;
             break;
         case '2':
             bubble->choosenSport = Sports::Skeleton;
             break;
         case '3':
             bubble->choosenSport = Sports::Skies;
             break;
         case '4':
             bubble->choosenSport = Sports::FigureSkiing;
             break;
         default:
             break;
     }
     
     bubble->observerObject = this;
     followingSubject->registerObserver(bubble);
}

string countryToString(Country country) {
	switch (country) {
	case Country::Russia:
		return "России";
	case Country::Japan:
		return "Японии";
	case Country::France:
		return "Франции";
	case Country::Finland:
		return "Финляндии";
	case Country::Canada:
		return "Канады";
	default:
		break;
	}
    MyException exception;
    throw exception.wrongCountry();
}

string sportsToString(Sports sport) {
	switch (sport) {
	case Sports::Biatlon:
		return "биатлону";
		break;
	case Sports::Skeleton:
		return "скелетону";
		break;
	case Sports::Skies:
		return "конькобежному спорту";
		break;
	case Sports::FigureSkiing:
		return "фигурному катанию";
		break;
	default:
		break;
	}
    MyException exception;
	throw exception.wrongSports();
}

void User::update(Notify* newNotify) {
    cout << "Новое уведомление: " << endl << "Уважаемый " << this->getUsername() << ", спортсмен из " << countryToString(newNotify->country) << " занял " << newNotify->place << " место по " << sportsToString(newNotify->sport) << endl;
}

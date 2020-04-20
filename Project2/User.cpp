//
//  User.cpp
//  CourseWorkProgrammingTechnology
//
//  Created by ����� ������� on 11.03.2020.
//  Copyright � 2020 Hooba-booba. All rights reserved.
//

#include "User.hpp"
#include "Types.h"
#include <string>
#include <iostream>
#include "MyException.h"

using namespace std;

User::~User() {
	//������ ����������
}

User :: User() {
    // ������ ����������
}

User :: User(Subject* followingSubject, std::string username) {
    char ask {};
    this->username = username;
    while (true) {
        makeBubble(followingSubject);
        cout << "��������� ��������? 1 - �� 2 - ���" << endl;
        cin >> ask;
        if (ask == '2')
            break;
    }
}

void User::makeBubble(Subject* followingSubject) {
     char choosenCountry{};
     char choosenSport{};
     Shell* bubble = new Shell();
     
     cout << "��������, �� ����� ������ ������" << endl << "1 - ������" << endl << "2 - ������" << endl << "3 - ������" << endl << "4 - ���������" << endl << "5 - �������" << endl;
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
    
     cout << "�������� ��� ������, �� ������� ������ ���������" << endl << "1 - �������" << endl << "2 - ��������" << endl << "3 - ������������ �����" << endl << "4 - �������� �������" << endl;
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
		return "������";
	case Country::Japan:
		return "������";
	case Country::France:
		return "�������";
	case Country::Finland:
		return "���������";
	case Country::Canada:
		return "������";
	default:
		break;
	}
    MyException exception;
    throw exception.wrongCountry();
}

string sportsToString(Sports sport) {
	switch (sport) {
	case Sports::Biatlon:
		return "��������";
		break;
	case Sports::Skeleton:
		return "���������";
		break;
	case Sports::Skies:
		return "������������� ������";
		break;
	case Sports::FigureSkiing:
		return "��������� �������";
		break;
	default:
		break;
	}
    MyException exception;
	throw exception.wrongSports();
}

void User::update(Notify* newNotify) {
    cout << "����� �����������: " << endl << "��������� " << this->getUsername() << ", ��������� �� " << countryToString(newNotify->country) << " ����� " << newNotify->place << " ����� �� " << sportsToString(newNotify->sport) << endl;
}

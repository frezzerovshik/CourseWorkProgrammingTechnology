//
//  Games.cpp
//  CourseWorkProgrammingTechnology
//
//  Created by Артем Шарапов on 11.03.2020.
//  Copyright © 2020 Hooba-booba. All rights reserved.
//

#include "Games.hpp"
#include <iostream>

using namespace std;

void Games:: notifyObservers(Notify newNotify) {
    for (int i = 0 ; i < listOfObservers.size(); ++i) {
        listOfObservers[i]->observerObject->update(newNotify);
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

//
//  Subject.h
//  CourseWorkProgrammingTechnology
//
//  Created by Артем Шарапов on 11.03.2020.
//  Copyright © 2020 Hooba-booba. All rights reserved.
//

#pragma once
#include "Country.h"
#include "Sports.h"
#include <vector>
#include "Observer.h"

class Shell {
public:
    Observer* observerObject;
    Country choosenCountry;
    Sports choosenSport;
};

class Subject {
    std::vector<Shell> listOfObservers;
public:
    virtual void notifyObservers() = 0;
    virtual void registerObserver(Observer* newObserver) = 0;
    virtual void unsubObserver(Observer* wantToLeave) = 0;
};

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
#include "Types.h"
#include "Observer.h"

class Subject {
public:
    std::vector<Shell*> listOfObservers;
    virtual void notifyObservers(Notify newNotify) = 0;
    virtual void registerObserver(Shell* newObserver) = 0;
    virtual void unsubObserver(Country countryKey , Sports sportsKey , Observer* user) = 0;
};

//
//  Games.hpp
//  CourseWorkProgrammingTechnology
//
//  Created by Артем Шарапов on 11.03.2020.
//  Copyright © 2020 Hooba-booba. All rights reserved.
//

#pragma once
#include "Observer.h"
#include "Subject.h"
#include "Sportsman.hpp"

class Games : Subject {
    std::vector<Sportsman> competitors;
public:
    Games();
    ~Games();
    void notifyObservers(Notify newNotify) override;
    void unsubObserver(Country countryKey , Sports sportsKey , Observer* user) override;
    void registerObserver(Shell *newObserver) override;
    void competitions();
};


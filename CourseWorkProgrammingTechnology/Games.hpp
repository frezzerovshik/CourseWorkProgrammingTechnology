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
    void notifyObservers() override;
    void unsubObserver(Observer *wantToLeave) override;
    void registerObserver(Observer *newObserver) override;
};


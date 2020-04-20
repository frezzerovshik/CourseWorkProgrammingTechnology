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

class Games : public Subject {
    std::vector<Sportsman> competitors;
public:
    Games();
    ~Games();
    
	void notifyObservers(Notify newNotify);
    void unsubObserver(Country countryKey , Sports sportsKey , Observer* user);
    void registerObserver(Shell *newObserver);
    
	void competitions();
	
	void biatlon();
	void skeleton();
	void skies();
	void figureSkiing();
    
    void freeList();
    unsigned long numberOfObservers();
    void printObserversInfo();

	void removeUser(Observer* observerObject);
};


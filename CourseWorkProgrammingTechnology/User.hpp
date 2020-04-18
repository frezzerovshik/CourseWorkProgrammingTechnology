//
//  User.hpp
//  CourseWorkProgrammingTechnology
//
//  Created by Артем Шарапов on 11.03.2020.
//  Copyright © 2020 Hooba-booba. All rights reserved.
//

#pragma once
#include "Observer.h"
#include "Subject.h"
#include "Country.h"

class User : public Observer {
public:
	User();
    User(Subject* followingObject);
    void makeBubble(Subject* followingObject);
    ~User();
    void update(Notify* newNotify);
};

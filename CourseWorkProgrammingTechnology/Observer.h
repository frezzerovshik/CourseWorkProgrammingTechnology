//
//  Observer.h
//  CourseWorkProgrammingTechnology
//
//  Created by Артем Шарапов on 11.03.2020.
//  Copyright © 2020 Hooba-booba. All rights reserved.
//

#pragma once
#include <string>
class Notify;

class Observer {
protected:
     std::string username;
public:
    virtual void update(Notify* newNotify) = 0;
    std::string getUsername() {
        return username;
    }
};

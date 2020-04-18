//
//  main.cpp
//  CourseWorkProgrammingTechnology
//
//  Created by Артем Шарапов on 10.03.2020.
//  Copyright © 2020 Hooba-booba. All rights reserved.
//

#include <iostream>
#include "Games.hpp"
#include "User.hpp"
#include "MyException.h"

using namespace std;

int main(int argc, const char * argv[]) {
    try {
        Games olympicGames;
        User observer(&olympicGames);
        olympicGames.competitions();
    }
    catch (int errorCode) {
        switch (errorCode) {
            case EMPTY_FILE: {
                cout << "Вызвано исключение: файл, содержащий информацию о спортсменах пуст" << endl;
                break;
            }
            case WRONG_COUNTRY: {
                cout << "Вызвано исключение: ошибка при формирование уведомления (неопределенное значение страны)" << endl;
                break;
            }
            case WRONG_SPORTS: {
                cout << "Вызвано исключение: ошибка при формирование уведомления (неопределенное значение вида спорта)" << endl;
                break;
            }
            default: {
                cout << "Вызвано системное исключение" << endl;
                break;
            }
        }
    }
    
    return 0;
}

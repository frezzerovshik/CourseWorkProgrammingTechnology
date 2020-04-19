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
        cout << "ОЛИМПИЙСКИЕ ИГРЫ" << endl << "Пройдите инициализацию, выбрав страны и виды спорта, за результатами которых Вы хотите следить: " << endl;
        Games olympicGames;
        int numOfObservers{};
        cout << "Скольких наблюдателей Вы хотите объявить?" << endl;
        while (true) {
            cin >> numOfObservers;
            if (numOfObservers <= 0) {
                cout << "Число наблюдателей не может быть меньшим либо равным 0, повторите ввод" << endl;
                continue;
            }
            else {
                break;
            }
        }
        vector<User*> listOfObservers;
        for (int i = 0; i<numOfObservers; ++i) {
            cout << "Пожалуйста, введите имя пользователя:" << endl;
            string username;
            cin >> username;
            User* observer = new User(&olympicGames, username);
            listOfObservers.push_back(observer);
        }
        MyException exception;
        char choosenFunction{};
        bool continueCycle = true;
        while(continueCycle) {
            cout << "1 - наблюдение за играми" << endl << "2 - добавить страны и виды спорта, за которыми желаете наблюдать" << endl << "3 - отписаться от уведомлений" << endl << "4 - выход" << endl;
            cin >> choosenFunction;
            switch (choosenFunction) {
                case '1':
                    olympicGames.competitions();
                    break;
                case '2':
                    break;
                case '3': {
                    char ask{};
                    cout << "Желаете отписаться от всех уведомлений? 1 - да, 2 - нет" << endl;
                    cin >> ask;
                    switch (ask) {
                        case '1': {
                            olympicGames.freeList();
                            break;
                        }
                        case '2': {
                            olympicGames.remind();
                            int number{};
                            while (true) {
                                cout << "Введите количество подписок, от которых Вы хотите отказаться: " << endl;
                                cin >> number;
                                if (number > olympicGames.numberOfObservers() || number <= 0) {
                                cout << "Введенное Вами число не должно быть больше чем " << olympicGames.numberOfObservers() << "и не должно быть меньше либо равным 0, повторите ввод" << endl;
                                    continue;
                                }
                                else {
                                    break;
                                }
                            }
                            for (int i = 0; i < number; ++i) {
                                cout << "1: Россия" << endl << "2: Канада" << endl << "3: Франция" << endl << "4: Финляндия" << endl << "5: Япония" << endl << endl;
                                cout << "1: Биатлон" << endl << "2: Скелетон" << endl << "3: Конькобежный спорт" << endl << "4: Фигурное катание" << endl;
                                string configurationOfUnsubRequest;
                                int country, sport;
                                while (true) {
                                    cout << "Пожалуйста, введите 2 числа в следующем виде: НомерСтраны НомерВидаСпорта" << endl << "Например: 1 3,что подразумевает Россия Конькобежный спорт" << endl;
                                    cin.ignore(1000 , '\n');
                                    getline(cin , configurationOfUnsubRequest);
                                    cout << "Длина введенной строки " << configurationOfUnsubRequest.length() << endl;
                                    if (configurationOfUnsubRequest.length() != 3) {
                                        cout << "Пожалуйста, повторите ввод, Вы ввели " << configurationOfUnsubRequest.size() << " символа(ов) вместо 3-х" << endl;
                                        continue;
                                    }
                                    else {
                                        if ((configurationOfUnsubRequest[0] >= 49 && configurationOfUnsubRequest[0] <= 53) &&
                                            (configurationOfUnsubRequest[2] >= 49 && configurationOfUnsubRequest[2] <= 52)) {
                                            country = atoi(&configurationOfUnsubRequest[0]);
                                            sport = atoi(&configurationOfUnsubRequest[2]);
                                            break;
                                        }
                                        else {
                                            cout << "Введите 2 числа через пробел, первое число в диапазоне от 1 до 5 включительно, второе от 1 до 4 включительно" << endl;
                                            continue;
                                        }
                                    }
                                }
                                Country countryKey;
                                Sports  sportKey;
                                switch (sport) {
                                    case 1: {
                                        sportKey = Sports::Biatlon;
                                        break;
                                    }
                                    case 2: {
                                        sportKey = Sports::Skeleton;
                                        break;
                                    }
                                    case 3: {
                                        sportKey = Sports::Skies;
                                        break;
                                    }
                                    case 4: {
                                        sportKey = Sports::FigureSkiing;
                                        break;
                                    }
                                }

                                switch (country) {
                                    case 1: {
                                        countryKey = Country::Russia;
                                        break;
                                    }
                                    case 2: {
                                        countryKey = Country::Canada;
                                        break;
                                    }
                                    case 3: {
                                        countryKey = Country::France;
                                        break;
                                    }
                                    case 4: {
                                        countryKey = Country::Finland;
                                        break;
                                    }
                                    case 5: {
                                        countryKey = Country::Japan;
                                        break;
                                    }
                                    default:
                                        break;
                                }
                                for (int i = 0; i < listOfObservers.size(); ++i)
                                    cout << i << ": Имя пользователя: " << listOfObservers[i]->getUsername() << endl;
                                int numberOfChoosenUser{};
                                while (true) {
                                    cout << "Пожалуйста, введите номер пользователя, к которому привязана подписка, которую Вы хотите отменить:" << endl;
                                    cin >> numberOfChoosenUser;
                                    if (numberOfChoosenUser < 0 || numberOfChoosenUser >= listOfObservers.size()) {
                                        cout << "Пожалуйста, повторите ввод" << endl;
                                        continue;
                                    }
                                    else {
                                        break;
                                    }
                                }
                                olympicGames.unsubObserver(countryKey, sportKey, listOfObservers[i]);
                            }
                            break;
                        }
                        default: {
                            throw exception.wrongAnswer();
                            break;
                        }
                    }
                    break;
                }
                case '4': {
                    cout << "Вы уверены, что хотите выйти? 1 - да, 2 - нет" << endl;
                    char ask{};
                    cin >> ask;
                    switch (ask) {
                        case '1':
                            continueCycle = false;
                            break;
                        case '2':
                            break;
                        default:
                            throw exception.wrongAnswer();
                            break;
                    }
                    break;
                }
                default:
                    break;
            }
        }
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

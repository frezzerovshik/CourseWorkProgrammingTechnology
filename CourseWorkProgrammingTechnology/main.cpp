//
//  main.cpp
//  CourseWorkProgrammingTechnology
//
//  Created by Артем Шарапов on 10.03.2020.
//  Copyright © 2020 Hooba-booba. All rights reserved.
//

//Задачи этого модуля:
//1. Предоставление инструментов пользователю для работы с программой
//2. Обработка исключительных ситуаций, определенных в других модулях проекта

#include <iostream>
#include "Games.hpp"
#include "User.hpp"
#include "MyException.h"

using namespace std;

int main(int argc, const char * argv[]) {
    try {
#pragma mark - Инициализация
//Программа не будет решать поставленные задачи, если не будет инициализированных наблюдателей, поэтому пользователю необходимо принудительно инициализироваться, объектов-наблюдателей может быть более чем 1 (соблюдение отношения один ко многим)
        cout << "ОЛИМПИЙСКИЕ ИГРЫ" << endl << "Пройдите инициализацию, выбрав страны и виды спорта, за результатами которых Вы хотите следить: " << endl;
        Games olympicGames; //Объект-симулятор Олимпийских игр, реализует интерфейс Subject (за изменением его состояния возможно наблюдать)
        int numOfObservers{};
        string charValueOfObserverNum;
        cout << "Скольких наблюдателей Вы хотите объявить?" << endl;
//Подобная организация ввода позволяет программе гибко обработать случаи, когда пользователь вводит некорректные данные, не приводя к сбоям в работе и вызову исключительных ситуаций
        while (true) {
            cin >> charValueOfObserverNum;
            try {
                numOfObservers = stoi(charValueOfObserverNum);
            }
            catch (...) {
                cout << "Пожалуйста, введите числовое значение" << endl;
                continue;
            }
            if (numOfObservers <= 0) {
                cout << "Число наблюдателей не может быть меньшим либо равным 0, повторите ввод" << endl;
                continue;
            }
            else {
                break;
            }
        }
        vector<User*> listOfObservers; //User - это класс-симулятор пользователя, принимает и выводит уведомления, так же может отправлять запросы на подписку и отписку от уведомлений
        for (int i = 0; i<numOfObservers; ++i) {
            string username;
            while (true) {
                cout << "Пожалуйста, введите имя пользователя:" << endl;
                cin >> username;
                if (username == "") {
                    cout << "Имя пользователя не должно являться пустой строкой, пожалуйста, введите содержательное имя пользователя" << endl;
                    continue;
                }
                else {
                    if (!listOfObservers.empty()) {
                        bool nameReserved = false;
                        for (int j = 0; j < listOfObservers.size(); ++j) {
                            if (listOfObservers[j]->getUsername() == username) {
                                nameReserved = true;
                                break;
                            }
                        }
                        if (nameReserved == true) {
                            cout << "Имя пользователя занято, пожалуйста, попробуйте другое" << endl;
                            continue;
                        }
                        else {
                            break;
                        }
                    }
                    else {
                        break;
                    }
                }
            }
            User* observer = new User(&olympicGames, username);
            listOfObservers.push_back(observer);
        }
        MyException exception;
        char choosenFunction{};
        bool continueCycle = true; // Флаг признака продолжения работы программы
#pragma mark - Основной цикл начало
        while(continueCycle) {
            cout << "1 - наблюдение за играми" << endl << "2 - добавить страны и виды спорта, за которыми желаете наблюдать" << endl << "3 - отписаться от уведомлений" << endl << "4 - просмотреть информацию о подписках" << endl << "5 - выход" << endl;
            cin >> choosenFunction;
            switch (choosenFunction) {
#pragma mark - Наблюдение за соревнованиями
                case '1':
                    cout << "Учтите, если Вы не увидели уведомления о результатах команды, за которую Вы болеете - значит она не вошла в тройку лидеров" << endl;
                    olympicGames.competitions();
                    break;
                case '2': {
#pragma mark - Добавление подписок
//Один объект-пользователь может оформлять несколько подписок, но, т.к. предоставляется возможность создавать несколько объектов-наблюдателей,
//необходимо выбрать от имени какого объекта подписываться на обновления
                    for (int i = 0; i < listOfObservers.size(); ++i)
                        cout << i << ": Имя пользователя: " << listOfObservers[i]->getUsername() << endl;
                    cout << "Введите номер пользователя, от чьего лица Вы хотите подписаться на новые уведомления" << endl;
                    int numberOfChoosenUser{};
                    string charNumber{};
                    while (true) {
                        cin >> charNumber;
                        try {
                            numberOfChoosenUser = stoi(charNumber);
                        }
                        catch (...) {
                            cout << "Пожалуйста, введите ЧИСЛО" << endl;
                            continue;
                        }
                        cout << charNumber << " было преобразовано в " << numberOfChoosenUser << endl;
                        if (numberOfChoosenUser < 0 || numberOfChoosenUser > listOfObservers.size()-1) {
                            cout << "Пожалуйста, повторите ввод" << endl;
                            continue;
                        }
                        else {
                            break;
                        }
                    }
                    listOfObservers[numberOfChoosenUser]->makeBubble(&olympicGames); // Метод makeBubble создает некоторый "пузырек", которых хранит
//информацию, необходимую классу, реализующему протокол Subject в том виде, в котором ему удобно с ней работать, внутри метод
//происходит запрос на подписку у объекта, который передан как параметр метода
//Определен в User.hpp
                    break;
                }
                case '3': {
#pragma mark - Отказ от подписок
                    char ask{};
//Пользователь может оформить слишком большое количество подписок и , если возникает потребность удаления всех подписок, процесс поэлементного
//ручного удаления может быть очень долгим и утомительным, поэтому, целесообразно предоставить быстрый и удобный способ отказаться от всех подписок
                    cout << "Желаете отписаться от всех уведомлений? 1 - да, 2 - нет" << endl;
                    cin >> ask;
                    switch (ask) {
                        case '1': {
//Метод определен в Games.hpp
                            olympicGames.freeList();
                            break;
                        }
                        case '2': {
                            olympicGames.printObserversInfo();
                            int number{};
                            while (true) { //Защита ввода
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
//Код описанный в этом цикле формирует запрос на однократную отмену подписки
//Краткое описание - алгоритм требует от пользователя ввод строки в определенном формате, проводит проверки на соответствие формату и корректность
//содержательных данных, после чего отправляет составленный запрос объекту класса-наследника Subject
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
#pragma mark - Просмотр информации о подписках
                case '4':{
                    olympicGames.printObserversInfo();
                    break;
                }
                case '5': {
#pragma mark - Выход из программы
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
#pragma mark - Основной цикл конец
//Удаление всей динамической памяти, выделенной в этом блоке
        for (int i = 0; i < listOfObservers.size(); ++i) {
            delete listOfObservers[i];
        }
    }
    catch (int errorCode) {
#pragma mark - Блок catch
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
            case WRONG_ANSWER: {
                cout << "Вызвано исключение: некорректно введен ответ на вопрос от программы" << endl;
                break;
            }
            case WRONG_VALUE: {
                cout << "Вызвано исключение: ошибка в заполнении файла" << endl << "Формат заполнения файла: " << endl << "ЧислоЗаписей\nЛовкость(число)\nВид спорта(Biatlon or Skeleton or Skies of FigureSkiing)\nУдача(число)\nИмя(строка)\nСила(число)\nВыносливость(число)\nCтрана(Russia or Canada or France or Finland or Japan)"<<endl<<endl<<"!!!Файл заполняется построчно, без пустых строк,в точном соответствии с порядком, указанным выше"<<endl<<"Пример:"<<endl<<"2\n20\nFigureSkiing\n50\nAnton Shatilov\n80\n56\nRussia\n50\nSkies\n30\nMark Johnson\n60\n32\nCanada\n";
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

//
//  main.cpp
//  CourseWorkProgrammingTechnology
//
//  Created by ����� ������� on 10.03.2020.
//  Copyright � 2020 Hooba-booba. All rights reserved.
//

//������ ����� ������:
//1. �������������� ������������ ������������ ��� ������ � ����������
//2. ��������� �������������� ��������, ������������ � ������ ������� �������

#include <iostream>
#include "Games.hpp"
#include "User.hpp"
#include "MyException.h"

using namespace std;

int main(int argc, const char * argv[]) {
    try {
		system("chcp 1251");
//��������� �� ����� ������ ������������ ������, ���� �� ����� ������������������ ������������, ������� ������������ ���������� ������������� ������������������, ��������-������������ ����� ���� ����� ��� 1 (���������� ��������� ���� �� ������)
        cout << "����������� ����" << endl << "�������� �������������, ������ ������ � ���� ������, �� ������������ ������� �� ������ �������: " << endl;
        Games olympicGames; //������-��������� ����������� ���, ��������� ��������� Subject (�� ���������� ��� ��������� �������� ���������)
        int numOfObservers{};
        string charValueOfObserverNum;
        cout << "�������� ������������ �� ������ ��������?" << endl;
//�������� ����������� ����� ��������� ��������� ����� ���������� ������, ����� ������������ ������ ������������ ������, �� ������� � ����� � ������ � ������ �������������� ��������
        while (true) {
            cin >> charValueOfObserverNum;
            try {
                numOfObservers = stoi(charValueOfObserverNum);
            }
            catch (...) {
                cout << "����������, ������� �������� ��������" << endl;
                continue;
            }
            if (numOfObservers <= 0) {
                cout << "����� ������������ �� ����� ���� ������� ���� ������ 0, ��������� ����" << endl;
                continue;
            }
            else {
                break;
            }
        }
        vector<User*> listOfObservers; //User - ��� �����-��������� ������������, ��������� � ������� �����������, ��� �� ����� ���������� ������� �� �������� � ������� �� �����������
        for (int i = 0; i<numOfObservers; ++i) {
            string username;
            while (true) {
                cout << "����������, ������� ��� ������������:" << endl;
                cin >> username;
                if (username == "") {
                    cout << "��� ������������ �� ������ �������� ������ �������, ����������, ������� �������������� ��� ������������" << endl;
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
                            cout << "��� ������������ ������, ����������, ���������� ������" << endl;
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
        bool continueCycle = true; // ���� �������� ����������� ������ ���������

        while(continueCycle) {
			cout << "1 - ���������� �� ������" << endl << "2 - �������� ������ � ���� ������, �� �������� ������� ���������" << endl << "3 - ���������� �� �����������" << endl << "4 - ����������� ���������� � ���������" << endl << "5 - �������� ������������" << endl << "6 - ������� ������������" << endl << "7 - �����" << endl;
            cin >> choosenFunction;
            switch (choosenFunction) {

                case '1':
                    cout << "������, ���� �� �� ������� ����������� � ����������� �������, �� ������� �� ������� - ������ ��� �� ����� � ������ �������" << endl;
                    olympicGames.competitions();
                    break;
                case '2': {

//���� ������-������������ ����� ��������� ��������� ��������, ��, �.�. ��������������� ����������� ��������� ��������� ��������-������������,
//���������� ������� �� ����� ������ ������� ������������� �� ����������
                    for (int i = 0; i < listOfObservers.size(); ++i)
                        cout << i << ": ��� ������������: " << listOfObservers[i]->getUsername() << endl;
                    cout << "������� ����� ������������, �� ����� ���� �� ������ ����������� �� ����� �����������" << endl;
                    int numberOfChoosenUser{};
                    string charNumber{};
                    while (true) {
                        cin >> charNumber;
                        try {
                            numberOfChoosenUser = stoi(charNumber);
                        }
                        catch (...) {
                            cout << "����������, ������� �����" << endl;
                            continue;
                        }
                        cout << charNumber << " ���� ������������� � " << numberOfChoosenUser << endl;
                        if (numberOfChoosenUser < 0 || numberOfChoosenUser > listOfObservers.size()-1) {
                            cout << "����������, ��������� ����" << endl;
                            continue;
                        }
                        else {
                            break;
                        }
                    }
                    listOfObservers[numberOfChoosenUser]->makeBubble(&olympicGames); // ����� makeBubble ������� ��������� "�������", ������� ������
//����������, ����������� ������, ������������ �������� Subject � ��� ����, � ������� ��� ������ � ��� ��������, ������ �����
//���������� ������ �� �������� � �������, ������� ������� ��� �������� ������
//��������� � User.hpp
                    break;
                }
                case '3': {

                    char ask{};
//������������ ����� �������� ������� ������� ���������� �������� � , ���� ��������� ����������� �������� ���� ��������, ������� �������������
//������� �������� ����� ���� ����� ������ � ������������, �������, ������������� ������������ ������� � ������� ������ ���������� �� ���� ��������
                    cout << "������� ���������� �� ���� �����������? 1 - ��, 2 - ���" << endl;
                    cin >> ask;
                    switch (ask) {
                        case '1': {
//����� ��������� � Games.hpp
                            olympicGames.freeList();
                            break;
                        }
                        case '2': {
                            olympicGames.printObserversInfo();
                            int number{};
                            while (true) { //������ �����
                                cout << "������� ���������� ��������, �� ������� �� ������ ����������: " << endl;
                                cin >> number;
                                if (number > olympicGames.numberOfObservers() || number <= 0) {
                                cout << "��������� ���� ����� �� ������ ���� ������ ��� " << olympicGames.numberOfObservers() << "� �� ������ ���� ������ ���� ������ 0, ��������� ����" << endl;
                                    continue;
                                }
                                else {
                                    break;
                                }
                            }
//��� ��������� � ���� ����� ��������� ������ �� ����������� ������ ��������
//������� �������� - �������� ������� �� ������������ ���� ������ � ������������ �������, �������� �������� �� ������������ ������� � ������������
//�������������� ������, ����� ���� ���������� ������������ ������ ������� ������-���������� Subject
                            for (int i = 0; i < number; ++i) {
                                cout << "1: ������" << endl << "2: ������" << endl << "3: �������" << endl << "4: ���������" << endl << "5: ������" << endl << endl;
                                cout << "1: �������" << endl << "2: ��������" << endl << "3: ������������ �����" << endl << "4: �������� �������" << endl;
                                string configurationOfUnsubRequest;
                                int country, sport;
                                while (true) {
                                    cout << "����������, ������� 2 ����� � ��������� ����: ����������� ���������������" << endl << "��������: 1 3,��� ������������� ������ ������������ �����" << endl;
                                    cin.ignore(1000 , '\n');
                                    getline(cin , configurationOfUnsubRequest);
                                    cout << "����� ��������� ������ " << configurationOfUnsubRequest.length() << endl;
                                    if (configurationOfUnsubRequest.length() != 3) {
                                        cout << "����������, ��������� ����, �� ����� " << configurationOfUnsubRequest.size() << " �������(��) ������ 3-�" << endl;
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
                                            cout << "������� 2 ����� ����� ������, ������ ����� � ��������� �� 1 �� 5 ������������, ������ �� 1 �� 4 ������������" << endl;
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
                                    cout << i << ": ��� ������������: " << listOfObservers[i]->getUsername() << endl;
                                int numberOfChoosenUser{};
                                while (true) {
                                    cout << "����������, ������� ����� ������������, � �������� ��������� ��������, ������� �� ������ ��������:" << endl;
                                    cin >> numberOfChoosenUser;
                                    if (numberOfChoosenUser < 0 || numberOfChoosenUser >= listOfObservers.size()) {
                                        cout << "����������, ��������� ����" << endl;
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

                case '4':{
                    olympicGames.printObserversInfo();
                    break;
                }
				case '5': {
					int numOfObservers{};
					string charValueOfObserverNum;
					cout << "�������� ������������ �� ������ ��������?" << endl;
					//�������� ����������� ����� ��������� ��������� ����� ���������� ������, ����� ������������ ������ ������������ ������, �� ������� � ����� � ������ � ������ �������������� ��������
					while (true) {
						cin >> charValueOfObserverNum;
						try {
							numOfObservers = stoi(charValueOfObserverNum);
						}
						catch (...) {
							cout << "����������, ������� �������� ��������" << endl;
							continue;
						}
						if (numOfObservers <= 0) {
							cout << "����� ������������ �� ����� ���� ������� ���� ������ 0, ��������� ����" << endl;
							continue;
						}
						else {
							break;
						}
					}
					for (int i = 0; i < numOfObservers; ++i) {
						string username;
						while (true) {
							cout << "����������, ������� ��� ������������:" << endl;
							cin >> username;
							if (username == "") {
								cout << "��� ������������ �� ������ �������� ������ �������, ����������, ������� �������������� ��� ������������" << endl;
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
										cout << "��� ������������ ������, ����������, ���������� ������" << endl;
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
					break;
				}
				case '6': {
					olympicGames.printObserversInfo();
					string stringValueOfNumber;
					int number;
					cout << "����������, ������� ����� ������������, �������� �� ������ �������" << endl;
					while (true) {
						cin.ignore(1000, '\n');
						getline(cin, stringValueOfNumber);
						try {
							number = stoi(stringValueOfNumber);
						}
						catch (...) {
							cout << "����������, ������� �������� ��������" << endl;
							continue;
						}

						if (number < 0 || number > listOfObservers.size() - 1) {
							cout << "����������, ������� ���������� ����� ������������" << endl;
							continue;
						}
						else {
							break;
						}
					}
					cout << "�� �������, ��� ������ ������� ������������ � ������ " << listOfObservers[number]->getUsername() << "? 1 - �� 2 - ��� " << endl;
					char answer{};
					cin >> answer;
					switch (answer) {
					case '1': {
						olympicGames.removeUser(*(listOfObservers.begin() + number));
						listOfObservers.erase(listOfObservers.begin() + number);
						break;
					}
					case '2': {
						break;
					}
					default: {
						throw exception.wrongAnswer();
					}
					}
					break;
				}
                case '7': {

                    cout << "�� �������, ��� ������ �����? 1 - ��, 2 - ���" << endl;
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
//�������� ���� ������������ ������, ���������� � ���� �����
        for (int i = 0; i < listOfObservers.size(); ++i) {
            delete listOfObservers[i];
        }
    }
    catch (int errorCode) {

        switch (errorCode) {
            case EMPTY_FILE: {
                cout << "������� ����������: ����, ���������� ���������� � ����������� ����" << endl;
                break;
            }
            case WRONG_COUNTRY: {
                cout << "������� ����������: ������ ��� ������������ ����������� (�������������� �������� ������)" << endl;
                break;
            }
            case WRONG_SPORTS: {
                cout << "������� ����������: ������ ��� ������������ ����������� (�������������� �������� ���� ������)" << endl;
                break;
            }
            case WRONG_ANSWER: {
                cout << "������� ����������: ����������� ������ ����� �� ������ �� ���������" << endl;
                break;
            }
            case WRONG_VALUE: {
                cout << "������� ����������: ������ � ���������� �����" << endl << "������ ���������� �����: " << endl << "������������\n��������(�����)\n��� ������(Biatlon or Skeleton or Skies of FigureSkiing)\n�����(�����)\n���(������)\n����(�����)\n������������(�����)\nC�����(Russia or Canada or France or Finland or Japan)"<<endl<<endl<<"!!!���� ����������� ���������, ��� ������ �����,� ������ ������������ � ��������, ��������� ����"<<endl<<"������:"<<endl<<"2\n20\nFigureSkiing\n50\nAnton Shatilov\n80\n56\nRussia\n50\nSkies\n30\nMark Johnson\n60\n32\nCanada\n";
                break;
            }
            default: {
                cout << "������� ��������� ����������" << endl;
                break;
            }
        }
    }
    return 0;
}

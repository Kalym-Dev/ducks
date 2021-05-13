#include <iostream>

#include "Lake.h"
#include "Farm.h"
#include "Hunter.h"
#include "Duck.h"
#include "Marble.h"
#include "Madagascar.h"
#include "Chirki.h"

using std::cout;
using std::endl;
using std::string;
using std::cin;

int com_num = 0;

int main() {


    Madagascar mad("tom", 22, 100, 0);
    Marble mar("jerry", 22,"dnd", 600);
    Chirki chirki("johs", 1231, "red", 54);

    Lake lake1;
    mad.setHomeAddress(&lake1);
    mar.setHomeAddress(&lake1);

    lake1.addElemToEnd(&mad);
    lake1.addElemToEnd(&mar);
    lake1.addElemToEnd(&chirki);

    Madagascar mad1("tom1", 22, 100, 0);
    Marble mar1("jerry1", 22,"dnd", 600);

    Lake lake2;
    mad.setHomeAddress(&lake2);
    mar.setHomeAddress(&lake2);

    lake2.addElemToEnd(&mad1);
    lake2.addElemToEnd(&mar1);

    Farm farm1(1);

    Hunter hun1(2, 1, &farm1);
    Hunter hun2(2, 1, &farm1);

    int shoot1 = 0;
    int shoot2 = 0;

    int day = 0;
    int temp_choose;
    int temp_what_can = 0;
    int t_fly = 0;
    int t_swi = 0;
    int t_mig = 0;
    int t_not = 0;

    bool is_hunting_season = false;
    int is_escape = 0;
    while(com_num != 6) {
        if(day <= 7)
        {
            cout << "Hunting season!" << endl;
            is_hunting_season = true;
        }else{
            is_hunting_season = false;
            if(day == 14) day = 0;
            cout << "Closed" << endl;
        }
        cout << "1. Show count ducks in every lake!" << endl;
        cout << "2. Show info about ducks in lake: " << endl;
        cout << "3. Show statistic ability types ducks: " << endl;
        if(is_hunting_season) cout << "4. Hunters shoot" << endl;
        cout << "5. Scip day" << endl;
        cout << "6. exit" << endl;
        cout << "Введите команду: " << endl;
        cin >> com_num;
        switch(com_num){
            case 1:
                cout << "Lake 1: "  + to_string(lake1.getLength()) << endl;
                cout << "Lake 2: "  + to_string(lake2.getLength()) << endl;
                cout << "Farm: "  + to_string(farm1.getLength()) << endl;
                break;
            case 2:
                cout << "Choose lake1 (1) or lake2 (2) or Farm (3): " << endl;
                cin >> temp_choose;
                if(temp_choose != 1 && temp_choose != 2 && temp_choose != 3){
                    cout << "Wrong choose!";
                }else if(temp_choose == 1){
                    for(int i = 0; i < lake1.getLength(); i++)
                    {
                        lake1[i]->tellAboutYourself();
                        cout << endl;
                    }
                }else if(temp_choose == 2){
                    for(int i = 0; i < lake2.getLength(); i++)
                    {
                        lake2[i]->tellAboutYourself();
                        cout << endl;
                    }
                }else if(temp_choose == 3){
                    for(int i = 0; i < farm1.getLength(); i++)
                    {
                        farm1[i]->tellAboutYourself();
                        cout << endl;
                    }
                }
                break;
            case 3:
                cout << "Choose lake1 (1) or lake2 (2): " << endl;
                cin >> temp_choose;


                if(temp_choose != 1 && temp_choose != 2){
                    cout << "Wrong choose!";
                }else if(temp_choose == 1){
                    for(int i = 0; i < lake1.getLength(); i++)
                    {
                        temp_what_can = lake1[i]->getWhatcan(); // 1 - летать, 2 - плавать, 3 - мигрировать, 4 - безьдельничать
                        if(temp_what_can == 1)
                        {
                            t_fly++;
                        }else if(temp_what_can == 2)
                        {
                            t_swi++;
                        }else if(temp_what_can == 3)
                        {
                            t_mig++;
                        }else if(temp_what_can == 4)
                        {
                            t_not++;
                        }
                    }
                }else if(temp_choose == 2){
                    for(int i = 0; i < lake2.getLength(); i++)
                    {
                        temp_what_can = lake2[i]->getWhatcan(); // 1 - летать, 2 - плавать, 3 - мигрировать, 4 - безьдельничать
                        if(temp_what_can == 1)
                        {
                            t_fly++;
                        }else if(temp_what_can == 2)
                        {
                            t_swi++;
                        }else if(temp_what_can == 3)
                        {
                            t_mig++;
                        }else if(temp_what_can == 4)
                        {
                            t_not++;
                        }
                    }
                }
                cout << "Fly: " + to_string(t_fly) << endl;
                cout << "Swi: " + to_string(t_swi) << endl;
                cout << "Mig: " + to_string(t_mig) << endl;
                cout << "Not: " + to_string(t_not) << endl;
                break;
            case 4:
                cout << "Choose lake1 (1) or lake2 (2): " << endl;
                cin >> temp_choose;


                if(temp_choose != 1 && temp_choose != 2){
                    cout << "Wrong choose!";
                }else if(temp_choose == 1){
                    shoot1 = hun1.getHuntingquantity();
                    for(int i = 0; i < shoot1; i++) {
                        if (lake1.getLength() > 0) {
                            if (farm1.getLength() > 0) {
                                lake1[rand() % lake1.getLength()]->setCurAddress(hun1.getHunterFarm());
                                hun1.getHunterFarm()->addElemToEnd(lake1[rand() % lake1.getLength()]);
                                lake1.remove(rand() % lake1.getLength());
                            } else {
                                shoot1 = i;
                            }
                        }
                    }

                    shoot2 = hun2.getHuntingquantity();
                    for(int i = 0; i < shoot2; i++)
                    {
                        if(lake1.getLength() > 0){
                            lake1[rand() % lake1.getLength()]->setCurAddress(hun2.getHunterFarm());
                            hun2.getHunterFarm()->addElemToEnd(lake1[rand() % lake1.getLength()]);
                            lake1.remove(rand() % lake1.getLength());
                        }else{
                            shoot2 = i;
                        }
                    }
                }else if(temp_choose == 2){
                    shoot1 = hun1.getHuntingquantity();
                    for(int i = 0; i < shoot1; i++)
                    {
                        if(lake2.getLength() > 0){
                            lake2[rand() % lake2.getLength()]->setCurAddress(hun1.getHunterFarm());
                            hun1.getHunterFarm()->addElemToEnd(lake2[rand() % lake2.getLength()]);
                            lake2.remove(rand() % lake2.getLength());
                        }else{
                            shoot1 = i;
                        }
                    }
                    shoot2 = hun2.getHuntingquantity();
                    for(int i = 0; i < shoot2; i++)
                    {
                        if(lake2.getLength() > 0){
                            lake2[rand() % lake2.getLength()]->setCurAddress(hun2.getHunterFarm());
                            hun2.getHunterFarm()->addElemToEnd(lake1[rand() % lake2.getLength()]);
                            lake2.remove(rand() % lake2.getLength());
                        }else{
                            shoot2 = i;
                        }
                    }
                }

                cout << "Hunter 1: " + to_string(shoot1) + " nice shoots" << endl;
                cout << "Hunter 2: " + to_string(shoot2) + " nice shoots" << endl;
                cout << "Captured : " + to_string(shoot1 + shoot2) << endl;
                break;
            case 5:
                day++;
                break;
            case 6:
                return 0;
                break;
            default:
                break;
        }

        if(day % 2 == 0 && day != 0)
        {
            for(int i = 0; i < farm1.getLength(); i++)
            {
                if(farm1.getEscapetype() == farm1[i]->getWhatcan())
                {
                    is_escape = rand() % 2;
                    if(is_escape == 1)
                    {
                        if(farm1[i]->getHomeAddress() != nullptr)
                        {
                            farm1[i]->setCurAddress(farm1[i]->getHomeAddress());
                        }else{
                            if((rand() % 2) == 1 ) farm1[i]->setCurAddress(&lake1);
                            if((rand() % 2) == 0 ) farm1[i]->setCurAddress(&lake2);
                        }
                    }
                }
            }
        }
    }




    return 0;
}

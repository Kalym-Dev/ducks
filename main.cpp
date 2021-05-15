#include <iostream>

#include <vector>

#include "Lake.h"
#include "Farm.h"

#include "Hunter.h"

#include "Marble.h"
#include "Madagascar.h"
#include "Chirki.h"
#include "Cherrety.h"
#include "Layaing.h"
#include "Peganky.h"

using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::vector;

int com_num = 0;

void add_random_home(vector<Lake*> &lakes, vector<Farm*> &farms, Duck *duck)
{

    int t_lake_num = 0;
    int t_farm_num = 0;

    int t_duck_home = 0;
    int t_knows_home = 0;

    t_duck_home = rand() % 2 + 1;
    if(t_duck_home == 1){
        t_lake_num = rand() % lakes.size() + 1;
        if(t_lake_num > 0 && t_lake_num <= lakes.size()){
            lakes[t_lake_num - 1]->addElemToEnd(duck);
            duck->setCurAddress(lakes[t_farm_num - 1]);
            t_knows_home = rand() % 2;
            if(t_knows_home == 1)
            {
                duck->setHomeAddress(lakes[t_farm_num - 1]);
            }else{
                duck->setHomeAddress(nullptr);
            }
        }
    }else if(t_duck_home == 2){
        t_farm_num = rand() % farms.size() + 1;
        if(t_farm_num > 0 && t_farm_num <= farms.size()){
            farms[t_farm_num - 1]->addElemToEnd(duck);
            duck->setCurAddress(farms[t_farm_num - 1]);
            t_knows_home = rand() % 2;
            if(t_knows_home == 1)
            {
                duck->setHomeAddress(farms[t_farm_num - 1]);;
            }else{
                duck->setHomeAddress(nullptr);
            }
        }
    }
}

void add_duck_home(vector<Lake*> &lakes, vector<Farm*> &farms, Duck *duck)
{

    int t_lake_num = 0;
    int t_farm_num = 0;

    int t_duck_home = 0;

    int t_knows_home = 0;

    cout << "Duck home is lake (1) or farm (2)?" << endl;
    cin >> t_duck_home;
    if(t_duck_home == 1){
        cout << "Choose duck home lake" << endl;
        for(int j = 0; j < lakes.size(); j++)
        {
            cout << "Lake " + to_string(j + 1) + " ";
        }
        cout << endl;
        cin >> t_lake_num;
        if(t_lake_num > 0 && t_lake_num <= lakes.size()){
            lakes[t_lake_num - 1]->addElemToEnd(duck);
            duck->setCurAddress(lakes[t_farm_num - 1]);
            cout << "Duck knows own home? (1) - yes (0) - no" << endl;
            cin >> t_knows_home;
            if(t_knows_home == 1)
            {
                duck->setHomeAddress(lakes[t_farm_num - 1]);
            }else{
                duck->setHomeAddress(nullptr);
            }

        }else{
            cout << "Corrupt lake num!" << endl;
        }
    }else if(t_duck_home == 2){
        cout << "Choose duck home farm" << endl;
        for(int j = 0; j < farms.size(); j++)
        {
            cout << "Farm " + to_string(j + 1) + " ";
        }
        cout << endl;
        cin >> t_farm_num;
        if(t_farm_num > 0 && t_farm_num <= farms.size()){
            farms[t_farm_num - 1]->addElemToEnd(duck);
            duck->setCurAddress(farms[t_farm_num - 1]);
            cout << "Duck knows own home? (1) - yes (2) - no" << endl;
            cin >> t_knows_home;
            if(t_knows_home == 1)
            {
                duck->setHomeAddress(farms[t_farm_num - 1]);
            }else if(t_knows_home == 2){
                duck->setHomeAddress(nullptr);
            }else{
                cout << "Corrupt info!" << endl;
            }

        }else{
            cout << "Corrupt farm num!" << endl;
        }
    }else{
        cout << "Corrupt duck home!";
        return;
    }
}

int main() {

    int t_lake_count = 0;
    cout << "Enter lake count" << endl;
    cin >> t_lake_count;
    vector<Lake*> lakes;
    Lake* t_lake;
    if(t_lake_count > 0) {
        for(int i = 0; i < t_lake_count; i++)
        {
            t_lake = new Lake;
            lakes.push_back(t_lake);
        }
    }else{
        cout << "Corrupt lakes count!" << endl;
        return 0;
    }

    int t_farm_count = 0;
    int t_farm_type = 0;
    int t_farm_know = 1;
    bool t_farm_know_flag = true;
    cout << "Enter farm count" << endl;
    cin >> t_farm_count;
    vector<Farm*> farms;
    Farm* t_farm;
    if(t_farm_count > 0) {
        for(int i = 0; i < t_farm_count; i++)
        {
            cout << "Describe your farm" << endl;
            cout << "Ducks know where live? Yes - 1 No - 0" << endl;
            cin >> t_farm_know;
            if(t_farm_know == 1)
            {
                t_farm_know_flag = true;
            }else if(t_farm_know == 0)
            {
                t_farm_know_flag = false;
            }else{
                cout << "Corrupt farm known!" << endl;
                return 0;
            }
            cout << "Who can escape from farm? 1 - flying, 2 - swiming, 3 - migration, 4 - nothing" << endl;
            cin >> t_farm_type;
            switch(t_farm_type){
                case 1:
                    t_farm = new Farm(t_farm_type, t_farm_know_flag);
                    farms.push_back(t_farm);
                    break;
                case 2:
                    t_farm = new Farm(t_farm_type, t_farm_know_flag);
                    farms.push_back(t_farm);
                    break;
                case 3:
                    t_farm = new Farm(t_farm_type, t_farm_know_flag);
                    farms.push_back(t_farm);
                    break;
                case 4:
                    t_farm = new Farm(t_farm_type, t_farm_know_flag);
                    farms.push_back(t_farm);
                    break;
                default:
                    cout << "Corrupt farm type!" << endl;
                    return 0;
                    break;
            }
        }
    }else{
        cout << "Corrupt farm count!" << endl;
        return 0;
    }

    int t_hun_count = 0;
    int t_hun_max = 0;
    int t_hun_min = 0;
    int t_farm_num = 0;
    Farm* t_hun_farm = nullptr;
    cout << "Enter hunters count" << endl;
    cin >> t_hun_count;
    vector<Hunter*> hunters;
    Hunter* t_hun;
    if(t_hun_count > 0) {
        for(int i = 0; i < t_hun_count; i++)
        {
            cout << "Describe your hunter" << endl;
            cout << "Enter maximum ducks" << endl;
            cin >> t_hun_max;
            if(t_hun_max > 0)
            {
                cout << "Enter minimum ducks" << endl;
                cin >> t_hun_min;

                if(t_hun_min >= 0 && t_hun_min <= t_hun_max)
                {
                    cout << "Choose hunter farm" << endl;
                    for(int j = 0; j < farms.size(); j++)
                    {
                        cout << "Farm (" + to_string(j + 1) + ") ";
                    }
                    cout << endl;
                    cin >> t_farm_num;
                    if(t_farm_num > 0 && t_farm_num <= farms.size()){
                        t_hun = new Hunter(t_hun_max, t_hun_min, farms[t_farm_num - 1]);
                        hunters.push_back(t_hun);
                    }else{
                        cout << "Corrupt farm num!" << endl;
                    }
                }else{
                    cout << "Corrupt minimum!" << endl;
                }
            }else{
                cout << "Corrupt maximum!" << endl;
            }

        }
    }else{
        cout << "Corrupt hunters count!" << endl;
        return 0;
    }



    int duck_com_num = 0;
    int duck_count = 0;
    int duck_type = 0;
    int t_duck_home = 0;
    int t_lake_num = 0;
    Farm* t_duck_farm = nullptr;
    Lake* t_duck_lake = nullptr;

    Marble* t_marble;
    Madagascar* t_magascar;
    Chirki* t_chirki;
    Cherrety* t_cherrety;
    Layaing* t_layaing;
    Peganky* t_peganky;


    string t_name;
    int t_weight = 0;

    string t_hobby;
    int t_wingspan = 0;

    int t_beak_size = 0;
    int t_dex = 0;

    string t_beak_color;
    int t_health = 0;

    int t_paw_size = 0;

    int t_age = 0;

    int t_stamina = 0;
    string t_form;

    int t_duck_count_generate = 0;
    int t_rand_farm = 0;
    int t_rand_lake = 0;
    int t_rand_duck_type = 0;
    string t_rand_name;
    int t_rand_weight = 0;

    string t_rand_hobby;
    int t_rand_wingspan = 0;

    int t_rand_beak_size = 0;
    int t_rand_dex = 0;

    string t_rand_beak_color;
    int t_rand_health = 0;

    int t_rand_paw_size = 0;

    int t_rand_age = 0;

    int t_rand_stamina = 0;
    string t_rand_form;

    Marble* t_rand_marble;
    Madagascar* t_rand_magascar;
    Chirki* t_rand_chirki;
    Cherrety* t_rand_cherrety;
    Layaing* t_rand_layaing;
    Peganky* t_rand_peganky;


    while(duck_com_num != 3) {
        cout << "1. Manual adding ducks!" << endl;
        cout << "2. Automatic generate ducks in lakes and farms: " << endl;
        cout << "3. Exit " << endl;
        cout << "Enter command number: " << endl;
        cin >> duck_com_num;

        switch (duck_com_num) {
            case 1:
                cout << "Enter duck count" << endl;
                cin >> duck_count;
                if(duck_count > 0){
                    for(int i = 0; i < duck_count; i++)
                    {
                        cout << "Choose your duck type 1 - Marble, 2 - Madagascar, 3 - Chirki, 4 - Cherrety, 5 - Layiang, 6 - Peganky" << endl;
                        cin >> duck_type;
                        cout << "Choose duck name" << endl;
                        cin >> t_name;
                        cout << "Choose duck weight" << endl;
                        cin >> t_weight;
                        if(t_weight <= 0){
                            cout << "Corrupt weight!";
                            return 0;
                        }
                        switch (duck_type) {
                            case 1:
                                cout << "Choose duck hobby" << endl;
                                cin >> t_hobby;
                                cout << "Choose duck wingspan" << endl;
                                cin >> t_wingspan;
                                if(t_wingspan <= 0){
                                    cout << "Corrupt wingspan!";
                                    return 0;
                                }
                                t_marble = new Marble(t_name, t_weight, t_hobby, t_wingspan);

                                add_duck_home(lakes, farms, t_marble);
                                break;
                            case 2:
                                cout << "Choose duck beak size" << endl;
                                cin >> t_beak_size;
                                if(t_beak_size <= 0){
                                    cout << "Corrupt beak size!";
                                    return 0;
                                }
                                cout << "Choose duck dex" << endl;
                                cin >> t_dex;
                                if(t_dex <= 0){
                                    cout << "Corrupt dex!";
                                    return 0;
                                }
                                t_magascar = new Madagascar(t_name, t_weight, t_beak_size, t_dex);

                                add_duck_home(lakes, farms, t_magascar);
                                break;
                            case 3:
                                cout << "Choose duck health" << endl;
                                cin >> t_health;
                                if(t_health <= 0){
                                    cout << "Corrupt health size!";
                                    return 0;
                                }
                                cout << "Choose duck beak color" << endl;
                                cin >> t_beak_color;
                                t_chirki = new Chirki(t_name, t_weight, t_beak_color, t_health);

                                add_duck_home(lakes, farms, t_chirki);
                                break;
                            case 4:
                                cout << "Choose duck paw size" << endl;
                                cin >> t_paw_size;
                                if(t_paw_size <= 0){
                                    cout << "Corrupt paw size!";
                                    return 0;
                                }
                                cout << "Choose duck beak color" << endl;
                                cin >> t_beak_color;
                                t_cherrety = new Cherrety(t_name, t_weight, t_beak_color, t_paw_size);

                                add_duck_home(lakes, farms, t_cherrety);
                                break;
                            case 5:
                                cout << "Choose duck age" << endl;
                                cin >> t_age;
                                if(t_age <= 0){
                                    cout << "Corrupt age!";
                                    return 0;
                                }
                                cout << "Choose duck hobyy" << endl;
                                cin >> t_hobby;
                                t_layaing = new Layaing(t_name, t_weight, t_hobby, t_age);

                                add_duck_home(lakes, farms, t_layaing);
                                break;
                            case 6:
                                cout << "Choose duck stamina" << endl;
                                cin >> t_stamina;
                                if(t_stamina <= 0){
                                    cout << "Corrupt stamina!";
                                    return 0;
                                }
                                cout << "Choose duck form" << endl;
                                cin >> t_form;
                                t_peganky = new Peganky(t_name, t_weight, t_form, t_stamina);

                                add_duck_home(lakes, farms, t_peganky);
                                break;
                            default:
                                break;
                        }
                    }
                }else{
                    cout << "Corrupt duck count!";
                }
                break;
            case 2:
                cout << "Enter duck count generate" << endl;
                srand(time(0));
                cin >> t_duck_count_generate;
                if(t_duck_count_generate > 0)
                {
                    for(int i = 0; i < t_duck_count_generate; i++)
                    {
                        t_rand_duck_type = 1 + rand() % 6;
                        t_rand_name = "Name " + to_string(rand());
                        t_rand_weight = rand();
                        switch (t_rand_duck_type) {
                            case 1:
                                t_rand_hobby = "Hobby " + to_string(rand());
                                t_rand_wingspan = rand();
                                t_rand_marble = new Marble(t_rand_name, t_rand_weight, t_rand_hobby, t_rand_wingspan);
                                add_random_home(lakes, farms, t_rand_marble);
                                break;
                            case 2:
                                t_rand_beak_size = rand();
                                t_rand_dex = rand();
                                t_rand_magascar = new Madagascar(t_rand_name, t_rand_weight, t_rand_beak_size, t_rand_dex);
                                add_random_home(lakes, farms, t_rand_magascar);
                                break;
                            case 3:
                                t_rand_health = rand();
                                t_rand_beak_color = "Color" + to_string(rand());
                                t_rand_chirki = new Chirki(t_rand_name, t_rand_weight, t_rand_beak_color, t_rand_health);
                                add_random_home(lakes, farms, t_rand_chirki);
                                break;
                            case 4:
                                t_rand_paw_size = rand();
                                t_rand_beak_color = "Color" + to_string(rand());
                                t_rand_cherrety = new Cherrety(t_rand_name, t_rand_paw_size, t_rand_beak_color, t_rand_health);
                                add_random_home(lakes, farms, t_rand_cherrety);
                                break;
                            case 5:
                                t_rand_age = rand();
                                t_rand_hobby = "Hobby" + to_string(rand());
                                t_layaing = new Layaing(t_rand_name, t_rand_paw_size, t_rand_hobby, t_rand_age);
                                add_random_home(lakes, farms, t_layaing);
                                break;
                            case 6:
                                t_rand_stamina = rand();
                                t_rand_form = "Form" + to_string(rand());
                                t_peganky = new Peganky(t_rand_name, t_rand_paw_size, t_rand_form, t_rand_stamina);
                                add_random_home(lakes, farms, t_peganky);
                                break;
                        }
                    }
                }else{
                    cout << "Corrupt duck count generate!" << endl;
                }
                break;
            case 3:
                break;
            default:
                break;
        }

    }


    Madagascar mad("tom", 22, 100, 0);
    Marble mar("jerry", 22,"dnd", 600);
    Chirki chirki("johs", 1231, "red", 54);

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
    int temp_shoot_index = 0;

    int rand_lake_index = 0;

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
                for(int i = 0; i < lakes.size(); i++)
                {
                    cout << "Lake "  + to_string(i + 1) + ": " + to_string(lakes[i]->getLength()) << endl;
                }

                for(int i = 0; i < farms.size(); i++)
                {
                    cout << "Farm "  + to_string(i + 1) + ": " + to_string(farms[i]->getLength()) << endl;
                }
                break;
            case 2:
                cout << "Choose Lake (1) or Farm (3): " << endl;
                cin >> temp_choose;
                if(temp_choose != 1 && temp_choose != 2 && temp_choose != 3){
                    cout << "Wrong choose!";
                }else if(temp_choose == 1){
                    cout << "Choose duck lake" << endl;
                    for(int j = 0; j < lakes.size(); j++)
                    {
                        cout << "Lake " + to_string(j + 1) + " ";
                    }
                    cout << endl;
                    cin >> t_lake_num;
                    if(t_lake_num > 0 && t_lake_num <= lakes.size()){
                        for(int i = 0; i < lakes[t_lake_num - 1]->getLength(); i++){
                            (*lakes[t_lake_num - 1])[i]->tellAboutYourself();
                            cout << endl;
                        }
                    }else{
                        cout << "Corrupt lake num!" << endl;
                    }
                }else if(temp_choose == 3){
                    cout << "Choose duck farm" << endl;
                    for(int j = 0; j < farms.size(); j++)
                    {
                        cout << "Farm " + to_string(j + 1) + " ";
                    }
                    cout << endl;
                    cin >> t_farm_num;
                    if(t_farm_num > 0 && t_farm_num <= farms.size()){
                        for(int i = 0; i < farms[t_farm_num - 1]->getLength(); i++){
                            (*farms[t_farm_num - 1])[i]->tellAboutYourself();
                            cout << endl;
                        }
                    }else{
                        cout << "Corrupt farm num!" << endl;
                    }
                }
                break;
            case 3:
                cout << "Choose Lake (1) or Farm (2): " << endl;
                cin >> temp_choose;
                if(temp_choose != 1 && temp_choose != 2){
                    cout << "Wrong choose!";
                }else if(temp_choose == 1){
                    cout << "Choose duck lake" << endl;
                    for(int j = 0; j < lakes.size(); j++)
                    {
                        cout << "Lake " + to_string(j + 1) + " ";
                    }
                    cout << endl;
                    cin >> t_lake_num;
                    if(t_lake_num > 0 && t_lake_num <= lakes.size()){
                        for(int i = 0; i < lakes[t_lake_num - 1]->getLength(); i++){
                            temp_what_can = (*lakes[t_lake_num - 1])[i]->getWhatcan(); // 1 - летать, 2 - плавать, 3 - мигрировать, 4 - безьдельничать
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
                    }else{
                        cout << "Corrupt lake num!" << endl;
                    }
                }else if(temp_choose == 2){
                    cout << "Choose duck farm" << endl;
                    for(int j = 0; j < farms.size(); j++)
                    {
                        cout << "Farm " + to_string(j + 1) + " ";
                    }
                    cout << endl;
                    cin >> t_farm_num;
                    if(t_farm_num > 0 && t_farm_num <= farms.size()){
                        for(int i = 0; i < farms[t_farm_num - 1]->getLength(); i++){
                            temp_what_can = (*farms[t_lake_num - 1])[i]->getWhatcan(); // 1 - летать, 2 - плавать, 3 - мигрировать, 4 - безьдельничать
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
                    }else{
                        cout << "Corrupt farm num!" << endl;
                    }
                }
                cout << "Fly: " + to_string(t_fly) << endl;
                cout << "Swi: " + to_string(t_swi) << endl;
                cout << "Mig: " + to_string(t_mig) << endl;
                cout << "Not: " + to_string(t_not) << endl;
                break;
            case 4:
                cout << "Choose duck lake there begun hunt" << endl;
                for(int j = 0; j < lakes.size(); j++)
                {
                    cout << "Lake " + to_string(j + 1) + " ";
                }
                cout << endl;
                cin >> t_lake_num;

                if(t_lake_num > 0 && t_lake_num <= lakes.size()){
                    for(int i = 0; i < hunters.size(); i++) {
                        shoot1 = hunters[i]->getHuntingquantity();
                        cout << "Hunter " + to_string(i + 1) + ": " + to_string(shoot1) << endl;
                        for (int j = 0; j < shoot1; j++) {
                            if (lakes[t_lake_num - 1]->getLength() > 0) {
                                temp_shoot_index = rand() % (lakes[t_lake_num - 1]->getLength() - 1);
                                (*lakes[t_lake_num - 1])[temp_shoot_index]->setCurAddress(hunters[i]->getHunterFarm());
                                hunters[i]->getHunterFarm()->addElemToEnd((*lakes[t_lake_num - 1])[temp_shoot_index]);
                                (*lakes[t_lake_num - 1]).remove(temp_shoot_index);
                            } else {
                                cout << "Nothing to catch!" << endl;
                                shoot1 = 0;
                                break;
                            }
                        }
                        day++;
                        shoot2 += shoot1;
                    }
                    cout << "All captured: " + to_string(shoot2) << endl;
                }else{
                    cout << "Corrupt lake num!" << endl;
                }

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

        if(day != 1 && day != 0) //в первый день и в нулевой охоты нету
        {
            for(int i = 0; i < farms.size(); i++)
            {
                for(int j = 0; j < farms[i]->getLength(); j++)
                {
                    if(farms[i]->getEscapetype() == (*farms[i])[j]->getWhatcan())
                    {
                        is_escape = rand() % 2;
                        if(is_escape == 1)
                        {
                            if(!(*farms[i])[j]->getIsescapee())
                            {
                                if((*farms[i])[j]->getHomeAddress() != nullptr)
                                {
                                    (*farms[i])[j]->setCurAddress((*farms[i])[j]->getHomeAddress());
                                    (*farms[i])[j]->setIsescapee(true);
                                    ((*farms[i])[j]->getHomeAddress())->addElemToEnd((*farms[i])[j]);
                                }else{
                                    if(lakes.size() > 1){
                                        rand_lake_index = rand() % (lakes.size() - 1);
                                    }else{
                                        rand_lake_index = rand() % (lakes.size());
                                    }
                                    (*farms[i])[j]->setCurAddress(lakes[rand_lake_index]);
                                    (*farms[i])[j]->setIsescapee(true);
                                    lakes[rand_lake_index]->addElemToEnd((*farms[i])[j]);
                                }
                                cout << "Duck " << (*farms[i])[j]->getName() << " Escape!" << endl;
                                (*farms[i]).remove(j);
                            }
                        }
                    }
                }
            }
        }
    }




    return 0;
}

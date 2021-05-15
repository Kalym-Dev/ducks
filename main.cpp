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

void add_random_home(vector<Lake*> &lakes, vector<Farm*> &farms, Duck *duck) //процедура которая на вход принмает векторы ферм и озер и указатель на объект типа утка (и любые производные)
{

    int t_lake_num = 0;
    int t_farm_num = 0;

    int t_duck_home = 0;
    int t_knows_home = 0;

    t_duck_home = rand() % 2 + 1; //утка где будет жить на ферме или в озере
    if(t_duck_home == 1){ //видать на озере
        t_lake_num = rand() % lakes.size() + 1; //выбираем случаное озеро
        if(t_lake_num > 0 && t_lake_num <= lakes.size()){ //проверяем чтобы было все хорошо
            lakes[t_lake_num - 1]->addElemToEnd(duck); //добавляем в конец озера нашу утку
            duck->setCurAddress(lakes[t_farm_num - 1]); //текущий адрес нашей утки
            t_knows_home = rand() % 2; //наша утка знает где ее родина?
            if(t_knows_home == 1) //видать, да
            {
                duck->setHomeAddress(lakes[t_farm_num - 1]); //выставляем родной дом (это же озеро, которое выбрали выше)
            }else{
                duck->setHomeAddress(nullptr); //не знает, так не знает
            }
        }
    }else if(t_duck_home == 2){ //видать на ферме
        t_farm_num = rand() % farms.size() + 1; //фермы работают аналогично озерам, можно разделить на две разные процедуры, но необязательно
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

void add_duck_home(vector<Lake*> &lakes, vector<Farm*> &farms, Duck *duck) //работает также как и процедура выше, только все задается ручками.
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

    int t_lake_count = 0; //количество озер, можно задать в коде. убрав cin ниже
    cout << "Enter lake count" << endl;
    cin >> t_lake_count; //чтобы задать ручками убрать
    vector<Lake*> lakes; //векторозер
    Lake* t_lake;
    if(t_lake_count > 0) { //тут проверяем что все хорошо с количеством, и создаем озера этого же количества. Память выделяем динамически. Можно сделать очистку мусора (даже нужно)
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
    if(t_farm_count > 0) { //ровно тоже самое что и с озерами, только есть пару дополнительных параметров
        for(int i = 0; i < t_farm_count; i++)
        {
            cout << "Describe your farm" << endl;
            cout << "Ducks know where live? Yes - 1 No - 0" << endl;
            cin >> t_farm_know; //первый параметр это какие утки могут выбраться с фермы, то есть с какимми знаниями утки могут выбраться (знают или не знают они о доме)
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
            cin >> t_farm_type; //тут тип кто может сбежать с фермы
            switch(t_farm_type){ //выбираем тип и создаем соответсвующий объект фермы. Можно в принципе в одну процедуру запихать эти две строчки под case
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
    cin >> t_hun_count; //тут количество охотников сообщите
    vector<Hunter*> hunters;
    Hunter* t_hun;
    if(t_hun_count > 0) {
        for(int i = 0; i < t_hun_count; i++)
        {
            cout << "Describe your hunter" << endl;
            cout << "Enter maximum ducks" << endl;
            cin >> t_hun_max; //Описываем охотников с помощью их максимального количества возможной пойманной дичи
            if(t_hun_max > 0)
            {
                cout << "Enter minimum ducks" << endl;
                cin >> t_hun_min; //и минимальной

                if(t_hun_min >= 0 && t_hun_min <= t_hun_max) //проверяем не больше ли минимум максимума
                {
                    cout << "Choose hunter farm" << endl; //выбираем родную ферму для охотника, он туда несет дичь (из всех ферм)
                    for(int j = 0; j < farms.size(); j++)
                    {
                        cout << "Farm (" + to_string(j + 1) + ") ";
                    }
                    cout << endl;
                    cin >> t_farm_num;
                    if(t_farm_num > 0 && t_farm_num <= farms.size()){ //наконец выбрав создаем объект охотника и вставляем в вектор
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


    //### Ниже параметры и типы уток конкретные (задаваемые ручками) со всеми атрибутами
    int duck_com_num = 0; //это номер команды интерфейса (консольного) для уток
    int duck_count = 0; //количество уток
    int duck_type = 0; //тип утки
    int t_duck_home = 0; //знает ли о доме
    int t_lake_num = 0; //номер озера
    Farm* t_duck_farm = nullptr; //это временные вещи,
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
    //### Тут аналогично просто переменные для случайной генерации

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
    //###
    //Ниже для неувлоимой утки. Она просто утка, без особых черт, способность у нее особенная
    Duck t_elu_duck("Elusive", 1000, 5);
    int elu_duck_knows = 0; //знает ли утка о доме
    int t_duck_chance = 0; //просто перменная куда запихивается значение от рандомной функции. Утка неуловимая появлется с некотоорым шансом
    bool t_elu_flag = false; //это флаг чтобы следить есть ли утка на фермах или озерах, чтобы ее удалить или не создавать еще одну
    int t_days_for_debuf = 0; //это количество дней до удаления утки, задается ниже
    int rand_farm_index = 0; //просто случайный индекс для нашей утки

    while(duck_com_num != 3){  //а вот и блок с командами утки. сделан бесконечный цикл, который закончится когда нажмете команду 3, то есть введете 3.
        cout << "1. Manual adding ducks!" << endl; //ручное задание уток, не рекомендую, долго
        cout << "2. Automatic generate ducks in lakes and farms: " << endl; //автоматическое задание, случайная генерация
        cout << "3. Exit " << endl;
        cout << "Enter command number: " << endl;
        cin >> duck_com_num;

        switch (duck_com_num) {
            case 1:
                //ну тут собственно задатеся все руками. главное читать что просят и все понятно
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
                //тут просто количество вводишь и он сам генерирует уток и раскидывает по все озерам и фермам (рандомно)
                cout << "Enter duck count generate" << endl;
                srand(time(0)); //так нужно сделать чтобы rand() давала разные значения при вызове
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

    int shoot1 = 0; //количество выстрелов сделанных охотников
    int shoot2 = 0; //суммарное количество сделанных выстрелов (ну короче поймайных уток)

    int day = 0;
    int temp_choose;
    int temp_what_can = 0;
    int t_fly = 0; //эти 4 переменные для подсчета типов способностей уток. Летающих, плавающих, мигрирующих, ничего не делающих
    int t_swi = 0;
    int t_mig = 0;
    int t_not = 0;

    bool is_hunting_season = false; //открыт ли сехон охоты?
    int is_escape = 0;
    int temp_shoot_index = 0; //индекс куда в который попал охотник (утка подстрелянная)

    int rand_lake_index = 0;

    while(com_num != 6) {
        if(day <= 7) //сезон охоты идет 7 дней, если нужно по другому то задается здесь, можно сделать ручной ввод, но лень
        {
            cout << "Hunting season!" << endl;
            is_hunting_season = true;
        }else{
            is_hunting_season = false;
            if(day == 14) day = 0; //после 14 дней обнуляем
            cout << "Closed" << endl;
        }
        cout << "1. Show count ducks in every lake!" << endl; //показываем количество утко в каждом озере
        cout << "2. Show info about ducks in lake: " << endl; //Тут каждая утка в озере с информацией о себе
        cout << "3. Show statistic ability types ducks: " << endl; //тут количество сгрупированных по способностям
        if(is_hunting_season) cout << "4. Hunters shoot" << endl; //делаем выстрел охотниками, или выходим на охоту охотниками. Надо выбрать озеро куда идем. Один поход - один день
        cout << "5. Scip day" << endl; //пропускаем день
        cout << "6. exit" << endl; //выход
        cout << "Введите команду: " << endl; //задаем номер команды
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
                            (*farms[t_farm_num - 1])[i]->tellAboutYourself(); //проходимся и рассказываем о себе
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
                        for(int i = 0; i < lakes[t_lake_num - 1]->getLength(); i++){ //ниже считаем каждый типы действий уток в выбранной озере
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
                        for(int i = 0; i < farms[t_farm_num - 1]->getLength(); i++){ //тут что же то же что и выше только про фермы. Стоит запихнуть в отедльную процедуру
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
                                if(lakes[t_lake_num - 1]->getLength() > 1){
                                    temp_shoot_index = rand() % (lakes[t_lake_num - 1]->getLength() - 1); //охотник выбирает жертву случайно
                                }else{
                                    temp_shoot_index = 0;
                                }
                                (*lakes[t_lake_num - 1])[temp_shoot_index]->setCurAddress(hunters[i]->getHunterFarm()); //это оззнчает что мы берем подстреленную утку и даем ей адрес фермы охотника
                                hunters[i]->getHunterFarm()->addElemToEnd((*lakes[t_lake_num - 1])[temp_shoot_index]); //здесь ДОБАВЛЯЕМ в ферму нашу утку
                                (*lakes[t_lake_num - 1]).remove(temp_shoot_index); //удаляем ее из озера
                            } else {
                                //cout << "Nothing to catch!" << endl;
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
                //return 0;
                break;
            default:
                break;
        }
        if(day != 1 && day != 0) //в первый день и в нулевой охоты нету
        {
            for(int i = 0; i < farms.size(); i++) //блок побега
            {
                for(int j = 0; j < farms[i]->getLength(); j++) //продйемся по всем фермам
                {
                    if(farms[i]->getEscapetype() == (*farms[i])[j]->getWhatcan()) //может сбежать лишь тот кто способен это сделать
                    {
                        is_escape = rand() % 2; //но с некоторым шансом
                        if(is_escape == 1)
                        {
                            if(!(*farms[i])[j]->getIsescapee()) //смотрим, а наша утка уже не бежала. Если бежала то не убежит больше
                            {
                                if((*farms[i])[j]->getHomeAddress() != nullptr) //если утка знает где ее дом
                                {
                                    (*farms[i])[j]->setCurAddress((*farms[i])[j]->getHomeAddress()); //до текущий адрес ее будет в домашней озерее
                                    (*farms[i])[j]->setIsescapee(true); //она становится побегушником
                                    ((*farms[i])[j]->getHomeAddress())->addElemToEnd((*farms[i])[j]); //и добавляем в домашнее озеро нашу утку
                                }else{ //а если не знает то беижит в случайнеое озеро
                                    if(lakes.size() > 1){
                                        rand_lake_index = rand() % (lakes.size() - 1);
                                    }else{
                                        rand_lake_index = rand() % (lakes.size());
                                    }//выбрали случайный индекс озера
                                    (*farms[i])[j]->setCurAddress(lakes[rand_lake_index]); //тоже самое что и выше
                                    (*farms[i])[j]->setIsescapee(true);
                                    lakes[rand_lake_index]->addElemToEnd((*farms[i])[j]);
                                }
                                cout << "Duck " << (*farms[i])[j]->getName() << " Escape!" << endl;
                                (*farms[i]).remove(j);
                            }
                        }
                    }else if((*farms[i])[j]->getWhatcan() == 5){ //если утка неуловимая то она все время бежит
                        if(farms.size() > 1){
                            rand_lake_index = rand() % (lakes.size() - 1);
                        }else{
                            rand_lake_index = rand() % (lakes.size());
                        }
                        (*farms[i])[j]->setCurAddress(lakes[rand_lake_index]);
                        lakes[rand_lake_index]->addElemToEnd((*farms[i])[j]);
                        cout << "Duck " << (*farms[i])[j]->getName() << " Escape!" << endl;
                        (*farms[i]).remove(j);
                    }
                }
            }

            for(int i = 0; i < lakes.size(); i++)
            {
                for(int j = 0; j < lakes[i]->getLength(); j++)
                {
                    if((*lakes[i])[j]->getWhatcan() == 3) //если утка мигиррующая то она мигрирует куда-нибудь
                    {
                        if(lakes.size() > 1){
                            rand_lake_index = rand() % (lakes.size() - 1);
                        }else{
                            rand_lake_index = rand() % (lakes.size());
                        }
                        (*lakes[i])[j]->setCurAddress(lakes[rand_lake_index]);
                        lakes[rand_lake_index]->addElemToEnd((*lakes[i])[j]);
                        (*lakes[i]).remove(j);
                    }
                }
            }

            if(t_elu_flag) //если у нас есть уже неуловимая утка, значит ей жить два дня а потом пропасть. Поэтому когда ей уже жить 0 дней, то мы ее ищем и удаляем
            {
                if(t_days_for_debuf == 0)
                {
                    t_elu_flag = false;
                    for(int i = 0; i < farms.size(); i++)
                    {
                        for(int j = 0; j < farms[i]->getLength(); j++)
                        {
                            if((*farms[i])[j]->getWhatcan() == 5)
                            {
                                (*farms[i]).remove(j);
                                goto out_farm;
                            }
                            if(false) out_farm:break;
                        }
                    }
                    for(int i = 0; i < lakes.size(); i++)
                    {
                        for(int j = 0; j < lakes[i]->getLength(); j++)
                        {
                            if((*lakes[i])[j]->getWhatcan() == 5)
                            {
                                (*lakes[i]).remove(j);
                                goto out_lake;
                            }
                        }
                        if(false) out_lake:break;
                    }
                }else{
                    t_days_for_debuf--;
                }
            }

            //Elusive duck
            t_duck_chance = rand() % 2; //с некотоырм шансом поялвется утка неуловимая и если ее еще нет
            if(t_duck_chance == 1 && !t_elu_flag){
                t_duck_home = rand() % 2 + 1; //утка на ферме или на озере
                if(t_duck_home == 1){
                    t_lake_num = rand() % lakes.size() + 1;
                    if(t_lake_num > 0 && t_lake_num <= lakes.size()){
                        lakes[t_lake_num - 1]->addElemToEnd(&t_elu_duck);
                        t_elu_duck.setCurAddress(lakes[t_farm_num - 1]);
                        elu_duck_knows = rand() % 2; //все остальнео аналогично примерам выше, стоит перенссти в отдельные процедуры
                        if(elu_duck_knows == 1)
                        {
                            t_elu_duck.setHomeAddress(lakes[t_farm_num - 1]);
                        }else{
                            t_elu_duck.setHomeAddress(nullptr);
                        }
                        t_days_for_debuf = 2; //ей жить два дня
                        t_elu_flag = true; //это значит что неуловимая появилась
                    }
                }else if(t_duck_home == 2){
                    t_farm_num = rand() % farms.size() + 1;
                    if(t_farm_num > 0 && t_farm_num <= farms.size()){
                        farms[t_farm_num - 1]->addElemToEnd(&t_elu_duck);
                        t_elu_duck.setCurAddress(farms[t_farm_num - 1]);
                        elu_duck_knows = rand() % 2;
                        if(elu_duck_knows == 1)
                        {
                            t_elu_duck.setHomeAddress(farms[t_farm_num - 1]);;
                        }else{
                            t_elu_duck.setHomeAddress(nullptr);
                        }
                    }
                    t_days_for_debuf = 2; //ей жить два дня
                    t_elu_flag = true; //это значит что неуловимая появилась
                }
            }

        }
    }

    return 0;
}

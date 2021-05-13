//#include <iostream>
//
//#include "Lake.h"
//#include "Farm.h"
//#include "Hunter.h"
//#include "Duck.h"
//#include "Marble.h"
//#include "Madagascar.h"
//#include "Chirki.h"
//
//int main() {
//
//
//    Madagascar test1("tom", 22, 100, 0);
//    Marble test4("jerry", 22,"dnd", 600);
//    Chirki test2("johs", 1231, "red", 54);
//
//    Lake lake1;
//    test1.setHomeAddress(&lake1);
//    test4.setHomeAddress(&lake1);
//
//    lake1.addElemToEnd(&test1);
//    lake1.addElemToEnd(&test4);
//    lake1.addElemToEnd(&test2);
//
//    lake1[0]->tellAboutYourself();
//    std::cout << "\n";
//    lake1[1]->tellAboutYourself();
//    std::cout << "\n";
//    lake1[2]->tellAboutYourself();
//
//    std::cout << std::endl;
//
//    Farm farm1(1);
//    std::cout << farm1.getLength();
//    Hunter hun1(3, 1, &farm1);
//    int count = hun1.getHuntingquantity();
//    std::cout << std::endl << count << std::endl;
//    int temp_len = lake1.getLength();
//    for(int i = 0; i < count; i++)
//    {
//        std::cout << i << ": " << rand() % temp_len;
//        lake1[rand() % temp_len]->setCurAddress(hun1.getHunterFarm());
//        hun1.getHunterFarm()->addElemToEnd(lake1[rand() % temp_len]);
//        lake1.remove(rand() % temp_len);
//        std::cout << std::endl;
//    }
//
//    std::cout << farm1.getLength();
//
//
//
//
//    return 0;
//}

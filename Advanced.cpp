#include <iostream>

class Advanced {
    int people;
    bool love, wind, greed, humid, gold, religion, gun, plague, renaissance, love, Aliens = false;

    Advanced() {
        people = 3;
    }

        int getPeople() {
        return people;
    }

    void eventHandler(std::string value) {
            if(value.compare("volcano")==0) {
            std::cout << "The volcano devastated the advanced people and wiped out their civilization.\n";
            people =0;
        }
            if(value.compare("love")==0) {
                if(people == 0) {
                    std::cout << "There is no one here to be loved.\n";
                } else {
                    std::cout << "Love is in the air.\n";
                    people +=1;
                }
            }
    }
    
        bool endHandler(std::string value) {
        if(value.compare("peace") == 0) {
            if(people == 3 && love && renaissance) {
                std::cout << "This advanced civilization is in harmony and peace.\n";
                return true;
            }

        }else if(value.compare("god")==0) {
            std::cout << "This advanced civilization scoffs at the idea of god as they are beyond religion.\n";
            return false;

        } else if(value.compare("christmas")==0) {
            std::cout << "This advanced civilization scoffs at the idea of christmas as they are beyond religion.\n";
            return false;

        } else if(value.compare("cultural")==0) {
            if(religion && renaissance && Aliens) {
            std::cout << "The aliens taught the advanced civilization to grow and accept old concepts. Culture is now being developed.\n";
            return true;
                        }

        } else if(value.compare("nothing")==0) {
            if(people == 0 && Aliens) {
                std::cout << "The world may be vast, but there is no one here. The nomads are gone.\n";
                return true;
            }
        } else if(value.compare("Greedy")==0) {
             std::cout << "This advanced civilization scoffs at the idea of greed as they are beyond selfishness.\n";
            return false;

        } else if(value.compare("warming")==0) {
            if(humid && wind) {
            std::cout << "The world is slowing warming up. This may be a problem, but not the nomads problem.\n";
            return true;
            }
        } else if(value.compare("gone")==0) {
            if(people == 0) {
                std::cout << "The world may be vast, but there is no one here. The nomads are gone.\n";
                return true;
            }
        }
        return false;
    }

};
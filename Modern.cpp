#include <iostream>

class Modern {
    int people;
    bool love, wind, greed, humid, gold, religion, gun, plague, renaissance, love, Aliens = false;

    Modern() {
        people = 3;
    }

        int getPeople() {
        return people;
    }

    void eventHandler(std::string value) {
            if(value.compare("volcano")==0) {
            std::cout << "The volcano devastated the modern people and wiped out their civilization.\n";
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
                std::cout << "This modern civilization is in harmony and peace.\n";
                return true;
            }

        }else if(value.compare("god")==0) {
            if(love && Aliens){
            std::cout << "The trial that the aliens brough made the modern civilization believe even stronger in their god.\n";
            return true;
            }

        } else if(value.compare("christmas")==0) {
            if(religion && love) {
            std::cout << "Its a beautiful snowy day and the modern covilization is giving gifts to each other.\n";
            return true;
            }

        } else if(value.compare("cultural")==0) {
            std::cout << "The modern civilization has vast ties to their culture and refuses to change.\n";
            return false;
        } else if(value.compare("nothing")==0) {
            if(people == 0 && Aliens) {
                std::cout << "The world may be vast, but there is no one here. The nomads are gone.\n";
                return true;
            }
        } else if(value.compare("Greedy")==0) {
            if (people == 1 && gold && gun && greed) {
                std::cout << "The modern civilization really likes their gold.\n";
                return true;
            }

        } else if(value.compare("before")==0) {
            if(people == 2 && plague && humid) {
                std::cout << "Time to buy toilet paper and milk.\n";
                return true;
            }
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
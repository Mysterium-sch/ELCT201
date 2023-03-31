#include <iostream>

class Advanced {
    int people;

    Advanced() {
        people = 3;
    }

        int getPeople() {
        return people;
    }

    void eventHandler() {

    }
    
        bool endHandler(std::string value) {
        if(value.compare("peace") == 0) {
            if(people == 3) {
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
            std::cout << "The aliens taught the advanced civilization to grow and accept old concepts. Culture is now being developed.\n";
            return true;

        } else if(value.compare("nothing")==0) {
            if(people == 0) {
                std::cout << "The world may be vast, but there is no one here. The nomads are gone.\n";
                return true;
            }
        } else if(value.compare("Greedy")==0) {
             std::cout << "This advanced civilization scoffs at the idea of greed as they are beyond selfishness.\n";
            return false;

        } else if(value.compare("warming")==0) {
            std::cout << "The world is slowing warming up. This may be a problem, but not the nomads problem.\n";
            return true;
        } else if(value.compare("gone")==0) {
            if(people == 0) {
                std::cout << "The world may be vast, but there is no one here. The nomads are gone.\n";
                return true;
            }
        }
        return false;
    }

};
#include <iostream>

class Nomad {
    int people;

    Nomad() {
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
                std::cout << "This nomadic civilization is in harmony and peace.\n";
                return true;
            }

        }else if(value.compare("god")==0) {

        } else if(value.compare("christmas")==0) {

        } else if(value.compare("cultural")==0) {

        } else if(value.compare("nothing")==0) {
            if(people == 0) {
                std::cout << "The world may be vast, but there is no one here. The nomads are gone.\n";
                return true;
            }
        } else if(value.compare("Greedy")==0) {

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
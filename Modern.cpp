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
                    love = !love;
                    if(love) {
                        std::cout << "Love is in the air.\n";
                        if(people != 3) {
                            people +=1;
                        }
                    } else {
                        std::cout << "The season of love is over.\n";
                    }
                    
                }
            }
            if(value.compare("wind")==0) {
                wind=!wind;
                if(wind) {
                    std::cout << "Its getting pretty windy.\n";
                } else {
                    std::cout << "The wind has died down.\n";
                }
            }if(value.compare("greed")==0) {
                greed != greed;
                if(greed) {
                std::cout << "People have started to get greedy.\n";
                } else {
                    std::cout << "The people's greed is dying down.\n";
                }
            }if(value.compare("humid")==0) {
                humid != humid;
                if(humid)
                    std::cout << "The humid has gotten worse.\n";
                else {
                    std::cout << "The humidity is dying down.\n";
                }

            } if(value.compare("Gold")==0) {
                gold = true;
                std::cout << "Theres gold in these parts.\n";
            } if(value.compare("gun")==0) {
                gun == true;
                std::cout << "Gun powder has been discovered.\n";

            } if(value.compare("religion")==0) {
                religion != religion;
                if(religion) {
                    std::cout << "The people are becoming spiritual.\n";
                } else {
                    std::cout << "The people are losing their faith.\n";
                }

            } if(value.compare("plague")==0) {
                    plague != plague;
                    if(plague) {
                        std::cout << "A mysterious cough is going around.\n";
                    } else {
                        std::cout << "A cure was found for the disease.\n";
                    }
            } if(value.compare("aliens")==0) {
                    Aliens != Aliens;
                    if(Aliens) {
                        std::cout << "Mysterious space men have appeared.\n";
                    } else {
                        std::cout << "The space men have left.\n";
                    }
            } if(value.compare("renaissance")==0) {
                renaissance != renaissance;
                if(renaissance) {
                    std::cout << "Music and art has become increasing popular.\n";
                } else {
                    std::cout << "People are becomming less and less creative.\n";
                }
            }
            
                        // Advanced events
            if(value.compare("blizzard")==0) {
                if(wind) {
                    std::cout << "A blizzard has struck the civilization.\n";
                    if(people != 0) {
                        people -= 1;
                    } else {
                        std::cout << "but everyone is already gone...\n";
                    }
                }
            } if(value.compare("warAlien") == 0) {
                if(gun && Aliens && greed) {
                    if(people != 0) {
                    std::cout << "The civilization yearned for the alien's tech, which didn't work out for them.\n";
                    people -= 1;
                    if(people <= 0) {
                        people = 0;
                    }
                }
                }
            } if(value.compare("warGold") == 0) {
                if(gun && gold && greed) {
                    if(people != 0) {
                        std::cout << "The civilization has started a war over the gold!\n";
                        people -= 1;
                    }
                }
            } if(value.compare("heatStroke")==0) {
                if(humid) {
                    std::cout << "The civilization is unprepared for the heat.\n";
                    if(people != 0) {
                        people -= 1;
                    } else {
                        std::cout << "but everyone is already gone...\n";
                    }
                }
            } if(value.compare("warReligion")==0) {
                if(gun && religion) {
                    if(people != 0) {
                        std::cout << "TThe civilization can't come to consenses on who's religion is right.\n";
                        people -= 1;
                    }
                }
            } if(value.compare("plagueDeaths")==0) {
                if(plague) {
                    std::cout << "The sickness is worstening during these harsh winters.\n";
                    if(people != 0) {
                        people -= 1;
                    } else {
                        std::cout << "but everyone is already gone...\n";
                    }
                }
            } if(value.compare("boon")==0) {
                if(renaissance && love) {
                    std::cout << "A celebration of life is happening as people immegrate to this civilization\n";
                    if(people != 3 || people != 2) {
                        people += 2;
                    }
                }
            } if(value.compare("abducted")==0) {
                if(Aliens) {
                    std::cout << "Someone has gone missing, the Aliens claim the didn't do it.\n";
                    people -= 1;
                    if (people <= 0) {
                        people =0;
                    }
                }
            } if (value.compare("hope")==0) {
                if(religion && plague) {
                    std::cout << "God will cure this plague.\n";
                    people -= 1;
                    if (people <= 0) {
                        people = 0;
                    }
                }
            } if(value.compare("AlienPlague")==0) {
                if(Aliens && plague) {
                    std::cout << "Everyone started getting weird bumps after the aliens arrived...\n";
                    people -= 2;
                    if(people < 0) {
                        people = 0;
                    }
                }
            } if(value.compare("GunLove")==0) {
                std::cout << "People sure love their guns.\n";
                people -= 1;
                if(people < 0) {
                    people =0 ;
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
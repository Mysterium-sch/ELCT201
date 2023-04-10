#include "Modern.h"

    Modern::Modern() {
        people = 3;
    }

    int getPeople() {
        return people;
    }

    void Modern::eventHandler(std::string value) {
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
                if(!gold) {
                gold = true;
                std::cout << "The advanced civilization has no need for gold.\n";
                }
            } if(value.compare("gun")==0) {
                gun == true;
                std::cout << "Gun powder has been discovered.\n";

            } if(value.compare("religion")==0) {
                religion != religion;
                std::cout << "The advanced civilization is beyond having faith in religion.\n";

            } if(value.compare("plague")==0) {
                    plague != plague;
                    if(plague) {
                        std::cout << "A mysterious cough is going around.\n";
                    } else {
                        std::cout << "A cure was found for the disease.\n";
                    }
            } if(value.compare("aliens")==0) {
                    Aliens != Aliens;
                    std::cout << "These modern men do not belivie in fly saucers.\n";
            } if(value.compare("renaissance")==0) {
                renaissance != renaissance;
                if(renaissance) {
                    std::cout << "Music and art has become increasing popular.\n";
                } else {
                    std::cout << "People are becomming less and less creative.\n";
                }
            }
            if(value.compare("cold")==0) {
                cold = !cold;
                if(cold) {
                    std::cout << "The world is becoming very cold.\n";
                } else {
                    std::cout << "The frost is melting away.\n";
                }
            } if(value.compare("hot")==0) {
                hot != hot;
                if(hot) {
                    std::cout << "The world is becoming increasingly warm.\n";
                } else {
                    std::cout << "The heat is dying down.\n";
                }
            } if(value.compare("dark")==0) {
                dark != dark;
                if(dark) {
                    std::cout << "The world is getting dark.\n";
                } else {
                    std::cout << "The darkness is subsiding.\n";
                }
            } if(value.compare("light")==0) {
                light != light;
                if(light) {
                    std::cout << "The world is very bright.\n";
                } else {
                    std::cout << "The brightness is subsiding.\n";
                }
            }
                        // Advanced events
            if(value.compare("blizzard")==0) {
                if(wind && cold) {
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
                    std::cout << "There are no aliens to fight.\n";
                }
                }
            } if(value.compare("warGold") == 0) {
                if(gun && gold && greed) {
                    if(people != 0) {
                        std::cout << "The advanced civilization wonders why the times of old faught over the golden rock\n";
                        
                    }
                }
            } if(value.compare("heatStroke")==0) {
                if(humid && hot) {
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
                        std::cout << "TThe civilization cannot compreehend why religion caused war in the olden times.\n";
    
                    }
                }
            } if(value.compare("plagueDeaths")==0) {
                if(plague && cold) {
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
                if(Aliens && dark) {
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
                    std::cout << "There are no aliens here.\n";
                    
                }
            } if(value.compare("GunLove")==0) {
                if(love && gun) {
                std::cout << "People sure love their guns.\n";
                people -= 1;
                if(people < 0) {
                    people =0 ;
                }
                }
            }
            
            }

        bool Modern::endHandler(std::string value) {
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
            if(religion && love && cold) {
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
            if(people == 2 && plague && humid && hot) {
                std::cout << "Time to buy toilet paper and milk.\n";
                return true;
            }
        } else if(value.compare("warming")==0) {
            if(humid && wind && hot) {
                std::cout << "The world is slowing warming up. This may be a problem, but not the nomads problem.\n";
            return true;
            }
        } else if(value.compare("gone")==0) {
            if(people == 0 && cold && dark) {
                std::cout << "The world may be vast, but there is no one here. The nomads are gone.\n";
                return true;
            }
        }
        return false;
    }
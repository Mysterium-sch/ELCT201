#include "Modern.h"

    Modern::Modern() {
        people = 3;
    }

    int Modern::getPeople() {
        return people;
    }

    void Modern::eventHandler(string value) {
            if(value.compare("volcano")==0) {
            cout << "The volcano devastated the modern people and wiped out their civilization.\n";
            people =0;
        }
            if(value.compare("love")==0) {
                if(people == 0) {
                    cout << "There is no one here to be loved.\n";
                } else {
                    love = !love;
                    if(love) {
                        cout << "Love is in the air.\n";
                        if(people != 3) {
                            people +=1;
                        }
                    } else {
                        cout << "The season of love is over.\n";
                    }
                    
                }
            }
            if(value.compare("wind")==0) {
                wind=!wind;
                if(wind) {
                    cout << "Its getting pretty windy.\n";
                } else {
                    cout << "The wind has died down.\n";
                }
            }if(value.compare("greed")==0) {
                greed = !greed;
                if(greed) {
                cout << "People have started to get greedy.\n";
                } else {
                    cout << "The people's greed is dying down.\n";
                }
            }if(value.compare("humid")==0) {
                humid = !humid;
                if(humid)
                    cout << "The humid has gotten worse.\n";
                else {
                    cout << "The humidity is dying down.\n";
                }

            } if(value.compare("Gold")==0) {
                if(!gold) {
                gold = true;
                cout << "The advanced civilization has no need for gold.\n";
                }
            } if(value.compare("gun")==0) {
                gun = true;
                cout << "Gun powder has been discovered.\n";

            } if(value.compare("religion")==0) {
                religion = !religion;
                cout << "The advanced civilization is beyond having faith in religion.\n";

            } if(value.compare("plague")==0) {
                    plague = !plague;
                    if(plague) {
                        cout << "A mysterious cough is going around.\n";
                    } else {
                        cout << "A cure was found for the disease.\n";
                    }
            } if(value.compare("aliens")==0) {
                    Aliens = !Aliens;
                    cout << "These modern men do not belivie in fly saucers.\n";
            } if(value.compare("renaissance")==0) {
                renaissance = !renaissance;
                if(renaissance) {
                    cout << "Music and art has become increasing popular.\n";
                } else {
                    cout << "People are becomming less and less creative.\n";
                }
            }
            if(value.compare("cold")==0) {
                cold = !cold;
                if(cold) {
                    cout << "The world is becoming very cold.\n";
                } else {
                    cout << "The frost is melting away.\n";
                }
            } if(value.compare("hot")==0) {
                hot = !hot;
                if(hot) {
                    cout << "The world is becoming increasingly warm.\n";
                } else {
                    cout << "The heat is dying down.\n";
                }
            } if(value.compare("dark")==0) {
                dark = !dark;
                if(dark) {
                    cout << "The world is getting dark.\n";
                } else {
                    cout << "The darkness is subsiding.\n";
                }
            } if(value.compare("light")==0) {
                light = !light;
                if(light) {
                    cout << "The world is very bright.\n";
                } else {
                    cout << "The brightness is subsiding.\n";
                }
            }
                        // Advanced events
            if(value.compare("blizzard")==0) {
                if(wind && cold) {
                    cout << "A blizzard has struck the civilization.\n";
                    if(people != 0) {
                        people -= 1;
                    } else {
                        cout << "but everyone is already gone...\n";
                    }
                }
            } if(value.compare("warAlien") == 0) {
                if(gun && Aliens && greed) {
                    if(people != 0) {
                    cout << "There are no aliens to fight.\n";
                }
                }
            } if(value.compare("warGold") == 0) {
                if(gun && gold && greed) {
                    if(people != 0) {
                        cout << "The advanced civilization wonders why the times of old faught over the golden rock\n";
                        
                    }
                }
            } if(value.compare("heatStroke")==0) {
                if(humid && hot) {
                    cout << "The civilization is unprepared for the heat.\n";
                    if(people != 0) {
                        people -= 1;
                    } else {
                        cout << "but everyone is already gone...\n";
                    }
                }
            } if(value.compare("warReligion")==0) {
                if(gun && religion) {
                    if(people != 0) {
                        cout << "TThe civilization cannot compreehend why religion caused war in the olden times.\n";
    
                    }
                }
            } if(value.compare("plagueDeaths")==0) {
                if(plague && cold) {
                    cout << "The sickness is worstening during these harsh winters.\n";
                    if(people != 0) {
                        people -= 1;
                    } else {
                        cout << "but everyone is already gone...\n";
                    }
                }
            } if(value.compare("boon")==0) {
                if(renaissance && love) {
                    cout << "A celebration of life is happening as people immegrate to this civilization\n";
                    if(people != 3 || people != 2) {
                        people += 2;
                    }
                }
            } if(value.compare("abducted")==0) {
                if(Aliens && dark) {
                    cout << "Someone has gone missing, the Aliens claim the didn't do it.\n";
                    people -= 1;
                    if (people <= 0) {
                        people =0;
                    }
                }
            } if (value.compare("hope")==0) {
                if(religion && plague) {
                    cout << "God will cure this plague.\n";
                    people -= 1;
                    if (people <= 0) {
                        people = 0;
                    }
                }
            } if(value.compare("AlienPlague")==0) {
                if(Aliens && plague) {
                    cout << "There are no aliens here.\n";
                    
                }
            } if(value.compare("GunLove")==0) {
                if(love && gun) {
                cout << "People sure love their guns.\n";
                people -= 1;
                if(people < 0) {
                    people =0 ;
                }
                }
            }
            
            }

        bool Modern::endHandler(string value) {
        if(value.compare("peace") == 0) {
            if(people == 3 && love && renaissance) {
                cout << "This modern civilization is in harmony and peace.\n";
                return true;
            }

        }else if(value.compare("god")==0) {
            if(love && Aliens){
            cout << "The trial that the aliens brough made the modern civilization believe even stronger in their god.\n";
            return true;
            }

        } else if(value.compare("christmas")==0) {
            if(religion && love && cold) {
            cout << "Its a beautiful snowy day and the modern covilization is giving gifts to each other.\n";
            return true;
            }

        } else if(value.compare("cultural")==0) {
            cout << "The modern civilization has vast ties to their culture and refuses to change.\n";
            return false;
        } else if(value.compare("nothing")==0) {
            if(people == 0 && Aliens) {
                cout << "The world may be vast, but there is no one here. The nomads are gone.\n";
                return true;
            }
        } else if(value.compare("Greedy")==0) {
            if (people == 1 && gold && gun && greed) {
                cout << "The modern civilization really likes their gold.\n";
                return true;
            }

        } else if(value.compare("before")==0) {
            if(people == 2 && plague && humid && hot) {
                cout << "Time to buy toilet paper and milk.\n";
                return true;
            }
        } else if(value.compare("warming")==0) {
            if(humid && wind && hot) {
                cout << "The world is slowing warming up. This may be a problem, but not the nomads problem.\n";
            return true;
            }
        } else if(value.compare("gone")==0) {
            if(people == 0 && cold && dark) {
                cout << "The world may be vast, but there is no one here. The nomads are gone.\n";
                return true;
            }
        }
        return false;
    }

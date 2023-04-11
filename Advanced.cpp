// Copyright Team 5
#include "Advanced.h"

    Advanced::Advanced() {
        people = 3;
    }

    int Advanced::getPeople() {
        return people;
    }

    void Advanced::eventHandler(string value) {
            if(value.compare("volcano")==0) {
            cout << "The volcano devastated the advanced people and wiped out their civilization.\n";
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
                wind = !wind;
                if(wind) {
                    cout << "Its getting pretty windy.\n";
                } else {
                    cout << "The wind has died down.\n";
                }
            }if(value.compare("greed")==0) {
                greed = !greed;
                cout << "The advanced civilization is immune to the powers that greed holds.\n";
            }if(value.compare("humid")==0) {
                humid = !humid;
                if(humid)
                    cout << "The humid has gotten worse.\n";
                else {
                    cout << "The humidity is dying down.\n";
                }

            } if(value.compare("Gold")==0) {
                gold = true;
                cout << "Theres gold in these parts.\n";
            } if(value.compare("gun")==0) {
                gun = true;
                cout << "Gun powder has been discovered.\n";

            } if(value.compare("religion")==0) {
                religion = !religion;
                if(religion) {
                    cout << "The people are becoming spiritual.\n";
                } else {
                    cout << "The people are losing their faith.\n";
                }

            } if(value.compare("plague")==0) {
                    plague = !plague;
                    if(plague) {
                        cout << "A mysterious cough is going around.\n";
                    } else {
                        cout << "A cure was found for the disease.\n";
                    }
            } if(value.compare("aliens")==0) {
                    Aliens = !Aliens;
                    if(Aliens) {
                        cout << "Mysterious space men have appeared.\n";
                    } else {
                        cout << "The space men have left.\n";
                    }
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
                    if(people != 00) {
                    cout << "This advanced civilization admires the aliens technology and plans to work harder to acheivie such feats.\n";
                }
                }
            } if(value.compare("warGold") == 0) {
                if(gun && gold && greed) {
                    if(people != 0) {
                        cout << "The civilization has started a war over the gold!\n";
                        people -= 1;
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
                        cout << "TThe civilization can't come to consenses on who's religion is right.\n";
                        people -= 1;
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
                    cout << "The advanced civilization does not belevie 'god' will cure their plague.\n";
                }
            } if(value.compare("AlienPlague")==0) {
                if(Aliens && plague) {
                    cout << "Everyone started getting weird bumps after the aliens arrived...\n";
                    people -= 2;
                    if(people < 0) {
                        people = 0;
                    }
                }
            } if(value.compare("GunLove")==0) {
                if(gun && love) {
                cout << "People sure love their guns.\n";
                people -= 1;
                if(people < 0) {
                    people =0 ;
                }
                }
            }
    }
            
    
        bool Advanced::endHandler(string value) {
        if(value.compare("peace") == 0) {
            if(people == 3 && love && renaissance) {
                cout << "This advanced civilization is in harmony and peace.\n";
                return true;
            }

        }else if(value.compare("god")==0) {
            cout << "This advanced civilization scoffs at the idea of god as they are beyond religion.\n";
            return false;

        } else if(value.compare("christmas")==0) {
            cout << "This advanced civilization scoffs at the idea of christmas as they are beyond religion.\n";
            return false;

        } else if(value.compare("cultural")==0) {
            if(religion && renaissance && Aliens) {
            cout << "The aliens taught the advanced civilization to grow and accept old concepts. Culture is now being developed.\n";
            return true;
                        }

        } else if(value.compare("nothing")==0) {
            if(people == 0 && Aliens) {
                cout << "The world may be vast, but there is no one here. The nomads are gone.\n";
                return true;
            }
        } else if(value.compare("Greedy")==0) {
             cout << "This advanced civilization scoffs at the idea of greed as they are beyond selfishness.\n";
            return false;

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

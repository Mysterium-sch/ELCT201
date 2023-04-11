// Copyright Team 5
#include "death.h"

    Death::Death(string s) {
        people = 3;
        world = s;
    }

    int Death::getPeople() {
        return people;
    }

    string Death::getType() {
        return world;
    }

    void Death::eventHandler(string value) {
        string ouput;
            if(value.compare("volcano")==0) {
            ouput = "The volcano devastated the Death people and wiped out their civilization.\n";
            people =0;
        }
            if(value.compare("love")==0) {
                if(people == 0) {
                    ouput = "There is no one here to be loved.\n";
                } else {
                    love = !love;
                    if(love) {
                        ouput = "Love is in the air.\n";
                        if(people != 3) {
                            people +=1;
                        }
                    } else {
                        ouput = "The season of love is over.\n";
                    }
                    
                }
            }
            if(value.compare("wind")==0) {
                wind = !wind;
                if(wind) {
                    ouput = "Its getting pretty windy.\n";
                } else {
                    ouput = "The wind has died down.\n";
                }
            }if(value.compare("greed")==0) {
                greed = !greed;
                ouput = "The Death civilization is immune to the powers that greed holds.\n";
            }if(value.compare("humid")==0) {
                humid = !humid;
                if(humid)
                    ouput = "The humid has gotten worse.\n";
                else {
                    ouput = "The humidity is dying down.\n";
                }

            } if(value.compare("Gold")==0) {
                gold = true;
                ouput = "Theres gold in these parts.\n";
            } if(value.compare("gun")==0) {
                gun = true;
                ouput = "Gun powder has been discovered.\n";

            } if(value.compare("religion")==0) {
                religion = !religion;
                if(religion) {
                    ouput = "The people are becoming spiritual.\n";
                } else {
                    ouput = "The people are losing their faith.\n";
                }

            } if(value.compare("plague")==0) {
                    plague = !plague;
                    if(plague) {
                        ouput = "A mysterious cough is going around.\n";
                    } else {
                        ouput = "A cure was found for the disease.\n";
                    }
            } if(value.compare("aliens")==0) {
                    Aliens = !Aliens;
                    if(Aliens) {
                        ouput = "Mysterious space men have appeared.\n";
                    } else {
                        ouput = "The space men have left.\n";
                    }
            } if(value.compare("renaissance")==0) {
                renaissance = !renaissance;
                if(renaissance) {
                    ouput = "Music and art has become increasing popular.\n";
                } else {
                    ouput = "People are becomming less and less creative.\n";
                }
            }
            if(value.compare("cold")==0) {
                cold = !cold;
                if(cold) {
                    ouput = "The world is becoming very cold.\n";
                } else {
                    ouput = "The frost is melting away.\n";
                }
            } if(value.compare("hot")==0) {
                hot = !hot;
                if(hot) {
                    ouput = "The world is becoming increasingly warm.\n";
                } else {
                    ouput = "The heat is dying down.\n";
                }
            } if(value.compare("dark")==0) {
                dark = !dark;
                if(dark) {
                    ouput = "The world is getting dark.\n";
                } else {
                    ouput = "The darkness is subsiding.\n";
                }
            } if(value.compare("light")==0) {
                light = !light;
                if(light) {
                    ouput = "The world is very bright.\n";
                } else {
                    ouput = "The brightness is subsiding.\n";
                }
            }
            // Death events
            if(value.compare("blizzard")==0) {
                if(wind && cold) {
                    ouput = "A blizzard has struck the civilization.\n";
                    if(people != 0) {
                        people -= 1;
                    } else {
                        ouput = "but everyone is already gone...\n";
                    }
                }
            } if(value.compare("warAlien") == 0) {
                if(gun && Aliens && greed) {
                    if(people != 00) {
                    ouput = "This Death civilization admires the aliens technology and plans to work harder to acheivie such feats.\n";
                }
                }
            } if(value.compare("warGold") == 0) {
                if(gun && gold && greed) {
                    if(people != 0) {
                        ouput = "The civilization has started a war over the gold!\n";
                        people -= 1;
                    }
                }
            } if(value.compare("heatStroke")==0) {
                if(humid && hot) {
                    ouput = "The civilization is unprepared for the heat.\n";
                    if(people != 0) {
                        people -= 1;
                    } else {
                        ouput = "but everyone is already gone...\n";
                    }
                }
            } if(value.compare("warReligion")==0) {
                if(gun && religion) {
                    if(people != 0) {
                        ouput = "TThe civilization can't come to consenses on who's religion is right.\n";
                        people -= 1;
                    }
                }
            } if(value.compare("plagueDeaths")==0) {
                if(plague && cold) {
                    ouput = "The sickness is worstening during these harsh winters.\n";
                    if(people != 0) {
                        people -= 1;
                    } else {
                        ouput = "but everyone is already gone...\n";
                    }
                }
            } if(value.compare("boon")==0) {
                if(renaissance && love) {
                    ouput = "A celebration of life is happening as people immegrate to this civilization\n";
                    if(people != 3 || people != 2) {
                        people += 2;
                    }
                }
            } if(value.compare("abducted")==0) {
                if(Aliens && dark) {
                    ouput = "Someone has gone missing, the Aliens claim the didn't do it.\n";
                    people -= 1;
                    if (people <= 0) {
                        people =0;
                    }
                }
            } if (value.compare("hope")==0) {
                if(religion && plague) {
                    ouput = "The Death civilization does not belevie 'god' will cure their plague.\n";
                }
            } if(value.compare("AlienPlague")==0) {
                if(Aliens && plague) {
                    ouput = "Everyone started getting weird bumps after the aliens arrived...\n";
                    people -= 2;
                    if(people < 0) {
                        people = 0;
                    }
                }
            } if(value.compare("GunLove")==0) {
                if(gun && love) {
                ouput = "People sure love their guns.\n";
                people -= 1;
                if(people < 0) {
                    people =0 ;
                }
                }
            }

        cout << ouput;
    }
            
    
        bool Death::endHandler(string value) {
            string output;
        if(value.compare("peace") == 0) {
            if(people == 3 && love && renaissance) {
                ouput = "This Death civilization is in harmony and peace.\n";
                return true;
            }

        }else if(value.compare("god")==0) {
            ouput = "This Death civilization scoffs at the idea of god as they are beyond religion.\n";
            return false;

        } else if(value.compare("christmas")==0) {
            ouput = "This Death civilization scoffs at the idea of christmas as they are beyond religion.\n";
            return false;

        } else if(value.compare("cultural")==0) {
            if(religion && renaissance && Aliens) {
            ouput = "The aliens taught the Death civilization to grow and accept old concepts. Culture is now being developed.\n";
            return true;
                        }

        } else if(value.compare("nothing")==0) {
            if(people == 0 && Aliens) {
                ouput = "The world may be vast, but there is no one here. The nomads are gone.\n";
                return true;
            }
        } else if(value.compare("Greedy")==0) {
             ouput = "This Death civilization scoffs at the idea of greed as they are beyond selfishness.\n";
            return false;

        } else if(value.compare("warming")==0) {
            if(humid && wind && hot) {
            ouput = "The world is slowing warming up. This may be a problem, but not the nomads problem.\n";
            return true;
            }
        } else if(value.compare("gone")==0) {
            if(people == 0 && cold && dark) {
                ouput = "The world may be vast, but there is no one here. The nomads are gone.\n";
                return true;
            }
        }
        cout << output;
        return false;
    }
// Copyright Team 5
#include "death.h"
#include "mbed.h"

    Death::Death(string s) {
        people = 3;
        world = s;
        love = 0; wind=0; greed=0; religion=0; gun=0; plague=0; Aliens=0; cold=0; dark=0; hot=0; light = 0;
        ending = 0;
    }

    int Death::getPeople() {
        return people;
    }

    string Death::getType() {
        return world;
    }

    void Death::eventHandler(string value) {
        string output;
        if(ending > 0) {
            return;
        }
            if(value.compare("volcano")==0) {
            cout << "\n\rThe volcano devastated The" + world + " people and wiped out their civilization.\n";
            people =0;
        }
            else if(value.compare("love")==0) {
                if(people == 0) {
                    cout << "\n\rThere is no one here to be loved.\n";
                } else {
                    if(love==0){love=1;}else{love=0;}
                    if(love==1) {
                        cout << "\n\rLove is in the air.\n";
                        if(people != 3) {
                            people +=1;
                        }
                    } else {
                        cout << "\n\rThe season of love is over.\n";
                    }
                    
                }
                                if(people<2 && love==1) {
                    cout << "\n\rA celebration of life is happening as people immegrate to this civilization\n";
                    if(people != 3 || people != 2) {
                        people += 2;
                    }
                }
                                if(gun + love==2) {
                cout << "\n\rPeople sure love their guns.\n";
                people -= 1;
                if(people < 0) {
                    people =0 ;
                }
                }
            }
            else if(value.compare("wind")==0) {
                if(wind ==0){wind =1;}else{wind =0;}
                if(wind == 1) {
                    cout << "\n\rIts getting pretty windy.\n";
                } else {
                    cout << "\n\rThe wind has died down.\n";
                }
                if(wind+cold == 2) {
                    if(world.compare("nomad")==0) {
                        cout << "\n\rThe nomads noticed the weather changing and moved to somewhere warmer.\n";
                    } else {
                    cout << "\n\rA blizzard has struck the civilization.\n";
                    if(people != 0) {
                        people -= 1;
                    } else {
                        cout << "\n\rbut everyone is already gone...\n";
                    }
                    }
                }
                if(wind + hot==2) {
                    if(world.compare("nomad")==0) {
                        cout <<  "\n\rThe nomads noticed the weather getting warmer and moved north.\n";
                    } else {
                    cout << "\n\rThe civilization is unprepared for the heat.\n";
                    if(people != 0) {
                        people -= 1;
                    } else {
                        cout << "\n\rbut everyone is already gone...\n";
                    }
                    }
                }
            }else if(value.compare("greed")==0) {
                if(greed==0){greed=1;}else{greed=0;}
                if(world.compare("advanced")== 0) {
                    cout << "\n\rThe " + world + " civilization is immune to the powers that greed holds.\n";
                } else {
                    cout << "\n\rPeople are becoming very envious of others success and belonings\n";
                }
                if(gun + Aliens + greed==3) {
                    if(people != 0) {
                    if(world.compare("advanced")== 0) {
                    cout << "\n\rThis " + world + " civilization admires the aliens technology and plans to work harder to acheivie such feats.\n";
                } else if (world.compare("nomad")==0) {
                    cout << "\n\rThe civilization yearned for the alien's tech, which didn't work out for them.\n";
                    people -= 1;
                    if(people <= 0) {
                        people = 0;
                    }
                } else {
                    cout << "\n\rThere are no aliens to fight.\n";
                }
                }
                }

            }else if(value.compare("gun")==0) {
                gun = 1;
                cout << "\n\rGun powder has been discovered.\n";
                if(gun + Aliens + greed==3) {
                    if(people != 0) {
                    if(world.compare("advanced")== 0) {
                    cout << "\n\rThis " + world + " civilization admires the aliens technology and plans to work harder to acheivie such feats.\n";
                } else if (world.compare("nomad")==0) {
                    cout << "\n\rThe civilization yearned for the alien's tech, which didn't work out for them.\n";
                    people -= 1;
                    if(people <= 0) {
                        people = 0;
                    }
                } else {
                    cout << "\n\rThere are no aliens to fight.\n";
                }
                }
                }
                 if(gun + religion==2) {
                    if(world.compare("advanced")==0) {
                        cout << "\n\rThe advanced civilization has agreed religion is dumb.\n";
                    }
                    if(people != 0) {
                        cout << "\n\rThe civilization can't come to consenses on who's religion is right.\n";
                        people -= 1;
                    }
                }
            }else if(value.compare("religion")==0) {
                if(religion ==0){religion =1;}else{religion =0;}
                if(religion==1) {
                    cout << "\n\rThe people are becoming spiritual.\n";
                        if(world.compare("advanced")==0) {
                        cout << "\n\rbut the advanced civiulation is past the point of needing a god\n";
                    }
                } else {
                    cout << "\n\rThe people are losing their faith.\n";
                }
                if(gun + religion==2) {
                    if(world.compare("advanced")==0) {
                        cout << "\n\rThe advanced civilization has agreed religion is dumb.\n";
                    }
                    if(people != 0) {
                        cout << "\n\rThe civilization can't come to consenses on who's religion is right.\n";
                        people -= 1;
                    }
                }
                                if(gun + love==2) {
                cout << "\n\rPeople sure love their guns.\n";
                people -= 1;
                if(people < 0) {
                    people =0 ;
                }
                }

            }else if(value.compare("plague")==0) {
                    if(plague==0){plague=1;}else{plague=0;}
                    if(plague==1) {
                        cout << "\n\rA mysterious cough is going around.\n";
                    } else {
                        cout << "\n\rA cure was found for the disease.\n";
                    }
                    if(plague + cold==2) {
                    if(world.compare("nomad")==0) {
                        cout << "\n\rThe nomads move before the cold sets in so plague does not spread as fast.\n";
                    } else {
                    cout << "\n\rThe sickness is worstening during these harsh winters.\n";
                    if(people != 0) {
                        people -= 1;
                    } else {
                        cout << "\n\rbut everyone is already gone...\n";
                    }
                    }
                }
                if(Aliens + plague==2) {
                    if(world.compare("modern")==0) {
                        cout << "\n\rThere are no aliens here.\n";
                    } else {
                    cout << "\n\rEveryone started getting weird bumps after the aliens arrived...\n";
                    people -= 2;
                    if(people < 0) {
                        people = 0;
                    }
                }
                }
            }else if(value.compare("alien")==0) {
                    if(Aliens==0){Aliens=1;}else{Aliens=0;}
                    if(Aliens==1) {
                        cout << "\n\rMysterious space men have appeared.\n";
                        if(world.compare("modern")==0) {
                            cout << "\n\rBut the modern civulization does not belivie in such things.\n";
                        }
                    } else {
                        cout << "\n\rThe space men have left.\n";
                    }
                                    if(gun + Aliens + greed==3) {
                    if(people != 0) {
                    if(world.compare("advanced")== 0) {
                    cout << "\n\rThis " + world + " civilization admires the aliens technology and plans to work harder to acheivie such feats.\n";
                } else if (world.compare("nomad")==0) {
                    cout << "\n\rThe civilization yearned for the alien's tech, which didn't work out for them.\n";
                    people -= 1;
                    if(people <= 0) {
                        people = 0;
                    }
                } else {
                    cout << "\n\rThere are no aliens to fight.\n";
                }
                }
                }
                
                if(Aliens + dark==2) {
                    if(world.compare("modern")==0) {
                        cout << "\n\rSomeone has gone missing, the Aliens claim the didn't do it.\n";
                    } else {
                    cout << "\n\rSomeone has gone missing, the Aliens claim the didn't do it.\n";
                    } 
                    people -= 1;
                    if (people <= 0) {
                        people =0;
                    }
                }
                if(Aliens + plague==2) {
                    if(world.compare("modern")==0) {
                        cout << "\n\rThere are no aliens here.\n";
                    } else {
                    cout << "\n\rEveryone started getting weird bumps after the aliens arrived...\n";
                    people -= 2;
                    if(people < 0) {
                        people = 0;
                    }
                }
                }
            } else if(value.compare("cold")==0) {
               if(cold<0) {
                    cold = 0;
                }
                cold+=1;
                if(cold==1) {
                    cout << "\n\rThe world is becoming very cold.\n";
                }
                if(wind+cold == 2) {
                    if(world.compare("nomad")==0) {
                        cout << "\n\rThe nomads noticed the weather changing and moved to somewhere warmer.\n";
                    } else {
                    cout << "\n\rA blizzard has struck the civilization.\n";
                    if(people != 0) {
                        people -= 1;
                    } else {
                        cout << "\n\rbut everyone is already gone...\n";
                    }
                    }
                }
                if(plague + cold==2) {
                    if(world.compare("nomad")==0) {
                        cout << "\n\rThe nomads move before the cold sets in so plague does not spread as fast.\n";
                    } else {
                    cout << "\n\rThe sickness is worstening during these harsh winters.\n";
                    if(people != 0) {
                        people -= 1;
                    } else {
                        cout << "\n\rbut everyone is already gone...\n";
                    }
                    }
                }
            }else if(value.compare("hot")==0) {
                if(hot<0) {
                    hot = 0;
                }
                hot+=1;
                if(hot==1) {
                    cout << "\n\rThe world is becoming increasingly warm.\n";
                }
                if(wind + hot==2) {
                    if(world.compare("nomad")==0) {
                        cout <<  "\n\rThe nomads noticed the weather getting warmer and moved north.\n";
                    } else {
                    cout << "\n\rThe civilization is unprepared for the heat.\n";
                    if(people != 0) {
                        people -= 1;
                    } else {
                        cout << "\n\rbut everyone is already gone...\n";
                    }
                    }
                }
            
            
            } else if(value.compare("neither1")==0){
                dark -= 1;
                light -= 1;
                if(light == 0 || dark == 0) {
                cout << "\n\rThe world's light is in perfect harmony.\n";
                }
            }else if(value.compare("neither2")==0){
                cold -= 1;
                hot -= 1;
                if(cold== 0 || hot==0) {
                cout << "\n\rThe world's temperature is in perfect harmony.\n";
                }
            }else if(value.compare("dark")==0) {
                if(dark<0) {
                    dark = 0;
                }
                dark+=1;
                if(dark==1) {
                cout << "\n\rThe world is getting dark.\n";
                }
                if(Aliens + dark==2) {
                    if(world.compare("modern")==0) {
                        cout << "\n\rSomeone has gone missing, the Aliens claim the didn't do it.\n";
                    } else {
                    cout << "\n\rSomeone has gone missing, the Aliens claim the didn't do it.\n";
                    } 
                    people -= 1;
                    if (people <= 0) {
                        people =0;
                    }
                }
            }else if(value.compare("light")==0) {
                if(light<0) {
                    light = 0;
                }
                light+=1;
                if(light==1) {
                cout << "\n\rThe world is very bright.\n";
                }
}
    }
            
    
        bool Death::endHandler(string value) {
            if(ending<1) {
            if(value.compare("beachday")==0) {
                if(light + hot + love ==3 && people == 3) {
                    cout << "\n\rThis " + world + " is having a lovely day at the beach. The weather is perfect for it.\n";
                    ending = 1;
}
        } else if(value.compare("christmas")==0) {
            if(cold+love+religion==3) {
            if(world.compare("advanced")==0) {
            cout << "\n\rThis " + world + " civilization scoffs at the idea of christmas as they are beyond religion.\n";
            ending = 0;
            } else {
                cout << "\n\rIts a beautiful snowy day and the " + world + " civilization is giving gifts to each other.\n";
                ending = 1;
            }
            }

        } else if(value.compare("cultural")==0) {
            if(religion + love + Aliens==3) {
            if(world.compare("advanced")==0) {
            cout << "\n\rThe aliens taught The " + world + " civilization to grow and accept old concepts. Culture is now being developed.\n";
            ending = 1;
            } else if (world.compare("modern")==0) {
                cout << "\n\rThe modern civilization has vast ties to their culture and refuses to change.\n";
                ending = 0;
            } else {
                cout << "\n\rThe nomadic civilization moves to often to develop their culture.\n";
                ending = 0;
            }
                        }
        } else if(value.compare("nothing")==0) {
            if(people == 0 && Aliens==1) {
                cout << "\n\rThe world may be vast, but there is no one here. The "+ world +" people are gone.\n";
                ending = 1;
            }
        } else if(value.compare("warming")==0) {
            if(wind + hot==2 && people < 2) {
            cout << "\n\rThe world is slowing warming up. This may be a problem, but not the " + world + "s problem.\n";
            ending = 1;
            }
        } else if(value.compare("gone")==0) {
            if(people == 0 && cold + dark==2) {
                cout << "\n\rThe world may be vast, but there is no one here. The " << world << "s` are gone.\n";
                ending = 1;
            }
        }
            }
        return (ending==1);
    }

// Copyright Team 5
#include "death.h"
#include "mbed.h"

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
        string output;
            if(value.compare("volcano")==0) {
            output = "The volcano devastated The" + world + " people and wiped out their civilization.\n";
            people =0;
        }
            if(value.compare("love")==0) {
                if(people == 0) {
                    output = "There is no one here to be loved.\n";
                } else {
                    love = !love;
                    if(love) {
                        output = "Love is in the air.\n";
                        if(people != 3) {
                            people +=1;
                        }
                    } else {
                        output = "The season of love is over.\n";
                    }
                    
                }
            }
            if(value.compare("wind")==0) {
                wind = !wind;
                if(wind) {
                    output = "Its getting pretty windy.\n";
                } else {
                    output = "The wind has died down.\n";
                }
            }if(value.compare("greed")==0) {
                greed = !greed;
                output = "The" + world + " civilization is immune to the powers that greed holds.\n";

            } if(value.compare("gun")==0) {
                gun = true;
                output = "Gun powder has been discovered.\n";

            } if(value.compare("religion")==0) {
                religion = !religion;
                if(religion) {
                    output = "The people are becoming spiritual.\n";
                } else {
                    output = "The people are losing their faith.\n";
                }

            } if(value.compare("plague")==0) {
                    plague = !plague;
                    if(plague) {
                        output = "A mysterious cough is going around.\n";
                    } else {
                        output = "A cure was found for the disease.\n";
                    }
            } if(value.compare("aliens")==0) {
                    Aliens = !Aliens;
                    if(Aliens) {
                        output = "Mysterious space men have appeared.\n";
                    } else {
                        output = "The space men have left.\n";
                    }
            }
            if(value.compare("cold")==0) {
                cold = !cold;
                if(cold) {
                    output = "The world is becoming very cold.\n";
                } else {
                    output = "The frost is melting away.\n";
                }
            } if(value.compare("hot")==0) {
                hot = !hot;
                if(hot) {
                    output = "The world is becoming increasingly warm.\n";
                } else {
                    output = "The heat is dying down.\n";
                }
            } if(value.compare("dark")==0) {
                dark = !dark;
                if(dark) {
                    output = "The world is getting dark.\n";
                } else {
                    output = "The darkness is subsiding.\n";
                }
            } if(value.compare("light")==0) {
                light = !light;
                if(light) {
                    output = "The world is very bright.\n";
                } else {
                    output = "The brightness is subsiding.\n";
                }
            }
            
            // Death events
                if(wind && cold) {
                    if(world.compare("nomad")==0) {
                        output += "The nomads noticed the weather changing and moved to somewhere warmer.\n";
                    } else {
                    output += "A blizzard has struck the civilization.\n";
                    if(people != 0) {
                        people -= 1;
                    } else {
                        output = "but everyone is already gone...\n";
                    }
                    }
                }
                if(gun && Aliens && greed) {
                    if(people != 0) {
                    if(world.compare("advanced")== 0) {
                    output += "This " + world + " civilization admires the aliens technology and plans to work harder to acheivie such feats.\n";
                } else if (world.compare("nomad")==0) {
                    output += "The civilization yearned for the alien's tech, which didn't work out for them.\n";
                    people -= 1;
                    if(people <= 0) {
                        people = 0;
                    }
                } else {
                    output += "There are no aliens to fight.\n";
                }
                }
                }
                if(wind && hot) {
                    if(world.compare("nomad")==0) {
                        output +=  "The nomads noticed the weather getting warmer and moved north.\n";
                    } else {
                    output += "The civilization is unprepared for the heat.\n";
                    if(people != 0) {
                        people -= 1;
                    } else {
                        output += "but everyone is already gone...\n";
                    }
                    }
                }
                if(gun && religion) {
                    if(world.compare("advanced")==0) {
                        output += "The advanced civilization has agreed religion is dumb.\n";
                    }
                    if(people != 0) {
                        output += "The civilization can't come to consenses on who's religion is right.\n";
                        people -= 1;
                    }
                }
                if(plague && cold) {
                    if(world.compare("nomad")==0) {
                        output += "The nomads move before the cold sets in so plague does not spread as fast.\n";
                    } else {
                    output += "The sickness is worstening during these harsh winters.\n";
                    if(people != 0) {
                        people -= 1;
                    } else {
                        output += "but everyone is already gone...\n";
                    }
                    }
                }
                if(people<2 && love) {
                    output += "A celebration of life is happening as people immegrate to this civilization\n";
                    if(people != 3 || people != 2) {
                        people += 2;
                    }
                }
                if(Aliens && dark) {
                    if(world.compare("modern")==0) {
                        output += "Someone has gone missing, the Aliens claim the didn't do it.\n";
                    } else {
                    output += "Someone has gone missing, the Aliens claim the didn't do it.\n";
                    } 
                    people -= 1;
                    if (people <= 0) {
                        people =0;
                    }
                }
                if(Aliens && plague) {
                    if(world.compare("modern")==0) {
                        output += "There are no aliens here.\n";
                    } else {
                    output += "Everyone started getting weird bumps after the aliens arrived...\n";
                    people -= 2;
                    if(people < 0) {
                        people = 0;
                    }
                }
                }
                if(gun && love) {
                output += "People sure love their guns.\n";
                people -= 1;
                if(people < 0) {
                    people =0 ;
                }
                }

        cout << output;
    }
            
    
        bool Death::endHandler(string value) {
            string output;
            bool ending;
            if(value.compare("beachday")) {
                if(light && hot && love && people == 3) {
                    output = "This " + world + " is having a lovely day at the beach. The weather is perfect for it.\n";
                    ending = true;
}
        } else if(value.compare("christmas")==0) {
            if(world.compare("advanced")==0) {
            output = "This " + world + " civilization scoffs at the idea of christmas as they are beyond religion.\n";
            ending = false;
            } else {
                output = "Its a beautiful snowy day and the " + world + " civilization is giving gifts to each other.\n";
                ending = true;
            }

        } else if(value.compare("cultural")==0) {
            if(religion && love && Aliens) {
            if(world.compare("advanced")==0) {
            output = "The aliens taught The" + world + " civilization to grow and accept old concepts. Culture is now being developed.\n";
            ending = true;
            } else if (world.compare("modern")==0) {
                output = "The modern civilization has vast ties to their culture and refuses to change.\n";
                ending = false;
            } else {
                output = "The nomadic civilization moves to often to develop their culture.\n";
                ending = false;
            }
                        }
        } else if(value.compare("nothing")==0) {
            if(people == 0 && Aliens) {
                output = "The world may be vast, but there is no one here. The "+ world +" people are gone.\n";
                ending = true;
            }
        } else if(value.compare("warming")==0) {
            if(wind && hot && people < 2) {
            output = "The world is slowing warming up. This may be a problem, but not the " + world + "s problem.\n";
            ending = true;
            }
        } else if(value.compare("gone")==0) {
            if(people == 0 && cold && dark) {
                output = "The world may be vast, but there is no one here. The nomads are gone.\n";
                ending = true;
            }
        }
        cout << output;
        return ending;
    }

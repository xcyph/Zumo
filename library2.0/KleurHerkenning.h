#ifndef KleurHerkenning_H
#define KleurHerkenning_H

#include <Zumo32U4.h>
#include <Wire.h>

class KleurHerkenning {
  public:
    KleurHerkenning();
    void leesWaardes();
    bool groen();
    bool bruin();
    bool grijs();
  private:
    int gem;
    LijnHerkenning LijnHer;

};

#endif

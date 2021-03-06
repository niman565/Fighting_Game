#include "Stance.cpp"

class Fighter {
    private:
        Stance* stances[7];
        Stance* currentStance;
        bool blockBonusOn;
        int blockBonus;
        bool attackBonusOn;
        int attackBonus;
        std::string name;
        int chanceOfAttack;
        int health;
    public:
        const static int AGGRESSIVE = 0;
        const static int BALANCED = 1;
        const static int DEFENSIVE = 2;
        const static int AGGRESSIVE_FLIPPED = 3;
        const static int BALANCED_FLIPPED = 4;
        const static int DEFENSIVE_FLIPPED = 5;

        const static int NEUTRAL = 0;
        const static int ATTACK_LOW = 1;
        const static int ATTACK_MID = 2;
        const static int ATTACK_HIGH = 3;
        const static int BLOCK_LOW = 4;
        const static int BLOCK_MID = 5;
        const static int BLOCK_HIGH = 6;

        Fl_GIF_Image* getImage(void) { return currentStance->getImage(); }
        int getChanceOfAttack(void) { return chanceOfAttack; }
        int getHealth(void) { return health; }
        int getPower(void);
        int getToughness(void);
        int getStanceType(void) { return currentStance->getType(); }
        int getStanceHeight(void) { return currentStance->getHeight(); }
        std::string getStanceName(void) { return currentStance->getName(); }
        std::string getName(void) { return name; }
        void setStance(int type);
        void adjustHealth(int change) { health += change; }
        void toggleBlockBonus(bool set) { blockBonusOn = set; }
        void toggleAttackBonus(bool set) { attackBonusOn = set; }
        Fighter(int style);
};

Fighter::Fighter(int style) {
    health = 100;
    for (int i = 0; i < 7; i++) {
        stances[i] = new Stance(style, i);
    }
    currentStance = stances[0];
    if (style == 0 || style == 3) {
        blockBonus = 2;
        attackBonus = 3;
        chanceOfAttack = 70;
        name = "Aggressive";
    } else if (style == 1 || style == 4) {
        blockBonus = 4;
        attackBonus = 2;
        chanceOfAttack = 50;
        name = "Balanced";
    } else if (style == 2 || style == 5) {
        blockBonus = 4;
        attackBonus = 1;
        chanceOfAttack = 40;
        name = "Defensive";
    }
    setStance(0);
    blockBonusOn = false;
    attackBonusOn = false;
}

int Fighter::getPower(void) {
    if (attackBonusOn) {
        return currentStance->getPower() + attackBonus;
        attackBonusOn = false;
    } else {
        return currentStance->getPower();
    }
}

int Fighter::getToughness(void) {
    if (blockBonusOn) {
        return currentStance->getToughness() + blockBonus;
        blockBonusOn = false;
    } else {
        return currentStance->getToughness();
    }
}

void Fighter::setStance(int type) {
    currentStance = stances[type];
}

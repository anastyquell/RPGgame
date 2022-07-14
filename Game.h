#pragma once
#include "lib.h"
#include "Menu.h"
#include "Magic.h"
#include "File.h"
#include "Character.h"
auto* file = new File<Magician>("", "data.bin");

using namespace std;

class Game {
    Menu m;

    Character* mob = new Mob();


    Magician* mag;
    Magic* ma = mob->UseMobMagic();

    Magic* fire;
    Magic* ice;
    Magic* elect;
    Magic* dendro;
    Magic* hill;

    double ataka;
    bool f;

    void stanHp() {
        cout << "\n\nСтан вашого здоров'я: " << mag->getHp() << "\nСтан здоров'я противника: " << mob->getHp();;
    }
public:
    Game() {
        this->mag = new Magician(1, 500, 1000, 1, 0.1);
        this->fire = mag->UseFireMagic();
        this->ice = mag->UseIceMagic();
        this->elect = mag->UseElectroMagic();
        this->dendro = mag->UseDendroMagic();
        this->hill = mag->UseHeelMagic();
    }
    Game(auto* mag) {
        this->mag = mag;
        this->fire = this->mag->UseFireMagic();
        this->ice = this->mag->UseIceMagic();
        this->elect = this->mag->UseElectroMagic();
        this->dendro = this->mag->UseDendroMagic();
        this->hill = this->mag->UseHeelMagic();
    }
    
    void battle(int moobType, int opit, int point) {
        mob->getLvl(mag->getLvl());
        mob->getStartHp();
        while(1){
            stanHp();
            int x = m.menuScills();
            switch (x)
            {
            case 1:
                ataka = fire->Use(mag->getAtk());
                ice->setStatusFire();
                mob->setHp(mob->dropHp(ataka, moobType));
                ataka = ma->Use(mob->getAtk());
                mag->setHp(mag->dropHp(ataka));
                break;
            case 2:
                ataka = ice->Use(mag->getAtk());
                fire->setStatusIce();
                mob->setHp(mob->dropHp(ataka, moobType));
                ataka = ma->Use(mob->getAtk());
                mag->setHp(mag->dropHp(ataka));
                break;
            case 3:
                ataka = elect->Use(mag->getAtk());
                dendro->setStatusElectro();
                mob->setHp(mob->dropHp(ataka, moobType));
                ataka = ma->Use(mob->getAtk());
                mag->setHp(mag->dropHp(ataka));
                break;
            case 4:
                ataka = dendro->Use(mag->getAtk());
                elect->setStatusDendro();
                mob->setHp(mob->dropHp(ataka, moobType));
                ataka = ma->Use(mob->getAtk());
                mag->setHp(mag->dropHp(ataka));
                break;
            case 5:
                mag->setHp(hill->Use(mag->getHp(), mag->getMaxHp()));
                ataka = ma->Use(mob->getAtk());
                mag->setHp(mag->dropHp(ataka));
                break;
            }
            if (mag->getHp() <= 0) {
                cout << "Ви програли!\n";
                f = 0;
                break;
            }
            else if (mob->getHp() <= 0) {
                cout << "Ви перемогли!\n";

                mag->addOpit(opit);
                mag->addPoint(point);

                mag->appLvl(mag->getOpit());

                cout << "\nВаш баланс: " << mag->getPoint();
                cout << "\nДосвiд " << mag->getOpit() << " iз " << 1000*mag->getLvl() << endl;
                
                f = 1;
                system("pause");
                break;
            }
        }
        
        
        system("cls");
    }
    void educationPart1() {
        mag->startParams();
        cout << "Вiтаю, друже! Ти став студентом школи магiї, а це означає що тебе чекають неймовiрнi випробування та цiкавi пригоди!\n Я електро-помiчник i ознайомлю тебе з правилами нашої школи\n";
        cout << "I почнемо одразу з практики!\n";
        cout << "На тебе напав слайм! Ти можешь користуватися 4 елементами, наносити звичайнi атаки та лiкуватися.\n За 1 хiд можливо використати 1 здiбнiсть. Не забувай про резисти!\n";
    }
    void educationPart2(){
        cout << "Вау! Ти змiг перемогти, вiтаю!\n";
        cout << "Зверни увагу, якщо ти накладаєш статус якоїсь стихiї - можеш отримати бонус до урону наступної атаки!\n";
        cout << "Комбiнацiї можливих реакцiй: вогонь+лiд, дендро+електро та навпаки\n";
        cout << "Тепер ти можеш вiдвiдувати рiзнi тренувальнi кабiнети.\n Також у нашiй школi є лабораторiя де ти зможешь знайти кориснi зiлля та пiдвищити рiвень своих навикiв!";
        cout << "Коли ти проходиш 1 тренувальний кабiнет - ти отримуєш золото. Без нього йти до лабораторiї немає сенсу!\n Кожен кабiнет вiдрiзняється рiвнем складностi.";
        cout << "Цiкавих тобi тренувань та побачимося на екзаменi!";
    }

    void room1() {
        do {
            cout << "На вас напав слайм!";
            battle(4, 50, 100);
            cout << "На вас напав вовк!";
            battle(4, 50, 100);
            cout << "На вас напав паук!";
            battle(1, 100, 200);
            cout << "На вас напав слайм!";
            battle(1, 100, 200);
            cout << "На вас напав мертвець!";
            battle(1, 100, 200);
            f = 0;
        } while (f);
        mainMenu();
    }
    void room2() {
        if (mag->getLvl() >= 5) {
            do {
                cout << "На вас напав вовкулака!";
                battle(2, 200, 400);
                cout << "На вас напав дикий пес!";
                battle(1, 100, 200);
                cout << "На вас напав скелет!";
                battle(1, 100, 200);
                cout << "На вас напав ядовитий павук!";
                battle(1, 100, 200);
                cout << "На вас напав слайм!";
                battle(2, 200, 400);
                cout << "На вас напав вовк!";
                battle(2, 200, 400);
                cout << "На вас напав мертвець!";
                battle(2, 200, 400);
                f = 0;
            } while (f);

            cout << "\nВiтаємо, ти пройшов першу кiмнату!";
            system("pause");
        }
        else {
            cout << "Ви ще не досягли 5 рівня, пройдіть інші кімнати та повертайтесь пізніше!\n";
            system("pause");
        }
        mainMenu();
        
    }
    void room3() {
        if (mag->getLvl() >= 8) {
            do {
                cout << "На вас напав привид!";
                battle(1, 100, 200);
                cout << "На вас напав слайм!";
                battle(2, 200, 400);
                cout << "На вас напав мертвець!";
                battle(2, 200, 400);
                cout << "На вас напав чахлик!";
                battle(1, 100, 200);
                cout << "На вас напав привид!";
                battle(2, 200, 400);
                cout << "На вас напав вовкулака!";
                battle(2, 200, 400);
                cout << "На вас напала вiдьма!";
                battle(2, 200, 400);
                cout << "На вас напав привид!";
                battle(2, 200, 400);
                cout << "На вас напав мертвець!";
                battle(2, 200, 400);
                f = 0;
            } while (f);


            cout << "\nВiтаємо, ти пройшов першу кiмнату!";
            system("pause");
        }
        else {
            cout << "Ви ще не досягли 8 рівня, пройдіть інші кімнати та повертайтесь пізніше!\n";
            system("pause");

        }
        mainMenu();
    }

    void examen() {
        if (mag->getLvl() >= 10) {
            cout << "Щоб пройти екзамен ви повиннi подолоти Чорного мага!";
            battle(3, 1000, 2000);

            cout << "\nВiтаємо, ти пройшов екзамен!";
            system("pause");
        }
        else {
            cout << "Ви ще не досягли 10 рівня, пройдіть інші кімнати та повертайтесь пізніше!\n";
            system("pause");

        }
        mainMenu();
    }

    void appLvlScills() {
        cout << "Цiна, щоб пiдвищити здiбнiсть на 1 рiвень - 200 монет\n";
        int x = m.appScills();

        switch (x)
        {
        case 1:
            fire->appLvlScills();
            mag->dropPoint(200);
            cout << "Рiвень магiї вогню пiдвищено!\n";
            break;
        case 2:
            ice->appLvlScills();
            mag->dropHp(200);
            cout << "Рiвень магiї льоду пiдвищено!\n";
            break;
        case 3:
            elect->appLvlScills();
            mag->dropPoint(200);
            cout << "Рiвень магiї електро пiдвищено!\n";
            break;
        case 4:
            dendro->appLvlScills();
            mag->dropPoint(200);
            cout << "Рiвень магiї землi пiдвищено!\n";
            break;
        case 5:
            hill->appLvlScills();
            mag->dropPoint(200);
            cout << "Рiвень магiї лiкування пiдвищено!\n";
            break;
        default:
            break;
        }
        system("pause");
        mainMenu();
    }

    void viewScills() {
        cout << "Рiвень магiї вогню: " << fire->getLvlScills() << endl;
        cout << "Рiвень магiї льоду: " << ice->getLvlScills() << endl;
        cout << "Рiвень магiї електро: " << elect->getLvlScills() << endl;
        cout << "Рiвень магiї землi: " << dendro->getLvlScills() << endl;
        cout << "Рiвень магiї лiкування: " << hill->getLvlScills() << endl; 
        system("pause");
        mainMenu();
    }

    void labolatory() {
        int x = m.labolatoryMenu();
        switch (x)
        {
        case 1:
            appLvlScills();
            break;
        case 2:
            viewScills();
            break;
        case 3:
            break;
        case 4:
            break;
        }
        system("pause");
        mainMenu();
    }

    void mainMenu() {
        int x = m.mainMenu();
        switch (x)
        {
        case 1:
            room1();
            break;
        case 2:
            room2();
            break;
        case 3:
            room3();
            break;
        case 4:
            examen();
            break;
        case 5:
            labolatory();
            break;

        case 6:
            cout << file->Save(*mag);
            system("pause");
            mainMenu();
            break;

        case 0:
            break;
        }

    }
};
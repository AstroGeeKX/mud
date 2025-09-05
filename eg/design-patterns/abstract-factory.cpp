#include <iostream>
#include <string>
using namespace std;

// 船体
class ShipBody {
   public:
    virtual string getShipBody() = 0;
    virtual ~ShipBody() {}
};

class WoodBody : public ShipBody {
   public:
    string getShipBody() override { return string("用<木材>制作轮船船体..."); }
};

class IronBody : public ShipBody {
   public:
    string getShipBody() override { return string("用<钢铁>制作轮船船体..."); }
};

class MetalBody : public ShipBody {
   public:
    string getShipBody() override { return string("用<合金>制作轮船船体..."); }
};

// 武器
class Weapon {
   public:
    virtual string getWeapon() = 0;
    virtual ~Weapon() {}
};

class Gun : public Weapon {
   public:
    string getWeapon() override { return string("配备的武器是<枪>..."); }
};

class Cannon : public Weapon {
   public:
    string getWeapon() override {
        return string("配备的武器是<自动机关炮>...");
    }
};

class Laser : public Weapon {
   public:
    string getWeapon() override { return string("配备的武器是<激光>..."); }
};

// 动力
class Engine {
   public:
    virtual string getEngine() = 0;
    virtual ~Engine() {}
};

class Human : public Engine {
   public:
    string getEngine() override { return string("使用<人力驱动>..."); }
};

class Diesel : public Engine {
   public:
    string getEngine() override { return string("使用<内燃机驱动>..."); }
};

class Nuclear : public Engine {
   public:
    string getEngine() override { return string("使用<核能驱动>..."); }
};

// 轮船类
class Ship {
   public:
    Ship(ShipBody* body, Weapon* weapon, Engine* engine)
        : m_body(body), m_weapon(weapon), m_engine(engine) {}
    string getProperty() {
        string info = m_body->getShipBody() + m_weapon->getWeapon() +
                      m_engine->getEngine();
        return info;
    }
    ~Ship() {
        delete m_body;
        delete m_engine;
        delete m_weapon;
    }

   private:
    ShipBody* m_body = nullptr;
    Weapon* m_weapon = nullptr;
    Engine* m_engine = nullptr;
};

// 工厂类
class AbstractFactory {
   public:
    virtual Ship* createShip() = 0;
    virtual ~AbstractFactory() {}
};

class BasicFactory : public AbstractFactory {
   public:
    Ship* createShip() override {
        Ship* ship = new Ship(new WoodBody, new Gun, new Human);
        cout << "<基础型>战船生产完毕, 可以下水啦..." << endl;
        return ship;
    }
};

class StandardFactory : public AbstractFactory {
   public:
    Ship* createShip() override {
        Ship* ship = new Ship(new IronBody, new Cannon, new Diesel);
        cout << "<标准型>战船生产完毕, 可以下水啦..." << endl;
        return ship;
    }
};

class UltimateFactory : public AbstractFactory {
   public:
    Ship* createShip() override {
        Ship* ship = new Ship(new MetalBody, new Laser, new Nuclear);
        cout << "<旗舰型>战船生产完毕, 可以下水啦..." << endl;
        return ship;
    }
};

int main() {
    AbstractFactory* factroy = new StandardFactory;
    Ship* ship = factroy->createShip();
    cout << ship->getProperty();
    delete ship;
    delete factroy;
    return 0;
}

// 作者: 苏丙榅
// 链接:
// https://subingwen.cn/design-patterns/abstract-factory/#2-1-%E8%AE%BE%E8%AE%A1%E5%9B%BE%E7%BA%B8
// 来源: 爱编程的大丙
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


// 工厂模式一般在工厂类里会有 `new 产品` 的操作，并且返回 `产品*`指针

// 抽象工厂和工厂模式大同小异，区别在于产品是否有一个基的抽象类

// 阅读代码正确方式是“逐行扫视”一遍，定位关键词，再重头仔细阅读

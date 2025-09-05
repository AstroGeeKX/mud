#include <iostream>
#include <string>
using namespace std;

// 战士的抽象类
class Soldier {
   public:
    Soldier() {}
    Soldier(string name) : m_name(name) {}
    string getName() { return m_name; };
    virtual void fight() = 0;
    virtual ~Soldier() {}

   protected:
    string m_name = string();
};

// 黑胡子(Marshall·D·Teach)
class Teach : public Soldier {
   public:
    using Soldier::Soldier;
    void fight() override {
        cout << m_name << "依靠惊人的力量和高超的体术战斗..." << endl;
    }
};

// 抽象的恶魔果实
class DevilFruit : public Soldier {
   public:
    // 指定要给哪个人吃恶魔果实 -- 附魔
    void enchantment(Soldier* soldier) {
        m_human = soldier;
        m_name = m_human->getName();
    }
    virtual ~DevilFruit() {}

   protected:
    Soldier* m_human = nullptr;
};

// 暗暗果实
class DarkFruit : public DevilFruit {
   public:
    void fight() override {
        m_human->fight();
        // 使用当前恶魔果实的能力
        cout << m_human->getName()
             << "吃了暗暗果实, 可以拥有黑洞一样的无限吸引力..." << endl;
        warning();
    }

   private:
    void warning() {
        cout << m_human->getName()
             << "你要注意: 吃了暗暗果实, "
                "身体元素化之后不能躲避攻击，会吸收所有伤害!"
             << endl;
    }
};

// 震震果实
class QuakeFruit : public DevilFruit {
   public:
    void fight() override {
        m_human->fight();
        cout << m_human->getName()
             << "吃了震震果实, 可以在任意空间引发震动, 摧毁目标...!" << endl;
    }
};

// 大饼果实
class PieFruit : public DevilFruit {
   public:
    void fight() override {
        m_human->fight();
        cout << m_human->getName() << "吃了大饼果实, 获得大饼铠甲...!" << endl;
        ability();
    }

    void ability() {
        cout << "最强辅助 -- 大饼果实可以将身边事物变成大饼, "
                "帮助自己和队友回血..."
             << endl;
    }
};

int main() {
    Teach* teach = new Teach("马歇尔·D·蒂奇");
    DarkFruit* dark = new DarkFruit;
    QuakeFruit* quake = new QuakeFruit;
    PieFruit* pie = new PieFruit;
    // 黑胡子吃了暗暗果实
    dark->enchantment(teach);
    // 黑胡子又吃了震震果实
    quake->enchantment(dark);
    // 黑胡子又吃了大饼果实
    pie->enchantment(quake);
    // 战斗
    pie->fight();
    delete teach;
    delete dark;
    delete quake;
    delete pie;
    return 0;
}

// 作者: 苏丙榅
// 链接:
// https://subingwen.cn/design-patterns/decorator/#2-5-%E5%85%AD%E8%BE%B9%E5%BD%A2%E6%88%98%E5%A3%AB
// 来源: 爱编程的大丙
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// 装饰模式主要是一种递归的思维，类似于链表的结构，逐层封装，
// 每次执行fight的时候，都会执行指针（被修饰对象）（被修饰的被修饰对象）里的fight，
// 逐层递归，直到第一层被修饰为止，再展开，依次打印出各自的fight内容。

// 修饰前的类，塞进修饰方法里，得出修饰后的对象
// Shape circle = new Circle();  // 圆形类
// ShapeDecorator redCircle = new RedShapeDecorator(new Circle());  // 塞进修饰
// 得到修饰后的类，既可以用圆形类，也可以用修饰的圆形类来完成画圆操作

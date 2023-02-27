#include <dp.h>

using namespace std;

int main() {
    sf::RenderWindow win(sf::VideoMode(width, height), "Double Pendulum");
    sf::Event ev;
    Pend pnd(Pendul(cl1, cm1, ca1), Pendul(cl2, cm2, ca2));
    win.setFramerateLimit(100);
    while(win.isOpen()) {
        while(win.pollEvent(ev)) {
            if(ev.type == sf::Event::Closed) win.close();
            if(ev.type == sf::Event::KeyPressed) {
                switch(ev.key.code) {
                    case sf::Keyboard::Space:
                        pnd.chshow();
                        break;
                    default:
                        break;
                }
            }
            if(ev.type == sf::Event::MouseButtonPressed) {
                if(ev.mouseButton.button == sf::Mouse::Left) pnd.chlog();
            }
        }
        pnd.update();
        pnd.render();
        win.clear();
        win.draw(pnd);
        win.display();
    }
}
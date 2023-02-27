#include <dp.h>

Pendul::Pendul(float l, float m, float a):len(l),mass(m),angle(a) {}

Pend::Pend(Pendul pendul1, Pendul pendul2):p1(pendul1),p2(pendul2) {
    trail = sf::VertexArray(sf::Points);
    if(!fnt.loadFromFile("Arialn.ttf")) std::cout << "Font error\n";
    textr.create(width, height);
    textr.setSmooth(true);
    this->setTexture(textr.getTexture());
    vb.create(3);
    vb.setPrimitiveType(sf::LineStrip);
    pends[0].setFillColor(sf::Color::White);
    pends[1].setFillColor(sf::Color::White);
    pends[0].setRadius(p1.mass*3);
    pends[1].setRadius(p2.mass*3);
    pends[0].setOrigin(p1.mass*3, p1.mass*3);
    pends[1].setOrigin(p2.mass*3, p2.mass*3);
    pends[0].setOutlineThickness(2);
    pends[1].setOutlineThickness(2);
    pends[0].setOutlineColor(sf::Color::Yellow);
    pends[1].setOutlineColor(sf::Color::Yellow);
    va[0].color = sf::Color::White;
    va[1].color = sf::Color::White;
    va[2].color = sf::Color::White;
    va[0].position = sf::Vector2f(width/2, upper);
}
void Pend::update() {
    float a = -(p1.mass+p2.mass)*G*p1.len*sin(p1.angle)-p2.mass*p1.len*p2.len*p2.vel*p2.vel*sin(p1.angle-p2.angle), 
          b = (p1.mass+p2.mass)*p1.len*p1.len,
          c = p2.mass*p1.len*p2.len*cos(p1.angle-p2.angle),
          f = -p2.mass*G*p2.len*sin(p2.angle)+p2.mass*p1.len*p2.len*p1.vel*p1.vel*sin(p1.angle-p2.angle),
          k = p2.mass*p2.len*p2.len,
          w = p2.mass*p1.len*p2.len*cos(p1.angle-p2.angle);
    p2.acc = (f-a*w/b)/(k-c*w/b);
    p1.acc = a/b-c*p2.acc/b;
    p2.vel = p2.vel+p2.acc*time;
    p1.vel = p1.vel+p1.acc*time;
    p2.angle = p2.angle+p2.vel*time;
    p1.angle = p1.angle+p1.vel*time;
    p1.x = abs(width/2-p1.len*sin(p1.angle));
    p1.y = upper+p1.len*cos(p1.angle);
    p2.x = abs(width/2-(p1.len*sin(p1.angle)+p2.len*sin(p2.angle)));
    p2.y = upper+p1.y+p2.len*cos(p2.angle);
}
void Pend::render() {
    sf::Vector2f pos1 = sf::Vector2f(p1.x, p1.y), pos2 = sf::Vector2f(p2.x, p2.y);
    trail.append(sf::Vertex(pos1, sf::Color(224, 224, 224)));
    trail.append(sf::Vertex(pos2, sf::Color(244, 244, 244)));
    va[1].position = pos1;
    va[2].position = pos2;
    pends[0].setPosition(pos1);
    pends[1].setPosition(pos2);
    vb.update(va);
    textr.clear(sf::Color::Black);
    if(show) textr.draw(vb);
    textr.draw(pends[0]);
    textr.draw(pends[1]);
    textr.draw(trail);
    if(log) {
        sf::Text txt;
        std::stringstream ss;
        txt.setFont(fnt);
        txt.setFillColor(sf::Color::White);
        txt.setCharacterSize(20);
        txt.setPosition(upper, upper);
        ss << "Angle 1: " << p1.angle << "\nAngle 2: " << p2.angle << "\nVel 1: " << p1.vel << "\nVel 2: " << p2.vel << "\nAcc 1: " << p1.acc << "\nAcc 2: " << p2.acc << "\n";
        txt.setString(ss.str());
        textr.draw(txt);
    }
    textr.display();
}
void Pend::chshow() {
    show = !show;
}
void Pend::chlog() {
    log = !log;
}
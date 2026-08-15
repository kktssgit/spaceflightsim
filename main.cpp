#include <SFML/Graphics.hpp>
#include "kmath.hpp"
#include "kgraph.hpp"

using ld = long double;

static sf::RenderWindow window(sf::VideoMode({600u, 600u}), "Space Flight Sim");

void drawPolygon(const kgraph::Polygon& poly, sf::Color col = sf::Color{255,255,255,255}){
    sf::ConvexShape conv;
    conv.setPointCount(poly.size);
    for(size_t i{};i<poly.size;i++){
        conv.setPoint(i,{poly.vertices[i].x, poly.vertices[i].y});
    }
    conv.setFillColor(col);
    window.draw(conv);
}

sf::View view(sf::FloatRect({-300.0,-300.0},{600.0,600.0}));

void handleControls(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        view.move({-5.0,0.0});
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        view.move({5.0,0.0});
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        view.move({0.0,5.0});
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        view.move({0.0,-5.0});

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Hyphen))
        view.zoom(1.02040816f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Equal) &&
       sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift))
        view.zoom(0.98f);
    
}

int main() {

    kgraph::Polygon p({
        {-100.0,-100.0},
        {-100.0,100.0},
        {100.0,100.0},
        {100.0,-100.0}});

    window.setFramerateLimit(60);

    while (window.isOpen()) {
        while(const std::optional event = window.pollEvent()) {
            if(event->is<sf::Event::Closed>())
                window.close();
        }

        window.setView(view);
        handleControls();
        window.clear(sf::Color::Black);

        drawPolygon(p);
        
        window.display();
    }
}

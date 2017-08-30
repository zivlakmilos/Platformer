#include "mainmenu.h"

#include <SFML/Graphics.hpp>

#include "resourcemanager.h"
#include "gamestatemanager.h"

MainMenu::MainMenu(void)
    : GameState(),
      m_selectedOption(OptionStart)
{
    m_options[OptionStart] = "Start";
    m_options[OptionQuit] = "Quit";
}

MainMenu::~MainMenu(void)
{
}

void MainMenu::handleEvents(sf::RenderWindow &window)
{
    GameStateManager *manager = GameStateManager::getGameStateManager();

    sf::Event event;
    while(window.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                switch(event.key.code)
                {
                    case sf::Keyboard::Escape:
                        window.close();
                        break;
                    case sf::Keyboard::Down:
                        if(++m_selectedOption >= OptionCount)
                            m_selectedOption = 0;
                        break;
                    case sf::Keyboard::Up:
                        if(--m_selectedOption < 0)
                            m_selectedOption = OptionCount - 1;
                        break;
                    case sf::Keyboard::Return:
                        if(m_selectedOption == OptionQuit)
                            window.close();
                        else if(m_selectedOption == OptionStart)
                            manager->setCurrentGameState("gameplay");
                        break;
                }
                break;
        }
    }
}

void MainMenu::update(float deltaTime)
{
}

void MainMenu::render(sf::RenderWindow &window)
{
    auto font = ResourceManager::getResourceManager()->getFont("kaushan");
    for(int i = 0; i < OptionCount; i++)
    {
        sf::Text text(m_options[i], *font);

        int height = text.getLocalBounds().height + 10.0f;
        float top = window.getSize().y / 2.0f - height * OptionCount / 2.0f;

        text.setPosition(window.getSize().x / 2.0f - text.getLocalBounds().width / 2.0f,
                         top + i * height);
        text.setColor(i == m_selectedOption ? sf::Color::Red : sf::Color::White);

        window.draw(text);
    }
}

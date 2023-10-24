#include "GameObject/GameObject.hpp"
#include "ComponentFactory/ComponentFactory.hpp"
#include "ComponentBluePrint/ComponentBluePrint.hpp"
#include <iostream>

int main()
{
    ComponentFactory all_components;

    RTEngine::GameObject player;
    player.setName("Mario");
    player.bind(all_components._Transform_());
    __signature__ sign  = player.getSignature();

    for (auto [key, value] : sign)
        std::cout << key << "=>" << value << std::endl;
}
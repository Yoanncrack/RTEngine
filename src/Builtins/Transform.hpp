#pragma once

//#include <glm/vec2.hpp>

struct Transform
{
    /*
    Transform(glm::vec2 p = glm::vec2(0, 0), glm::vec2 r=(0, 0), glm::vec2 s(1,1)) : position(p), rotation(r), scale(s) {}
    glm::vec2 position;
    glm::vec2 rotation;
    glm::vec2 scale;
    */
   Transform(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z){}
   int x;
   int y;
   int z;
};

#pragma once

#include "../ComponentBluePrint/ComponentBluePrint.hpp"
#include "../../constants/constants.hpp"
#include "../Builtins/builtins.hpp"


class ComponentFactory
{
    public:

    ComponentFactory() {last_id = -1;}

    Component<Transform> _Transform_()
    {
        Component<Transform> cpmnt;
        int id = generateId();
        cpmnt.setId(id);
        cpmnt.setValue(Transform());
        return cpmnt;
    }

    private:

    int generateId()
    {
        return last_id + 1;
    }

    int last_id;
};

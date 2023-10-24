#pragma once
#include "../../constants/constants.hpp"
#include <any>

class IComponent {

    public:

    virtual void setId(size_t id) = 0;
};

template<typename CMPT_TYPE>
class Component : IComponent {

    public:

    Component(){}

    Component(const Component &other) {
        *this = other;
    }

    Component &operator=(const Component &other) {
        m_id = other.getId();
        m_value = other.m_value;
        return *this;
    }

    

    void setValue(CMPT_TYPE cmpnt)
    {
        m_value = cmpnt;
    }

    void setId(size_t id) {
        m_id = id;
    }

    size_t getId() const {
        return m_id;
    }

    protected:

    CMPT_TYPE m_value;
    size_t m_id;
};

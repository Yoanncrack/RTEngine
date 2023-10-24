#pragma once
#include <bitset>
#include "../../constants/constants.hpp"
#include "../ComponentBluePrint/ComponentBluePrint.hpp"
#include <vector>
#include <any>
#include <unordered_map>
#include <memory>

namespace RTEngine
{
    class GameObject
    {

    public:
        GameObject(){}

        GameObject(const GameObject &obj)
        {
            m_signature = obj.getSignature();
            m_components = obj.getComponents();
            m_nested = obj.getNestedObjects();
            m_state = (STATE)obj.getState();
            m_name = obj.getName();
        }

        void setName(std::string name)
        {
            m_name = name;
        }

        GameObject &operator=(GameObject &other)
        {
            return other;
        }

        template <typename TYPE>
        void bind(const Component<TYPE> &cmpnt)
        {
            int cmpnt_id = cmpnt.getId();

            m_signature[cmpnt_id] = true;
            m_components[cmpnt_id] = std::make_any<Component<TYPE>>(cmpnt);
        }


        template <typename TYPE>
        void unbind(const Component<TYPE> &cmpnt)
        {
            int cmpnt_id = cmpnt.getId();

            m_signature[cmpnt_id] = false;
            m_components[cmpnt_id] = std::make_any<Component<TYPE>>(cmpnt);
        }

        template <typename TYPE>
        Component<TYPE> &operator[](int id)
        {
            if (!m_components.contains(id))
                throw(std::exception());
            return m_components[id];
        }

        void insert(const GameObject &other)
        {
            m_nested.push_back(std::make_shared<GameObject>(other));
        }

        void setActive(bool state)
        {
            m_state = (STATE)state;
        }

        __signature__ getSignature() const
        {
            return m_signature;
        }

        std::unordered_map<int, std::any> getComponents() const
        {
            return m_components;
        }

        std::vector<std::shared_ptr<GameObject>> getNestedObjects() const
        {
            return m_nested;
        }

        bool getState() const
        {
            return (bool)m_state;
        }
        
        std::string getName() const
        {
            return m_name;
        }


    private:
        enum STATE
        {
            ACTIVE = 1,
            INACTIVE = 0
        };

        __signature__ m_signature;
        std::unordered_map<int, std::any> m_components;
        std::vector<std::shared_ptr<GameObject>> m_nested;
        STATE m_state;
        std::string m_name;
    };
}
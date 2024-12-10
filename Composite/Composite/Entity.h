#pragma once
#include "TransformComponent.h"
#include <vector>
#include <type_traits>

#define COMPONENT_TEMPLATE \
template<typename T, typename ...Args, typename = std::enable_if_t<std::is_base_of_v<Component, T>>>


class Entity
{
public:
	Entity();
	Entity(Vec2 _pos, Vec2 _scale, float _rotation);
	Entity(sf::Vector2f _pos, sf::Vector2f _scale, float _rotation);
	~Entity();

	COMPONENT_TEMPLATE T* AddComponent(Args... _args)
	{
		T* component = new T(_args...);

		component->SetOwner(this);

		m_Component.push_back(component);

		return component;
	}

	COMPONENT_TEMPLATE T* GetComponent() const
	{
		for (Component* comp : m_Component)
		{
			T* castedComp = dynamic_cast<T*>(comp);

			if (castedComp != nullptr)
				return castedComp;
		}

		return nullptr;
	}

	COMPONENT_TEMPLATE std::vector<T*> GetComponents() const
	{
		std::vector<T*> compsOfType;

		for (Component* comp : m_Component)
		{
			T* castedComp = dynamic_cast<T*>(comp);

			if (castedComp != nullptr)
			{
				compsOfType.push_back(castedComp);
			}
		}

		return compsOfType;
	}

	COMPONENT_TEMPLATE void RemoveComponent()
	{
		for (int i = 0; i < m_Component.size(); i++)
		{
			T* castedComp = dynamic_cast<T*>(m_Component[i]);

			if (castedComp != nullptr)
			{
				delete m_Component[i];
				m_Component.erase(m_Component.begin() + i);
				return;
			}
		}
	}

	COMPONENT_TEMPLATE void RemoveComponents()
	{
		for (int i = 0; i < m_Component.size(); i++)
		{
			T* castedComp = dynamic_cast<T*>(m_Component[i]);

			if (castedComp != nullptr)
			{
				delete m_Component[i];
				m_Component.erase(m_Component.begin() + i);
				i--;
			}
		}
	}

	TransformComponent* transform = nullptr;

private:
	std::vector<Component*> m_Component;

};

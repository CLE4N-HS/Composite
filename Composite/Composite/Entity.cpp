#include "Entity.h"
#include "RectRenderer.h"

Entity::Entity()
{
	transform = AddComponent<TransformComponent>(Vec2());
}

Entity::Entity(Vec2 _pos, Vec2 _scale, float _rotation)
{
	transform = AddComponent<TransformComponent>(_pos, _scale, _rotation);
}

Entity::Entity(sf::Vector2f _pos, sf::Vector2f _scale, float _rotation)
{
	transform = AddComponent<TransformComponent>(_pos, _scale, _rotation);
}

Entity::~Entity()
{
	RemoveComponents<Component>();
}

nlohmann::json Entity::ToJson()
{
	nlohmann::json j;

	j["name"] = GetName();

	for (Component* comp : m_Component)
	{
		if (dynamic_cast<TransformComponent*>(comp))
		{
			j["Component"]["TransformComponent"] = comp->ToJson();
		}
		else if (dynamic_cast<RectRenderer*>(comp))
		{
			j["Component"]["RectRenderer"] = comp->ToJson();
		}
	}

	return j;
}

void Entity::FromJson(const nlohmann::json& _json)
{
	m_name = _json["name"];

	for (auto& comp : _json["Component"].items())
	{
		Component* newComp = nullptr;

		if (comp.key() == "TransformComponent")
		{
			newComp = transform;
		}
		else if (comp.key() == "RectRenderer")
		{
			newComp = AddComponent<RectRenderer>();
		}

		if (newComp)
		{
			newComp->FromJson(comp.value());
		}
	}
}

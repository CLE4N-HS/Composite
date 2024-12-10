#include "Entity.h"

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

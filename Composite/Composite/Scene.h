#pragma once
#include "Tools.h"
#include "Entity.h"

#define SCENE_TEMPLATE \
template<typename T, typename = std::enable_if_t<std::is_base_of_v<Entity, T>>>

class Scene
{
public:
	Scene();
	~Scene();

	virtual void Update();
	virtual void Render(sf::RenderTarget& _renderTarget);

	SCENE_TEMPLATE T* CreateEntity(Vec2 _pos, Vec2 _size, float _rotation)
	{
		T* newEntity = new T(_pos, _size, _rotation);

		m_Entities.push_back(newEntity);

		return newEntity;
	}

	SCENE_TEMPLATE T* CreateEntity(sf::Vector2f _pos, sf::Vector2f _size, float _rotation)
	{
		T* newEntity = new T(_pos, _size, _rotation);

		m_Entities.push_back(newEntity);

		return newEntity;
	}

	SCENE_TEMPLATE T* GetEntity(int _index)
	{
		return m_Entities[_index];
	}

	void DestroyEntity(int _index);

	void DestroyEntity(Entity* _entity);

private:
	std::vector<Entity*> m_Entities;

};

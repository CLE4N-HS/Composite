#include "Scene.h"
#include "RenderComponent.h"

Scene::Scene()
{
}

Scene::~Scene()
{
	while (m_Entities.size() > 0)
	{
		DestroyEntity(0);
	}
}

void Scene::Update()
{
	for (Entity* entity : m_Entities)
	{
		for (Component* comp : entity->GetComponents<Component>())
		{
			comp->Update();
		}
	}
}

void Scene::Render(sf::RenderTarget& _renderTarget)
{
	for (Entity* entity : m_Entities)
	{
		for (RenderComponent* renderComp : entity->GetComponents<RenderComponent>())
		{
			renderComp->Render(_renderTarget);
		}
	}
}

void Scene::DestroyEntity(int _index)
{
	delete m_Entities[_index];
	m_Entities.erase(m_Entities.begin() + _index);
}

void Scene::DestroyEntity(Entity* _entity)
{
	for (int i = 0; i < m_Entities.size(); i++)
	{
		if (m_Entities[i] == _entity)
		{
			delete m_Entities[i];
			m_Entities.erase(m_Entities.begin() + i);
			return;
		}
	}
}

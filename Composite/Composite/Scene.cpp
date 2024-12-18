#include "Scene.h"
#include "RenderComponent.h"
#include <fstream>

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

void Scene::Save()
{
	nlohmann::json j;
	
	for (Entity* entity : m_Entities)
	{
		j["entities"].push_back(entity->ToJson());
	}

	std::ofstream file("../JSON/Scene.json");

	if (file.is_open())
	{
		file << j.dump(4);

		file.close();
	}
}

void Scene::Load()
{
	std::ifstream file("../JSON/Scene.json");

	if (file.is_open())
	{
		nlohmann::json j;

		file >> j;
		
		for (nlohmann::json& entityJson : j["entities"])
		{
			Entity* newEntity = CreateEntity(sf::Vector2f(), sf::Vector2f(), 0.f);
			newEntity->FromJson(entityJson);
		}

		file.close();
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

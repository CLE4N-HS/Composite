#include "Entity.h"
#include "FirstComponent.h"
#include "SecondComponent.h"
#include "TransformComponent.h"

#include "GameScene.h"
#include "Tools.h"
#include "RectRenderer.h"
#include "CircleRenderer.h"

#include "imgui.h"
#include "imgui-SFML.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Composite");

	GameScene* newScene = new GameScene();

	//newScene->CreateEntity<Entity>(Vec2(50.f, 50.f), Vec2(60.f, 40.f), 0.f);
	//newScene->CreateEntity<Entity>(Vec2(150.f, 150.f), Vec2(40.f, 40.f), 50.f);
	newScene->CreateEntity<Entity>(sf::Vector2f(200.f, 200.f), sf::Vector2f(60.f, 60.f), 0.f);
	newScene->CreateEntity<Entity>(sf::Vector2f(600.f, 200.f), sf::Vector2f(60.f, 60.f), 50.f);
	newScene->CreateEntity<Entity>(sf::Vector2f(400.f, 400.f), sf::Vector2f(120.f, 120.f), 50.f);

	newScene->GetEntity<Entity>(0)->AddComponent<RectRenderer>(sf::Color(255, 255, 0));
	newScene->GetEntity<Entity>(1)->AddComponent<RectRenderer>(sf::Color(255, 0, 255));
	newScene->GetEntity<Entity>(2)->AddComponent<CircleRenderer>(sf::Color(255, 0, 255));

	newScene->GetEntity<Entity>(0)->GetComponent<RenderComponent>()->SetColor(sf::Color(255, 0, 0));

	ImGui::SFML::Init(window);

	sf::Clock deltaClock;

	while (window.isOpen())
	{
		sf::Event sfEvent;
		
		while (window.pollEvent(sfEvent))
		{
			ImGui::SFML::ProcessEvent(window, sfEvent);
			if (sfEvent.type == sf::Event::Closed ||
				sf::Mouse::isButtonPressed(sf::Mouse::Middle))
				window.close();
		}



		// ImGui
		ImGui::SFML::Update(window, deltaClock.restart());

		ImGui::Begin("Window");
		ImGui::Text("Buttons :");
		ImGui::Separator();

		if (ImGui::Button("Button"))
		{
			std::cout << "Button pressed." << std::endl;
		}

		ImGui::Separator();

		Entity* p = newScene->GetEntity<Entity>(0);

		sf::Vector2f pPos = p->transform->GetPos();
		ImGui::Text("Position :");
		ImGui::PushItemWidth(100.f);
		ImGui::DragFloat("posX", &pPos.x, 0.1f, 0.f, 800.f, "%.1f");
		ImGui::SameLine();
		ImGui::DragFloat("posY", &pPos.y, 0.1f, 0.f, 800.f, "%.1f");
		p->transform->SetPos(pPos);

		sf::Vector2f pScale = p->transform->GetScale();
		ImGui::Text("Scale : ");
		ImGui::DragFloat("scaleX", &pScale.x, 0.1f, 0.f, 800.f, "%.1f");
		ImGui::SameLine();
		ImGui::DragFloat("scaleY", &pScale.y, 0.1f, 0.f, 800.f, "%.1f");
		p->transform->SetScale(pScale);
		
		float pRotation = p->transform->GetRotation();
		ImGui::Text("Rotation : ");
		ImGui::DragFloat("Angle", &pRotation, 0.1f, 0.f, 800.f, "%.1f");
		p->transform->SetRotation(pRotation);

		float igColor[4];
		ImGui::Text("Color : ");
		ImGui::ColorEdit4("asas", igColor);


		ImGui::End();


	






		// Update every entity components
		newScene->Update();

		window.clear();

		// Draw every renderer comp
		newScene->Render(window);


		ImGui::SFML::Render(window);
		window.display();
	}

	ImGui::SFML::Shutdown(window);


	return 0;
	





	//for (;;)
	{
		Entity* e = new Entity();
		e->AddComponent<FirstComponent>();
		e->AddComponent<SecondComponent>(1);
		//e->transform->update();
		delete e;
	}



	//Entity* entity = new Entity();
	//
	//TransformComponent* transComp = entity->AddComponent<TransformComponent>(Vec2(0.f, 0.f));
	//
	//transComp->SetPos(50.f, 50.f);
	//entity->transform->SetPos(10.f, 10.f);
	//
	//transComp->Update();
	//
	//transComp->Move(12.5f, 10.f);
	//
	//transComp->Update();


	
	//delete entity;

	return EXIT_SUCCESS;
}
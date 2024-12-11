#include "Entity.h"
#include "FirstComponent.h"
#include "SecondComponent.h"
#include "TransformComponent.h"

#include "GameScene.h"
#include "Tools.h"
#include "RectRenderer.h"
#include "CircleRenderer.h"

#ifdef USING_IMGUI
#include "imgui.h"
#include "imgui-SFML.h"
#endif


#include "Editor.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Composite");

	GameScene* newScene = new GameScene();

	//newScene->CreateEntity<Entity>(Vec2(50.f, 50.f), Vec2(60.f, 40.f), 0.f);
	//newScene->CreateEntity<Entity>(Vec2(150.f, 150.f), Vec2(40.f, 40.f), 50.f);
	newScene->CreateEntity(sf::Vector2f(200.f, 200.f), sf::Vector2f(60.f, 60.f), 0.f);
	newScene->CreateEntity(sf::Vector2f(600.f, 200.f), sf::Vector2f(60.f, 60.f), 50.f);
	newScene->CreateEntity(sf::Vector2f(400.f, 400.f), sf::Vector2f(120.f, 120.f), 50.f);

	newScene->GetEntity<Entity>(0)->AddComponent<RectRenderer>(sf::Color(255, 255, 0));
	newScene->GetEntity<Entity>(1)->AddComponent<RectRenderer>(sf::Color(255, 0, 255));
	newScene->GetEntity<Entity>(2)->AddComponent<CircleRenderer>(sf::Color(255, 0, 255));

	newScene->GetEntity<Entity>(0)->GetComponent<RenderComponent>()->SetColor(sf::Color(255, 0, 0));

#ifdef USING_IMGUI
	ImGui::SFML::Init(window);
#endif // USING_IMGUI

	Editor editor;

	sf::Clock deltaClock;

	while (window.isOpen())
	{
		sf::Event sfEvent;
		
		while (window.pollEvent(sfEvent))
		{
#ifdef USING_IMGUI
			ImGui::SFML::ProcessEvent(window, sfEvent);
#endif // USING_IMGUI
			if (sfEvent.type == sf::Event::Closed ||
				sf::Mouse::isButtonPressed(sf::Mouse::Middle))
				window.close();
		}

		// ImGui
		ImGui::SFML::Update(window, deltaClock.restart());

#ifdef USING_IMGUIa

		ImGui::SetNextWindowPos(ImVec2(0.f, 0.f));
		ImGui::SetNextWindowSize(ImVec2(250.f, 250.f), ImGuiCond_Once);

		ImGui::Begin("Window", nullptr, ImGuiWindowFlags_NoCollapse);
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
		ImGui::DragFloat("X##Position", &pPos.x, 0.1f, 0.f, 800.f, "%.1f");
		ImGui::SameLine();
		ImGui::DragFloat("Y##Position", &pPos.y, 0.1f, 0.f, 800.f, "%.1f");
		p->transform->SetPos(pPos);

		sf::Vector2f pScale = p->transform->GetScale();
		ImGui::Text("Scale : ");
		ImGui::DragFloat("X##Scale", &pScale.x, 0.1f, 0.f, 800.f, "%.1f");
		ImGui::SameLine();
		ImGui::DragFloat("Y##Scale", &pScale.y, 0.1f, 0.f, 800.f, "%.1f");
		p->transform->SetScale(pScale);
		
		float pRotation = p->transform->GetRotation();
		ImGui::Text("Rotation : ");
		ImGui::DragFloat("Angle", &pRotation, 0.1f, 0.f, 800.f, "%.1f");
		p->transform->SetRotation(pRotation);

		sf::Color pColor = p->GetComponent<RenderComponent>()->GetColor();
		float igColor[4]{ static_cast<float>(pColor.r) / 255.f, static_cast<float>(pColor.g) / 255.f, static_cast<float>(pColor.b) / 255.f, static_cast<float>(pColor.a) / 255.f };
		ImGui::Text("Color : ");
		ImGui::PushItemWidth(255.f);
		ImGui::ColorEdit4("RGBA", igColor, ImGuiColorEditFlags_AlphaBar | ImGuiColorEditFlags_NoInputs);
		sf::Color pNewColor = sf::Color(static_cast<sf::Uint8>(igColor[0] * 255.f), static_cast<sf::Uint8>(igColor[1] * 255.f), static_cast<sf::Uint8>(igColor[2] * 255.f), static_cast<sf::Uint8>(igColor[3] * 255.f));
		p->GetComponent<RenderComponent>()->SetColor(pNewColor);


		ImGui::End();
#endif // USING_IMGUI





		// Update every entity components
		newScene->Update();

		window.clear();

		editor.Render(*newScene);

		// Draw every renderer comp
		newScene->Render(window);


#ifdef USING_IMGUI
		ImGui::SFML::Render(window);
#endif // USING_IMGUI

		window.display();
	}

#ifdef USING_IMGUI
	ImGui::SFML::Shutdown(window);
#endif // USING_IMGUI


	return 0;
	





	//for (;;)
	{
		Entity* e = new Entity();
		//e->AddComponent<FirstComponent>();
		//e->AddComponent<SecondComponent>(1);
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
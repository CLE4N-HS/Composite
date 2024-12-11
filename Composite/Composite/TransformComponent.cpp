#include "TransformComponent.h"

#ifdef USING_IMGUI
namespace ig = ImGui;
#endif // USING_IMGUI

TransformComponent::TransformComponent(Vec2 _vec)/* : m_Pos(_vec)*/
{
}

TransformComponent::TransformComponent(float _x, float _y) : m_Pos(_x, _y)
{
}

TransformComponent::TransformComponent(Vec2 _pos, Vec2 _scale, float _rotation) /*:
	m_Pos(_pos), m_Scale(_scale), m_Rotation(_rotation)*/
{
}

TransformComponent::TransformComponent(sf::Vector2f _pos, sf::Vector2f _scale, float _rotation) :
	m_Pos(_pos), m_Scale(_scale), m_Rotation(_rotation)
{
}

void TransformComponent::Update()
{
	//std::cout << m_Pos.x << ", " << m_Pos.y << std::endl;
}

#ifdef USING_IMGUI
void TransformComponent::OnImGuiRender()
{
	if (ig::CollapsingHeader("Transform", ImGuiTreeNodeFlags_DefaultOpen))
	{
		ig::Text("Position :");
		ig::DragFloat2("##Position", &m_Pos.x, 1.f);
		ig::Text("Scale :");
		ig::DragFloat2("##Scale", &m_Scale.x, 0.1f);
		ig::Text("Rotation :");
		ig::DragFloat("##Rotation", &m_Rotation, 1.f, 0.f, 360.f);
	}
}
#endif // USING_IMGUI

//void TransformComponent::Move(const Vec2& _pos)
//{
//	m_Pos.x += _pos.x;
//	m_Pos.y += _pos.y;
//}
//
//void TransformComponent::Move(const float& _posX, const float& _posY)
//{
//	m_Pos.x += _posX;
//	m_Pos.y += _posY;
//}

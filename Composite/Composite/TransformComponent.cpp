#include "TransformComponent.h"

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
	m_Pos(_pos), m_Scale(_scale), m_Rotation(m_Rotation)
{
}

void TransformComponent::Update()
{
	//std::cout << m_Pos.x << ", " << m_Pos.y << std::endl;
}

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

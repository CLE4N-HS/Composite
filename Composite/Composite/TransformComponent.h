#pragma once
#include "Component.h"

struct Vec2 {
	inline Vec2() { x = 0.f; y = 0.f; }
	inline Vec2(float _x, float _y) { x = _x; y = _y; }
	float x = 0.f;
	float y = 0.f;
	inline sf::Vector2f ToVector2f() { return sf::Vector2f(this->x, this->y); }
};

class TransformComponent : public Component
{
	using Component::Component;

public:
	TransformComponent(Vec2 _vec);
	TransformComponent(float _x, float _y);
	TransformComponent(Vec2 _pos, Vec2 _scale, float _rotation);
	TransformComponent(sf::Vector2f _pos, sf::Vector2f _scale, float _rotation);

	virtual void Update() override;

#ifdef USING_IMGUI
	virtual void OnImGuiRender() override;
#endif // USING_IMGUI

	//inline void SetPos(const Vec2& _pos) { m_Pos = _pos; }
	//inline void SetPos(const float& _posX, const float& _posY) { m_Pos.x = _posX; m_Pos.y = _posY; }
	//
	//inline void SetRotation(const float& _rotation) { m_Rotation = _rotation; }
	//
	//inline void SetScale(const Vec2& _scale) { m_Scale = _scale; }
	//inline void SetScale(const float& _scaleX, const float& _scaleY) { m_Scale.x = _scaleX; m_Scale.y = _scaleY; }
	//
	//inline Vec2 GetPos() const { return m_Pos; }
	//inline float GetRotation() const { return m_Rotation; }
	//inline Vec2 GetScale() const { return m_Scale; }
	//
	//void Move(const Vec2& _pos);
	//void Move(const float& _posX, const float& _posY);

	inline sf::Vector2f GetPos() const { return m_Pos; }
	inline sf::Vector2f GetScale() const { return m_Scale; }
	inline float GetRotation() const { return m_Rotation; }

	inline void SetPos(const sf::Vector2f& _pos) { m_Pos = _pos; }
	inline void SetScale(const sf::Vector2f& _scale) { m_Scale = _scale; }
	inline void SetRotation(const float& _rotation) { m_Rotation = _rotation; }

private:
	//Vec2 m_Pos = Vec2();
	//Vec2 m_Scale = Vec2();
	sf::Vector2f m_Pos = sf::Vector2f();
	sf::Vector2f m_Scale = sf::Vector2f();
	float m_Rotation = 0.f;

};

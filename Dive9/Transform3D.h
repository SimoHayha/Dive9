#pragma once

#include "stdafx.h"

namespace Dive9
{
	class Transform3D
	{
	public:
		Transform3D();
		virtual ~Transform3D();

		void	Position(DirectX::XMVECTOR& position);
		void	Rotation(DirectX::XMMATRIX& rotation);
		void	Scale(DirectX::XMVECTOR& scale);

		void	UpdateLocal();
		void	UpdateWorld(DirectX::XMMATRIX& parent);
		void	UpdateWorld();

		void	LocalMatrix(DirectX::XMMATRIX& matrix) const;
		void	WorldMatrix(DirectX::XMMATRIX& matrix) const;

		void	GetView(DirectX::XMMATRIX& matrix) const;

		DirectX::XMVECTOR	LocalToWorldSpace(DirectX::XMVECTOR const& input);
		DirectX::XMVECTOR	WorldToLocalSpace(DirectX::XMVECTOR const& input);
		DirectX::XMVECTOR	LocalVectorToWorldSpace(DirectX::XMVECTOR const& input);
		DirectX::XMVECTOR	LocalPointToWorldSpace(DirectX::XMVECTOR const& input);
		DirectX::XMVECTOR	WorldVectorToLocalSpace(DirectX::XMVECTOR const& input);
		DirectX::XMVECTOR	WorldPointToLocalSpace(DirectX::XMVECTOR const& input);

	protected:
		DirectX::XMFLOAT3	m_translation;
		DirectX::XMFLOAT3X3	m_rotation;
		DirectX::XMFLOAT3	m_scale;
		DirectX::XMFLOAT4X4	m_world;
		DirectX::XMFLOAT4X4	m_local;
	};
}
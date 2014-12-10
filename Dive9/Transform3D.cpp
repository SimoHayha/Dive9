#include "stdafx.h"
#include "Transform3D.h"

using namespace Dive9;

Transform3D::Transform3D()
{
	DirectX::XMStoreFloat3(&m_translation, DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f));
	DirectX::XMStoreFloat3x3(&m_rotation, DirectX::XMMatrixIdentity());
	DirectX::XMStoreFloat3(&m_scale, DirectX::XMVectorSet(1.0f, 1.0f, 1.0f, 0.0f));

	DirectX::XMStoreFloat4x4(&m_world, DirectX::XMMatrixIdentity());
	DirectX::XMStoreFloat4x4(&m_local, DirectX::XMMatrixIdentity());
}

Dive9::Transform3D::~Transform3D()
{
}

void Transform3D::Position(DirectX::XMVECTOR& position)
{
	position = DirectX::XMLoadFloat3(&m_translation);
}

void Transform3D::Rotation(DirectX::XMMATRIX& rotation)
{
	rotation = DirectX::XMLoadFloat3x3(&m_rotation);
}

void Transform3D::Scale(DirectX::XMVECTOR& scale)
{
	scale = DirectX::XMLoadFloat3(&m_scale);
}

void Transform3D::UpdateLocal()
{
	DirectX::XMMATRIX	local = DirectX::XMLoadFloat4x4(&m_local);

	local = DirectX::XMMatrixIdentity();
	local *= DirectX::XMLoadFloat3x3(&m_rotation);
	local *= DirectX::XMMatrixTranslationFromVector(DirectX::XMLoadFloat3(&m_translation));
	local *= DirectX::XMMatrixScalingFromVector(DirectX::XMLoadFloat3(&m_scale));

	DirectX::XMStoreFloat4x4(&m_local, local);
}

void Transform3D::UpdateWorld(DirectX::XMMATRIX& parent)
{
	DirectX::XMMATRIX	world = DirectX::XMLoadFloat4x4(&m_world);
	world = DirectX::XMLoadFloat4x4(&m_local) * parent;
	DirectX::XMStoreFloat4x4(&m_world, world);
}

void Transform3D::UpdateWorld()
{
	DirectX::XMMATRIX	world = DirectX::XMLoadFloat4x4(&m_world);
	world = DirectX::XMLoadFloat4x4(&m_local);
	DirectX::XMStoreFloat4x4(&m_world, world);
}

void Transform3D::LocalMatrix(DirectX::XMMATRIX& matrix) const
{
	matrix = DirectX::XMLoadFloat4x4(&m_local);
}

void Transform3D::WorldMatrix(DirectX::XMMATRIX& matrix) const
{
	matrix = DirectX::XMLoadFloat4x4(&m_world);
}

void Transform3D::GetView(DirectX::XMMATRIX& matrix) const
{
	DirectX::XMVECTOR	eye = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 1.0f);
	DirectX::XMVECTOR	lookAt = DirectX::XMVectorSet(0.0f, 0.0f, 1.0f, 1.0f);
	DirectX::XMVECTOR	up = DirectX::XMVectorSet(0.0f, 1.0f, 0.0f, 1.0f);

	eye = DirectX::XMVector3Transform(eye, DirectX::XMLoadFloat4x4(&m_world));
	lookAt = DirectX::XMVector3Transform(lookAt, DirectX::XMLoadFloat4x4(&m_world));
	up = DirectX::XMVector3Transform(up, DirectX::XMLoadFloat4x4(&m_world));

	matrix = DirectX::XMMatrixLookAtLH(eye, lookAt, up);
}

DirectX::XMVECTOR Transform3D::LocalToWorldSpace(DirectX::XMVECTOR const& input)
{
	return DirectX::XMVector4Transform(input, DirectX::XMLoadFloat4x4(&m_world));
}

DirectX::XMVECTOR Transform3D::WorldToLocalSpace(DirectX::XMVECTOR const& input)
{
	return DirectX::XMVector4Transform(input, DirectX::XMMatrixInverse(nullptr, DirectX::XMLoadFloat4x4(&m_world)));
}

DirectX::XMVECTOR Transform3D::LocalVectorToWorldSpace(DirectX::XMVECTOR const& input)
{
}

DirectX::XMVECTOR Transform3D::LocalPointToWorldSpace(DirectX::XMVECTOR const& input)
{

}

DirectX::XMVECTOR Transform3D::WorldVectorToLocalSpace(DirectX::XMVECTOR const& input)
{

}

DirectX::XMVECTOR Transform3D::WorldPointToLocalSpace(DirectX::XMVECTOR const& input)
{

}

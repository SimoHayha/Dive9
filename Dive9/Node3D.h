#pragma once

#include "stdafx.h"

namespace Dive9
{
	class Node3D
	{
	public:
		Node3D();
		virtual ~Node3D();

		void	Update(float time);
		void	UpdateLocal(float time);
		void	UpdateWorld();

		void	AttachChild(Node3D* child);
		void	DetachChild(Node3D* child);

		void	AttachParent(Node3D* parent);
		void	DetachParent();
		Node3D*	GetParent();

		std::wstring	ToString();
		void			SetName(std::string const& name);
		std::wstring	GetName() const;

		std::vector<Node3D*> const&	Nodes();

	protected:
		std::wstring	m_name;

		std::vector<Node3D*>	m_nodes;

		Node3D*	m_parent;
	};
}
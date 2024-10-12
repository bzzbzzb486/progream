#include"threaded_binary_tree.h"

Node* Threaded_Binary_Tree::Init()
{
	int d = 0;
	cin >> d;
	if (d == -1)
	{
		return NULL;
	}
	else
	{
		Node* n = new Node;
		n->date = d;
		n->left = this->Init();
		n->right = this->Init();
		return n;
	}
}

void Threaded_Binary_Tree::Front_Init(Node* r)
{
	if (q.empty())
	{
		q.push(r);
		if (r->left != NULL)
			this->Front_Init(r->left);
		if (r->right != NULL)
			this->Front_Init(r->right);
		return;
	}

	if (q.front()->right == NULL)
		q.front()->right = r;
	if (r->left == NULL)
	{
		r->left = q.front();
		q.push(r);
	}
	else
	{
		q.push(r);
		this->Front_Init(r->left);
	}

	if (r->right == q.front() || r->right == NULL)
		return;
	else
		this->Front_Init(r->right);
}

void Threaded_Binary_Tree::Middle_Init(Node* r)
{
	if (r->left != NULL)
		this->Middle_Init(r->left);
	if (q.empty())
	{
		q.push(r);
		if (r->right != NULL)
			this->Middle_Init(r->right);
		return;
	}
	if (q.front()->right == NULL)
		q.front()->right = r;
	if (r->left == NULL)
		r->left = q.front();
	if (r->right != NULL)
		this->Middle_Init(r->right);
}

void Threaded_Binary_Tree::Behind_Init(Node* r)
{
	if (r->left != NULL)
		this->Behind_Init(r->left);
	if (r->right != NULL)
		this->Behind_Init(r->right);
	if (!q.empty() && q.front()->right == NULL)
		q.front()->right = r;
	if (!q.empty() && r->left == NULL)
		r->left = q.front();
	q.push(r);
}

void Threaded_Binary_Tree::Init_by_Threaded(way travel_way)
{
	switch (travel_way)
	{
	case front:
		this->Front_Init(root);
		break;
	case middle:
		this->Middle_Init(root);
		break;
	case behind:
		this->Behind_Init(root);
		break;
	}
}
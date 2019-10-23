#include "BinaryTree.h"



BinaryTree::BinaryTree()
{
}


BinaryTree::~BinaryTree()
{
}

void BinaryTree::draw(aie::Renderer2D* renderer, TreeNode* selected)
{
	draw(renderer, m_pRoot, 640, 680, 640, selected);
}

void BinaryTree::insert(int a_nValue)
{
	TreeNode *newNode = new TreeNode(a_nValue);
	TreeNode *currentNode;
	newNode->setData(a_nValue);

	if (isEmpty() == true) {
		m_pRoot = *newNode;
		return;
	}
	else {
		currentNode = m_pRoot;
	}

	while (currentNode != nullptr)
	{
		if (newNode->getData() < currentNode->getData()) {
			currentNode->setLeft(newNode);
		}
		if (newNode->getData() > currentNode->getData()) {
			currentNode->setRight(newNode);
		}
		if (newNode->getData() == currentNode->getData()) {
			return;
		}
	}
}

bool BinaryTree::findNode(int a_nSearchValue, TreeNode ** ppOutNode, TreeNode ** ppOutParent)
{
	return false;
}

void BinaryTree::draw(aie::Renderer2D* renderer, TreeNode* pNode, int x, int y,
	int horizontalSpacing, TreeNode* selected)
{
	horizontalSpacing /= 2;
	if (pNode) {
		if (pNode->hasLeft()) {
			renderer->setRenderColour(1, 0, 0);
			renderer->drawLine(x, y, x - horizontalSpacing, y - 80);
			draw(renderer, pNode->getLeft(), x - horizontalSpacing,
				y - 80, horizontalSpacing, selected);
		}
		if (pNode->hasRight()) {
			renderer->setRenderColour(1, 0, 0);
			renderer->drawLine(x, y, x + horizontalSpacing, y - 80);
			draw(renderer, pNode->getRight(), x + horizontalSpacing,
				y - 80, horizontalSpacing, selected);
		}
		pNode->draw(renderer, x, y, (selected == pNode));
	}
}
